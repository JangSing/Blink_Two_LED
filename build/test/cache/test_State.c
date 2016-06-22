#include "mock_Timer.h"
#include "Button.h"
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



  UnityAssertEqualNumber((_U_SINT)((IS_PRESSED)), (_U_SINT)((getButton(BUTTON_A))), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((NOT_PRESSED)), (_U_SINT)((getButton(BUTTON_B))), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);

}



void test_turnLed_should_turn_on_or_off_for_selected_LED(void)

{

  turnLed(LED_RED,LED_OFF);

  turnLed(LED_GREEN,LED_ON);



  UnityAssertEqualNumber((_U_SINT)((LED_OFF)), (_U_SINT)((ledRed)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((LED_ON)), (_U_SINT)((ledGreen)), (((void *)0)), (_U_UINT)39, UNITY_DISPLAY_STYLE_INT);

}



void test_state_RELEASE_when_button_pressed_should_on_LED_and_change_state(void)

{

  buttonA=IS_PRESSED;

  TaskState tempA={RELEASED,0,0,LED_RED,BUTTON_A};



  UnityAssertEqualNumber((_U_SINT)((RELEASED)), (_U_SINT)((tempA.state)), (((void *)0)), (_U_UINT)47, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((tempA.recordTime)), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((tempA.interval)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((LED_RED)), (_U_SINT)((tempA.whichLED)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((BUTTON_A)), (_U_SINT)((tempA.whichButton)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT);



  buttonAndLed(&tempA);



  UnityAssertEqualNumber((_U_SINT)((LED_ON)), (_U_SINT)((ledRed)), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((LED_OFF)), (_U_SINT)((ledGreen)), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((IS_PRESSED)), (_U_SINT)((tempA.state)), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

}



void test_state_RELEASE_when_button_not_pressed_should_do_nothing(void)

{

  buttonA=NOT_PRESSED;

  TaskState tempA={RELEASED,0,0,LED_RED,BUTTON_A};



  UnityAssertEqualNumber((_U_SINT)((RELEASED)), (_U_SINT)((tempA.state)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((tempA.recordTime)), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((tempA.interval)), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((LED_RED)), (_U_SINT)((tempA.whichLED)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((BUTTON_A)), (_U_SINT)((tempA.whichButton)), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);



  buttonAndLed(&tempA);



  UnityAssertEqualNumber((_U_SINT)((LED_OFF)), (_U_SINT)((ledRed)), (((void *)0)), (_U_UINT)73, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((LED_OFF)), (_U_SINT)((ledGreen)), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((RELEASED)), (_U_SINT)((tempA.state)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

}



void test_state_PRESSED_ON_when_button_not_pressed_should_change_state(void)

{

  buttonA=NOT_PRESSED;

  TaskState tempA={PRESSED_ON,0,250,LED_RED,BUTTON_A};



  getTimer_CMockExpectAndReturn(83, 0);

  UnityAssertEqualNumber((_U_SINT)((PRESSED_ON)), (_U_SINT)((tempA.state)), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((tempA.recordTime)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((250)), (_U_SINT)((tempA.interval)), (((void *)0)), (_U_UINT)86, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((LED_RED)), (_U_SINT)((tempA.whichLED)), (((void *)0)), (_U_UINT)87, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((BUTTON_A)), (_U_SINT)((tempA.whichButton)), (((void *)0)), (_U_UINT)88, UNITY_DISPLAY_STYLE_INT);



  buttonAndLed(&tempA);



  UnityAssertEqualNumber((_U_SINT)((RELEASED_ON)), (_U_SINT)((tempA.state)), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_INT);

}



void test_state_PRESSED_ON_when_timer_expired_should_turn_off_led_restart_timer_and_change_state(void)

{

  buttonA=IS_PRESSED;

  ledRed=LED_ON;



  TaskState tempA={PRESSED_ON,0,250,LED_RED,BUTTON_A};



  getTimer_CMockExpectAndReturn(102, 250);

  UnityAssertEqualNumber((_U_SINT)((PRESSED_ON)), (_U_SINT)((tempA.state)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((tempA.recordTime)), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((250)), (_U_SINT)((tempA.interval)), (((void *)0)), (_U_UINT)105, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((LED_RED)), (_U_SINT)((tempA.whichLED)), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((BUTTON_A)), (_U_SINT)((tempA.whichButton)), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT);



  buttonAndLed(&tempA);



  UnityAssertEqualNumber((_U_SINT)((PRESSED_OFF)), (_U_SINT)((tempA.state)), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT);

}
