/**
 * @brief An Arduino Library, which helps you to interract with outputs.
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

#ifndef Output_h
#define Output_h

#include "Arduino.h"

class Output
{
    public:
        /**
         * @brief Creates new Output instance.
         * @details This method creates a new Output instance.
         * It also sets up the output so you don't have
         * to call "pinMode()" anymore.
         * @param pin The Arduino Pin of the Output.
         * @return void
         */
        Output(int pin);
        
        /**
         * @brief Returns the current state of the output.
         * @details This returns a boolean var that means
         * the state HIGH would result in true and the state
         * LOW would result in false
         * @return bool
         */
        bool getState();
        
        /**
         * @brief Set the state of the output
         * @details true means HIGH and false means LOW
         * @param state The new state of the output
         * @return void
         */
        void setState(bool state);
        
        /**
         * @brief Toggle the state of the output
         * @details If the state is low the new state is high.
         * If the state is high the new state is low
         * @return void
         */
        void toggleState();
    private:
        /**
         * @brief Updates the Output
         * @details Sets the output to the value of _state
         * @return void
         */
        void updateOutput();
        int _pin;
        bool _state;
};

#endif