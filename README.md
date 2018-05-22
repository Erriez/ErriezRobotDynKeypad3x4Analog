# RobotDyn  library for Arduino
[![Build Status](https://travis-ci.org/Erriez/ErriezRobotDynKeypad3x4Analog.svg?branch=master)](https://travis-ci.org/ErriezRobotDynKeypad3x4Analog)

This is a RobotDyn Keypad 3x4 with analog output library for Arduino.

## Hardware
Any Arduino / ESP8266 board with an ADC (Analog Digital Converter).

![RobotDyn Keypad 3x4 Analog](https://raw.githubusercontent.com/Erriez/ErriezRobotDynKeypad3x4Analog/master/extras/ErriezRobotDynKeypad3x4Analog.png)

## Pins

| Keypad | Any Arduino board | WeMos D1 & R2 / Node MCU | WeMos LOLIN32 |
| ------ | :---------------: | :----------------------: | :-----------: |
| VCC    |   5V (or 3.3V)    |           3V3            |      3V3      |
| GND    |        GND        |           GND            |      GND      |
| OUT    |  A0 (ANALOG pin)  |            A0            |       0       |

- 

## Example

Examples | Erriez RobotDyn Keypad 3x4 Analog:

* [Calibrate](https://github.com/Erriez/ErriezRobotDynKeypad3x4Analog/blob/master/examples/Calibrate/Calibrate.ino)
* [Example](https://github.com/Erriez/ErriezRobotDynKeypad3x4Analog/blob/master/examples/Example/Example.ino)

## Usage

**Initialization**

```c++
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
```

**Get buttons**

```c++
// Read buttons:
// -1:    Buttons up
// 0..11: Button down
int keypadState = keypad.getButtons();
```

## Library dependencies

- None.

## Documentation

- [Doxygen online HTML](https://Erriez.github.io/ErriezRobotDynKeypad3x4Analog/)
- [Doxygen PDF](https://github.com/Erriez/ErriezRobotDynKeypad3x4Analog/raw/master/docs/latex/refman.pdf)

## Library installation

Please refer to the [Wiki](https://github.com/Erriez/ErriezArduinoLibrariesAndSketches/wiki) page.