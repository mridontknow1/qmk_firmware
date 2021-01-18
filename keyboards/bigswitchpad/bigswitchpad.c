/* Copyright 2020 Richard
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "bigswitchpad.h"


#ifdef RGB_MATRIX_ENABLE
#define DRIVER_LED_TOTAL = 12
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {   0,  	1,  		2, },
  {   11,  	NO_LED,  	3, },
  {   10, 	NO_LED,  	4, },
  {   9, 	NO_LED, 	5, },
  {   8,  	7,  		6  }
}, {
  // LED Index to Physical Position
  { 0,  0 }, 	{ 112,  0 }, 	{ 224,  0 },
  { 0,  16 }, 	{ 112,  16 }, 	{ 224,  16 },
  { 0,  32 }, 	{ 112,  32 }, 	{ 224,  32 },
  { 0,  48 }, 	{ 112,  48 }, 	{ 224,  48 },
  { 0,  64 }, 	{ 112,  64 }, 	{ 224,  64 }

}, {
  // LED Index to Flag
  2, 2, 2,
  2, 2, 2,
  2, 2, 2,
  2, 2, 2,
  2, 2, 2
} };
#endif
