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
 * \file RobotDynKeypad3x4Analog.cpp
 * \brief RobotDyn Keypad 3x4 Analog library for Arduino
 * \details
 *     Source: https://github.com/Erriez/RobotDynKeypad3x4Analog
 *
 *  0    = None         +----------------------+
 *  490  = Button 11    |o    OUT GND VCC     o|
 *  510  = Button 0     +----------------------+
 *  540  = Button 10    |                      |
 *  570  = Button 9     |    1     2     3     |
 *  600  = Button 8     |                      |
 *  640  = Button 7     |    4     5     6     |
 *  680  = Button 6     |                      |
 *  730  = Button 5     |    7     8     9     |
 *  790  = Button 4     |                      |
 *  850  = Button 3     |    10    0    11     |
 *  930  = Button 2     |o                    o|
 *  1023 = Button 1     +----------------------+
 *                             TOP  VIEW
 */

#include "RobotDynKeypad3x4Analog.h"


/*!
 * \brief Constructor LCDKeypadShield class
 * \param analogPin
 *    Analog pin number
 * \param maxAnalogValue
 *    Maximum value of the ADC (1023 for most Arduino boards, around 991..995 for ESP8266 boards)
 */
RobotDynKeypad3x4Analog::RobotDynKeypad3x4Analog(uint8_t analogPin, uint16_t maxAnalogValue) :
        _analogPin(analogPin), _maxAnalogValue(maxAnalogValue)
{

}

/*!
 * \brief Read buttons from one analog pin
 * \return
 *    -1:    Button up
 *    0..11: Button down
 */
int RobotDynKeypad3x4Analog::getButtons()
{
    int analogValue;
    int button;

    analogValue = analogRead(_analogPin);

    analogValue = (int)map(analogValue, 0, _maxAnalogValue, 0, 1023);

    if (analogValue < 450) {
        button = -1;
    } else if (analogValue < 500) {
        button = 11;
    } else if (analogValue < 525) {
        button = 0;
    } else if (analogValue < 555) {
        button = 10;
    } else if (analogValue < 585) {
        button = 9;
    } else if (analogValue < 620) {
        button = 8;
    } else if (analogValue < 660) {
        button = 7;
    } else if (analogValue < 705) {
        button = 6;
    } else if (analogValue < 760) {
        button = 5;
    } else if (analogValue < 820) {
        button = 4;
    } else if (analogValue < 890) {
        button = 3;
    } else if (analogValue < 976) {
        button = 2;
    } else {
        button = 1;
    }

    // For debugging purposes
    // Serial.println(analogValue);

    return button;
}
