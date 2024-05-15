# 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\SMART-ROOM.ino"
# 2 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\SMART-ROOM.ino" 2
# 3 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\SMART-ROOM.ino" 2
# 4 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\SMART-ROOM.ino" 2
# 5 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\SMART-ROOM.ino" 2
# 6 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\SMART-ROOM.ino" 2
# 7 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\SMART-ROOM.ino" 2
# 8 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\SMART-ROOM.ino" 2
# 9 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\SMART-ROOM.ino" 2
# 10 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\SMART-ROOM.ino" 2
# 11 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\SMART-ROOM.ino" 2


//pin del sensore di movimento ad ultrasuoni



//Photosensor pin


//Temperature


//LED's pin




//PIN del bottone


//Servo mottore


//Definisco i periodi




Scheduler sched;

void setup() {
  //doorMotor.attach(SERVO_PIN);
  Serial.begin(9600);


  //Setup del DoorTask
  DistanceSensor *doorSensor = new UltrasonicSensor(3, 2);
  MyServo *servo = new Motor(6);
  DoorTask *doorTask = new DoorTask(doorSensor, servo);
  doorTask->init(50);

  //Setup del ClimaTask
  TemperatureSensor *tempSensor = new TemperatureSensorImpl(A1);
  Light *hotLed = new Led(9);
  Light *coldLed = new Led(10);
  ClimaTask *climaTask = new ClimaTask(tempSensor, hotLed, coldLed);
  climaTask->init(50);

  //Setup del LightTask
  Light_Sensor *lightSensor = new LightSensorImpl(A2);
  Light *lightLed = new Led(12);
  Button *btn = new ButtonImpl(8);
  LightTask *lightTask = new LightTask(lightSensor, lightLed, btn);
  lightTask->init(50);


  sched.init(50);
  sched.addTask(doorTask);
  sched.addTask(climaTask);
  sched.addTask(lightTask);

}

void loop(){
  sched.schedule();

}
