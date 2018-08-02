#!/bin/sh

# Install Python platformio 
# pip install -U platformio

# Update library
# git fetch
# git pull

# Build example(s)
platformio ci --lib=".." --project-conf=platformio.ini ../examples/RobotDynKeypad3x4Analog/RobotDynKeypad3x4Analog.ino
platformio ci --lib=".." --project-conf=platformio.ini ../examples/PrintADC/PrintADC.ino
