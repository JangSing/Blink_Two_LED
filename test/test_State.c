#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "unity.h"
#include "State.h"
#include "Button.h"
#include "mock_Timer.h"

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
  
  TEST_ASSERT_EQUAL(IS_PRESSED,getButton(BUTTON_A));
  TEST_ASSERT_EQUAL(NOT_PRESSED,getButton(BUTTON_B));
}

void test_turnLed_should_turn_on_or_off_for_selected_LED(void)
{
  turnLed(LED_RED,LED_OFF);
  turnLed(LED_GREEN,LED_ON);
  
  TEST_ASSERT_EQUAL(LED_OFF,ledRed);
  TEST_ASSERT_EQUAL(LED_ON,ledGreen);
}

void test_state_RELEASE_when_button_pressed_should_on_LED_and_change_state(void)
{
  buttonA=IS_PRESSED;
  TaskState tempA={RELEASED,0,0,LED_RED,BUTTON_A};
  
  TEST_ASSERT_EQUAL(RELEASED,tempA.state);
  TEST_ASSERT_EQUAL(0,tempA.recordTime);
  TEST_ASSERT_EQUAL(0,tempA.interval);
  TEST_ASSERT_EQUAL(LED_RED,tempA.whichLED);
  TEST_ASSERT_EQUAL(BUTTON_A,tempA.whichButton);
  
  buttonAndLed(&tempA);
  
  TEST_ASSERT_EQUAL(LED_ON,ledRed);
  TEST_ASSERT_EQUAL(LED_OFF,ledGreen);
  TEST_ASSERT_EQUAL(IS_PRESSED,tempA.state);
}

void test_state_RELEASE_when_button_not_pressed_should_do_nothing(void)
{
  buttonA=NOT_PRESSED;
  TaskState tempA={RELEASED,0,0,LED_RED,BUTTON_A};
  
  TEST_ASSERT_EQUAL(RELEASED,tempA.state);
  TEST_ASSERT_EQUAL(0,tempA.recordTime);
  TEST_ASSERT_EQUAL(0,tempA.interval);
  TEST_ASSERT_EQUAL(LED_RED,tempA.whichLED);
  TEST_ASSERT_EQUAL(BUTTON_A,tempA.whichButton);
  
  buttonAndLed(&tempA);
  
  TEST_ASSERT_EQUAL(LED_OFF,ledRed);
  TEST_ASSERT_EQUAL(LED_OFF,ledGreen);
  TEST_ASSERT_EQUAL(RELEASED,tempA.state);
}

void test_state_PRESSED_ON_when_button_not_pressed_should_change_state(void)
{
  buttonA=NOT_PRESSED;
  TaskState tempA={PRESSED_ON,0,250,LED_RED,BUTTON_A};
  
  getTimer_ExpectAndReturn(0);
  TEST_ASSERT_EQUAL(PRESSED_ON,tempA.state);
  TEST_ASSERT_EQUAL(0,tempA.recordTime);
  TEST_ASSERT_EQUAL(250,tempA.interval);
  TEST_ASSERT_EQUAL(LED_RED,tempA.whichLED);
  TEST_ASSERT_EQUAL(BUTTON_A,tempA.whichButton);
  
  buttonAndLed(&tempA);
  
  TEST_ASSERT_EQUAL(RELEASED_ON,tempA.state);
}

void test_state_PRESSED_ON_when_timer_expired_should_turn_off_led_restart_timer_and_change_state(void)
{
  buttonA=IS_PRESSED;
  ledRed=LED_ON;
  
  TaskState tempA={PRESSED_ON,0,250,LED_RED,BUTTON_A};
  
  getTimer_ExpectAndReturn(250);
  TEST_ASSERT_EQUAL(PRESSED_ON,tempA.state);
  TEST_ASSERT_EQUAL(0,tempA.recordTime);
  TEST_ASSERT_EQUAL(250,tempA.interval);
  TEST_ASSERT_EQUAL(LED_RED,tempA.whichLED);
  TEST_ASSERT_EQUAL(BUTTON_A,tempA.whichButton);
  
  buttonAndLed(&tempA);
  
  TEST_ASSERT_EQUAL(PRESSED_OFF,tempA.state);
}
