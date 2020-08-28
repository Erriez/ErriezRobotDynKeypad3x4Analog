/*
 * MIT License
 *
 * Copyright (c) 2018-2020 Erriez
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
 * \brief RobotDyn Keypad 3x4 with analog output example
 * \details
 *      Source:         https://github.com/Erriez/RobotDynKeypad3x4Analog
 *      Documentation:  https://erriez.github.io/RobotDynKeypad3x4Analog
 */

#include <ErriezRobotDynKeypad3x4Analog.h>


// Connect the keypad OUT pin to the ANALOG pin of an Arduino / ESP8266 / ESP32 board
#define KEYPAD_ANALOG_PIN   A0

// Create keypad object
RobotDynKeypad3x4Analog keypad(KEYPAD_ANALOG_PIN);

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
            Serial.print(F("Button "));
            Serial.print(keypadState, DEC);
            Serial.println(F(" down"));
        }
    }

    delay(100);
}
