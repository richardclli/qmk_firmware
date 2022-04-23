/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

#pragma once

/* USB Device descriptor parameter */
#define PRODUCT_ID 0x0120
#define DEVICE_VER 0x0100

/* key matrix pins */
#define MATRIX_ROW_PINS { B5, B4, B3, A15, A14, A13 }
#define MATRIX_COL_PINS { C14, C15, A0, A1, A2, A3, A4, A5, A6, A7, B0, B1, A8, A9, A10, H3 }

/* We uses a pin with a stronger pull resistor than the internal MCU pins */
// #define MATRIX_UNSELECT_DRIVE_HIGH

/* RGB Matrix Configuration */
#define DRIVER_1_LED_TOTAL 48
#define DRIVER_2_LED_TOTAL 39
#define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_KEYRELEASES
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SPLASH + 1

/* Enable CapsLcok LED */
#define CAPS_LOCK_LED_INDEX1 33
#define CAPS_LOCK_LED_INDEX2 34
#define CAPS_LOCK_LED_INDEX3 50
#define CAPS_LOCK_LED_INDEX4 51
#define CAPS_LOCK_LED_INDEX5 63
#define CAPS_LOCK_LED_INDEX6 64


