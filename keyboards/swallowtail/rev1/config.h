/*
Copyright 2019 e3w2q
Copyright 2021 takjn

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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x787b
#define DEVICE_VER      0x0001
#define MANUFACTURER    takjn
#define PRODUCT         Swallowtail
#define DESCRIPTION     Split keyboard with 60 keys

/* key matrix size */
#define MATRIX_ROWS 5*2 //master: 5 rows, slave: 5 rows
#define MATRIX_COLS 6

/*
 * Keyboard Matrix Assignments
*/
#define MATRIX_ROW_PINS { F7, B1, B3, B2, B6 }
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5 }
#define DIODE_DIRECTION COL2ROW

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D2

/*
 * Handedness by Pin
 * https://beta.docs.qmk.fm/using-qmk/hardware-features/feature_split_keyboard#handedness-by-pin
 */
#define SPLIT_HAND_PIN F6

#define RGB_DI_PIN D3
#ifdef RGB_MATRIX_ENABLE
    #define SPLIT_TRANSPORT_MIRROR
    #define DRIVER_LED_TOTAL 60
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_SPLIT { 30, 30 }
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
    #define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
#endif
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md
#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_SPLIT
  #define RGBLED_NUM 30
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 150 /* The maximum brightness level */
  #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
// /*== all animations enable ==*/
//   #define RGBLIGHT_ANIMATION
// /*== or choose animations ==*/
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD
//   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//   #define RGBLIGHT_EFFECT_SNAKE
  #define RGBLIGHT_EFFECT_KNIGHT
//   #define RGBLIGHT_EFFECT_CHRISTMAS
//   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
//   #define RGBLIGHT_EFFECT_RGB_TEST
//   #define RGBLIGHT_EFFECT_ALTERNATING
// /*== customize breathing effect ==*/
//   /*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
//   #define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
//   /*==== use exp() and sin() ====*/
//   #define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
//   #define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
