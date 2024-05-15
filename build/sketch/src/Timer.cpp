#line 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\src\\Timer.cpp"
#include "Timer.h"
#include "Arduino.h"
#include <TimerOne.h>

volatile bool timerFlag = false;

void timerHandler() {
  timerFlag = true;
}

Timer::Timer() {
  timerFlag = false;
  Timer1.detachInterrupt();
}

/* period in ms */
void Timer::setupPeriod(int period) {
  Timer1.initialize(period * 1000L);
  Timer1.attachInterrupt(timerHandler);
}

void Timer::waitForNextTick() {
  /* wait for timer signal */
  while (!timerFlag){
  }
  timerFlag = false;
}
