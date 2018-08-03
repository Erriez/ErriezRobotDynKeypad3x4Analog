/*
 * MIT License
 *
 * Copyright (c) 2018 Erriez
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*!
 * \file RobotDynKeypad3x4Analog.h
 * \brief RobotDyn Keypad 3x4 Analog library for Arduino
 * \details
 *      Source: https://github.com/Erriez/RobotDynKeypad3x4Analog
 *      Documentation:  https://erriez.github.io/RobotDynKeypad3x4Analog
 */

#ifndef ROBOT_DYN_KEYPAD_3X4_ANALOG_H__
#define ROBOT_DYN_KEYPAD_3X4_ANALOG_H__

#include <Arduino.h>

#if ARDUINO_ARCH_AVR
#define MAX_ANALOG_VALUE    1023
#elif ARDUINO_ARCH_ESP8266
#define MAX_ANALOG_VALUE    995
#elif ARDUINO_ARCH_ESP32
#define MAX_ANALOG_VALUE    4095
#else
#error "Unknown target"
#endif

/*!
 * \brief RobotDyn Keypad 3x4 Analog class
 */
class RobotDynKeypad3x4Analog
{
public:
    explicit RobotDynKeypad3x4Analog(uint8_t analogPin, uint16_t maxAnalogValue=MAX_ANALOG_VALUE);
    int getButtons();

protected:
    uint16_t _maxAnalogValue;   //!< Max analog value
    uint8_t  _analogPin;        //!< Analog pin number
};

#endif // ROBOT_DYN_KEYPAD_3X4_ANALOG_H__
