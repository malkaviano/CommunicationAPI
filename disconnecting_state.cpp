#include "status.h"
#include "state_machine.h"
#include "communication.h"
#include "state_name.h"
#include <iostream>

using namespace std;

int DisconnectingState::CloseComm() {
    cout << "Cleanup connection" << "\n";

    changeState(StateName::CLOSED_CONNECTION);

    return Status::OK;
}