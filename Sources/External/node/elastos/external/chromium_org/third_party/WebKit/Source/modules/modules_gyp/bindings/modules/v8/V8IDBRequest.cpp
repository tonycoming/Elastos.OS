// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8IDBRequest.h"

#include "bindings/core/v8/V8DOMError.h"
#include "bindings/modules/v8/V8IDBTransaction.h"
#include "bindings/v8/ExceptionState.h"
#include "bindings/v8/ScriptValue.h"
#include "bindings/v8/V8AbstractEventListener.h"
#include "bindings/v8/V8DOMConfiguration.h"
#include "bindings/v8/V8EventListenerList.h"
#include "bindings/v8/V8HiddenValue.h"
#include "bindings/v8/V8ObjectConstructor.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/Document.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/TraceEvent.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace WebCore {

static void initializeScriptWrappableForInterface(IDBRequest* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8IDBRequest::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

void webCoreInitializeScriptWrappableForInterface(WebCore::IDBRequest* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
const WrapperTypeInfo V8IDBRequest::wrapperTypeInfo = { gin::kEmbedderBlink, V8IDBRequest::domTemplate, V8IDBRequest::derefObject, V8IDBRequest::toActiveDOMObject, V8IDBRequest::toEventTarget, 0, V8IDBRequest::installPerContextEnabledMethods, &V8EventTarget::wrapperTypeInfo, WrapperTypeObjectPrototype, GarbageCollectedObject };

namespace IDBRequestV8Internal {

template <typename T> void V8_USE(T) { }

static void resultAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    v8::Handle<v8::String> propertyName = v8AtomicString(info.GetIsolate(), "result");
    IDBRequest* impl = V8IDBRequest::toNative(holder);
    if (!impl->isResultDirty()) {
        v8::Handle<v8::Value> v8Value = V8HiddenValue::getHiddenValue(info.GetIsolate(), holder, propertyName);
        if (!v8Value.IsEmpty()) {
            v8SetReturnValue(info, v8Value);
            return;
        }
    }
    ExceptionState exceptionState(ExceptionState::GetterContext, "result", "IDBRequest", holder, info.GetIsolate());
    ScriptValue v8Value = impl->result(exceptionState);
    if (UNLIKELY(exceptionState.throwIfNeeded()))
        return;
    V8HiddenValue::setHiddenValue(info.GetIsolate(), holder, propertyName, v8Value.v8Value());
    v8SetReturnValue(info, v8Value.v8Value());
}

static void resultAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    IDBRequestV8Internal::resultAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void errorAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    IDBRequest* impl = V8IDBRequest::toNative(holder);
    ExceptionState exceptionState(ExceptionState::GetterContext, "error", "IDBRequest", holder, info.GetIsolate());
    RefPtrWillBeRawPtr<DOMError> v8Value = impl->error(exceptionState);
    if (UNLIKELY(exceptionState.throwIfNeeded()))
        return;
    RefPtrWillBeRawPtr<DOMError> result(v8Value);
    if (result && DOMDataStore::setReturnValueFromWrapper<V8DOMError>(info.GetReturnValue(), result.get()))
        return;
    v8::Handle<v8::Value> wrapper = toV8(result.get(), holder, info.GetIsolate());
    if (!wrapper.IsEmpty()) {
        V8HiddenValue::setHiddenValue(info.GetIsolate(), holder, v8AtomicString(info.GetIsolate(), "error"), wrapper);
        v8SetReturnValue(info, wrapper);
    }
}

static void errorAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    IDBRequestV8Internal::errorAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void sourceAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    IDBRequest* impl = V8IDBRequest::toNative(holder);
    v8SetReturnValue(info, impl->source().v8Value());
}

static void sourceAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    IDBRequestV8Internal::sourceAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void transactionAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    IDBRequest* impl = V8IDBRequest::toNative(holder);
    RawPtr<IDBTransaction> result(impl->transaction());
    if (result && DOMDataStore::setReturnValueFromWrapper<V8IDBTransaction>(info.GetReturnValue(), result.get()))
        return;
    v8::Handle<v8::Value> wrapper = toV8(result.get(), holder, info.GetIsolate());
    if (!wrapper.IsEmpty()) {
        V8HiddenValue::setHiddenValue(info.GetIsolate(), holder, v8AtomicString(info.GetIsolate(), "transaction"), wrapper);
        v8SetReturnValue(info, wrapper);
    }
}

static void transactionAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    IDBRequestV8Internal::transactionAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void readyStateAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    IDBRequest* impl = V8IDBRequest::toNative(holder);
    v8SetReturnValueString(info, impl->readyState(), info.GetIsolate());
}

static void readyStateAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    IDBRequestV8Internal::readyStateAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void onsuccessAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    IDBRequest* impl = V8IDBRequest::toNative(holder);
    EventListener* v8Value = impl->onsuccess();
    v8SetReturnValue(info, v8Value ? v8::Handle<v8::Value>(V8AbstractEventListener::cast(v8Value)->getListenerObject(impl->executionContext())) : v8::Handle<v8::Value>(v8::Null(info.GetIsolate())));
}

static void onsuccessAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    IDBRequestV8Internal::onsuccessAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void onsuccessAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    IDBRequest* impl = V8IDBRequest::toNative(holder);
    moveEventListenerToNewWrapper(holder, impl->onsuccess(), v8Value, V8IDBRequest::eventListenerCacheIndex, info.GetIsolate());
    impl->setOnsuccess(V8EventListenerList::getEventListener(ScriptState::current(info.GetIsolate()), v8Value, true, ListenerFindOrCreate));
}

static void onsuccessAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    IDBRequestV8Internal::onsuccessAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void onerrorAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    IDBRequest* impl = V8IDBRequest::toNative(holder);
    EventListener* v8Value = impl->onerror();
    v8SetReturnValue(info, v8Value ? v8::Handle<v8::Value>(V8AbstractEventListener::cast(v8Value)->getListenerObject(impl->executionContext())) : v8::Handle<v8::Value>(v8::Null(info.GetIsolate())));
}

static void onerrorAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    IDBRequestV8Internal::onerrorAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void onerrorAttributeSetter(v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    IDBRequest* impl = V8IDBRequest::toNative(holder);
    moveEventListenerToNewWrapper(holder, impl->onerror(), v8Value, V8IDBRequest::eventListenerCacheIndex, info.GetIsolate());
    impl->setOnerror(V8EventListenerList::getEventListener(ScriptState::current(info.GetIsolate()), v8Value, true, ListenerFindOrCreate));
}

static void onerrorAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    IDBRequestV8Internal::onerrorAttributeSetter(v8Value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

} // namespace IDBRequestV8Internal

static const V8DOMConfiguration::AttributeConfiguration V8IDBRequestAttributes[] = {
    {"result", IDBRequestV8Internal::resultAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"error", IDBRequestV8Internal::errorAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"source", IDBRequestV8Internal::sourceAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"transaction", IDBRequestV8Internal::transactionAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"readyState", IDBRequestV8Internal::readyStateAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"onsuccess", IDBRequestV8Internal::onsuccessAttributeGetterCallback, IDBRequestV8Internal::onsuccessAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"onerror", IDBRequestV8Internal::onerrorAttributeGetterCallback, IDBRequestV8Internal::onerrorAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
};

static void configureV8IDBRequestTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "IDBRequest", V8EventTarget::domTemplate(isolate), V8IDBRequest::internalFieldCount,
        V8IDBRequestAttributes, WTF_ARRAY_LENGTH(V8IDBRequestAttributes),
        0, 0,
        0, 0,
        isolate);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8IDBRequest::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), configureV8IDBRequestTemplate);
}

bool V8IDBRequest::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8IDBRequest::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

IDBRequest* V8IDBRequest::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex)) : 0;
}

ActiveDOMObject* V8IDBRequest::toActiveDOMObject(v8::Handle<v8::Object> wrapper)
{
    return toNative(wrapper);
}

EventTarget* V8IDBRequest::toEventTarget(v8::Handle<v8::Object> object)
{
    return toNative(object);
}

v8::Handle<v8::Object> wrap(IDBRequest* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8IDBRequest>(impl, isolate));
    return V8IDBRequest::createWrapper(impl, creationContext, isolate);
}

v8::Handle<v8::Object> V8IDBRequest::createWrapper(RawPtr<IDBRequest> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8IDBRequest>(impl.get(), isolate));
    if (ScriptWrappable::wrapperCanBeStoredInObject(impl.get())) {
        const WrapperTypeInfo* actualInfo = ScriptWrappable::fromObject(impl.get())->typeInfo();
        // Might be a XXXConstructor::wrapperTypeInfo instead of an XXX::wrapperTypeInfo. These will both have
        // the same object de-ref functions, though, so use that as the basis of the check.
        RELEASE_ASSERT_WITH_SECURITY_IMPLICATION(actualInfo->derefObjectFunction == wrapperTypeInfo.derefObjectFunction);
    }

    v8::Handle<v8::Object> wrapper = V8DOMWrapper::createWrapper(creationContext, &wrapperTypeInfo, toInternalPointer(impl.get()), isolate);
    if (UNLIKELY(wrapper.IsEmpty()))
        return wrapper;

    installPerContextEnabledProperties(wrapper, impl.get(), isolate);
    V8DOMWrapper::associateObjectWithWrapper<V8IDBRequest>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Dependent);
    return wrapper;
}

void V8IDBRequest::derefObject(void* object)
{
}

template<>
v8::Handle<v8::Value> toV8NoInline(IDBRequest* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace WebCore
