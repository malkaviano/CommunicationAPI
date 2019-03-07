#include "status.h"
#include "state_machine.h"
#include <iostream>
#include "state_name.h"
#include "bar_code_readed_state.h"

using namespace std;

int BarCodeReaded::OpenDoor() {
    cout << "Opening door" << "\n";

    changeState(StateName::RECEIVING_ENVELOPE);

    return Status::OK;
}