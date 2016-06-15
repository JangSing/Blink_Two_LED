#ifndef State_H
#define State_H

typedef enum{RELEASED, PRESSED_ON, PRESSED_OFF, RELEASED_ON, RELEASED_OFF,TURNING_OFF} FsmState;
typedef enum{BUTTON_A, BUTTON_B}Button;
typedef enum{LED_RED, LED_GREEN}LedColour;
typedef enum{LED_OFF, LED_ON}LedState;
typedef enum{NOT_PRESSED, IS_PRESSED}ButtonState;

typedef struct{
  FsmState state;
  unsigned int recordTime;
  int interval;
  LedColour whichLED;
  Button whichButton;
}TaskState;

int buttonA;
int buttonB;
int ledRed;
int ledGreen;

void buttonAndLed(TaskState *ts);

int getButton(Button bt);

void turnLed(LedColour ld,LedState ls);

#endif // State_H
