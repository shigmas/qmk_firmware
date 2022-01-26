/* Copyright 2019 e3w2q
 * Copyright 2021 takjn
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

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  ADJUST = SAFE_RANGE,
  RGB_RST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* Base */
    KC_GESC,          KC_1,               KC_2,             KC_3,             KC_4,               KC_5,
    KC_TAB,           KC_Q,               KC_W,             KC_E,             KC_R,               KC_T,
    KC_GRV,           KC_A,               KC_S,             KC_D,             KC_F,               KC_G,
    LSFT_T(KC_QUOT),  KC_Z,               KC_X,             KC_C,             KC_V,               KC_B,
    ADJUST,           KC_LGUI,            KC_LALT,          LT(_LOWER,KC_MINS), KC_LCTRL,        KC_ENT,

    KC_6,             KC_7,               KC_8,             KC_9,             KC_0,               KC_BSLS,
    KC_Y,             KC_U,               KC_I,             KC_O,             KC_P,               KC_BSPC,
    KC_H,             KC_J,               KC_K,             KC_L,             KC_SCLN,            KC_QUOT,
    KC_N,             KC_M,               KC_COMM,          KC_DOT,           RSFT_T(KC_SLSH),    KC_RSFT,
    KC_SPC,           RALT_T(KC_RBRC),    LT(_RAISE,KC_EQL),KC_CAPSLOCK,      KC__VOLUP,          KC__VOLDOWN
  ),
  [_LOWER] = LAYOUT(
    KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,
    _______,  KC_EQL,   KC_MINS,  KC_PLUS,  KC_LCBR,  KC_RCBR,
    _______,  _______,  _______,  _______,  _______,  _______,

    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_DEL,
    _______,  _______,  _______,  KC_F11,   KC_F12,   _______,
    KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
    KC_LBRC,  KC_RBRC,  KC_LCBR,  KC_RCBR,  KC_BSLS,  _______,
    _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_END
  ),
  [_RAISE] = LAYOUT(
    KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,
    _______,  KC_INS,   KC_PSCR,  KC_APP,   _______,  _______,
    _______,  KC_LALT,  KC_LCTL,  KC_LSFT,  _______,  KC_CAPS,
    _______,  KC_EQL,   KC_MINS,  KC_PLUS,  KC_PASTE, _______,
    _______,  _______,  _______,  _______,  _______,  _______,

    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_DEL,
    KC_PGUP,  _______,  KC_UP,    _______,  _______,  KC_DEL,
    KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_DEL,   KC_BSPC,
    _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGUP,  _______,
    _______,  _______,  _______,  _______,  _______,  _______
  ),
  [_ADJUST] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,
    _______,  RGB_TOG,  RGB_MOD,  RGB_RST,  _______,  _______,
    _______,  RGB_HUI,  RGB_SAI,  RGB_VAI,  _______,  _______,
    _______,  RGB_HUD,  RGB_SAD,  RGB_VAD,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,

    _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_LOWER);
        layer_on(_RAISE);
      } else {
        layer_off(_LOWER);
        layer_off(_RAISE);
      }
      break;
    case RGB_RST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
  }
  return true;
}

#ifdef OLED_ENABLE
void render_status(void) {

    // Render OS icon
    static const char os_logo[][2][3] PROGMEM  ={
        {{0x95,0x96,0},{0xb5,0xb6,0}},
        {{0x97,0x98,0},{0xb7,0xb8,0}},
        {{0x99,0x9a,0},{0xb9,0xba,0}},
        {{0x9b,0x9c,0},{0xbb,0xbc,0}},
        {{0x9d,0x9e,0},{0xbd,0xbe,0}},
    };
    oled_write_P(os_logo[4][0], false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(os_logo[4][1], false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR(" Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
    }

    oled_write_P(PSTR("\n"), false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(qmk_logo, false);
}

static void render_rgbled_status(bool full) {
#ifdef RGBLIGHT_ENABLE
  if (RGBLIGHT_MODES > 1 && rgblight_is_enabled()) {
      char buf[30];
      if (full) {
          snprintf(buf, sizeof(buf), "LED %2d: %d,%d,%d ",
                   rgblight_get_mode(),
                   rgblight_get_hue()/RGBLIGHT_HUE_STEP,
                   rgblight_get_sat()/RGBLIGHT_SAT_STEP,
                   rgblight_get_val()/RGBLIGHT_VAL_STEP);
      } else {
          snprintf(buf, sizeof(buf), "[%2d] ", rgblight_get_mode());
      }
      oled_write(buf, false);
  } else {
    oled_write_P(PSTR("\n"), false);
  }
#endif
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

void oled_task_user(void) {
  if(is_keyboard_master()){
    render_status();
  }else{
    render_logo();
    render_rgbled_status(true);
  }
}
#endif

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {{
// Left
    { 5, 4, 3, 2, 1, 0},
    { 6, 7, 8, 9,10,11},
    {17,16,15,14,13,12},
    {18,19,20,21,22,23},
    {29,28,27,26,25,24},
// Right
    {35,34,33,32,31,30},
    {36,37,38,39,40,41},
    {47,46,45,44,43,42},
    {48,49,50,51,52,53},
    {59,58,57,56,55,54}
}, {
// Left
    {102,0},{81,0},{61,0},{41,0},{20,0},{0,0},
    {0,16},{20,16},{41,16},{61,16},{81,16},{102,16},
    {102,32},{81,32},{61,32},{41,32},{20,32},{0,32},
    {0,48},{20,48},{41,48},{61,48},{81,48},{102,48},
    {102,64},{81,64},{61,64},{41,64},{20,64},{0,64},
// Right
    {122, 0},{143, 0},{163, 0},{183, 0},{204, 0},{224, 0},
    {224,16},{204,16},{183,16},{163,16},{143,16},{122,16},
    {122,32},{143,32},{163,32},{183,32},{204,32},{224,32},
    {224,48},{204,48},{183,48},{163,48},{143,48},{122,48},
    {122,64},{143,64},{163,64},{183,64},{204,64},{224,64}
}, {
// Left
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
// Right
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4
} };
#endif
