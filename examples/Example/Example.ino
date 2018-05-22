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
#include <RobotDynKeypad3x4Analog.h>

// Connect the keypad OUT pin to the ANALOG pin of an Arduino board
#define KEYPAD_ANALOG_PIN   A0

// Maximum analog value on +3.3V or +5V analog conversion
// Run Calibrate.ino when a button value does not match and update the value below.
// This is value 1023 for most Arduino boards and around 991..995 for ESP8266 boards.
#define MAX_ANALOG_VALUE    1023

// Create keypad object
RobotDynKeypad3x4Analog keypad(KEYPAD_ANALOG_PIN, MAX_ANALOG_VALUE);

// Initial keypad state
static int keypadStateLast = -2;


void setup(void)
{
    // Initialize serial port
    Serial.begin(115200);
    while (!Serial) {
        ;
    }
    Serial.println(F("RobotDyn Keypad 3x4 Analog example"));
}

void loop(void)
{
    int keypadState;

    // Read buttons
    keypadState = keypad.getButtons();

    // Print button state only when it changed
    if (keypadState != keypadStateLast) {
        keypadStateLast = keypadState;

        if (keypadState == -1) {
            // -1: All buttons up
            Serial.println(F("Buttons up"));
        } else {
            // 0..11: Button down
            Serial.print(F("Buttons "));
            Serial.print(keypadState, DEC);
            Serial.println(F(" down"));
        }
    }

    delay(100);
}
