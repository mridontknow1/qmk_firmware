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
#include<stdio.h>
#include QMK_KEYBOARD_H

#define _BASE_L		0 	// Base Layer
#define _RGB_L 		1	// RGB Control Layer
#define _MAC_L		2	// Macro Definition Layer
#define _QMK_L		3	// QMK Functions Layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base Layer
   * ,-----------------------.
	* |                       | |--------|
	* |           F           | |  RGB L |
	* |                       | |--------|
	* |-------+-------+-------| |<<<<<<<<|>>>>>>>>|
    * | BEAR  | HI!!! | PLAY  | |VOL D   |   VOL U|
    * |-------+-------+-------| |<<<<<<<<|>>>>>>>>|
    * | FLIP  | FLIP2 | GLASS |
    * |-------+-------+-------|
    * |SHRUG  |HRTFACE|DISFACE|
    * |-------+-------+-------|
    * | CLOUD |  FU   |HAPPYFC|
    * `-----------------------'
    */
  [_BASE_L] = LAYOUT_ortho_3x5( /* Base */
	UD_F, 			TO(_RGB_L),
	BEAR, 			HIIII, 			KC_MPLY,
	TFLIP, 			TFLIP2, 		SGLASS,
	SHRUG, 			HEARTFACE, 		DISFACE,
	CLOUD, 			FU, 			HAPPYFACE
  ),

/* RGB Control Layer
    * ,-----------------------.
	* |                       | |--------|
	* |      RGB Values       | | BASE L |
	* |                       | |--------|
	* |-------+-------+-------| |<<<<<<<<|>>>>>>>>|
    * |MODE B |MODE F |ON/OFF | |HUE L   |   HUE R|
    * |-------+-------+-------| |<<<<<<<<|>>>>>>>>|
    * |SLOWER |ON/OFF |FASTER |
    * |-------+-------+-------|
    * |BLAKER |ON/OFF |WHITER |
    * |-------+-------+-------|
    * |DARKER |RESET L|BRIGHTR|
    * `-----------------------'
    */
  [_RGB_L] = LAYOUT_ortho_3x5( /* RGB Control */
	_______,		TO(_BASE_L),
	RGB_RMOD, 		RGB_MOD, 		RGB_TOG,
	RGB_SPD,		RGB_TOG, 		RGB_SPI,
	RGB_SAD,		RGB_TOG, 		RGB_SAI,
	RGB_VAD, 		MO(_QMK_L), 	RGB_VAI
  ),

 /* QMK Layer
    * ,-----------------------.
	* |                       | |--------|
	* |        _______        | |_______ |
	* |                       | |--------|
	* |-------+-------+-------| |<<<<<<<<|>>>>>>>>|
    * |_______|_______|_______| |_______ | _______|
    * |-------+-------+-------| |<<<<<<<<|>>>>>>>>|
    * |_______| RESET |_______|
    * |-------+-------+-------|
    * |_______|_______|_______|
    * |-------+-------+-------|
    * |_______|STAY ON|_______|
    * `-----------------------'
    */
  [_QMK_L] = LAYOUT_ortho_3x5( /* QMK Controls */
	_______,		_______,
	_______, 		_______, 		_______,
	_______,		RESET,  		_______,
	_______,		_______, 		_______,
	_______, 		_______, 		_______
  ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    switch(biton32(layer_state)){
		case _RGB_L: /* RGB Control Layer Active*/
			if (index == 0) { /* First encoder */
				if (clockwise) {
					rgblight_increase_hue_noeeprom();
				} else {
					rgblight_decrease_hue_noeeprom();
				}
			}
			break;
		default: /* Base Layer Active */
			if (index == 0) { /* First encoder */
				if (clockwise) {
					tap_code(KC_VOLU);
				} else {
					tap_code(KC_VOLD);
				}
			}
			break;
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case UD_F:			// Big Script F
			if (record->event.pressed) { // when keycode is pressed
			send_unicode_string("⠀⠀⠀⢀⡤⢶⣶⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ");
			SEND_STRING(SS_LSFT("\n"));
			send_unicode_string("⠀⠀⢀⣠⣤⣤⣤⣿⣧⣀⣀⣀⣀⣀⣀⣀⣀⣤⡄⠀ ");
			SEND_STRING(SS_LSFT("\n"));
			send_unicode_string("⢠⣾⡟⠋⠁⠀⠀⣸⠇⠈⣿⣿⡟⠉⠉⠉⠙⠻⣿⡀ ");
			SEND_STRING(SS_LSFT("\n"));
			send_unicode_string("⢺⣿⡀⠀⠀⢀⡴⠋⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠙⠇ ");
			SEND_STRING(SS_LSFT("\n"));
			send_unicode_string("⠈⠛⠿⠶⠚⠋⣀⣤⣤⣤⣿⣿⣇⣀⣀⣴⡆⠀⠀⠀ ");
			SEND_STRING(SS_LSFT("\n"));
			send_unicode_string("⠀⠀⠀⠀⠠⡞⠋⠀⠀⠀⣿⣿⡏⠉⠛⠻⣿⡀⠀⠀ ");
			SEND_STRING(SS_LSFT("\n"));
			send_unicode_string("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⡇⠀⠀⠀⠈⠁⠀⠀ ");
			SEND_STRING(SS_LSFT("\n"));
			send_unicode_string("⠀⠀⣠⣶⣶⣶⣶⡄⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀ ");
			SEND_STRING(SS_LSFT("\n"));
			send_unicode_string("⠀⢰⣿⠟⠉⠙⢿⡟⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀ ");
			SEND_STRING(SS_LSFT("\n"));
			send_unicode_string("⠀⢸⡟⠀⠀⠀⠘⠀⠀⠀⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀ ");
			SEND_STRING(SS_LSFT("\n"));
			send_unicode_string("⠀⠈⢿⡄⠀⠀⠀⠀⠀⣼⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀ ");
			SEND_STRING(SS_LSFT("\n"));
			send_unicode_string("⠀⠀⠀⠙⠷⠶⠶⠶⠿⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀.");
            }
			return false;
			break;
		case CLOUD:			//	(っ◕‿◕)っ
			if(record->event.pressed){
				send_unicode_string("(っ◕‿◕)っ");
				//send_unicode_hex_string("0028 3063 25D5 203F 25D5 0029 3063");
			}
			return false;
			break;
		case FU:			//	t(-_-t)
			if(record->event.pressed){
				SEND_STRING("t(-_-t)");
			}
			return false;
			break;
		case HAPPYFACE:		//	ʘ‿ʘ
			if(record->event.pressed){
				send_unicode_string("ʘ‿ʘ");
				//send_unicode_hex_string("0298 203F 0298");
			}
			return false;
			break;
		case SHRUG:			//	¯\_(ツ)_/¯
			if (record->event.pressed) {
				send_unicode_string("¯\\_(ツ)_/¯");
				//send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
			}
			return false;
			break;
		case HEARTFACE:		//	♥‿♥
			if(record->event.pressed){
				send_unicode_string("♥‿♥");
				//send_unicode_hex_string("2665 203F 2665");
			}
			return false;
			break;
		case DISFACE:		//	ಠ_ಠ
			if(record->event.pressed){
				send_unicode_string("ಠ_ಠ");
				//send_unicode_hex_string("0CA0 005F 0CA0");
			}
			return false;
			break;
		case TFLIP:			//	(╯°□°)╯ ︵ ┻━┻
			if(record->event.pressed){
				send_unicode_string("(╯°□°)╯ ︵ ┻━┻");
				//send_unicode_hex_string("0028 256F 00B0 25A1 00B0 0029 256F 0020 FE35 0020 253B 2501 253B");
			}
			return false;
			break;
		case TFLIP2:		//	┻━┻︵ \(°□°)/ ︵ ┻━┻
			if(record->event.pressed){
				send_unicode_string("┻━┻︵ \\(°□°)/ ︵ ┻━┻");
				//send_unicode_hex_string("253B 2501 253B FE35 0020 005C 0028 00B0 25A1 00B0 0029 002F 0020 FE35 0020 253B 2501 253B");
			}
			return false;
			break;
		case SGLASS:		//	(⌐■_■)
			if(record->event.pressed){
				send_unicode_string("(⌐■_■)");
				//send_unicode_hex_string("0028 2310 25A0 005F 25A0 0029");
			}
			return false;
			break;
		case BEAR:		//	ʕ•ᴥ•ʔ
			if(record->event.pressed){
				send_unicode_string("ʕ•ᴥ•ʔ");
				//send_unicode_hex_string("0295 2022 1D25 2022 0294");
			}
			return false;
			break;
		case HIIII:		//	⊂(◉‿◉)つ
			if(record->event.pressed){
				send_unicode_string("⊂(◉‿◉)つ");
				//send_unicode_hex_string("2282 0028 25C9 203F 25C9 0029 3064");
			}
			return false;
			break;
		}
    return true;
};

#ifdef RGBLIGHT_ENABLE
// Light all LEDs red when in QMK Functions Layer
const rgblight_segment_t PROGMEM qmk_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_RED}
);

// Define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	qmk_layer	// 0
);

// Layers will light up if layers are active
layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _QMK_L));
    return state;
}

void keyboard_post_init_user(void) {
	rgblight_enable_noeeprom();
	rgblight_sethsv_noeeprom(HSV_AZURE); // HSV_AZURE = (128, 102, 255)
	rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
	rgblight_step_noeeprom();

	// Enable the LED layers
    rgblight_layers = rgb_layers;
}
#endif

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
