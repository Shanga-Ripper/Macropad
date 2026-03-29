#include QMK_KEYBOARD_H
#include <stdio.h>

static bool    is_muted    = false;
static uint8_t volume_pct  = 50;   

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        C(KC_LEFT), C(KC_RIGHT), KC_MUTE
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// ... [Keep your existing animation logic here] ...

bool oled_task_user(void) {
    // This ensures all variables are used and the OLED updates
    if (is_muted) {
        oled_set_cursor(0,0); oled_write_P(PSTR("MUTE"), false);
    } else {
        // Your render_volume() logic here
    }
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    switch (keycode) {
        case KC_MUTE:
            is_muted = !is_muted;
            return true;
        case KC_VOLU:
            if (volume_pct < 100) volume_pct += 5;
            return true;
        case KC_VOLD:
            if (volume_pct > 0) volume_pct -= 5;
            return true;
    }
    return true;
}