#include "Button.h"

class ButtonImpl: public Button {
    public:
        ButtonImpl(int buttonPin);
        bool isPressed();

    private:
        int buttonPin;
        
};