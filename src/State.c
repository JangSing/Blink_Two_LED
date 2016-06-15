#include <stdio.h>
#include <time.h>
#include <dos.h>
#include "State.h"

int getButton(Button bt){
  if(bt==BUTTON_A)
    return buttonA;
  else
    return buttonB;
}

void turnLed(LedColour ld,LedState ls){
  if(ld==LED_RED)
    ledRed=ls;
  else
    ledGreen=ls;
}

void buttonAndLed(TaskState *ts){
  switch(ts->state){
    case RELEASED:
      if(getButton(ts->whichButton)== IS_PRESSED){
        turnLed(ts->whichLED,LED_ON);
        ts->recordTime=clock();
        ts->state=PRESSED_ON;
      }break;
    case PRESSED_ON:
      if(getButton(ts->whichButton)== NOT_PRESSED)
        ts->state=RELEASED_ON;
      if((clock()-ts->recordTime)==ts->interval){
        turnLed(ts->whichLED,LED_OFF);
        ts->recordTime=clock();
        ts->state=PRESSED_OFF;
      }break;
    case PRESSED_OFF:
      if(getButton(ts->whichButton)== NOT_PRESSED)
        ts->state=RELEASED_OFF;
      if((clock()-ts->recordTime)==ts->interval){
        turnLed(ts->whichLED,LED_ON);
        ts->recordTime=clock();
        ts->state=PRESSED_ON;
      }break;
    case RELEASED_ON:
      if(getButton(ts->whichButton)== IS_PRESSED){
        turnLed(ts->whichLED,LED_OFF);
        ts->state=TURNING_OFF;
      }
      if((clock()-ts->recordTime)==ts->interval){
        turnLed(ts->whichLED,LED_OFF);
        ts->recordTime=clock();
        ts->state=RELEASED_OFF;
      }break;
    case RELEASED_OFF:
      if(getButton(ts->whichButton)== IS_PRESSED){
        ts->state=TURNING_OFF;
      }
      if((clock()-ts->recordTime)==ts->interval){
        turnLed(ts->whichLED,LED_ON);
        ts->recordTime=clock();
        ts->state=RELEASED_ON;
      }break;
    case TURNING_OFF:
      if(getButton(ts->whichButton)== NOT_PRESSED){
        ts->state=RELEASED;
      }
    default:ts->state=RELEASED;break;
  }
}
    