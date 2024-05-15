#line 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\src\\Scheduler.cpp"
#include "Scheduler.h"

void Scheduler::init(int basePeriod) {
  this->basePeriod = basePeriod;
  timer.setupPeriod(basePeriod);
  nTasks = 0;
}

bool Scheduler::addTask(Task *task) {
  if (nTasks < MAX_TASKS - 1) {
    taskList[nTasks] = task;
    nTasks++;
    return true;
  }
  else {
    return false;
  }
}

void Scheduler::schedule() {
  timer.waitForNextTick();
  for (int i = 0; i < nTasks; i++) {
    if (taskList[i]->updateAndCheckTime(basePeriod)) {
      taskList[i]->tick();
    }
  }
}
