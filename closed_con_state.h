#ifndef ClosedConnectionState_inc
#define ClosedConnectionState_inc

#include "communication.h"
#include "state_machine.h"

class ClosedConnectionState : public Communication
{
  public:
    ClosedConnectionState();

    int OpenComm() override;
};

#endif