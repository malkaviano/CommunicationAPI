#ifndef ReceivingEnvelope_inc
#define ReceivingEnvelope_inc

#include "communication.h"
#include "state_machine.h"

class ReceivingEnvelopeState : public Communication {
    public:
        int CloseDoor() override;
};

#endif