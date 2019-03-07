#include "state_machine.h"
#include <iostream>
#include <memory>

using namespace std;

std::unique_ptr<Communication> closedConnectionState = std::make_unique<ClosedConnectionState>();
std::unique_ptr<Communication> openedConnectionState = std::make_unique<OpenConnectionState>();
std::unique_ptr<Communication> disconnectingState = std::make_unique<DisconnectingState>();
std::unique_ptr<Communication> depositStartedState = std::make_unique<DepositStartedState>();
std::unique_ptr<Communication> barCodeReadedState = std::make_unique<BarCodeReaded>();
std::unique_ptr<Communication> receivingEnvelopeState = std::make_unique<ReceivingEnvelopeState>();
std::unique_ptr<Communication> envelopeReceivedState = std::make_unique<EnvelopeReceivedState>();

std::unique_ptr<StateMachine> state_machine = std::make_unique<StateMachine>(*closedConnectionState);

StateMachine::StateMachine(Communication& cState) : cState(cState) {}
    
StateMachine::~StateMachine() {}

void changeState(StateName stateName) {
    switch (stateName)
    {
        case StateName::OPENED_CONNECTION:
            state_machine.reset(new StateMachine(*openedConnectionState));
            break;
        case StateName::CLOSED_CONNECTION:
            state_machine.reset(new StateMachine(*closedConnectionState));
            break;
        case StateName::DISCONNECTING:
            state_machine.reset(new StateMachine(*disconnectingState));
            state_machine->CloseComm();
            break;
        case StateName::DEPOSIT_STARTED:
            state_machine.reset(new StateMachine(*depositStartedState));
            break;
        case StateName::BAR_CODE_READED:
            state_machine.reset(new StateMachine(*barCodeReadedState));
            break;
        case StateName::RECEIVING_ENVELOPE:
            state_machine.reset(new StateMachine(*receivingEnvelopeState));
            break;
        case StateName::DOOR_CLOSED:
            DoorClosedState doorClosedState;

            if (doorClosedState.checkForEnvelope()) {
                changeState(StateName::ENVELOPE_RECEIVED);
            } else {
                changeState(StateName::DISCONNECTING);
            }
            break;
        case StateName::ENVELOPE_RECEIVED:
            state_machine.reset(new StateMachine(*envelopeReceivedState));
            state_machine->CompleteDeposit();
            break;
         case StateName::DEPOSIT_COMPLETED:
            std::cout << "Thank you for using our services, bye" << "\n";
            changeState(StateName::DISCONNECTING);
            break;
        default:
            break;
    }
}

int StateMachine::OpenComm() {
    state_machine->cState.OpenComm();
}

int StateMachine::StartDeposit() {
    state_machine->cState.StartDeposit();
}

int StateMachine::CloseComm() {
    state_machine->cState.CloseComm();
}

int StateMachine::CompleteDeposit() {
    state_machine->cState.CompleteDeposit();
}

int StateMachine::OpenDoor() {
    state_machine->cState.OpenDoor();
}

int StateMachine::ReadBarCode() {
    state_machine->cState.ReadBarCode();
}

int StateMachine::CloseDoor() {
    state_machine->cState.CloseDoor();
}

int StateMachine::CancelDeposit() {
    state_machine->cState.CancelDeposit();
}