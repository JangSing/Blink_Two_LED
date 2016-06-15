#include "State.h"
#include "unity.h"




void setUp(void)

{

  ledRed=LED_OFF;

  ledGreen=LED_OFF;

}



void tearDown(void)

{

  buttonA=NOT_PRESSED;

  buttonB=NOT_PRESSED;

  ledRed=LED_OFF;

  ledGreen=LED_OFF;

}



void test_getButton_if_input_the_button_should_return_button_state(void)

{

 buttonA=IS_PRESSED;

 buttonB=NOT_PRESSED;



  UnityAssertEqualNumber((_U_SINT)((getButton(BUTTON_A))), (_U_SINT)((IS_PRESSED)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((getButton(BUTTON_B))), (_U_SINT)((NOT_PRESSED)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);

}



void test_turnLed_should_turn_on_or_off_for_selected_LED(void)

{

  turnLed(LED_RED,LED_OFF);

  turnLed(LED_GREEN,LED_ON);



  UnityAssertEqualNumber((_U_SINT)((ledRed)), (_U_SINT)((LED_OFF)), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((ledGreen)), (_U_SINT)((LED_ON)), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);

}



void test_testing(void)

{

  clock_t start_t, end_t, total_t;



  buttonA=IS_PRESSED;

  TaskState *temp=malloc(sizeof(TaskState));

  temp->state=RELEASED;



  buttonAndLed(temp);



}
