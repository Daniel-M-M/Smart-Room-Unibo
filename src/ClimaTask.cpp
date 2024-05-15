#include "ClimaTask.h"
//TODO verificare xche la luce rossa non fa mezza luce e invece la blu si...

//La definizione delle temperature sono in gradi celcius
#define HOT_TEMP 32
#define HALF_HOT_TEMP 29
#define LIMIT_HOT_IDLE 26
#define LIMIT_COLD_IDLE 20
#define HALF_COLD_TEMP 18
#define COLD_TEMP 15

ClimaTask::ClimaTask(TemperatureSensor *tempSensor, Light *hotLed, Light *coldLed) {
    this->tempSensor = tempSensor;
    this->hotLed = hotLed;
    this->coldLed = coldLed;
}

void ClimaTask::init(int period) {
    Task::init(period);
    state = IDLE;//Il temperature sensor inizia con 24°c quindi IDLE state
}

void ClimaTask::tick(){
    switch (state) {
        case HOT:
            hot();
            break;
        case HALFHOT:
            halfHot();
            break;
        case IDLE:
            idle();
            break;
        case HALFCOLD:
            halfCold();
            break;
        case COLD:
            cold();
            break;
    }
}

//Chiamato da halfhot già in piena potenza la dimezza dopo che la temp va oltre 18 gradi
void ClimaTask::hot() {
    float currTemp = tempSensor->getTemperature();
    if (currTemp > 18) {
        hotLed->halfBrightness();//TODO qui non va boh!!
        state = HALFHOT;
    }
}

//La modalita halfhot è chiamata dall'idle
void ClimaTask::halfHot () {
    Serial.println("Sono allo stato HALAFHOT");
    float currTemp = tempSensor->getTemperature();
    //Se non ce la fa led a piena potenza e entra nella modalita hot
    if (currTemp < 15) {
        hotLed->switchOn();
        state = HOT;
    }
    //Caso celafacia ritorna alla modalita idle dopo aver superato 20°C
    if (currTemp > 20) {
        hotLed->switchOff();
        state = IDLE;
    }
}

//Start dello stato che se è sotto 20 acende il riscaldameto se è sopra 26 il raffredamento
void ClimaTask::idle() {
    float currTemp = tempSensor->getTemperature();
    if (currTemp < 20) {
        hotLed->halfBrightness();//TODO anche qui non va!!
        state = HALFHOT;
    }

    if (currTemp > LIMIT_HOT_IDLE) {
        coldLed->halfBrightness();
        state = HALFCOLD;
    }
}

//superando la soglia di 26 gradi entriamo nalla modalita halfcold con meta brillo delle lampadine
void ClimaTask::halfCold() {
    float currTemp = tempSensor->getTemperature();
    //caso la temp scenda troppo attiva la modalità cold con led al pieno
    if (currTemp > HOT_TEMP) {
        coldLed->switchOn();
        state = COLD;
    }
    //Se invece ce la fa e la temp risale entra nella modalità idle
    if (currTemp < LIMIT_HOT_IDLE) {
        coldLed->switchOff();
        state = IDLE;
    }
    
}

//Modalità cold chiamata da halfcold che quando arriva a 29 ritorna alla modalita halfcold.
void ClimaTask::cold() {
    float currTemp = tempSensor->getTemperature();
    if (currTemp < HALF_HOT_TEMP) {
        coldLed->halfBrightness();
        state = HALFCOLD;
    }
    
}

