/* Copyright 2020 Regan Palmer
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
#include "rainkeeb.h"

enum layers {
    _BASE,
    _RAISE,
    _HIGH,
    _NUMPAD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0
                                              |<<<<<<<|>>>>>>>|
                                              |VOL DO | VOL UP|
                                              |<<<<<<<|>>>>>>>|
    * ,-----------------------------------------------------------------------------------------------.
    * |   Q   |   W   |   E   |   R   |   T   |---------------|   Y   |   U   |   I   |   O   |   P   |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |   A   |   S   |   D   |   F   |   G   |     pause     |   H   |   J   |   K   |   L   | ENTER |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |   Z   |   X   |   C   |   V   |   B   |     shift     |   N   |   M   |   ,   |   .   | Bksp  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |L Ctrl | L Gui | L Alt |  Shift/Space  |     MO(1)     |     Space     | R Alt | R Gui | R Ctrl|
    * `-----------------------------------------------------------------------------------------------'
    */
	[_BASE] = LAYOUT( /* Layer 0 */
		KC_Q, 		KC_W,   	KC_E, 		KC_R,		KC_T, 					KC_Y,		KC_U, 		KC_I,		KC_O,       KC_P,
		KC_A, 		KC_S,		KC_D, 		KC_F,		KC_G, 		KC_MPLY,	KC_H, 		KC_J,		KC_K, 		KC_L,		KC_ENT,
		KC_Z, 		KC_X,		KC_C, 		KC_V,		KC_B, 		OLED_TOG,	KC_N, 		KC_M,		KC_COMM, 	KC_DOT,		KC_BSPC,
		KC_LCTRL, 	KC_LGUI, 	KC_LALT,	SFT_T(KC_SPC),		MO(1),			    KC_SPC,	            KC_RALT,    KC_RGUI,    KC_RCTL
	),
/*		KC_Q, KC_E, KC_T, KC_U, KC_O,
		KC_W, KC_R, KC_Y, KC_I, KC_P,
		KC_A, KC_D, KC_G, KC_H, KC_K, KC_ENT,
		KC_S, KC_F, KC_MPLY, KC_J, KC_L,
		KC_Z, KC_C, KC_B, KC_N, KC_COMM, KC_BSPC,
		KC_X, KC_V, KC_LSFT, KC_M, KC_DOT,
		KC_LCTL, KC_LGUI, MO(1), KC_RGUI, KC_RCTL,
		KC_LALT, SFT_T(KC_SPC), KC_SPC, KC_RALT),*/

    /* Layer 1
                                              |<<<<<<<|>>>>>>>|
                                              |VOL DO | VOL UP|
                                              |<<<<<<<|>>>>>>>|
    * ,-----------------------------------------------------------------------------------------------.
    * |   1   |   2   |   3   |   4   |   5   |---------------|   6   |   7   |   8   |   9   |   0   |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  esc  |  `~   |  \|   |   up  |   -   |     _____     |   [   |   ]   |   ;   |   '   | _____ |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  Tab  | CAPS  |  left | down  | right |     MO(2)     |   =   |   /   | _____ | _____ | _____ |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | _____ | _____ | _____ |     _____     |     _____     |     _____     | _____ | _____ | _____ |
    * `-----------------------------------------------------------------------------------------------'
    */
	[_RAISE] = LAYOUT( /* Layer 1 */
		KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,
		KC_ESC,     KC_GRV,     KC_BSLS,    KC_UP,      KC_MINS,    KC_TRNS,    KC_LBRC,    KC_RBRC,    KC_SCLN,    KC_QUOT,    KC_TRNS,
		KC_TAB,     KC_CAPS,    KC_LEFT,    KC_DOWN,    KC_RGHT,    MO(2),      KC_EQL,     KC_SLSH,    KC_TRNS,    KC_TRNS,    KC_TRNS,
		KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,            KC_TRNS,        KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS
    ),

    /* Layer 2
                                              |<<<<<<<|>>>>>>>|
                                              |VOL DO | VOL UP|
                                              |<<<<<<<|>>>>>>>|
    * ,-----------------------------------------------------------------------------------------------.
    * |   F1  |   F2  |   F3  |   F4  |   F5  |---------------|   F6  |   F7  |   F8  |   F9  |  F10  |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * |  F11  |  F12  |  F13  |  F14  |  F15  |     _____     | Home  | PgDn  | PgUp  |  End  | _____ |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | Reset | _____ | _____ | _____ | _____ |     _____     |  Ins  |  Del  | _____ | _____ | _____ |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | TO(0) | TO(3) | OLED  |     _____     |     _____     |     _____     | _____ | _____ | _____ |
    * `-----------------------------------------------------------------------------------------------'
    */
	[_HIGH] = LAYOUT( /* Layer 2 */
		KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                  KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,
		KC_F11,     KC_F12,     KC_F13,     KC_F14,     KC_F15,     KC_TRNS,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_TRNS,
		RESET,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_INS,     KC_DEL,     KC_TRNS,    KC_TRNS,    KC_TRNS,
		TO(0),      TO(3),      OLED_TOG,       KC_TRNS,            KC_TRNS,        KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS
    ),

    /* Layer 3
                                              |<<<<<<<|>>>>>>>|
                                              |VOL DO | VOL UP|
                                              |<<<<<<<|>>>>>>>|
    * ,-----------------------------------------------------------------------------------------------.
    * | _____ | _____ | _____ | _____ | _____ |---------------| _____ | _____ | _____ | _____ | _____ |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | _____ | _____ | _____ | _____ | _____ |     _____     | _____ | _____ | _____ | _____ | _____ |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | _____ | _____ | _____ | _____ | _____ |     _____     | _____ | _____ | _____ | _____ | _____ |
    * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    * | _____ | _____ | _____ |     _____     |     _____     |     _____     | _____ | _____ | _____ |
    * `-----------------------------------------------------------------------------------------------'
    */
	[_NUMPAD] = LAYOUT( /* Layer 3 */
		KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
		KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
		KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
		KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,            KC_TRNS,        KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS
    )
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

// process_record_user was here

void encoder_update_user(uint8_t index, bool clockwise) {
	switch (get_highest_layer(layer_state)) {
        case _BASE:
             if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
            break;
        case _RAISE:
            if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
            break;
		case _HIGH:
			if (clockwise) {
            tap_code(KC_MS_WH_RIGHT);
        } else {
            tap_code(KC_MS_WH_LEFT);
        }
			break;
        case _NUMPAD:
             if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
            break;
        default:
             if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
            break;
    }
}

/* https://docs.splitkb.com/hc/en-us/articles/360013811280-How-do-I-convert-an-image-for-use-on-an-OLED-display- */
/* known bug, wait to be merged to master https://github.com/qmk/qmk_firmware/pull/10800 */
/*static void render_logo(void) {
  static const char PROGMEM rain_logo[] = {
    // 'rain', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x18, 0x18, 0x18, 0x08, 0x08, 0x0c, 0xfc, 0xfc, 0xfc, // 0
    0x04, 0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 0x07, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0
    0x00, 0x60, 0xe0, 0xe0, 0x20, 0x20, 0x20, 0x30, 0x30, 0x30, 0x30, 0x30, 0x10, 0xff, 0xff, 0xff, // 1
    0x18, 0x08, 0x88, 0x88, 0x8c, 0x8c, 0x0c, 0x0c, 0x0c, 0x0c, 0x04, 0x0e, 0xfe, 0xfc, 0xfc, 0x18, // 1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 1
    0x00, 0x00, 0xff, 0xff, 0xf0, 0x00, 0x01, 0x63, 0xe7, 0xc7, 0xc6, 0x00, 0x00, 0xff, 0xff, 0xff, // 2
    0x00, 0x00, 0x00, 0x41, 0x43, 0xc3, 0xe7, 0xc6, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x0f, 0x00, 0x00, // 2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 2
    0x00, 0x00, 0x03, 0x0f, 0x1f, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x07, 0x0f, 0x07, // 3
    0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0x18, 0x38, 0xf8, 0xfe, 0x7f, 0x1f, 0x03, 0x00, 0x00, 0x00, // 3
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 3
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 3
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 3
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 3
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 3
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  // 3
  };

  oled_write_raw_P(rain_logo, sizeof(rain_logo));
} //*/

//wait for bug fix (listed above)
static void render_logo_line0(void) {
    static const char PROGMEM rain0_logo[] = {
        // 'rain0, 32x8px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x18, 0x18, 0x18, 0x08, 0x08, 0x0c, 0xfc, 0xfc, 0xfc, // 0
    0x04, 0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 0x07, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  // 0
    };
    oled_set_cursor(16,0);
    oled_write_raw_P(rain0_logo, sizeof(rain0_logo));
}

static void render_logo_line1(void) {
    static const char PROGMEM rain1_logo[] = {
        // 'rain1', 32x8px
        0x00, 0x60, 0xe0, 0xe0, 0x20, 0x20, 0x20, 0x30, 0x30, 0x30, 0x30, 0x30, 0x10, 0xff, 0xff, 0xff, // 1
        0x18, 0x08, 0x88, 0x88, 0x8c, 0x8c, 0x0c, 0x0c, 0x0c, 0x0c, 0x04, 0x0e, 0xfe, 0xfc, 0xfc, 0x18  // 1
        };
    oled_set_cursor(16,1);
    oled_write_raw_P(rain1_logo, sizeof(rain1_logo));
}

static void render_logo_line2(void) {
    static const char PROGMEM rain2_logo[] = {
        // 'rain3', 32x8px
        0x00, 0x00, 0xff, 0xff, 0xf0, 0x00, 0x01, 0x63, 0xe7, 0xc7, 0xc6, 0x00, 0x00, 0xff, 0xff, 0xff, // 2
        0x00, 0x00, 0x00, 0x41, 0x43, 0xc3, 0xe7, 0xc6, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x0f, 0x00, 0x00  // 2
        };
    oled_set_cursor(16,2);
    oled_write_raw_P(rain2_logo, sizeof(rain2_logo));
}

static void render_logo_line3(void) {
    static const char PROGMEM rain3_logo[] = {
        // 'rain3, 32x8px
        0x00, 0x00, 0x03, 0x0f, 0x1f, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x07, 0x0f, 0x07, // 3
        0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0x18, 0x38, 0xf8, 0xfe, 0x7f, 0x1f, 0x03, 0x00, 0x00, 0x00  // 3
        };
    oled_set_cursor(16,3);
    oled_write_raw_P(rain3_logo, sizeof(rain3_logo));
} //*/

/*
//Setup some mask which can be or'd with bytes to turn off pixels
const uint8_t single_bit_masks[8] = {127, 191, 223, 239, 247, 251, 253, 254};

static void fade_display(void) {
    //Define the reader structure
    oled_buffer_reader_t reader;
    uint8_t buff_char;
    if (random() % 30 == 0) {
        srand(timer_read());
        // Fetch a pointer for the buffer byte at index 0. The return structure
        // will have the pointer and the number of bytes remaining from this
        // index position if we want to perform a sequential read by
        // incrementing the buffer pointer
        reader = oled_read_raw(0);
        //Loop over the remaining buffer and erase pixels as we go
        for (uint16_t i = 0; i < reader.remaining_element_count; i++) {
            //Get the actual byte in the buffer by dereferencing the pointer
            buff_char = *reader.current_element;
            if (buff_char != 0) {
                oled_write_raw_byte(buff_char & single_bit_masks[rand() % 8], i);
            }
            //increment the pointer to fetch a new byte during the next loop
            reader.current_element++;
        }
    }
} //*/

bool oled_state = true;
char wpm[10];

void oled_task_user(void) {
    if (oled_state) {
        //render_logo();
// start comment here
        oled_set_cursor(7,0);
        oled_write_P(PSTR("rainkeeb"), false);
        render_logo_line0();
        oled_set_cursor(1,1);
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state)) {
            case 0:
                oled_write_P(PSTR("Base  "), false);
                break;
            case 1:
                oled_write_P(PSTR("Raise "), false);
                break;
            case 2:
                oled_write_P(PSTR("High  "), false);
                break;
            case 3:
                oled_write_P(PSTR("Numpad"), false);
                break;
            default:
                oled_write_P(PSTR("Undef "), false);
        }
        render_logo_line1();
        // Host Keyboard WPM
        sprintf(wpm, "WPM: %03d", get_current_wpm());
        oled_set_cursor(1,2);
        oled_write(wpm, false);
        render_logo_line2();
        render_logo_line3();
//*/

        //fade_display();

    } else {
        oled_off();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
		case OLED_TOG:			//	Turn OLED On or Off
			if (record->event.pressed) { // when keycode is pressed
				if (oled_state) {
                    oled_state = false;
                } else {
                    oled_state = true;
                }
			}
			return false;
			break;
    }
	return true;
}
