#include "WProgram.h"
#include "Button.h"

Button::Button(int pin)
{
    pinMode(pin, INPUT);
    _pin = pin;
}

bool Button::getState()
{
    if (digitalRead(_pin) == HIGH)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Button::waitUntilPressed()
{
    bool lastState = false;
    while(this->getState() == false || lastState == false)
    {
        lastState = this->getState();
        delay(5);
    }
}

void Button::waitUntilReleased()
{
    bool lastState = true;
    while(this->getState() == true || lastState == true)
    {
        lastState = this->getState();
        delay(5);
    }
}

void Button::waitUntilTouched()
{
    bool lastState = false;
    while (this->getState() == false || lastState == false)
    {
        lastState = this->getState();
        delay(5);
    }
    
    lastState = true;
    while (this->getState() == true || lastState == true)
    {
        lastState = this->getState();
        delay(5);
    }
}
