/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//Having this makes the left side encoder act like the right side
#undef EE_HANDS

#define RGB_MATRIX_LED_COUNT 36
#define RGB_MATRIX_SPLIT  { 18,  18 }

#undef ENCODER_RESOLUTION
#undef ENCODER_RESOLUTION_RIGHT

#define ENCODER_RESOLUTION 4
#define ENCODER_RESOLUTION_RIGHT 4