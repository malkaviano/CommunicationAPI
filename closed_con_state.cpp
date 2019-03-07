#include "status.h"
#include "closed_con_state.h"
#include <iostream>
#include "state_name.h"

using namespace std;

ClosedConnectionState::ClosedConnectionState() {}

int ClosedConnectionState::OpenComm() {
  std::cout << "Opening connection" << "\n";

  changeState(StateName::OPENED_CONNECTION);

  return Status::OK;
}