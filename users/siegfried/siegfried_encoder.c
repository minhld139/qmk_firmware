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

#include QMK_KEYBOARD_H

#include "siegfried.h"

#ifdef ENCODER_ENABLE
    static uint16_t key_timer;

    void encoder_action_volume(bool clockwise) {
        if (clockwise) {
            tap_code(KC_VOLU);
            if (timer_elapsed(key_timer) < 50) {
              tap_code(KC_VOLU); // if less than 50ms have passed, hit vol up again.
              key_timer = timer_read();
            } else {
              key_timer = timer_read();
              // do nothing if 50ms or more have passed
            }
        }
        else {
            tap_code(KC_VOLD);
            if (timer_elapsed(key_timer) < 100) {
              tap_code(KC_VOLD); // if less than 100ms have passed, hit vol down twice.
              key_timer = timer_read();
            } else {
              key_timer = timer_read();
              // do nothing if 100ms or more have passed
            }
        }
    }
	
    void encoder_action_mediatrack(bool clockwise) {
        if (clockwise)
            tap_code(KC_MEDIA_NEXT_TRACK);
        else
            tap_code(KC_MEDIA_PREV_TRACK);
    }

    void encoder_action_idle_timeout(bool clockwise) {
        if (clockwise)
            timeout_update_threshold(true);
        else 
            timeout_update_threshold(false);
    }

    void encoder_action_navpage(bool clockwise) {
        if (clockwise)
            tap_code16(KC_PGUP);
        else
            tap_code16(KC_PGDN);
    }

    #ifdef RGB_MATRIX_ENABLE
        void encoder_action_rgb_speed(bool clockwise) {
            if (clockwise)
                rgb_matrix_increase_speed_noeeprom();
            else
                rgb_matrix_decrease_speed_noeeprom();
        }
        void encoder_action_rgb_hue(bool clockwise) {
            if (clockwise)
                rgb_matrix_increase_hue_noeeprom();
            else
                rgb_matrix_decrease_hue_noeeprom();
        }
        void encoder_action_rgb_saturation(bool clockwise) {
            if (clockwise)
                rgb_matrix_increase_sat_noeeprom();
            else
                rgb_matrix_decrease_sat_noeeprom();
        }
        void encoder_action_rgb_brightness(bool clockwise) {
            if (clockwise)
                rgb_matrix_increase_val_noeeprom();
            else
                rgb_matrix_decrease_val_noeeprom();
        }
        void encoder_action_rgb_mode(bool clockwise) {
            if (clockwise)
                rgb_matrix_step_noeeprom();
            else
                rgb_matrix_step_reverse_noeeprom();
        }
    #elif defined(RGBLIGHT_ENABLE)
        void encoder_action_rgb_speed(bool clockwise) {
            if (clockwise)
                rgblight_increase_speed_noeeprom();
            else
                rgblight_decrease_speed_noeeprom();
        }
        void encoder_action_rgb_hue(bool clockwise) {
            if (clockwise)
                rgblight_increase_hue_noeeprom();
            else
                rgblight_decrease_hue_noeeprom();
        }
        void encoder_action_rgb_saturation(bool clockwise) {
            if (clockwise)
                rgblight_increase_sat_noeeprom();
            else
                rgblight_decrease_sat_noeeprom();
        }
        void encoder_action_rgb_brightness(bool clockwise) {
            if (clockwise)
                rgblight_increase_val_noeeprom();
            else
                rgblight_decrease_val_noeeprom();
        }
        void encoder_action_rgb_mode(bool clockwise) {
            if (clockwise)
                rgblight_step_noeeprom();
            else
                rgblight_step_reverse_noeeprom();
        }
    #endif // RGB_MATRIX_ENABLE || RGBLIGHT_ENABLE
#endif // ENCODER_ENABLE
