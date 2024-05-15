#line 1 "C:\\Users\\ace_m\\OneDrive\\Documenti\\quarto_semestre_TSI\\Embedded_IoT\\Lab_parte1\\SMART-ROOM\\src\\ButtonImpl.h"
#include "Button.h"

class ButtonImpl: public Button {
    public:
        ButtonImpl(int buttonPin);
        bool isPressed();

    private:
        int buttonPin;
        
};