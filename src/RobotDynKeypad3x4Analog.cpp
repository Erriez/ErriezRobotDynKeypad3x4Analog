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
 *   Experimental ADC keypad values
 * +------+---------+-------+--------+
 * |  AVR | ESP8266 | ESP32 | Button |
 * +------+---------+-------+--------+
 * |    0 |      0  |    0  |  None  |     +----------------------+
 * |  490 |    467  | 1700  |   11   |     |o    OUT GND VCC     o|
 * |  510 |    490  | 1800  |    0   |     +----------------------+
 * |  540 |    515  | 1900  |   10   |     |                      |
 * |  570 |    546  | 2050  |    9   |     |    1     2     3     |
 * |  600 |    580  | 2170  |    8   |     |                      |
 * |  640 |    615  | 2300  |    7   |     |    4     5     6     |
 * |  680 |    660  | 2500  |    6   |     |                      |
 * |  730 |    700  | 2700  |    5   |     |    7     8     9     |
 * |  790 |    760  | 2940  |    4   |     |                      |
 * |  850 |    825  | 3250  |    3   |     |    10    0    11     |
 * |  930 |    900  | 3700  |    2   |     |o                    o|
 * | 1023 |    990  | 4095  |    1   |     +----------------------+
 * +------+---------+-------+--------+            TOP  VIEW
 */

#include "RobotDynKeypad3x4Analog.h"


/*!
 * \brief Constructor LCDKeypadShield class
 * \param analogPin
 *    Analog pin number
 * \param maxAnalogValue
 *    Maximum value of the ADC value may be slightly different. This may be compensated, but was
 *    not needed during testing with several different boards.
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

#if ARDUINO_ARCH_AVR
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
#elif ARDUINO_ARCH_ESP8266
    analogValue = (int)map(analogValue, 0, _maxAnalogValue, 0, 995);

    if (analogValue < 440) {
        button = -1;
    } else if (analogValue < 478) {
        button = 11;
    } else if (analogValue < 502) {
        button = 0;
    } else if (analogValue < 530) {
        button = 10;
    } else if (analogValue < 563) {
        button = 9;
    } else if (analogValue < 597) {
        button = 8;
    } else if (analogValue < 637) {
        button = 7;
    } else if (analogValue < 680) {
        button = 6;
    } else if (analogValue < 730) {
        button = 5;
    } else if (analogValue < 792) {
        button = 4;
    } else if (analogValue < 862) {
        button = 3;
    } else if (analogValue < 945) {
        button = 2;
    } else {
        button = 1;
    }
#elif ARDUINO_ARCH_ESP32
    analogValue = (int)map(analogValue, 0, _maxAnalogValue, 0, 4095);

    if (analogValue < 1600) {
        button = -1;
    } else if (analogValue < 1750) {
        button = 11;
    } else if (analogValue < 1850) {
        button = 0;
    } else if (analogValue < 1925) {
        button = 10;
    } else if (analogValue < 2110) {
        button = 9;
    } else if (analogValue < 2235) {
        button = 8;
    } else if (analogValue < 2400) {
        button = 7;
    } else if (analogValue < 2600) {
        button = 6;
    } else if (analogValue < 2820) {
        button = 5;
    } else if (analogValue < 3095) {
        button = 4;
    } else if (analogValue < 3475) {
        button = 3;
    } else if (analogValue < 3897) {
        button = 2;
    } else {
        button = 1;
    }
#else
#error "Unknown target"
#endif

    // For debugging purposes
    // Serial.println(analogValue);

    return button;
}
