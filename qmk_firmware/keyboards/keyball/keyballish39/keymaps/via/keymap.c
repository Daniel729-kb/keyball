/* VIA keymap with one-time EEPROM handedness setters */

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "eeconfig.h"

enum custom_keycodes {
    HAND_LEFT = SAFE_RANGE,
    HAND_RIGHT,
};

// Reuse the same layout/keymap content from keyball39 via
#include "keyboards/keyball/keyball39/keymaps/via/keymap.c"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    switch (keycode) {
        case HAND_LEFT:
            eeconfig_update_handedness(true);
            reset_keyboard();
            return false;
        case HAND_RIGHT:
            eeconfig_update_handedness(false);
            reset_keyboard();
            return false;
    }
    return true;
}


