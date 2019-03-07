#ifndef OpenedConState_inc
#define OpenedConState_inc

#include "communication.h"
#include "state_machine.h"

class OpenConnectionState : public Communication
{
  public:
    int StartDeposit() override;

    int CloseComm() override;
};

#endif