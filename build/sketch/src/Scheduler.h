#line 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\src\\Scheduler.h"
#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Timer.h"
#include "Task.h"

#define MAX_TASKS 10

class Scheduler
{
  int basePeriod;
  int nTasks;
  Task *taskList[MAX_TASKS];
  Timer timer;

public:
  void init(int basePeriod);
  virtual bool addTask(Task *task);
  virtual void schedule();
};

#endif
