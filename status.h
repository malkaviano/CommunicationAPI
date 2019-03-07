#ifndef StatusEnum_inc
#define StatusEnum_inc

enum Status {
    OK = 0,
    ConnectionClosed = 1,
    DoorClosed = 2,
    ConnectionAlreadyOpen = 3,
    InvalidOperation = 4,
    DepositAlreadyStarted = 5,
    ErrorReadingBarCode = 6
};

#endif