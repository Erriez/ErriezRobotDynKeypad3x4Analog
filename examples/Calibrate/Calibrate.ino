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
 * \file Example.ino
 * \brief RobotDyn Keypad 3x4 Analog example
 * \details
 *    Source: https://github.com/Erriez/RobotDynKeypad3x4Analog
 */

#include <Arduino.h>

// Connect the keypad OUT pin to the ANALOG pin of an Arduino board
#define KEYPAD_ANALOG_PIN   A0

static int maxAnalogValue = 0;


void setup(void)
{
    Serial.begin(115200);
    while (!Serial) {
        ;
    }
    Serial.println(F("RobotDyn Keypad 3x4 Analog calibration"));
    Serial.println(F("Press button 1..."));
}

void loop(void)
{
    int analogValue;

    // Read analog value
    analogValue = analogRead(KEYPAD_ANALOG_PIN);

    // Print maximum ADC value for key 1 once. This is value 1023 for most Arduino boards,
    // and around 991..995 for ESP8266 boards.
    if ((analogValue >= 400) && (analogValue > maxAnalogValue)) {
        maxAnalogValue = analogValue;

        Serial.println(F("Use the following macro in Example.ino:"));
        Serial.print(F("#define MAX_ANALOG_VALUE  "));
        Serial.println(analogValue, DEC);
    }

    delay(100);
}
