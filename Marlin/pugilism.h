/*
  pugilism.h - Pugilism functions
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

#ifndef music_h
#define music_h

// Initialize outputs
void punch_init();
// Activate object ejection mechanism
void punch(float speed);
// Read value from laser sensor
void readPhotoCell();
// Punch repeatedly until object is ejected, or give up after a while and pause printing
void punchAndLaser(int punchCount, float speed);

#endif
