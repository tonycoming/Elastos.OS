//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#include "elastos/droid/dialer/widget/SearchEditTextLayout.h"
#include "elastos/droid/dialer/util/DialerUtils.h"
#include "elastos/droid/phone/common/animation/AnimUtils.h"
#include <elastos/core/CoreUtils.h>
#include "R.h"

using Elastos::Droid::Animation::IAnimator;
using Elastos::Droid::Animation::IValueAnimatorHelper;
using Elastos::Droid::Animation::CValueAnimatorHelper;
using Elastos::Droid::Animation::EIID_IAnimatorUpdateListener;
using Elastos::Droid::View::IViewGroupLayoutParams;
using Elastos::Droid::View::IViewGroupMarginLayoutParams;
using Elastos::Droid::View::EIID_IViewOnClickListener;
using Elastos::Droid::View::EIID_IViewOnFocusChangeListener;
using Elastos::Droid::Widget::ITextView;
using Elastos::Core::CoreUtils;
using Elastos::Core::IFloat;
using Elastos::Droid::Dialer::Util::DialerUtils;
using Elastos::Droid::Phone::Common::Animation::AnimUtils;

namespace Elastos {
namespace Droid {
namespace Dialer {
namespace Widget {


//================================================================
// SearchEditTextLayout::SearchViewFocusChangeListener
//================================================================
CAR_INTERFACE_IMPL(SearchEditTextLayout::SearchViewFocusChangeListener, Object, IViewOnFocusChangeListener);

SearchEditTextLayout::SearchViewFocusChangeListener::SearchViewFocusChangeListener(
    /* [in] */ SearchEditTextLayout* host)
    : mHost(host)
{}

ECode SearchEditTextLayout::SearchViewFocusChangeListener::OnFocusChange(
    /* [in] */ IView* v,
    /* [in] */ Boolean hasFocus)
{
    if (hasFocus) {
        DialerUtils::ShowInputMethod(v);
    }
    else {
        DialerUtils::HideInputMethod(v);
    }
    return NOERROR;
}


//================================================================
// SearchEditTextLayout::SearchCloseButtonClickListener
//================================================================
CAR_INTERFACE_IMPL(SearchEditTextLayout::SearchCloseButtonClickListener, Object, IViewOnClickListener);

SearchEditTextLayout::SearchCloseButtonClickListener::SearchCloseButtonClickListener(
    /* [in] */ SearchEditTextLayout* host)
    : mHost(host)
{}

ECode SearchEditTextLayout::SearchCloseButtonClickListener::OnClick(
    /* [in] */ IView* v)
{
    ITextView::Probe(mHost->mSearchView)->SetText((ICharSequence*)NULL);
    return NOERROR;
}


//================================================================
// SearchEditTextLayout::SearchBackButtonClickListener
//================================================================
CAR_INTERFACE_IMPL(SearchEditTextLayout::SearchBackButtonClickListener, Object, IViewOnClickListener);

SearchEditTextLayout::SearchBackButtonClickListener::SearchBackButtonClickListener(
    /* [in] */ SearchEditTextLayout* host)
    : mHost(host)
{}

ECode SearchEditTextLayout::SearchBackButtonClickListener::OnClick(
    /* [in] */ IView* v)
{
    if (mHost->mOnBackButtonClickedListener != NULL) {
        mHost->mOnBackButtonClickedListener->OnBackButtonClicked();
    }
    return NOERROR;
}


//================================================================
// SearchEditTextLayout::AnimatorUpdateListener
//================================================================
CAR_INTERFACE_IMPL(SearchEditTextLayout::AnimatorUpdateListener, Object, IAnimatorUpdateListener);

SearchEditTextLayout::AnimatorUpdateListener::AnimatorUpdateListener(
    /* [in] */ SearchEditTextLayout* host)
    : mHost(host)
{}

ECode SearchEditTextLayout::AnimatorUpdateListener::OnAnimationUpdate(
    /* [in] */ IValueAnimator* animation)
{
    AutoPtr<IInterface> value;
    animation->GetAnimatedValue((IInterface**)&value);
    Float fraction;
    IFloat::Probe(value)->GetValue(&fraction);
    mHost->SetMargins(fraction);
    return NOERROR;
}


//================================================================
// SearchEditTextLayout
//================================================================
const Float SearchEditTextLayout::EXPAND_MARGIN_FRACTION_START = 0.8f;
const Int32 SearchEditTextLayout::ANIMATION_DURATION = 200;

CAR_INTERFACE_IMPL(SearchEditTextLayout, FrameLayout, ISearchEditTextLayout);

SearchEditTextLayout::SearchEditTextLayout()
    : mIsExpanded(FALSE)
    , mIsFadedOut(FALSE)
    , mTopMargin(0)
    , mBottomMargin(0)
    , mLeftMargin(0)
    , mRightMargin(0)
    , mCollapsedElevation(0)
{}

ECode SearchEditTextLayout::constructor(
    /* [in] */ IContext* context,
    /* [in] */ IAttributeSet* attrs)
{
    return FrameLayout::constructor(context, attrs);
}

ECode SearchEditTextLayout::SetPreImeKeyListener(
    /* [in] */ IViewOnKeyListener* listener)
{
    mPreImeKeyListener = listener;
    return NOERROR;
}

ECode SearchEditTextLayout::SetOnBackButtonClickedListener(
    /* [in] */ IOnBackButtonClickedListener* listener)
{
    mOnBackButtonClickedListener = listener;
    return NOERROR;
}

ECode SearchEditTextLayout::OnFinishInflate()
{
    AutoPtr<IViewGroupLayoutParams> lp;
    GetLayoutParams((IViewGroupLayoutParams**)&lp);
    IViewGroupMarginLayoutParams* params = IViewGroupMarginLayoutParams::Probe(lp);
    params->GetTopMargin(&mTopMargin);
    params->GetBottomMargin(&mBottomMargin);
    params->GetLeftMargin(&mLeftMargin);
    params->GetRightMargin(&mRightMargin);

    GetElevation(&mCollapsedElevation);

    FindViewById(R::id::search_box_collapsed, (IView**)&mCollapsed);
    FindViewById(R::id::search_box_expanded, (IView**)&mExpanded);
    AutoPtr<IView> view;
    mExpanded->FindViewById(R::id::search_view, (IView**)&view);
    mSearchView = IEditText::Probe(view);

    FindViewById(R::id::search_magnifying_glass, (IView**)&mSearchIcon);
    FindViewById(R::id::search_box_start_search, (IView**)&mCollapsedSearchBox);
    FindViewById(R::id::voice_search_button, (IView**)&mVoiceSearchButtonView);
    FindViewById(R::id::dialtacts_options_menu_button, (IView**)&mOverflowButtonView);
    FindViewById(R::id::search_back_button, (IView**)&mBackButtonView);
    FindViewById(R::id::search_box_expanded, (IView**)&mExpandedSearchBox);
    FindViewById(R::id::search_close_button, (IView**)&mClearButtonView);

    view->SetOnFocusChangeListener(new SearchViewFocusChangeListener(this));

    view = NULL;
    FindViewById(R::id::search_close_button, (IView**)&view);
    view->SetOnClickListener(new SearchCloseButtonClickListener(this));

    view = NULL;
    FindViewById(R::id::search_back_button, (IView**)&view);
    view->SetOnClickListener(new SearchBackButtonClickListener(this));

    return FrameLayout::OnFinishInflate();
}

ECode SearchEditTextLayout::DispatchKeyEventPreIme(
    /* [in] */ IKeyEvent* event,
    /* [out] */ Boolean* res)
{
    VALIDATE_NOT_NULL(res);
    if (mPreImeKeyListener != NULL) {
        Int32 keyCode;
        event->GetKeyCode(&keyCode);
        Boolean result;
        if (mPreImeKeyListener->OnKey(this, keyCode, event, &result), result) {
            *res = TRUE;
            return NOERROR;
        }
    }
    return FrameLayout::DispatchKeyEventPreIme(event, res);
}

ECode SearchEditTextLayout::FadeOut()
{
    return FadeOut(NULL);
}

ECode SearchEditTextLayout::FadeOut(
    /* [in] */ IAnimationCallback* callback)
{
    AnimUtils::FadeOut(this, ANIMATION_DURATION, callback);
    mIsFadedOut = TRUE;
    return NOERROR;
}

ECode SearchEditTextLayout::FadeIn()
{
    AnimUtils::FadeIn(this, ANIMATION_DURATION);
    mIsFadedOut = FALSE;
    return NOERROR;
}

ECode SearchEditTextLayout::SetVisible(
    /* [in] */ Boolean visible)
{
    if (visible) {
        SetAlpha(1);
        SetVisibility(IView::VISIBLE);
        mIsFadedOut = FALSE;
    }
    else {
        SetAlpha(0);
        SetVisibility(IView::GONE);
        mIsFadedOut = TRUE;
    }
    return NOERROR;
}

ECode SearchEditTextLayout::Expand(
    /* [in] */ Boolean animate,
    /* [in] */ Boolean requestFocus)
{
    UpdateVisibility(TRUE /* isExpand */);

    if (animate) {
        AnimUtils::CrossFadeViews(mExpanded, mCollapsed, ANIMATION_DURATION);
        AutoPtr<IValueAnimatorHelper> helper;
        CValueAnimatorHelper::AcquireSingleton((IValueAnimatorHelper**)&helper);
        AutoPtr< ArrayOf<Float> > values = ArrayOf<Float>::Alloc(2);
        (*values)[0] = EXPAND_MARGIN_FRACTION_START;
        (*values)[1] = 0;
        mAnimator = NULL;
        helper->OfFloat(values, (IValueAnimator**)&mAnimator);
        SetMargins(EXPAND_MARGIN_FRACTION_START);
        PrepareAnimator(TRUE);
    }
    else {
        mExpanded->SetVisibility(IView::VISIBLE);
        mExpanded->SetAlpha(1);
        SetMargins(0);
        mCollapsed->SetVisibility(IView::GONE);
    }

    // Set 9-patch background. This owns the padding, so we need to restore the original values.
    Int32 paddingTop;
    GetPaddingTop(&paddingTop);
    Int32 paddingStart;
    GetPaddingStart(&paddingStart);
    Int32 paddingBottom;
    GetPaddingBottom(&paddingBottom);
    Int32 paddingEnd;
    GetPaddingEnd(&paddingEnd);
    SetBackgroundResource(R::drawable::search_shadow);
    SetElevation(0);
    SetPaddingRelative(paddingStart, paddingTop, paddingEnd, paddingBottom);

    SetElevation(0);
    if (requestFocus) {
        Boolean result;
        IView::Probe(mSearchView)->RequestFocus(&result);
    }
    mIsExpanded = TRUE;
    return NOERROR;
}

ECode SearchEditTextLayout::Collapse(
    /* [in] */ Boolean animate)
{
    UpdateVisibility(FALSE /* isExpand */);

    if (animate) {
        AnimUtils::CrossFadeViews(mCollapsed, mExpanded, ANIMATION_DURATION);
        AutoPtr<IValueAnimatorHelper> helper;
        CValueAnimatorHelper::AcquireSingleton((IValueAnimatorHelper**)&helper);
        AutoPtr< ArrayOf<Float> > values = ArrayOf<Float>::Alloc(2);
        (*values)[0] = 0;
        (*values)[1] = 1;
        mAnimator = NULL;
        helper->OfFloat(values, (IValueAnimator**)&mAnimator);
        PrepareAnimator(FALSE);
    }
    else {
        mCollapsed->SetVisibility(IView::VISIBLE);
        mCollapsed->SetAlpha(1);
        SetMargins(1);
        mExpanded->SetVisibility(IView::GONE);
    }

    mIsExpanded = FALSE;
    SetElevation(mCollapsedElevation);
    SetBackgroundResource(R::drawable::rounded_corner);
    return NOERROR;
}

void SearchEditTextLayout::UpdateVisibility(
    /* [in] */ Boolean isExpand)
{
    Int32 collapsedViewVisibility = isExpand ? IView::GONE : IView::VISIBLE;
    Int32 expandedViewVisibility = isExpand ? IView::VISIBLE : IView::GONE;

    mSearchIcon->SetVisibility(collapsedViewVisibility);
    mCollapsedSearchBox->SetVisibility(collapsedViewVisibility);
    mVoiceSearchButtonView->SetVisibility(collapsedViewVisibility);
    mOverflowButtonView->SetVisibility(collapsedViewVisibility);
    mBackButtonView->SetVisibility(expandedViewVisibility);
    // TODO: Prevents keyboard from jumping up in landscape mode after exiting the
    // SearchFragment when the query string is empty. More elegant fix?
    //mExpandedSearchBox.setVisibility(expandedViewVisibility);
    mClearButtonView->SetVisibility(expandedViewVisibility);
}

void SearchEditTextLayout::PrepareAnimator(
    /* [in] */ Boolean expand)
{
    if (mAnimator != NULL) {
        IAnimator::Probe(mAnimator)->Cancel();
    }

    mAnimator->AddUpdateListener(new AnimatorUpdateListener(this));

    mAnimator->SetDuration(ANIMATION_DURATION);
    IAnimator::Probe(mAnimator)->Start();
}


ECode SearchEditTextLayout::IsExpanded(
    /* [out] */ Boolean* isExpanded)
{
    VALIDATE_NOT_NULL(isExpanded);
    *isExpanded = mIsExpanded;
    return NOERROR;
}

ECode SearchEditTextLayout::IsFadedOut(
    /* [out] */ Boolean* isFadedOut)
{
    VALIDATE_NOT_NULL(isFadedOut);
    *isFadedOut = mIsFadedOut;
    return NOERROR;
}

void SearchEditTextLayout::SetMargins(
    /* [in] */ Float fraction)
{
    AutoPtr<IViewGroupLayoutParams> lp;
    GetLayoutParams((IViewGroupLayoutParams**)&lp);
    IViewGroupMarginLayoutParams* params = IViewGroupMarginLayoutParams::Probe(lp);

    params->SetTopMargin((Int32) (mTopMargin * fraction));
    params->SetBottomMargin((Int32) (mBottomMargin * fraction));
    params->SetLeftMargin((Int32) (mLeftMargin * fraction));
    params->SetRightMargin((Int32) (mRightMargin * fraction));
    RequestLayout();
}

} // Widget
} // Dialer
} // Droid
} // Elastos
