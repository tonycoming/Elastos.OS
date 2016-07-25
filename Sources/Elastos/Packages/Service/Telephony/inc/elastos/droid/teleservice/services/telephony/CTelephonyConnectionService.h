#ifndef  __ELASTOS_DROID_SERVICES_TELEPHONY_CTELEPHONYCONNECTIONSERVICE_H__
#define  __ELASTOS_DROID_SERVICES_TELEPHONY_CTELEPHONYCONNECTIONSERVICE_H__

#include "_Elastos_Droid_TeleService_Services_Telephony_CTelephonyConnectionService.h"
#include "elastos/droid/teleservice/services/telephony/GsmConferenceController.h"
#include "elastos/droid/teleservice/services/telephony/CdmaConferenceController.h"
#include "elastos/droid/teleservice/services/telephony/EmergencyTonePlayer.h"
#include "elastos/droid/telecom/ConnectionService.h"
#include "Elastos.Droid.Content.h"
#include "Elastos.Droid.Internal.h"
#include "Elastos.Droid.Telecom.h"
#include "elastos/droid/ext/frameworkext.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Content::IComponentName;
using Elastos::Droid::Internal::Telephony::ICall;
using Elastos::Droid::Internal::Telephony::IPhone;
using Elastos::Droid::Telecom::ConnectionService;
using Elastos::Droid::Telecom::IConnectionRequest;
using Elastos::Core::Object;

namespace Elastos {
namespace Droid {
namespace TeleService {
namespace Services {
namespace Telephony {

/**
 * Service for making GSM and CDMA connections.
 */
CarClass(CTelephonyConnectionService)
    , public ConnectionService
    , public ITelephonyConnectionService
{
private:
    class MyEmergencyCallHelperCallback
        : public Object
        , public IEmergencyCallHelperCallback
    {
    public:
        TO_STRING_IMPL("CTelephonyConnectionService::MyEmergencyCallHelperCallback")

        CAR_INTERFACE_DECL();

        MyEmergencyCallHelperCallback(
            /* [in] */ CTelephonyConnectionService* host,
            /* [in] */ ITelephonyConnection* connection,
            /* [in] */ IPhone* phone,
            /* [in] */ IConnectionRequest* request)
            : mHost(host)
            , mConnection(connection)
            , mPhone(phone)
            , mRequest(request)
        {}

        //@Override
        CARAPI OnComplete(
            /* [in] */ Boolean isRadioReady);

    private:
        CTelephonyConnectionService* mHost;
        AutoPtr<ITelephonyConnection> mConnection;
        AutoPtr<IPhone> mPhone;
        AutoPtr<IConnectionRequest> mRequest;
    };

public:
    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL();

    CTelephonyConnectionService();

    CARAPI constructor();

    //@Override
    CARAPI OnCreate();

    //@Override
    CARAPI OnCreateOutgoingConnection(
        /* [in] */ Elastos::Droid::Telecom::IPhoneAccountHandle* connectionManagerPhoneAccount,
        /* [in] */ IConnectionRequest* request,
        /* [out] */ Elastos::Droid::Telecom::IConnection** result);

    //@Override
    CARAPI OnCreateIncomingConnection(
        /* [in] */ Elastos::Droid::Telecom::IPhoneAccountHandle* connectionManagerPhoneAccount,
        /* [in] */ IConnectionRequest* request,
        /* [out] */ Elastos::Droid::Telecom::IConnection** result);

    //@Override
    CARAPI OnCreateUnknownConnection(
        /* [in] */ Elastos::Droid::Telecom::IPhoneAccountHandle* connectionManagerPhoneAccount,
        /* [in] */ IConnectionRequest* request,
        /* [out] */ Elastos::Droid::Telecom::IConnection** result);

    //@Override
    CARAPI OnConference(
        /* [in] */ Elastos::Droid::Telecom::IConnection* connection1,
        /* [in] */ Elastos::Droid::Telecom::IConnection* connection2);

private:
    CARAPI_(void) PlaceOutgoingConnection(
        /* [in] */ ITelephonyConnection* connection,
        /* [in] */ IPhone* phone,
        /* [in] */ IConnectionRequest* request);

    CARAPI_(AutoPtr<ITelephonyConnection>) CreateConnectionFor(
        /* [in] */ IPhone* phone,
        /* [in] */ Elastos::Droid::Internal::Telephony::IConnection* originalConnection,
        /* [in] */ Boolean isOutgoing);

    CARAPI_(Boolean) IsOriginalConnectionKnown(
        /* [in] */ Elastos::Droid::Internal::Telephony::IConnection* originalConnection);

    CARAPI_(AutoPtr<IPhone>) GetPhoneForAccount(
        /* [in] */ Elastos::Droid::Telecom::IPhoneAccountHandle* accountHandle,
        /* [in] */ Boolean isEmergency);

    /**
     * Determines if the connection should allow mute.
     *
     * @param phone The current phone.
     * @return {@code True} if the connection should allow mute.
     */
    CARAPI_(Boolean) AllowMute(
        /* [in] */ IPhone* phone);

private:
    AutoPtr<GsmConferenceController> mGsmConferenceController;
    AutoPtr<CdmaConferenceController> mCdmaConferenceController;
    AutoPtr<IComponentName> mExpectedComponentName;
    AutoPtr<IEmergencyCallHelper> mEmergencyCallHelper;
    AutoPtr<EmergencyTonePlayer> mEmergencyTonePlayer;
};

} // namespace Telephony
} // namespace Services
} // namespace TeleService
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_SERVICES_TELEPHONY_CTELEPHONYCONNECTIONSERVICE_H__