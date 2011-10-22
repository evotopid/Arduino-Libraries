/**
 * @brief An Arduino Library, which helps you to interract with buttons.
 * @author Cheese-Tornado
 * 
 * @copyright
 * Copyright (c) 2011 Cheese-Tornado
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * \n\n
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * \n\n
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**/

#include "WProgram.h"
#include "Button.h"

Button::Button(int pin, bool invert)
{
    pinMode(pin, INPUT);
    _pin = pin;
    _invert = invert;
}

bool Button::getState()
{
    if (this->getStateRaw() == HIGH)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Button::getStateRaw()
{
    if (_invert)
    {
        if (digitalRead(_pin) == HIGH)
        {
            return LOW;
        }
        else
        {
            return HIGH;
        }
    }
    else
    {
        return digitalRead(_pin);
    }
}

void Button::waitUntilPressed(bool debounce, int delayTime)
{
    if (debounce)
    {
        bool statesBuffer[8] = {false, false, false, false, false, false, false, false};
        
        while ( statesBuffer[0] == false || statesBuffer[1] == false || statesBuffer[2] == false || statesBuffer[3] == false || statesBuffer[4] == false || statesBuffer[5] == false || statesBuffer[6] == false || statesBuffer[7] == false ) 
        {
            // shift buffer
            for (int i=0; i<7; i++)
            {
                statesBuffer[i] = statesBuffer[i+1];
            }
            
            // read new data into buffer
            statesBuffer[7] = this->getState();
            
            // delay a short time
            delay(delayTime);
        }
    }
    else
    {
        while(this->getState() == false)
        {
            // delay a short time
            delay(delayTime);
        }
    }
}

void Button::waitUntilReleased(bool debounce, int delayTime)
{
    if (debounce)
    {
        bool statesBuffer[8] = {true, true, true, true, true, true, true, true};
        
        while ( statesBuffer[0] == true || statesBuffer[1] == true || statesBuffer[2] == true || statesBuffer[3] == true || statesBuffer[4] == true || statesBuffer[5] == true || statesBuffer[6] == true || statesBuffer[7] == true ) 
        {
            // shift buffer
            for (int i=0; i<7; i++)
            {
                statesBuffer[i] = statesBuffer[i+1];
            }
            
            // read new data into buffer
            statesBuffer[7] = this->getState();
            
            // delay a short time
            delay(delayTime);
        }
    }
    else
    {
        while(this->getState() == true)
        {
            // delay a short time
            delay(delayTime);
        }
    }
}

void Button::waitUntilTouched(bool debounce, int delayTime)
{
    this->waitUntilPressed(debounce, delayTime);
    this->waitUntilReleased(debounce, delayTime);
}
