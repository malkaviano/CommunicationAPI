#include "status.h"
#include "state_machine.h"
#include "communication.h"
#include <iostream>
#include "deposit_started_state.h"
#include "state_name.h"

using namespace std;

int DepositStartedState::ReadBarCode() {
    cout << "Reading bar code" << "\n";

    // Assuming bar code was successful
    auto barCodeRead = true;

    if( barCodeRead ) {
        cout << "Readed bar code successfuly" << "\n";

        changeState(StateName::BAR_CODE_READED);

        return Status::OK;
    } else {
        CancelDeposit();
    }
}

int DepositStartedState::CancelDeposit() {
    cout << "Reading bar code failed, aborting" << "\n";
    
    changeState(StateName::DISCONNECTING);

    return Status::ErrorReadingBarCode;
}