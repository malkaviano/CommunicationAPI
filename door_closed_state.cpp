#include "door_closed_state.h"
#include <iostream>

using namespace std;

bool DoorClosedState::checkForEnvelope() {
    // Let's assume envelope was deposited

    auto envelope = true;

    if (envelope) {
        std::cout << "Envelope deposited" << "\n";
    } else {
        std::cout << "Envelope not deposited, aborting" << "\n";
    }

    return envelope;
}