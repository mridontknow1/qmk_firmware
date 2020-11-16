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
#define _MAC_L		3	// Macro Definition Layer
#define _EMOJI_L	2	// Unicode Hex Emoji Layer
#define _QMK_L		4	// QMK Functions Layer

/* Create Macro Enum */
enum custom_keycodes {
    UD_1 = SAFE_RANGE,	//	<3 (User Defined 1)
	UD_2,				//	Merry Christmas! 
	UD_3,				//	Tell Han and Chewie that Dick loves them
	UD_F,				// 	F
	RGB_CONF,			//	Current RGB values, speed, and mode
	NOT_POS,			// 	WTF You can't hit this key!?!?!
	CMDCLEAR,			//	ctrl+'a', del
	CLOUD,  			//	(っ◕‿◕)っ
	FU,					//	t(-_-t)
	HAPPYFACE,			//	ʘ‿ʘ
	SHRUG,				//	¯\_(ツ)_/¯
	HEARTFACE,			//	♥‿♥
	DISFACE,			//	ಠ_ಠ
	TFLIP,				// 	(╯°□°)╯ ︵ ┻━┻
	TFLIP2,				//	┻━┻︵ \(°□°)/ ︵ ┻━┻
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base Layer
    * ,-----------------------.
	* |                       | |--------|
	* |           F           | | RGB L  |
	* |                       | |--------|
	* |-------+-------+-------| |<<<<<<<<|>>>>>>>>|
    * |  <3   | X Mas | PLAY  | |VOL D   |   VOL U|
    * |-------+-------+-------| |<<<<<<<<|>>>>>>>>|
    * |   7   |   8   | Chonk |
    * |-------+-------+-------|
    * |   4   |   5   |   6   |
    * |-------+-------+-------|
    * |   1   |   2   |   3   | 
    * `-----------------------'
    */
  [_BASE_L] = LAYOUT_ortho_3x5( /* Base */
	UD_F, 			TO(_RGB_L),		NOT_POS, 
	UD_1, 			UD_2, 			KC_MPLY, 
	KC_7, 			KC_8, 			UD_3, 
	KC_4, 			KC_5, 			KC_6, 
	KC_1, 			KC_2, 			KC_3
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
	RGB_CONF,		TO(_BASE_L),	_______, 
	RGB_RMOD, 		RGB_MOD, 		RGB_TOG, 
	RGB_SPD,		RGB_TOG, 		RGB_SPI, 
	RGB_SAD,		RGB_TOG, 		RGB_SAI, 
	RGB_VAD, 		MO(_QMK_L), 	RGB_VAI
  ),
  
/* Emoji Layer
   * ,-----------------------.
	* |                       | |--------|
	* |           F           | | BASE L |
	* |                       | |--------|
	* |-------+-------+-------| |<<<<<<<<|>>>>>>>>|
    * |  <3   | X Mas | PLAY  | |VOL D   |   VOL U|
    * |-------+-------+-------| |<<<<<<<<|>>>>>>>>|
    * | FLIP  | FLIP2 | Chonk |
    * |-------+-------+-------|
    * |SHRUG  |HRTFACE|DISFACE|
    * |-------+-------+-------|
    * | CLOUD |  FU   |HAPPYFC| 
    * `-----------------------'
    */
  [_EMOJI_L] = LAYOUT_ortho_3x5( /* Base */
	UD_F, 			TO(_RGB_L),		NOT_POS, 
	UD_1, 			UD_2, 			KC_MPLY, 
	TFLIP, 			TFLIP2, 		UD_3, 
	SHRUG, 			HEARTFACE, 		DISFACE, 
	CLOUD, 			FU, 			HAPPYFACE
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
	_______,		_______,		_______, 
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
		case UD_1:			//	<3
			if (record->event.pressed) { // when keycode is pressed
				SEND_STRING("<3");
			}
			return false;
			break;
		case UD_2:			//	Merry Christmas!
			if (record->event.pressed) { // when keycode is pressed
				SEND_STRING("Merry Christmas!");
			}
			return false;
			break;
		case UD_3:			//	Tell Han and Chewie that Dick loves them
			if (record->event.pressed) { // when keycode is pressed
				SEND_STRING("Tell Han and Chewie that Dick loves them");
			}
			return false;
			break;
		case UD_F:			// F
			if (record->event.pressed) { // when keycode is pressed
				SEND_STRING("F");
			}
			return false;
			break;
		case RGB_CONF:		//	Current RGB values, speed, and mode
			if (record->event.pressed) { // when keycode is pressed
				if (rgblight_is_enabled()) {
					char str[4];
					SEND_STRING("RGB: HSV(");
					sprintf(str, "%d", rgblight_get_hue());
					send_string(str);
					SEND_STRING(", ");
					sprintf(str, "%d", rgblight_get_sat());
					send_string(str);
					SEND_STRING(", ");
					sprintf(str, "%d", rgblight_get_val());
					send_string(str);
					SEND_STRING(") Mode(");
					sprintf(str, "%d", rgblight_get_mode());
					send_string(str);
					SEND_STRING(") Speed(");
					sprintf(str, "%d", rgblight_get_speed());
					send_string(str);
					SEND_STRING(")");
				}
				else {
					SEND_STRING("RGB Toggled OFF");
				}
			}
			return false;
			break;
		case NOT_POS:		//	WTF You can't hit this key!?!?!
			if (record->event.pressed) { // when keycode is pressed
				SEND_STRING("WTF You can't hit this key!?!?!");
			}
			return false;
			break;
		case CMDCLEAR:		//	ctrl+'a', del
			if (record->event.pressed) {
				SEND_STRING(SS_LCTL("a") SS_TAP(X_DEL));                 
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
				send_unicode_string("┻━┻︵ \(°□°)/ ︵ ┻━┻");
				//send_unicode_hex_string("253B 2501 253B FE35 0020 005C 0028 00B0 25A1 00B0 0029 002F 0020 FE35 0020 253B 2501 253B");
			}
			return false;
			break;
		}
    return true;
};

#ifdef RGBLIGHT_ENABLE
// Light all LEDs white when in Macro Definition Layer
const rgblight_segment_t PROGMEM mac_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_WHITE}
);

// Light all LEDs red when in QMK Functions Layer
const rgblight_segment_t PROGMEM qmk_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_RED}
);

// Define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    mac_layer,	// 0
	qmk_layer	// 1
);

// Layers will light up if layers are active
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _MAC_L));
	rgblight_set_layer_state(1, layer_state_cmp(state, _QMK_L));
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
