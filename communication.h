#ifndef Communication_inc
#define Communication_inc

#include "status.h"

// API public interface
class Communication
{
    public:
        Communication(); 
        virtual ~Communication();
        virtual int OpenComm();
        virtual int StartDeposit();
        virtual int CloseComm();
        virtual int CompleteDeposit();
        virtual int OpenDoor();
        virtual int ReadBarCode();
        virtual int CloseDoor();
        virtual int CancelDeposit();
};

#endif
