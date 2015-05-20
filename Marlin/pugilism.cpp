/*
  music.cpp - Pugilism functions
  Part of Marlin

  Copyright (c) 2009-2011 Simen Svale Skogsrud

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Configuration.h"

void punch_init()
{
  // Initialize pins
  pinMode(PUNCH_STEP_PIN, OUTPUT);
  pinMode(PUNCH_DIR_PIN, OUTPUT);
  pinMode(PUNCH_ENABLE_PIN, OUTPUT);
  // Disable driver
  digitalWrite(PUNCH_ENABLE_PIN, HIGH);
}

void punch(float speed)
{
  int delayLength = 1000 / (speed*2);
  SERIAL_ECHOLN("WHAM!");
  // Enable driver
  digitalWrite(PUNCH_ENABLE_PIN, LOW);
  // Set direction
  digitalWrite(PUNCH_DIR_PIN, HIGH);
  // Punch
  // Idea: Ramp up speed
  for (int i=0; i<150; i++) {
    delay(delayLength);
    digitalWrite(PUNCH_STEP_PIN, HIGH);
    delay(delayLength);
    digitalWrite(PUNCH_STEP_PIN, LOW);
  }
  // Reverse direction
  digitalWrite(PUNCH_DIR_PIN, LOW);
  // Retract
  for (int i=0; i<150; i++) {
    delay(10);
    digitalWrite(PUNCH_STEP_PIN, HIGH);
    delay(10);
    digitalWrite(PUNCH_STEP_PIN, LOW);
  }
  // Disable driver
  digitalWrite(PUNCH_ENABLE_PIN, HIGH);
}
