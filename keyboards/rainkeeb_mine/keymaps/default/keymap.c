/* Copyright 2020 Rain&Friends
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
#include QMK_KEYBOARD_H

/* Create Layer Enum */
enum rainkeeb_layers {
  _BASE,
  _NUMPAD,
  _MAX_VAL				// Do not assign this to a layer. Keep at end
};

/* Create Macro Enum */
enum rainkeeb_keycodes {
    UD_1 = SAFE_RANGE,	//	(User Defined 1)
	UD_2,				//	(User Defined 2)
	UD_S0,				// (
	UD_S9,				// )
	UD_QUOT				// "
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base Layer
                                              |<<<<<<<|>>>>>>>|
                                              |LAY DO | LAY UP|
                                              |<<<<<<<|>>>>>>>|
    * ,-----------------------------------------------------------------------------------------------.
    * |   Q   |   W   |   E   |   R   |   T   |---------------|   Y   |   U   |   I   |   O   |   P   |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |   A   |   S   |   D   |   F   |   G   |     pause     |   H   |   J   |   K   |   L   |  up   |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |   Z   |   X   |   C   |   V   |   B   |     macro     |   N   |   M   | left  | right | down  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |L Shift| L Ctrl| L Alt |     Space     |     layer     |     Space     | R Gui | R Alt | R Ctrl|
    * `-----------------------------------------------------------------------------------------------'
    */
  [_BASE] = rainkeeb_layout( /* Base Layer */
		KC_Q, 					KC_E, 					KC_T, 								KC_U, 					KC_O, 
					KC_W, 					KC_R, 								KC_Y, 					KC_I, 					KC_P,
		KC_A, 					KC_D, 					KC_G, 					KC_H, 					KC_K, 					KC_UP, 
					KC_S, 					KC_F, 					KC_MPLY,				KC_J, 					KC_L, 
		KC_Z, 					KC_C, 					KC_B, 					KC_N, 					KC_LEFT, 				KC_DOWN, 
					KC_X, 					KC_V, 					UD_1, 					KC_M, 					KC_RGHT, 
		KC_LSFT, 				KC_LALT, 							TO(_NUMPAD),						KC_RGUI, 				KC_RCTL, 
					KC_LCTL, 						KC_SPC, 						KC_SPC, 						KC_RALT
	),

/* Numpad Layer
                                              |<<<<<<<|>>>>>>>|
                                              |LAY DO | LAY UP|
                                              |<<<<<<<|>>>>>>>|
    * ,-----------------------------------------------------------------------------------------------.
    * |  Ins  |  Home |  PgUp |   (   |   )   |---------------|   7   |   8   |   9   |   -   |   /   |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Del  |  End  |  PgDn |   '   |   "   |     pause     |   4   |   5   |   6   |   +   |   *   |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Caps |  up   |  Num  |   .   |   ?   |     macro     |   1   |   2   |   3   |  Ent  | down  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | left  |  dwn  | right |     Space     |     layer     |       0       |   .   |  Ent  | R Ctrl|
    * `-----------------------------------------------------------------------------------------------'
    */
  [_NUMPAD] = rainkeeb_layout( /* Numpad Layer */
		KC_INS,					KC_PGUP,				UD_S0, 								KC_8, 					KC_PMNS, 
					KC_HOME,				UD_S9, 								KC_7, 					KC_9, 					KC_PSLS,
		KC_DEL, 				KC_PGDN,				KC_G, 					KC_4, 					KC_6, 					KC_PAST, 
					KC_END,					KC_QUOT,				KC_MPLY,				KC_5, 					KC_PPLS, 
		KC_CAPS, 				KC_NLCK,				UD_QUOT,				KC_1, 					KC_3, 					_______, 
					KC_UP, 					KC_DOT, 				UD_2, 					KC_2, 					KC_PENT, 
		KC_LEFT, 				KC_RGHT, 							TO(_BASE),							KC_PDOT, 				_______, 
					KC_DOWN, 						KC_SPC, 						KC_0, 							KC_PENT
	),
};

void keyboard_post_init_user(void) {
	
}

void encoder_update_user(uint8_t index, bool clockwise) {
	if (clockwise) {
		if (layer_state != _MAX_VAL-1 ) {
			layer_state++;
		} else {
			layer_state=_BASE;
		}
	} else {
		if (layer_state != _BASE ) {
			layer_state--;
		} else {
			layer_state=_MAX_VAL-1;
		}
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case UD_1:			//	<3
			if (record->event.pressed) { // when keycode is pressed
				SEND_STRING("<3");
			}
			return false;
			break;
		case UD_2:			//	pog keeb
			if (record->event.pressed) { // when keycode is pressed
				SEND_STRING("pog keeb");
			}
			return false;
			break;
		case UD_S0:			//	)
			if (record->event.pressed) { // when keycode is pressed
				SEND_STRING(")");
			}
			return false;
			break;
		case UD_S9:			//	(
			if (record->event.pressed) { // when keycode is pressed
				SEND_STRING("(");
			}
			return false;
			break;
		case UD_QUOT:			//	"
			if (record->event.pressed) { // when keycode is pressed
				SEND_STRING("\"");
			}
			return false;
			break;
		}
    return true;
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
