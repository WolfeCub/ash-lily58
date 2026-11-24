/* Copyright 2020 Josef Adamcik
 * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
 * Modification for Vial support by Drew Petersen
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

// clang-format off

#pragma once

// Handedness comes from SPLIT_HAND_PIN (GP4) in the keyboard-level config.h.

// Sync WPM from the master (USB) half to the other half, which draws the bongo cat
#define SPLIT_WPM_ENABLE

// Mirror the master's OLED on/off state (timeout + USB suspend) to the other half
#define SPLIT_OLED_ENABLE

// Turn the OLEDs off after 60s without input (QMK default, made explicit)
#define OLED_TIMEOUT 60000

// Turn the RGB off after 10 min without input while the host is awake
#define RGB_MATRIX_TIMEOUT 600000

// Sync the master's last-activity timestamps to the other half so its
// RGB timeout counts keypresses on both halves
#define SPLIT_ACTIVITY_ENABLE

// Double-tap the reset switch to enter the bootloader
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET

// Vial Support
#define VIAL_KEYBOARD_UID { 0x8F, 0xB8, 0x47, 0xEA, 0xA3, 0x5A, 0x5B, 0xDB }
#define DYNAMIC_KEYMAP_LAYER_COUNT 8
#define VIAL_COMBO_ENTRIES 64
#define VIAL_KEY_OVERRIDE_ENTRIES 64
#define VIAL_TAP_DANCE_ENTRIES 64
#define DYNAMIC_KEYMAP_MACRO_COUNT 32

#define DYNAMIC_KEYMAP_MACRO_EEPROM_SIZE 20480

// #define VIALRGB_NO_DIRECT