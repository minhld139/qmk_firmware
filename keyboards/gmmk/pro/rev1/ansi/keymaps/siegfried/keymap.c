/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
   Copyright 2021 Jonavin Eng @Jonavin
   Copyright 2022 gourdo1 <gourdo1@outlook.com>
   Copyright 2023 minhld <minhld139@gmail.com>

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

// Note: Many advanced functions referenced in this file are defined in /users/gourdo1/gourdo1.c
#include QMK_KEYBOARD_H

#include "rgb_matrix_map.h"

#include "siegfried.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	  [_WIN] = LAYOUT (
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,  KC_F4,  KC_F5,  KC_F6,   KC_F7,  KC_F8,  KC_F9,    KC_F10,   KC_F11,       KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,   KC_4,   KC_5,   KC_6,    KC_7,   KC_8,   KC_9,     KC_0,     KC_MINS,      KC_EQL,   KC_BSPC,            KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,   KC_R,   KC_T,   KC_Y,    KC_U,   KC_I,   KC_O,     KC_P,     KC_LBRC,      KC_RBRC,  KC_BSLS,            KC_END,
        KC_CAPS,  KC_A,     KC_S,     KC_D,   KC_F,   KC_G,   KC_H,    KC_J,   KC_K,   KC_L,     KC_SCLN,  KC_QUOT,                KC_ENT,             KC_PGUP,
        KC_LSFT,            KC_Z,     KC_X,   KC_C,   KC_V,   KC_B,    KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,                KC_RSFT,  KC_UP,    KC_PGDN,
        KC_LCTL,  KC_LGUI,  KC_LALT,                          KC_SPC,                            KC_RALT,  MO(_WIN_FN),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),
	  [_WIN_FN] = LAYOUT (
        EE_CLR,   _______,  _______,   _______,  KC_CALC,  KC_MPLY,  KC_MPRV,  KC_MNXT,  KC_MSTP,  _______,  _______,  _______,  KC_PSCR,  KC_F13,              KC_MPLY,
        _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_TOD,  RGB_TOI,  KC_INS,              _______,
        _______,  RGB_SAD,  RGB_VAI,   RGB_SAI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  QK_BOOT,             TO(_WIN),
        _______,  RGB_HUD,  RGB_VAD,   RGB_HUI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,             TO(_OSX),
        _______,            RGB_NITE,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  WDESK_L,  WDESK_R,  _______,            _______,  RGB_MOD,   _______,
        _______,  WINLOCK,  _______,                                 _______,                                _______,  _______,  _______,  RGB_SPD,  RGB_RMOD,  RGB_SPI
    ),
	  [_OSX] = LAYOUT (
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,  KC_F4,  KC_F5,  KC_F6,   KC_F7,  KC_F8,  KC_F9,    KC_F10,   KC_F11,       KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,   KC_4,   KC_5,   KC_6,    KC_7,   KC_8,   KC_9,     KC_0,     KC_MINS,      KC_EQL,   KC_BSPC,            KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,   KC_R,   KC_T,   KC_Y,    KC_U,   KC_I,   KC_O,     KC_P,     KC_LBRC,      KC_RBRC,  KC_BSLS,            KC_END,
        KC_CAPS,  KC_A,     KC_S,     KC_D,   KC_F,   KC_G,   KC_H,    KC_J,   KC_K,   KC_L,     KC_SCLN,  KC_QUOT,                KC_ENT,             KC_PGUP,
        KC_LSFT,            KC_Z,     KC_X,   KC_C,   KC_V,   KC_B,    KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,                KC_RSFT,  KC_UP,    KC_PGDN,
        KC_LCTL,  KC_LALT,  KC_LGUI,                          KC_SPC,                            KC_RALT,  MO(_OSX_FN),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),
	  [_OSX_FN] = LAYOUT (
        EE_CLR,   KC_BRID,  KC_BRIU,   KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  _______,  _______,  KC_MRWD,  KC_MPLY,  KC_MFFD,  _______,  KC_EJCT,             KC_MPLY,
        _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_TOD,  RGB_TOI,  KC_INS,              _______,
        _______,  RGB_SAD,  RGB_VAI,   RGB_SAI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  QK_BOOT,             TO(_WIN),
        _______,  RGB_HUD,  RGB_VAD,   RGB_HUI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,             TO(_OSX),
        _______,            RGB_NITE,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  MDESK_L,  MDESK_R,  _______,            _______,  RGB_MOD,   _______,
        _______,  _______,  _______,                                 _______,                                _______,  _______,  _______,  RGB_SPD,  RGB_RMOD,  RGB_SPI
    )
};

#if defined(ENCODER_ENABLE) && !defined(ENCODER_DEFAULTACTIONS_ENABLE) // Encoder Functionality when not using userspace defaults
    bool encoder_update_user(uint8_t index, bool clockwise) {
        uint8_t mods_state = get_mods();
        switch (get_highest_layer(layer_state)) {
        case _WIN:
        case _OSX:
            encoder_action_volume(clockwise);
            break;
        case _WIN_FN:
        case _OSX_FN:
            if (mods_state & MOD_BIT(KC_RSFT)) { // if holding Right Shift, change idle timeout
                encoder_action_idle_timeout(clockwise);
            } else if (mods_state & MOD_BIT(KC_RCTL)) {
                encoder_action_rgb_brightness(clockwise);
            } else if (mods_state & MOD_BIT(KC_RALT)) {
                encoder_action_rgb_hue(clockwise);
            } else {
                encoder_action_mediatrack(clockwise);
            }
            break;
        }
        return false;
    }
#endif // ENCODER_ENABLE && !ENCODER_DEFAULTACTIONS_ENABLE


#ifdef RGB_MATRIX_ENABLE

// Capslock, Scroll lock and Numlock indicator on Left side lights.
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_rgb_nightmode()) rgb_matrix_set_color_all(RGB_OFF);

    led_t led_state = host_keyboard_led_state();

    // CapsLock RGB setup
    if (led_state.caps_lock) {
        rgb_matrix_set_color(LED_L5, RGB_RED);
        rgb_matrix_set_color(LED_L6, RGB_RED);
        rgb_matrix_set_color(LED_CAPS, RGB_RED);
        rgb_matrix_set_color(LED_R5, RGB_RED);
        rgb_matrix_set_color(LED_R6, RGB_RED);
    }

    // Winkey disabled (gaming) mode RGB setup
    if (keymap_config.no_gui) {
        rgb_matrix_set_color(LED_LWIN, RGB_RED); //light up Winkey red when disabled
        rgb_matrix_set_color(LED_W, RGB_CHARTREUSE); //light up gaming keys with WSAD higlighted
        rgb_matrix_set_color(LED_S, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_A, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_D, RGB_CHARTREUSE);
        rgb_matrix_set_color(LED_Q, RGB_ORANGE2);
        rgb_matrix_set_color(LED_E, RGB_ORANGE2);
        rgb_matrix_set_color(LED_R, RGB_ORANGE2);
        rgb_matrix_set_color(LED_TAB, RGB_ORANGE2);
        rgb_matrix_set_color(LED_F, RGB_ORANGE2);
        rgb_matrix_set_color(LED_Z, RGB_ORANGE2);
        rgb_matrix_set_color(LED_X, RGB_ORANGE2);
        rgb_matrix_set_color(LED_C, RGB_ORANGE2);
        rgb_matrix_set_color(LED_V, RGB_ORANGE2);
        rgb_matrix_set_color(LED_SPC, RGB_ORANGE2);
        rgb_matrix_set_color(LED_LCTL, RGB_ORANGE2);
        rgb_matrix_set_color(LED_LSFT, RGB_ORANGE2);
    }

    // Fn selector mode RGB setup
    switch (get_highest_layer(layer_state)) {      // special handling per layer
        case _WIN_FN:                                 // on Fn layer
        case _OSX_FN:                                 // on Fn layer
            rgb_matrix_set_color(LED_FN, RGB_RED); // FN key

            // NEW RGB LIGHTING TO RING KEYBOARD ON FN LAYER ACTIVATION:
            for (uint8_t j = 0; j < ARRAY_SIZE(LED_LIST_FUNCROW); j++) {
                rgb_matrix_set_color(LED_LIST_FUNCROW[j], RGB_RED);
            }
            rgb_matrix_set_color(LED_LCTL, RGB_RED);
            rgb_matrix_set_color(LED_LALT, RGB_RED);
            rgb_matrix_set_color(LED_SPC, RGB_RED);
            rgb_matrix_set_color(LED_LWIN, RGB_RED);
            rgb_matrix_set_color(LED_RALT, RGB_RED);
            rgb_matrix_set_color(LED_FN, RGB_OFFBLUE);
            rgb_matrix_set_color(LED_RCTL, RGB_RED);
            rgb_matrix_set_color(LED_BSLS, RGB_RED);
            rgb_matrix_set_color(LED_L1, RGB_RED);
            rgb_matrix_set_color(LED_L2, RGB_RED);
            rgb_matrix_set_color(LED_L3, RGB_RED);
            rgb_matrix_set_color(LED_L4, RGB_RED);
            rgb_matrix_set_color(LED_L5, RGB_RED);
            rgb_matrix_set_color(LED_L6, RGB_RED);
            rgb_matrix_set_color(LED_L7, RGB_RED);
            rgb_matrix_set_color(LED_L8, RGB_RED);
            rgb_matrix_set_color(LED_R1, RGB_RED);
            rgb_matrix_set_color(LED_R2, RGB_RED);
            rgb_matrix_set_color(LED_R3, RGB_RED);
            rgb_matrix_set_color(LED_R4, RGB_RED);
            rgb_matrix_set_color(LED_R5, RGB_RED);
            rgb_matrix_set_color(LED_R6, RGB_RED);
            rgb_matrix_set_color(LED_R7, RGB_RED);
            rgb_matrix_set_color(LED_R8, RGB_RED);
            rgb_matrix_set_color(LED_MINS, RGB_OFFBLUE);
            rgb_matrix_set_color(LED_EQL, RGB_OFFBLUE);


            // RGB control
            rgb_matrix_set_color(LED_UP, RGB_CYAN);
            rgb_matrix_set_color(LED_DOWN, RGB_CYAN);
            rgb_matrix_set_color(LED_LEFT, RGB_CYAN);
            rgb_matrix_set_color(LED_RIGHT, RGB_CYAN);
            rgb_matrix_set_color(LED_W, RGB_CYAN);
            rgb_matrix_set_color(LED_S, RGB_CYAN);
            rgb_matrix_set_color(LED_A, RGB_CYAN);
            rgb_matrix_set_color(LED_D, RGB_CYAN);
            rgb_matrix_set_color(LED_Q, RGB_CYAN);
            rgb_matrix_set_color(LED_E, RGB_CYAN);
            rgb_matrix_set_color(LED_Z, RGB_CYAN);


            // Add RGB Timeout Indicator -- shows 0 to 139 using F row and num row; larger numbers using 16bit code
            uint16_t timeout_threshold = get_timeout_threshold();
            if (timeout_threshold <= 10)
                rgb_matrix_set_color(LED_LIST_FUNCROW[timeout_threshold], RGB_BLUE);
            else if (timeout_threshold < 140) {
                rgb_matrix_set_color(LED_LIST_FUNCROW[(timeout_threshold / 10)], RGB_CYAN);
                rgb_matrix_set_color(LED_LIST_FUNCROW[(timeout_threshold % 10)], RGB_BLUE);
            } else { // >= 140 minutes, just show these 3 lights
                rgb_matrix_set_color(LED_LIST_FUNCROW[10], RGB_CYAN);
                rgb_matrix_set_color(LED_LIST_FUNCROW[11], RGB_CYAN);
                rgb_matrix_set_color(LED_LIST_FUNCROW[12], RGB_CYAN);
            }

            // NKRO indicator
            if (keymap_config.nkro) {
                rgb_matrix_set_color(LED_N, RGB_GREEN); // FN key
            } else {
                rgb_matrix_set_color(LED_N, RGB_RED); // FN key
            }

            break;  // on FN layer
    }
    return false;
}
#endif // RGB_MATRIX_ENABLE
