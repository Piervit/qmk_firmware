/* Copyright 2025 @ Pierre Vittet 
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

/*Add esperanto layer to azerty french keyboard. **/

#include QMK_KEYBOARD_H
#include "unicode.h"

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

enum layers{
  MAC_BASE,         //The original MAC layer
  MAC_FN,           //The original MAC function layer
  WINAZ_BASE,       //The Windows/Linux original azerty layer
  WINAZ_FN,         //The Windows/Linux azerty function layer with only a change to allow switching to AZEL_BASE.
  AZEO_BASE,        //The Transformed azerteo layout
  AZEO_FN           //The function layer of the transformed azerteo layout.
};

/**
 * The specific esperanto letters with accent, using unicode code.
 */
enum unicode_names {
    EO_UA,
    EO_UAU,
    EO_JA,
    EO_JAU,
    EO_SA,
    EO_SAU,
    EO_GA,
    EO_GAU,
    EO_CA,
    EO_CAU,
};

const uint32_t unicode_map[] PROGMEM = {
    [EO_UA]  = 0x016D,  // ŭ
    [EO_UAU] = 0x016C,  // Ŭ
    [EO_JA]  = 0x0135,  // ĵ
    [EO_JAU] = 0x0134,  // Ĵ
    [EO_SA]  = 0x015D,  // ŝ
    [EO_SAU] = 0x015C,  // Ŝ
    [EO_GA]  = 0x011D,  // ĝ
    [EO_GAU] = 0x011C,  // Ĝ
    [EO_CA]  = 0x0109,  // ĉ
    [EO_CAU] = 0x0108,  // Ĉ
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_iso_83(
            //Base MAC layer
        KC_ESC,             KC_BRID,  KC_BRIU,  KC_NO,    KC_NO,    RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_DEL,   KC_INS,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,                      KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,             KC_HOME,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD, MO(MAC_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_iso_83(
            //Base MAC function layer
        _______,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
        _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______),

    [WINAZ_BASE] = LAYOUT_iso_83(
            //Base Windows layer
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_INS,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,                      KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,             KC_HOME,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(WINAZ_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
    [WINAZ_FN] = LAYOUT_iso_83(
            //Base Windows function layer with right control rebased to EO layer
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
        _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  DF(AZEO_BASE),  _______,  _______,  _______),
    [AZEO_BASE] = LAYOUT_iso_83(
            //New azerty EO layer. Mostly azerty layer with some rebase for EO keys
        KC_ESC,                     KC_F1,              KC_F2,              KC_F3,    KC_F4,    KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,             KC_F11,   KC_F12,   KC_DEL,   KC_INS,
        KC_GRV,   KC_1,             KC_2,               KC_3,               KC_4,     KC_5,     KC_6,               KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,            KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,             KC_W,               KC_E,               KC_R,     KC_T,     UP(EO_UA,EO_UAU),   KC_U,     KC_I,     KC_O,     KC_P,     UP(EO_JA, EO_JAU),  KC_RBRC,                      KC_PGDN,
        KC_CAPS,  UP(EO_SA,EO_SAU), KC_S,               KC_D,               KC_F,     KC_G,     KC_H,               KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_NUHS,  KC_ENT,             KC_HOME,
        KC_LSFT,  KC_NUBS,          UP(EO_GA, EO_GAU),  UP(EO_CA, EO_CAU),  KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LWIN,          KC_LALT,                                KC_SPC,                                                     KC_RALT,  MO(AZEO_FN),KC_RCTL,          KC_LEFT,  KC_DOWN,  KC_RGHT),

    [AZEO_FN] = LAYOUT_iso_83(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
        _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  UC_NEXT,  _______,                                _______,                                _______,  _______,  DF(WINAZ_BASE),  _______,  _______,  _______)
    };



