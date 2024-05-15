#include "src/Scheduler.h"
#include "src/DoorTask.h"
#include "src/Motor.h"
#include "src/Distance_SensorImpl.h"
#include "src/ClimaTask.h"
#include "src/Temperature_SensorImpl.h"
#include "src/Led.h"
#include "src/Light_SensorImpl.h"
#include "src/LightTask.h"
#include "src/ButtonImpl.h"


//pin del sensore di movimento ad ultrasuoni
#define ECHO_PIN 2
#define TRIG_PIN 3

//Photosensor pin
#define LDR_PIN A2

//Temperature
#define NTC_PIN A1

//LED's pin
#define LIGHT_PIN 12
#define COLD_LIGHT_PIN 10
#define HOT_LIGHT_PIN 9

//PIN del bottone
#define BTN_PIN 8

//Servo mottore
#define SERVO_PIN 6

//Definisco i periodi
#define DOOR_TASK_PERIOD 50
#define CLIMA_TASK_PERIOD 50
#define LIGHT_TASK_PERIOD 50
#define SCHED_PERIOD 50
Scheduler sched;

void setup() {
  //doorMotor.attach(SERVO_PIN);
  Serial.begin(9600);


  //Setup del DoorTask
  DistanceSensor *doorSensor = new UltrasonicSensor(TRIG_PIN, ECHO_PIN);
  MyServo *servo = new Motor(SERVO_PIN);
  DoorTask *doorTask = new DoorTask(doorSensor, servo);
  doorTask->init(DOOR_TASK_PERIOD);

  //Setup del ClimaTask
  TemperatureSensor *tempSensor = new TemperatureSensorImpl(NTC_PIN);
  Light *hotLed = new Led(HOT_LIGHT_PIN);
  Light *coldLed = new Led(COLD_LIGHT_PIN);
  ClimaTask *climaTask = new ClimaTask(tempSensor, hotLed, coldLed);
  climaTask->init(CLIMA_TASK_PERIOD);

  //Setup del LightTask
  Light_Sensor *lightSensor = new LightSensorImpl(LDR_PIN);
  Light *lightLed = new Led(LIGHT_PIN);
  Button *btn = new ButtonImpl(BTN_PIN);
  LightTask *lightTask = new LightTask(lightSensor, lightLed, btn);
  lightTask->init(LIGHT_TASK_PERIOD);


  sched.init(SCHED_PERIOD);
  sched.addTask(doorTask);
  sched.addTask(climaTask);
  sched.addTask(lightTask);

}

void loop(){
  sched.schedule();
  
}