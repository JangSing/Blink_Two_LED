#ifndef Button_H
#define Button_H

#include "State.h"


typedef struct{
  int output;
  int curState;
  FsmState state;
  int prevState;
  Button whichButton;
}ButtonSM;

void buttonFsm(ButtonSM *this);

#endif // Button_H
