#include QMK_KEYBOARD_H

enum {BASE};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS]={
[BASE]=LAYOUT(
 KC_1,KC_2,KC_3,
 KC_4,KC_5,KC_6,
 KC_7,KC_8,KC_9,
 KC_MUTE
)
};

bool encoder_update_user(uint8_t index,bool clockwise){
 if(index==0){
   tap_code(clockwise?KC_VOLU:KC_VOLD);
 }
 return false;
}

#ifdef OLED_ENABLE

bool oled_task_user(void) {
    oled_clear();

    oled_write_ln_P(PSTR("PAD IX"), false);
    oled_write_ln_P(PSTR("Layer: BASE"), false);
    oled_write_ln_P(PSTR("Encoder: Vol"), false);

    return false;
}

#endif