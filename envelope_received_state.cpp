#include "envelope_received_state.h"
#include <iostream>
#include "status.h"
#include "state_name.h"
#include "state_machine.h"

using namespace std;

int EnvelopeReceivedState::CompleteDeposit() {
    std::cout << "Deposit Completed" << "\n";

    changeState(StateName::DEPOSIT_COMPLETED);

    return Status::OK;
}