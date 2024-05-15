#line 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\src\\Timer.h"
#ifndef __TIMER__
#define __TIMER__

class Timer
{
public:
  Timer();
  void setupPeriod(int period);
  void waitForNextTick();
};

#endif
