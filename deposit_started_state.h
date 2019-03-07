#ifndef DepositState_inc
#define DepositState_inc

#include "communication.h"

class DepositStartedState : public Communication {
    public:
        int ReadBarCode() override;
        
        int CancelDeposit() override;
};

#endif