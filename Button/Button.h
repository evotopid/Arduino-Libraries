#ifndef Button_h
#define Button_h

//#define BUTTON_PRESSED true
//fal#define BUTTON_RELEASED false

#include "WProgram.h"

class Button
{
    public:
        Button(int pin);
        bool getState(); 
        void waitUntilPressed();
        void waitUntilReleased();
        void waitUntilTouched();
    private:
        int _pin;
};

#endif
