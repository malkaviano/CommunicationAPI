#include "status.h"
#include "opened_con_state.h"
#include <iostream>
#include "state_name.h"

using namespace std;

int OpenConnectionState::StartDeposit() {
  std::cout << "Starting Deposit" << "\n";

  changeState(StateName::DEPOSIT_STARTED);

  return Status::OK;
}

int OpenConnectionState::CloseComm() {
  std::cout << "Closing connection" << "\n";

  changeState(StateName::DISCONNECTING);

  return Status::OK;
}