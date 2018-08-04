rem Install Python27 platformio
rem C:\Python27\Scripts\pip.exe install -U platformio

rem Set Python path
set PATH=%PATH%;C:\Python27
set PATH=%PATH%;C:\Python27\Scripts

rem Update library
rem git fetch
rem git pull

rem Build example(s)
platformio ci --lib=".." --project-conf=platformio.ini ../examples/RobotDynKeypad3x4Analog/RobotDynKeypad3x4Analog.ino
platformio ci --lib=".." --project-conf=platformio.ini ../examples/PrintADC/PrintADC.ino

@pause