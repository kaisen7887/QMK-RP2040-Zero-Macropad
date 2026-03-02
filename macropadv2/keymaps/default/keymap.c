// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_1,   KC_2,   KC_3,   KC_PGUP,
        KC_4,   KC_5,   KC_6,   KC_PGDN,    KC_MUTE,
        KC_7,   KC_8,   KC_9,   KC_DELETE,  TO(1),
        KC_Z,   KC_X, KC_C, KC_PRINT_SCREEN
    ),
    [1] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F10,
        KC_F4,   KC_F5,   KC_F6,   KC_F11,   KC_MUTE,
        KC_F7,   KC_F8,   KC_F9,   KC_F12,   TO(0),
        KC_MNXT,   KC_MPLY, KC_MPRV, KC_PRINT_SCREEN
    )
};
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
      return false; /* Don't process further events if user function exists and returns false */
    }
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
layer_state_t layer_state_set_user(layer_state_t state) {
    if(IS_LAYER_ON_STATE(state, 0)) { 
        rgblight_setrgb_at(255, 0, 0, 0);
    } else if(IS_LAYER_ON_STATE(state, 1)) { 
        rgblight_setrgb_at(255, 255, 0, 0);
    } else { 
        rgblight_setrgb_at(255, 255, 255, 0);
    } 
    return state; 
}