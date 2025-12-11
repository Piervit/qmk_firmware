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

/*Add esperanto layer to azerty french keyboard.
 *This layout (and the unicode module) will try to always set the keyboard to a NUM LOCK STATE).
 *This is needed to correctly input the UTF8 symbol and to use the F1..F12 keys as keypad.
 * **/

#include QMK_KEYBOARD_H
#include "unicode.h"

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% LAYERS DEFINITION %%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 

enum layers{
  MAC_BASE,         //The original MAC layer
  MAC_FN,           //The original MAC function layer
  WINAZ_BASE,       //The Windows/Linux original azerty layer (F1 to F12 keys modified to be a numeric keypad)
  WINAZ_FN,         //The Windows/Linux azerty function layer with only a change to allow switching to AZEL_BASE.
  AZEO_BASE,        //The Transformed azerteo layout (F1 to F12 keys modified to be a numeric keypad)
  AZEO_FN,          //The function layer of the transformed azerteo layout.
  FN_KEY            //Set the F1..F12 layer to standard mod
};


//%%%%%%%%%%%%%%%%%%%%%%%%%%%% END LAYERS DEFINITION %%%%%%%%%%%%%%%%%%%%%%%%%%%% 

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% ESPERANTO UNICODE %%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
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
    EO_HA,
    EO_HAU,
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
    [EO_HA]  = 0x0125,  // ĥ
    [EO_HAU] = 0x0124,  // Ĥ

};

//%%%%%%%%%%%%%%%%%%%%%%%%%%%% END ESPERANTO UNICODE %%%%%%%%%%%%%%%%%%%%%%%%%%%% 
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% KEY OVERRIDING %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 

/**
 * The following override will make the usual CTRL+W, CTRL+Y, CTRL_Q, CTRL_X work as usual even if the key has been bind
 * to another esperanto keys.
 * We also add overriding for MAJ++ and MAJ+* which will provide '-' and '*' symbols.
 *
 */
const key_override_t minus_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PPLS,KC_PMNS);
const key_override_t div_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PAST, KC_PSLS);
const key_override_t ctrl_w_override = ko_make_basic(MOD_MASK_CTRL, KC_H, LCTL(KC_Z));
const key_override_t ctrl_y_override = ko_make_basic(MOD_MASK_CTRL, UP(EO_UA,EO_UAU), LCTL(KC_Z));
const key_override_t ctrl_q_override = ko_make_basic(MOD_MASK_CTRL, UP(EO_SA,EO_SAU), LCTL(KC_A));
const key_override_t ctrl_x_override = ko_make_basic(MOD_MASK_CTRL, UP(EO_CA,EO_CAU), LCTL(KC_X));

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    	&minus_key_override,
        &div_key_override,
        &ctrl_w_override,
        &ctrl_y_override,
        &ctrl_q_override,
        &ctrl_x_override
};
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%% END KEY OVERRIDING %%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%% LAYERS DEFINITION %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
//
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
        KC_ESC,             KC_P1,    KC_P2,    KC_P3,    KC_P4,    KC_P5,    KC_P6,    KC_P7,    KC_P8,    KC_P9,    KC_P0,    KC_PPLS,  KC_PAST,   KC_DEL,  KC_INS,
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
        DB_TOGG,  _______,  _______,                                _______,                                TG(FN_KEY), _______,  DF(AZEO_BASE),  _______,  _______,  _______),
    [AZEO_BASE] = LAYOUT_iso_83(
            //New azerty EO layer. Mostly azerty layer with some rebase for EO keys
        KC_ESC,                     KC_P1, KC_P2,              KC_P3,    KC_P4,    KC_P5,              KC_P6,    KC_P7,    KC_P8,    KC_P9,    KC_P0 ,             KC_PPLS,  KC_PAST,  KC_DEL,   KC_INS,
        KC_GRV,   KC_1,             KC_2,  KC_3,               KC_4,     KC_5,     KC_6,               KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,            KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,             KC_W,  KC_E,               KC_R,     KC_T,     UP(EO_UA,EO_UAU),   KC_U,     KC_I,     KC_O,     KC_P,     KC_NUBS,            KC_RBRC,                      KC_PGDN,
        KC_CAPS,  UP(EO_SA,EO_SAU), KC_S,  KC_D,               KC_F,     KC_G,     UP(EO_GA, EO_GAU),  KC_J,     KC_K,     KC_L,     KC_SCLN,  UP(EO_JA, EO_JAU),  KC_NUHS,  KC_ENT,             KC_HOME,
        KC_LSFT,  UP(EO_HA, EO_HAU),KC_H,  UP(EO_CA, EO_CAU),  KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LWIN,          KC_LALT,                                KC_SPC,                                                  KC_RALT,  MO(AZEO_FN),KC_RCTL,          KC_LEFT,  KC_DOWN,  KC_RGHT),

    [AZEO_FN] = LAYOUT_iso_83(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
        _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,
        DB_TOGG,  UC_NEXT,  _______,                                _______,                                TG(FN_KEY),_______,  DF(WINAZ_BASE),  _______,  _______,  _______),
    [FN_KEY] = LAYOUT_iso_83(
        _______,            KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,  KC_F6  ,  KC_F7  ,  KC_F8  ,  KC_F9  ,  KC_F10 ,  KC_F11 ,  KC_F12 ,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______)
    };

//%%%%%%%%%%%%%%%%%%%%%%%%%%% END LAYERS DEFINITION %%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//%%%%%%%%%%%%%%%%%%%%%%%%%%% KEYBOARD INIT FUNCTION %%%%%%%%%%%%%%%%%%%%%%%%%%%% 

/**
 * Check if num lock is activated, else activate it. We use num lock for several reason:
 *  - under windows: it is needed that it is activated to input correctly the unicode chars (eo codes).
 *  - generally for the replacement of the F1 to F12 key as a numeric keypad, this numeric keypad will not work without
 *  numlock.
 */
void numlock_on(void) {
  led_t led_state = host_keyboard_led_state();
  bool initial_cap_lock = led_state.caps_lock;
  if (! led_state.num_lock) {
    if (! initial_cap_lock) {
        tap_code(KC_CAPS_LOCK);
    }
    tap_code(KC_NUM_LOCK);

    led_state = host_keyboard_led_state();
    if (initial_cap_lock != led_state.caps_lock){
        tap_code(KC_CAPS_LOCK);
    }
  }
}

void keyboard_post_init_user(void) {
  // Call the post init code.
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
  numlock_on();
}

/**
 * Callback called on a layer change.
 */
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case FN_KEY:
        numlock_on(); //We don't want to check for num lock at every keystroke (for performance reason). So we use the
                      //opportunity to check on layers change.
        break;
    default: //  for any other layers, or the default layer
        break;
    }
  return state;
}

led_t            saved_led_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true; // Process all other keycodes normally
}


//%%%%%%%%%%%%%%%%%%%%%%%%% END KEYBOARD INIT FUNCTION %%%%%%%%%%%%%%%%%%%%%%%%%% 
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% KEYBOARD LIGHTING %%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 

#define RGB_STD_RED        0xFF, 0x00, 0x00 // Red, standard azery mode
#define RGB_STDFN_RED      0xFF, 0x20, 0x00 // Red, FN azery mode 
#define RGB_EO_GREEN       0x00, 0xFF, 0x00 // Green, EO Linux mode
#define RGB_EOFN_GREEN     0x00, 0xFF, 0x20 // Green, EO FN Linux mode 
#define RGB_EOWIN_BLUE     0x00, 0x00, 0xFF // Blue, EO windows mode
#define RGB_EOWINFN_BLUE   0x20, 0x00, 0xFF // Blue, EO FN windows mode 
#define RGB_BASEFN_OFF     0xFF, 0xFF, 0xFF // White
#define RGB_BASEFN_ON      0x00, 0x00, 0xFF // Blue

bool rgb_matrix_indicators_user() {
    uint8_t upper_line_last_led = 14;
    for (uint8_t i = 0; i < upper_line_last_led; i++) {
        if (!rgb_matrix_is_enabled()){
            rgb_matrix_set_color(i, RGB_OFF);
        }
        else if(layer_state_is(FN_KEY)) {
            rgb_matrix_set_color(i, RGB_BASEFN_OFF);
        }
        else{ 
            rgb_matrix_set_color(i, RGB_BASEFN_ON);
        }
    }
    uint8_t main_mode_keys[] = {72, 80, 81, 82, 83};
    uint8_t size = sizeof(main_mode_keys)/sizeof(main_mode_keys[0]);
    for (uint8_t i = 0; i < size; i++) {
        uint8_t key = main_mode_keys[i];
        if (!rgb_matrix_is_enabled()){
            rgb_matrix_set_color(key, RGB_OFF);
            continue;
        }
        if (layer_state_is(WINAZ_FN)){
            rgb_matrix_set_color(key, RGB_STDFN_RED);
        }
        else if (layer_state_is(AZEO_FN)){
            if(get_unicode_input_mode()== UNICODE_MODE_LINUX){
                rgb_matrix_set_color(key, RGB_EOFN_GREEN);
            }
            else{
                rgb_matrix_set_color(key, RGB_EOWINFN_BLUE);
            }
        }
        else if (default_layer_state == AZEO_BASE){
            //TODO: There should be a bug here (we should here enable the RGB_EO_GREEN). But for an unknown reason the
            //behaviour is correct with this code. This is either a bug in the use of default_layer_state variable or a
            //problem in how this variable is set.
            rgb_matrix_set_color(key, RGB_STD_RED);
        }
        else{
            if(get_unicode_input_mode()== UNICODE_MODE_LINUX){
                rgb_matrix_set_color(key, RGB_EO_GREEN);
            }
            else if(get_unicode_input_mode()== UNICODE_MODE_WINCOMPOSE){
                rgb_matrix_set_color(key, RGB_EOWIN_BLUE);
            }
        }

        //switch (get_highest_layer(layer_state|default_layer_state)) {
        //    case WINAZ_FN:
        //        rgb_matrix_set_color(i, RGB_STDFN_YELLOW);
        //        break;
        //    case WINAZ_BASE:
        //        rgb_matrix_set_color(i, RGB_STD_YELLOW);
        //        break;
        //    case AZEO_FN:
        //        rgb_matrix_set_color(i, RGB_EOFN_GREEN);
        //        break;
        //    case AZEO_BASE:
        //        rgb_matrix_set_color(i, RGB_EO_GREEN);
        //        break;
        //}
    }
    return false;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% END KEYBOARD LIGHTING %%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
