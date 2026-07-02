// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * ┌───┬───┬───┐
     * │ 1 │ 2 │ 3 │
     * ├───┼───┼───┤
     * │ 4 │ 5 │ 6 │
     * ├───┼───┼───┤
     * │ 7 │ 8 │ 9 │
     * ├───┘
     * │ M │  (Encoder Push)
     * └───┘
     */
    [0] = LAYOUT(
        KC_1, KC_2, KC_3,
        KC_4, KC_5, KC_6,
        KC_7, KC_8, KC_9,
        KC_MUTE
    )
};

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}

#endif

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

bool oled_task_user(void) {

    oled_clear();

    oled_write_ln_P(PSTR(" PAD IX"), false);
    oled_write_ln_P(PSTR("--------"), false);

    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("BASE"), false);
            break;

        default:
            oled_write_ln_P(PSTR("OTHER"), false);
            break;
    }

    led_t led_state = host_keyboard_led_state();

    oled_write_P(PSTR("Caps: "), false);
    oled_write_ln_P(
        led_state.caps_lock ? PSTR("ON") : PSTR("OFF"),
        false
    );

    oled_write_P(PSTR("Num : "), false);
    oled_write_ln_P(
        led_state.num_lock ? PSTR("ON") : PSTR("OFF"),
        false
    );

    return false;
}

#endif