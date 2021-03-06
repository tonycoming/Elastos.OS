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

//This file is autogenerated for
//    AwWebResourceResponse.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_AWWEBRESOURCERESPONSE_CALLBACK_DEC_HH
#define ELASTOS_AWWEBRESOURCERESPONSE_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_AwWebResourceResponse_InitCallback(Handle32 cb);
#ifdef __cplusplus
}
#endif

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace AndroidWebview {

struct ElaAwWebResourceResponseCallback
{
    String (*elastos_AwWebResourceResponse_getMimeType)(IInterface* obj);
    String (*elastos_AwWebResourceResponse_getCharset)(IInterface* obj);
    AutoPtr<IInterface> (*elastos_AwWebResourceResponse_getData)(IInterface* obj);
    Int32 (*elastos_AwWebResourceResponse_getStatusCode)(IInterface* obj);
    String (*elastos_AwWebResourceResponse_getReasonPhrase)(IInterface* obj);
    AutoPtr<ArrayOf<String> > (*elastos_AwWebResourceResponse_getResponseHeaderNames)(IInterface* obj);
    AutoPtr<ArrayOf<String> > (*elastos_AwWebResourceResponse_getResponseHeaderValues)(IInterface* obj);
};

void* AwWebResourceResponse::ElaAwWebResourceResponseCallback_Init()
{
    static ElaAwWebResourceResponseCallback sElaAwWebResourceResponseCallback;

    sElaAwWebResourceResponseCallback.elastos_AwWebResourceResponse_getMimeType = &AwWebResourceResponse::GetMimeType;
    sElaAwWebResourceResponseCallback.elastos_AwWebResourceResponse_getCharset = &AwWebResourceResponse::GetCharset;
    sElaAwWebResourceResponseCallback.elastos_AwWebResourceResponse_getData = &AwWebResourceResponse::GetData;
    sElaAwWebResourceResponseCallback.elastos_AwWebResourceResponse_getStatusCode = &AwWebResourceResponse::GetStatusCode;
    sElaAwWebResourceResponseCallback.elastos_AwWebResourceResponse_getReasonPhrase = &AwWebResourceResponse::GetReasonPhrase;
    sElaAwWebResourceResponseCallback.elastos_AwWebResourceResponse_getResponseHeaderNames = &AwWebResourceResponse::GetResponseHeaderNames;
    sElaAwWebResourceResponseCallback.elastos_AwWebResourceResponse_getResponseHeaderValues = &AwWebResourceResponse::GetResponseHeaderValues;

    Elastos_AwWebResourceResponse_InitCallback((Handle32)&sElaAwWebResourceResponseCallback);
    return &sElaAwWebResourceResponseCallback;
}

static void* sPElaAwWebResourceResponseCallback = AwWebResourceResponse::ElaAwWebResourceResponseCallback_Init();

} // namespace AndroidWebview
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_AWWEBRESOURCERESPONSE_CALLBACK_DEC_HH
