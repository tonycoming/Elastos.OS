#ifndef __ELASTOS_APPS_DIALER_LIST_CSHORTCUTCARDSADAPTER_H__
#define __ELASTOS_APPS_DIALER_LIST_CSHORTCUTCARDSADAPTER_H__

#include "_Elastos_Apps_Dialer_List_CShortcutCardsAdapter.h"
#include "ShortcutCardsAdapter.h"

namespace Elastos{
namespace Apps{
namespace Dialer {
namespace List {

CarClass(CShortcutCardsAdapter)
    , public ShortcutCardsAdapter
{
public:
    CAR_OBJECT_DECL()
};

} // List
} // Dialer
} // Apps
} // Elastos

#endif //__ELASTOS_APPS_DIALER_LIST_CSHORTCUTCARDSADAPTER_H__