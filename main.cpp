#include "communication.cpp"
#include "state_machine.cpp"
#include "opened_con_state.cpp"
#include "closed_con_state.cpp"
#include "deposit_started_state.cpp"
#include "disconnecting_state.cpp"
#include "bar_code_readed_state.cpp"
#include "receiving_envelope_state.cpp"
#include "door_closed_state.cpp"
#include "envelope_received_state.cpp"
#include <iostream>
#include <memory>


using namespace std;

int main(int argc, char** argv) {
    std::cout << "Started machine" << "\n";

    state_machine->OpenComm();

    state_machine->CloseComm();

    std::cout << "Re-Started machine" << "\n";

    state_machine->OpenComm();

    state_machine->StartDeposit();

    state_machine->ReadBarCode();

    state_machine->OpenDoor();

    state_machine->CloseDoor();
}