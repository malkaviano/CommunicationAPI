#ifndef StateMachine_inc
#define StateMachine_inc

#include <memory>
#include "state_name.h"
#include "communication.h"
#include "includes.h"

class StateMachine {
    private:
        Communication& cState;

    public:
        StateMachine(Communication& cState);
        
        ~StateMachine();

        friend void changeState(StateName stateName);

        int OpenComm();
        int StartDeposit();
        int CloseComm();
        int CompleteDeposit();
        int OpenDoor();
        int ReadBarCode();
        int CloseDoor();
        int CancelDeposit();
};

#endif