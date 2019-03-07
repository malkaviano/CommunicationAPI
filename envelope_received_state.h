#ifndef EnvelopeReceived_inc
#define EnvelopeReceived_inc

#include "communication.h"

class EnvelopeReceivedState : public Communication {
    int CompleteDeposit() override;
};

#endif