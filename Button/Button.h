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

#ifndef Button_h
#define Button_h

#include "WProgram.h"

class Button
{
    public:
        /**
         * @brief Creates a new Button instance.
         * @param pin The Arduino Pin of the input.
         * @return void
         */
        Button(int pin);
        
        /**
         * @brief Returns the current state of the button.
         * @details If the current state of the button is pressed,
         * than will be returned true, otherwise it will be false.
         * @return bool
         */
        bool getState();
        
        /**
         * @brief Returns the current raw state of the button.
         * @details If the current state of the button is pressed,
         * than will be returned HIGH, otherwise it will be LOW.
         * @return int
         */
        int getStateRaw();
        
        /**
         * @brief Waits until the button is pressed.
         * @details This function stops the current execution of
         * code, until the user presses the button down.
         * The code has simple noise filtering. 
         * @return void
         */
        void waitUntilPressed();
        
        /**
         * @brief Waits until the button is released.
         * @details This function stops the current execution of
         * code, until the user releases the button.
         * The code has simple noise filtering.
         * @return void
         */
        void waitUntilReleased();
        
        /**
         * @brief Waits until the button was touched.
         * @details This function stops the current execution of
         * code, until the user presses the button down and
         * releases the button again.
         * The code has simple noise filtering.
         * @return void
         */
        void waitUntilTouched();
    private:
        int _pin;
};

#endif
