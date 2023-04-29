/* Copyright 2021 Jonavin Eng @Jonavin
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

#pragma once


// LAYERS -- Note: to avoid compile problems, make sure total layers matches DYNAMIC_KEYMAP_LAYER_COUNT defined in config.h (where _COLEMAK layer is defined)
enum custom_user_layers {
    _WIN,
    _WIN_FN,
    _OSX,
    _OSX_FN,
};


// Windows
#define SWAP_L SGUI(KC_LEFT)                // Swap application to left display
#define SWAP_R SGUI(KC_RGHT)                // Swap application to right display
#define WDESK_L C(G(KC_LEFT))                // Switch to left virtual desktop
#define WDESK_R C(G(KC_RIGHT))               // Switch to right virtual desktop

// OSX
#define MDESK_L C(KC_LEFT)
#define MDESK_R C(KC_RIGHT)


// KEYCODES
enum custom_user_keycodes {
    KC_00 = SAFE_RANGE,
    RGB_TOI,        // Timeout idle time up
    RGB_TOD,        // Timeout idle time down
    RGB_NITE,       // Disables RGB backlighting effects but allows RGB indicators to still work
    // Windows
    WINLOCK,        // Toggles Windows key on and off

    TG_PAD,         // Toggles RGB highlighting of keys on numpad+mousekeys layer

    EMO_SHRUG,      // `\_("/)_/`
    EMO_CONFUSE,    // (*_*)
    EMO_SAD,        // :'-(
    EMO_NERVOUS,    // (~_~;)
    EMO_JOY,        // (^o^)
    EMO_TEARS,      // (T_T)

    NEW_SAFE_RANGE  // New safe range for keymap level custom keycodes
};


#ifdef RGB_MATRIX_ENABLE
void activate_rgb_nightmode(bool turn_on);
bool get_rgb_nightmode(void);
#endif


// IDLE TIMEOUTS
#ifdef IDLE_TIMEOUT_ENABLE
    #define TIMEOUT_THRESHOLD_DEFAULT 5 // default timeout minutes
    #define TIMEOUT_THRESHOLD_MAX 30 // upper limits (2 hours and 10 minutes -- no rgb indicators above this value)

    //prototype functions
    uint16_t get_timeout_threshold(void);
    void timeout_reset_timer(void);
    void timeout_update_threshold(bool increase);
    void timeout_tick_timer(void);
#endif //IDLE_TIMEOUT_ENABLE


// ENCODER ACTIONS
#ifdef ENCODER_ENABLE
    void encoder_action_volume(bool clockwise);
    void encoder_action_mediatrack(bool clockwise);
    void encoder_action_idle_timeout(bool clockwise);
    void encoder_action_navpage(bool clockwise);

    uint8_t get_selected_layer(void);
    void encoder_action_layerchange(bool clockwise);

    #if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
        void encoder_action_rgb_speed(bool clockwise);
        void encoder_action_rgb_hue(bool clockwise);
        void encoder_action_rgb_saturation(bool clockwise);
        void encoder_action_rgb_brightness(bool clockwise);
        void encoder_action_rgb_mode(bool clockwise);
    #endif // RGB_MATRIX_ENABLE / RGBLIGHT_ENABLE
#endif // ENCODER_ENABLE

