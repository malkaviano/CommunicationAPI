#ifndef DisconnectingStateState_inc
#define DisconnectingStateState_inc

#include "communication.h"
#include "state_machine.h"

class DisconnectingState : public Communication {
    public:
        int CloseComm() override;
};

#endif