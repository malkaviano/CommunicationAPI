#include "status.h"
#include "receiving_envelope_state.h"
#include <iostream>
#include "state_name.h"

using namespace std;

int ReceivingEnvelopeState::CloseDoor() {
    std::cout << "Closing door" << "\n";

    changeState(StateName::DOOR_CLOSED);

    return Status::OK;
}