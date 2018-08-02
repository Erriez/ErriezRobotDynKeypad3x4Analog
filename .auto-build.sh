#!/bin/sh

################################################################################
# Title         : .auto-build.sh
# Date created  : 2 August 2018
__AUTHOR__="Erriez"
#
# This script will start PlatformIO build.
#
################################################################################

################################################################################
##### Setup this script and get the current gh-pages branch.               #####
echo 'Setting up the script...'

# Exit with nonzero exit code if anything fails
set -e

# Build sources
platformio ci --lib="." --project-conf=platformio/platformio.ini examples/RobotDynKeypad3x4Analog/RobotDynKeypad3x4Analog.ino
platformio ci --lib="." --project-conf=platformio/platformio.ini examples/PrintADC/PrintADC.ino
