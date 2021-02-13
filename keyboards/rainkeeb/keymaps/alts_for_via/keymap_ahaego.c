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

// WPM-responsive animation stuff here. based on kyria keyboard
#define ANIM_FRAMES 6
#define ANIM_SIZE 64 // number of bytes in array, minimize for adequate firmware size, max is 1024

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_anim_frame = 0;

/* https://docs.splitkb.com/hc/en-us/articles/360013811280-How-do-I-convert-an-image-for-use-on-an-OLED-display- */
static void render_anim(void) {
    static const char PROGMEM anim0[ANIM_FRAMES][ANIM_SIZE] = {
        { // 'Face1', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //0
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //0
        },
        {// 'Face2', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //0
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //0
        },
        {// 'Face3', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //0
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //0
        }, //*/
        {// 'Face4', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //0
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //0
        },
        {// 'Face5', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x80, 0x84, 0x84, 0x04, 0x00, 0x00, 0x00, 0x00, //0
            0x00, 0x00, 0x00, 0x00, 0x04, 0x84, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //0
        },
        {// 'Face6', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, //0
            0x00, 0x00, 0x04, 0x04, 0x00, 0x88, 0x88, 0x80, 0x80, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00  //0
        }
    };
    static const char PROGMEM anim1[ANIM_FRAMES][ANIM_SIZE] = {
        { // 'Face1', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x08, 0x14, 0x0c, 0x1c, 0x0c, 0x04, 0x00, 0x00, 0x00, 0x00, //1
            0x00, 0x00, 0x00, 0x01, 0x07, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //1
        },
        {// 'Face2', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, //1
            0x00, 0x00, 0x00, 0x08, 0x06, 0x0e, 0x0c, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //1
        },
        {// 'Face3', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x04, 0x06, 0x00, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, //1
            0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x08, 0x18, 0x10, 0x20, 0x00, 0x00, 0x00, 0x00  //1
        }, //*/
        {// 'Face4', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x02, 0x1f, 0x3f, 0x3e, 0x1e, 0x00, 0x00, 0x00, 0x00, //1
            0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 0xf8, 0x38, 0xb0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00  //1
        },
        {// 'Face5', 128x32px
            0x00, 0x00, 0x08, 0x24, 0x06, 0x02, 0x02, 0x3a, 0x2e, 0x0e, 0x3c, 0x34, 0x00, 0x00, 0x00, 0x00, //1
            0x00, 0x00, 0x00, 0x00, 0x04, 0x3e, 0x0a, 0x0e, 0x3a, 0x32, 0x02, 0x02, 0x46, 0x1e, 0x04, 0x00  //1
        },
        {// 'Face6', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x02, 0x11, 0x03, 0x03, 0x17, 0x01, 0x01, 0x00, 0x00, 0x38, //1
            0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0b, 0x0b, 0x09, 0x01, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00  //1
        }
    };
    static const char PROGMEM anim2[ANIM_FRAMES][ANIM_SIZE] = {
        { // 'Face1', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x18, //2
            0x18, 0x18, 0x08, 0x18, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //2
        },
        {// 'Face2', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x07, 0x07, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, //2
            0x00, 0x00, 0x20, 0x20, 0x30, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //2
        },
        {// 'Face3', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0x78, 0x78, 0x78, //2
            0x78, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //2
        }, //*/
        {// 'Face4', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x70, 0x70, 0xc0, 0x00, //2
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //2
        },
        {// 'Face5', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xc0, //2
            0xc0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //2
        },
        {// 'Face6', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xf8, 0x30, 0xf8, 0xf8, 0xf8, //2
            0xf8, 0x78, 0x70, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //2
        }
    };
    static const char PROGMEM anim3[ANIM_FRAMES][ANIM_SIZE] = {
        { // 'Face1', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //3
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //3
        },
        {// 'Face2', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //3
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //3
        },
        {// 'Face3', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //3
            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //3
        }, //*/
        {// 'Face4', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //3
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //3
        },
        {// 'Face5', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //3
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //3
        },
        {// 'Face6', 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x0f, 0x31, 0x08, //3
            0x07, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //3
        }
    };

    void animation_phase(void) {
        current_anim_frame = (current_anim_frame + 1) % ANIM_FRAMES;
        oled_set_cursor(16,0);
        oled_write_raw_P(anim0[abs((ANIM_FRAMES-1)-current_anim_frame)], ANIM_SIZE);
        oled_set_cursor(16,1);
        oled_write_raw_P(anim1[abs((ANIM_FRAMES-1)-current_anim_frame)], ANIM_SIZE);
        oled_set_cursor(16,2);
        oled_write_raw_P(anim2[abs((ANIM_FRAMES-1)-current_anim_frame)], ANIM_SIZE);
        oled_set_cursor(16,3);
        oled_write_raw_P(anim3[abs((ANIM_FRAMES-1)-current_anim_frame)], ANIM_SIZE);
    }
    if(get_current_wpm() != 000) {
        oled_on(); // not essential but turns on animation OLED with any alpha keypress
        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
} //*/

bool oled_state = true;
char wpm[10];

void oled_task_user(void) {
    if (oled_state) {
        render_anim();
        oled_set_cursor(1,0);
        oled_write_P(PSTR("anime keeb"), false);
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
        }
        // Host Keyboard WPM
        sprintf(wpm, "WPM: %03d", get_current_wpm());
        oled_set_cursor(1,2);
        oled_write(wpm, false);
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
