#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x5246
#define PRODUCT_ID      0x4253
#define DEVICE_VER      0x0001
#define MANUFACTURER    Dick
#define PRODUCT         BigSwitchPad
#define DESCRIPTION     Keyboard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 3

/* key matrix pins */
#define MATRIX_ROW_PINS { D1, D0, D4, C6, D7 }
#define MATRIX_COL_PINS { E6, B4, B5 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* encoder pins (A clockwise, B counterclock)*/
#define ENCODERS_PAD_A { B3 }
#define ENCODERS_PAD_B { B2 }
//#define ENCODER_RESOLUTION 2

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* allow unicode text in windows */
/* Can convert unicode in Hex/UTF-32 Secion of:
https://r12a.github.io/app-conversion/ */
/*Need to run the following command in command prompt with admin priveleges:
reg add "HKCU\Control Panel\Input Method" -v EnableHexNumpad -t REG_SZ -d 1
*/
#define UNICODE_SELECTED_MODES UC_WIN
/* Modified UNICODE_TYPE_DELAY in
\qmk_firmware\quantum\process_keycode\process_unicode_common.h
from 10ms to 1ms */

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

#define RGB_DI_PIN B6
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 10
#define RGBLIGHT_VAL_STEP 10
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#endif

#endif
