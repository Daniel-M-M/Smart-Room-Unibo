#line 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\src\\DoorTask.cpp"
#include "DoorTask.h"
#include "Motor.h"
#include "Distance_Sensor.h"

//Posizione del servomotore
#define CLOSED_DOOR 0
#define OPEN_DOOR 90
//Limit tempo della porta aperta qui fare 60*sched_timer
#define TIMER_DOOR 60
//Limit di distanza per  che la porta si appra
#define DISTANCE_DOOR 50


DoorTask::DoorTask(DistanceSensor *doorSensor, MyServo *servo) {
    this->doorSensor = doorSensor;
    this->servo = servo;
    state = CLOSE;
    count = 0;//conta i tick
}

void DoorTask::init(int period) {
    Task::init(period);
    servo->setAngle(CLOSED_DOOR);
}

//Porta divisa in 4 state
void DoorTask::tick() {
    switch (state) {
        case CLOSE:
            open();
            break;
        case OPENING:
            opening();
            break;
        case OPENED:
            opened();
            break;
        case OPEN:
            close();
            break;
    }
}

//verifica se si è avvicinato qualcuno e se apre la porta cambiando lo satato a aprendo
void DoorTask::open() {
    float distance = this->doorSensor->getDistance();
    //Quando la persona si avicina alla porta e la porta non è ancora aperta
    if (distance < DISTANCE_DOOR && servo->getAngle() < OPEN_DOOR) {
        state = OPENING;
    }
}

//Porta allo stato aprendo si apre fin che non arriva all'angulazione di 90 gradi e cambia lo stato a aperta
void DoorTask::opening() {
    servo->forward();
    if (servo->getAngle() >= OPEN_DOOR) {
        state = OPENED;
    }
}

//Quando la porta è aperta a 90 gradi di posizione si parte un counter per che la faccia chiudere
//Se chiudi dopo 3 secondi cosi diventa visibile piu velocemente che al posta di 30 come rechiesto
//Dopo di che si passa allo stato aperta da un tot di tempo.
void DoorTask::opened() {
    float distance = this->doorSensor->getDistance();
    count++;
    if (count >= TIMER_DOOR && distance > DISTANCE_DOOR) {
        count = 0;
        state = OPEN;
    }
    
}

//Quado pasasto il tempo la porta entra in fase di chiusura finche non è alla posizione 0.
//Quando si passa a zero si dovrebbe settare il tutto.
void DoorTask::close() {
    if (servo->getAngle() > CLOSED_DOOR) {
        servo->backward();
    }

    if (servo->getAngle() == CLOSED_DOOR) {
        servo->setAngle(CLOSED_DOOR);
        state = CLOSE;
    }
    
}