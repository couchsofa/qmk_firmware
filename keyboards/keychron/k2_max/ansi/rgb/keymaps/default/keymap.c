/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

enum custom_keycodes {
    LANG_DE = SAFE_RANGE,
    LANG_GR,
    SZ,
    CAP_SZ,
    EURO,
};

enum layers {
    BASE,
    FN,
    L_UMLAUT,
    L_GREEK,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ansi_84(
     KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_SNAP,  KC_DEL,   RGB_MOD,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     LANG_DE,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            LANG_GR,  KC_UP,    KC_END,
     KC_LCTL,  KC_LCMMD, KC_LALT,                               KC_SPC,                                 KC_RALT,   MO(FN),   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[FN] = LAYOUT_ansi_84(
     _______,  KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  RGB_TOG,     
     _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
     _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______),

[L_UMLAUT] = LAYOUT_ansi_84(
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     _______,  _______,  _______,  EURO,     _______,  _______,  _______,  KC_LBRC,  _______,  KC_SCLN,  _______,  _______,  _______,  _______,            _______,
     _______,  KC_QUOT,  SZ,       CAP_SZ,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
     _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______),

[L_GREEK] = LAYOUT_ansi_84(
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     _______,  _______,  KC_V,     _______,  _______,  _______,  KC_G,     KC_Y,     _______,  KC_U,     _______,  _______,  _______,  _______,            _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
     _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______)
};

/* Setup windows for language switching:
 * Setttings -> Time & langaue -> Typing -> Advanced -> Input language hotkeys
 * EN (US) LAlt + Shift + 0
 * DE      LAlt + Shift + 1
 * GR      LAlt + Shift + 2
 *
 * English should be the default language matching the keyboard layout.
 */

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    case LANG_DE:
        if (record->event.pressed) { // press

            // Switch language to DE, activate Umlaut-layer
            SEND_STRING(SS_LALT(SS_LSFT("1")));
            layer_on(L_UMLAUT);

        } else { // release

            // Reset language to EN, deactivate Umlaut-layer
            SEND_STRING(SS_LALT(SS_LSFT("0")));
            layer_off(L_UMLAUT);
        }
        break;

     case LANG_GR:
        if (record->event.pressed) { // press

            // Switch language to GR, activate Umlaut-layer
            SEND_STRING(SS_LALT(SS_LSFT("2")));
            layer_on(L_GREEK);

        } else { // release

            // Reset language to EN, deactivate Umlaut-layer
            SEND_STRING(SS_LALT(SS_LSFT("0")));
            layer_off(L_GREEK);
        }
        break;

     case SZ:
        if (record->event.pressed) {

            SEND_STRING("-");
            //layer_off(L_UMLAUT);

        }
        break;

      case CAP_SZ:
        if (record->event.pressed) {

            SEND_STRING(SS_RALT(SS_LSFT("-")));
            //layer_off(L_UMLAUT);

        }
        break;

     case EURO:
        if (record->event.pressed) {

            SEND_STRING(SS_RALT("e"));
            //layer_off(L_UMLAUT);

        }
        break;
    }

    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}
/*
// Key overrides for the german capital esszett
const key_override_t capital_esszett = ko_make_with_layers(MOD_MASK_SHIFT, KC_S, CAP_SZ, 1 << L_UMLAUT);

const key_override_t **key_overrides = (const key_override_t *[]){
     &capital_esszett,
     NULL
};
*/
