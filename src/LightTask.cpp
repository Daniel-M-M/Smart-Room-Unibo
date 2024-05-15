#include "LightTask.h"

//La definizione della luminosità è in lux.
#define LOW_LIIGHT 100
#define HIGHT_LIGHT 500
//per controllare lo stato della luce
#define ON 1
#define OFF 0
//per evitare il bouncing
#define COUNT_TICK 4

LightTask::LightTask(Light_Sensor *lightSensor, Light *lightLed, Button *btn) {
    this->lightSensor = lightSensor;
    this->lightLed = lightLed;
    this->btn = btn;
}

void LightTask::init(int period) {
    Task::init(period);
    state = DAY;//Status dalla luce esterna
    on_off = OFF; //Status del led all'inizio lux = 500
    count = 0;//contatore di tick usato per evitare il bouncing
}

//La miglior scelta per gestire il bouncing è usando gli state
void LightTask::tick(){
    switch (state) {
        case NIGHT:
            night();
            break;
        case DAY:
            day();
            break;
        case TURNED_ON:
            turnedOn();
            break;
        case TURNED_OFF:
            turnedOff();
            break;
    }
}

//Funzione che prendi un valore del sensore e spegne le luci, ed è in ascolto all'input seriale
void LightTask::night() {
    //qui cerco di prendere un carattere della tastiera
    char mod;
    if (Serial.available()) {
        mod = Serial.read();
        Serial.println(mod);
    }

    //Se durate la note ricevo un input di tastiera cambi stato a manuale luce acese
    if (mod == 'M') {
        state = TURNED_ON;
    }
    
    //controllo lux per cambiare stato in luci off
    int lux = lightSensor->getLightIntensity();
    if (lux > HIGHT_LIGHT) {
        lightLed->switchOff();
        on_off = OFF;
        state = DAY;
    }
}

//Funzione che accende la luce caso sia buio
void LightTask::day() {
    //qui cerco di prendere un carattere della tastiera
    char mod;
    if (Serial.available()) {
        mod = Serial.read();
        Serial.println(mod);
    }

    //Lo stesso alla notte per spegnere la luce cambio modalità con luce spenta
    if (mod == 'M') {
        state = TURNED_OFF;
    }

    //prendo rilevamento dal sensore e verifico lux è bassa per accendere le luci
    int lux = lightSensor->getLightIntensity();
    if (lux < LOW_LIIGHT) {
        lightLed->switchOn();
        on_off = ON;
        state = NIGHT;
    }
}

//Funcione che è chiamata quando le luci sono accese e fa il turned off
void LightTask::turnedOn() {
    //Anche qui prendo un char per vedere il cambio di modalita
    char mod;
    if (Serial.available()) {
        mod = Serial.read();
        Serial.println(mod);
    }

    //scelto day perche alla notte acendiamo la luci
    if (mod == 'A') {
        state = DAY;
    }


    //Nella modalità manuale verifico lo stato del bottone e del led
    if (btn->isPressed()) {
        lightLed->switchOff();
        on_off = OFF;
        count++;//somo i tick nel caso 50milli per il bouncing
        if (count > COUNT_TICK) {
            count = 0;//azzero il counter
            state = TURNED_OFF;//cambio stato ad off
        }
    }
}

//Funzione chiama quando le luci sono spente
void LightTask::turnedOff(){
    //Anche qui prendo un char per vedere il cambio di modalita
    char mod;
    if (Serial.available()) {
        mod = Serial.read();
        Serial.println(mod);
    }

    //scelto day perche alla notte acende la luci
    if (mod == 'A') {
        state = DAY;
    }

    //Modalità manuale controllo bottone e acendo la luce
    if (btn->isPressed()) {
        lightLed->switchOn();
        on_off = ON;
        count++;//somo i tick nel caso 50milli
        if (count > COUNT_TICK) {
            count = 0;
            state = TURNED_ON;
        }
    }
}