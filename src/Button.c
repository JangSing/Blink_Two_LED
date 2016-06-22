#include "Button.h"
#include "Timer.h"
#include "State.h"

void buttonFsm(ButtonSM *this){
  
  switch(this->state){
    case IDLE:
      if(this->prevState!=getButton(this->whichButton)){
        // ts->recordTime=clock();
        this->prevState=getButton(this->whichButton);
        this->state=WAIT;
      }
    case WAIT:
      if(getTimer()==100){
        this->curState=getButton(this->whichButton);
        if(this->prevState==this->curState)
          this->output=this->curState;
        else
          this->prevState=this->curState;
        this->state=IDLE;
      }
  }
}