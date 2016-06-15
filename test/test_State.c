#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "unity.h"
#include "State.h"

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
  
  TEST_ASSERT_EQUAL(getButton(BUTTON_A),IS_PRESSED);
  TEST_ASSERT_EQUAL(getButton(BUTTON_B),NOT_PRESSED);
}

void test_turnLed_should_turn_on_or_off_for_selected_LED(void)
{
  turnLed(LED_RED,LED_OFF);
  turnLed(LED_GREEN,LED_ON);
  
  TEST_ASSERT_EQUAL(ledRed,LED_OFF);
  TEST_ASSERT_EQUAL(ledGreen,LED_ON);
}

void test_testing(void)
{
  clock_t start_t, end_t, total_t;
  
  buttonA=IS_PRESSED;
  TaskState *temp=malloc(sizeof(TaskState));
  temp->state=RELEASED;
  
  buttonAndLed(temp);
  
}
