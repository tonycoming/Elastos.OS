
#include "CSwipeHelperHelper.h"
#include "SwipeHelper.h"

namespace Elastos{
namespace Apps{
namespace Dialer {
namespace List {

CAR_INTERFACE_IMPL(CSwipeHelperHelper, Singleton, ISwipeHelperHelper)

CAR_SINGLETON_IMPL(CSwipeHelperHelper)

ECode CSwipeHelperHelper::InvalidateGlobalRegion(
    /* [in] */ IView* view)
{
    SwipeHelper::InvalidateGlobalRegion(view);
    return NOERROR;
}

ECode CSwipeHelperHelper::InvalidateGlobalRegion(
    /* [in] */ IView* view,
    /* [in] */ IRectF* childBounds)
{
    SwipeHelper::InvalidateGlobalRegion(view, childBounds);
    return NOERROR;
}

ECode CSwipeHelperHelper::SetSwipeable(
    /* [in] */ IView* view,
    /* [in] */ Boolean swipeable)
{
    SwipeHelper::SetSwipeable(view, swipeable);
    return NOERROR;
}

ECode CSwipeHelperHelper::IsSwipeable(
    /* [in] */ IView* view,
    /* [out] */ Boolean* result)
{
    VALUE_NOT_NULL(result);
    * result = SwipeHelper::IsSwipeable(view);
    return NOERROR;
}

ECode CSwipeHelperHelper::GetIS_SWIPEABLE(
    /* [out] */ IInterface** obj)
{
    VALUE_NOT_NULL(obj);
    *obj = SwipeHelper::IS_SWIPEABLE;
    REFCOUNT_ADD(*obj);
    return NOERROR;
}

} // List
} // Dialer
} // Apps
} // Elastos