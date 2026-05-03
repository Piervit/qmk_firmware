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
//#include "secure.h"
#include "keymap_introspection.h"

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% LAYERS DEFINITION %%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 

enum layers{
    /*FIXED LAYERS (because the MAC/Windows switch expect to find the layers a theses positions).*/
  MAC_BASE = 0,         //The original MAC layer. 
  MAC_FN = 10,           //The original MAC function layer 
  WINAZ_BASE = 2,       //The Windows/Linux original azerty layer (F1 to F12 keys modified to be a numeric keypad)
  WINAZ_FN = 11,         //The Windows/Linux azerty function layer with only a change to allow switching to AZEL_BASE.
    /*FREE ADDITIONNAL LAYERS (that we order as we want).*/
  FN_KEY = 9,           //Set the F1..F12 layer to standard mod
  AZEO_BASE = 7,        //The Transformed azerteo layout (F1 to F12 keys modified to be a numeric keypad)
  AZEO_FN = 12,          //The function layer of the transformed azerteo layout.
  MACEO_BASE = 13,       //The MAC Esperanto layer
  MACEO_FN = 14,         //The MAC Esperanto function layer
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
    EO_STR,
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
    [EO_STR] = 0x272D,  // Star
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


/**
 * We Want MAJ+1 to just type 1.
 **/

const key_override_t shift_1_override = ko_make_basic(MOD_MASK_SHIFT, KC_P1, KC_P1);
const key_override_t shift_2_override = ko_make_basic(MOD_MASK_SHIFT, KC_P2, KC_P2);
const key_override_t shift_3_override = ko_make_basic(MOD_MASK_SHIFT, KC_P3, KC_P3);
const key_override_t shift_4_override = ko_make_basic(MOD_MASK_SHIFT, KC_P4, KC_P4);
const key_override_t shift_5_override = ko_make_basic(MOD_MASK_SHIFT, KC_P5, KC_P5);
const key_override_t shift_6_override = ko_make_basic(MOD_MASK_SHIFT, KC_P6, KC_P6);
const key_override_t shift_7_override = ko_make_basic(MOD_MASK_SHIFT, KC_P7, KC_P7);
const key_override_t shift_8_override = ko_make_basic(MOD_MASK_SHIFT, KC_P8, KC_P8);
const key_override_t shift_9_override = ko_make_basic(MOD_MASK_SHIFT, KC_P9, KC_P9);
const key_override_t shift_0_override = ko_make_basic(MOD_MASK_SHIFT, KC_P0, KC_P0);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    	&minus_key_override,
        &div_key_override,
        &ctrl_w_override,
        &ctrl_y_override,
        &ctrl_q_override,
        &ctrl_x_override,
        &shift_0_override,
        &shift_1_override,
        &shift_2_override,
        &shift_3_override,
        &shift_4_override,
        &shift_5_override,
        &shift_6_override,
        &shift_7_override,
        &shift_8_override,
        &shift_9_override
};
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%% END KEY OVERRIDING %%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
//%%%%%%%%%%%%%%%%%%%%%%%%%%%% TAP DANCE DEFINITION %%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
// Enums of the key using tap dance.
enum {
    TD_C,
    TD_P,
    TD_H,
    TD_U,
    TD_B,
    TD_K,
    TD_Y,
    TD_S,
    TD_O,
};

//%%%%%%%%%%%%%%%%%%%%%%%%%%%% END DANCE DEFINITION %%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%% LAYERS DEFINITION %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_iso_83(
            //Base MAC layer
        KC_ESC,             KC_BRID,  KC_BRIU,  KC_NO,    KC_NO,    RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_DEL,   KC_LCTL,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,                      KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,             KC_HOME,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD, MO(MAC_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_iso_83(
            //Base MAC function layer
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,         _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,        _______,            _______,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                            _______,
        _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,        _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,                  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  DF(MACEO_BASE), _______,  _______,  _______),
    [MACEO_BASE] = LAYOUT_iso_83(
        KC_ESC,         KC_BRIU,          KC_BRID,  KC_TASK,          KC_FLXP,  KC_MPRV,  KC_MPLY,            KC_MNXT,  KC_PSCR,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_SLEP,  KC_DEL,             KC_LCTL,
        LSFT(KC_QUOT),  KC_1,             KC_2,     KC_3,             KC_4,     KC_5,     KC_6,               KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,         KC_Q,             KC_W,     KC_E,             KC_R,     KC_T,     UP(EO_UA,EO_UAU),   KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  UP(EO_STR,KC_RBRC),           KC_PGDN,
        KC_CAPS,        UP(EO_SA,EO_SAU), KC_S,     KC_D,             KC_F,     KC_G,     UP(EO_GA, EO_GAU),  KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,             KC_HOME,
        KC_LSFT,        UP(EO_HA, EO_HAU),KC_H,     UP(EO_CA, EO_CAU),KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,        KC_LOPT,          KC_LCMD,                                KC_SPC,                                           KC_RCMD, MO(MACEO_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
    [MACEO_FN] = LAYOUT_iso_83(
        _______,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,
        DM_REC1,  DM_PLY1,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
        _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  UC_NEXT,  _______,                                _______,                                _______,  _______,  DF(MAC_BASE),  _______,  _______,  _______),
    [WINAZ_BASE] = LAYOUT_iso_83(
            //Base Windows layer
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11 ,  KC_F12 ,   KC_DEL,  KC_LCTL,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     TD(TD_Y), TD(TD_U) ,KC_I,     TD(TD_O), TD(TD_P), KC_LBRC,  KC_RBRC,                      KC_PGDN,
        KC_CAPS,  KC_A,     TD(TD_S), KC_D,     KC_F,     KC_G,     TD(TD_H), KC_J,     TD(TD_K), KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,             KC_HOME,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     TD(TD_C), KC_V,     TD(TD_B), KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(WINAZ_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
    [WINAZ_FN] = LAYOUT_iso_83(
            //Base Windows function layer with right control rebased to EO layer
        _______,            KC_BRIU,  KC_BRID,  KC_TASK,  KC_FLXP,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_PSCR,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_SLEP,  _______,  _______,
        DM_REC1,  DM_PLY1,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
        _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,
        DB_TOGG,  _______,  _______,                                _______,                                TG(FN_KEY), _______,  DF(AZEO_BASE),  _______,  _______,  _______),
    [AZEO_BASE] = LAYOUT_iso_83(
            //New azerty EO layer. Mostly azerty layer with some rebase for EO keys
        KC_ESC,         KC_F1,            KC_F2, KC_F3,              KC_F4,    KC_F5,    KC_F6,              KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11 ,            KC_F12 ,  KC_DEL,             KC_LCTL,
        LSFT(KC_QUOT),  KC_1,             KC_2,  KC_3,               KC_4,     KC_5,     KC_6,               KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,            KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,         KC_Q,             KC_W,  KC_E,               KC_R,     KC_T,     UP(EO_UA,EO_UAU),   KC_U,     KC_I,     KC_O,     KC_P,     KC_NUBS,            UP(EO_STR,KC_RBRC),                      KC_PGDN,
        KC_CAPS,        UP(EO_SA,EO_SAU), KC_S,  KC_D,               KC_F,     KC_G,     UP(EO_GA, EO_GAU),  KC_J,     KC_K,     KC_L,     KC_SCLN,  UP(EO_JA, EO_JAU),  KC_NUHS,  KC_ENT,             KC_HOME,
        KC_LSFT,        UP(EO_HA, EO_HAU),KC_H,  UP(EO_CA, EO_CAU),  KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,            KC_UP,
        KC_LCTL,        KC_LWIN,          KC_LALT,                                KC_SPC,                                                  KC_RALT,  MO(AZEO_FN),KC_RCTL,          KC_LEFT,  KC_DOWN,  KC_RGHT),

    [AZEO_FN] = LAYOUT_iso_83(
        _______,            KC_BRIU,  KC_BRID,  KC_TASK,  KC_FLXP,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_PSCR,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_SLEP,  _______,  _______,
        DM_REC1,  DM_PLY1,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
        _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,  _______,
        DB_TOGG,  UC_NEXT,  _______,                                _______,                                TG(FN_KEY),_______,  DF(WINAZ_BASE),  _______,  _______,  _______),
    [FN_KEY] = LAYOUT_iso_83(
        _______,            KC_P1,    KC_P2,    KC_P3,    KC_P4,    KC_P5,    KC_P6,    KC_P7,    KC_P8,    KC_P9,    KC_P0 ,   KC_PPLS,  KC_PAST,  _______,  _______,
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
  secure_task();
}

/**
 * Callback called on a layer change.
 * TODO: We could add a feature to this function to switch the correct UNICODE_SELECTED_MODES according to MAC or
 * WINDOWS/LINUX layer.
 *
 */
layer_state_t layer_state_set_user(layer_state_t state) {
    if(layer_state_cmp(state, FN_KEY)){
        numlock_on(); //We don't want to check for num lock at every keystroke (for performance reason). So we use the
                      //opportunity to check on layers change.
    }
  return state;
}


//%%%%%%%%%%%%%%%%%%%%%%%%% END KEYBOARD INIT FUNCTION %%%%%%%%%%%%%%%%%%%%%%%%%% 
//%%%%%%%%%%%%%%%%%%%%%%%%% TAP DANCE FUNCTION %%%%%%%%%%%%%%%%%%%%%%%%%% 

//    TD_C_COPY, // git commit
//    TD_P_COPY, // git pull
//    TD_H_COPY, // git push
//    TD_U_COPY, // git push -u origin 
//    TD_B_COPY, // git checkout -b 
//    TD_K_COPY, // git checkout 
//    TD_Y_COPY, // git cherry-pick
//    TD_S_COPY, // git stash save
//    TD_O_COPY, // git stash pop

void hold_map_translate(uint16_t code){ 
    switch (code){
        case KC_C: 
            SEND_STRING("git co;;it "); break;
        case KC_P: 
            SEND_STRING("git pull "); break;
        case KC_H: 
            SEND_STRING("git push "); break;
        case KC_U: 
            SEND_STRING("git push 6u origin "); break;
        case KC_B: 
            SEND_STRING("git checkout 6b "); break;
        case KC_K: 
            SEND_STRING("git checkout "); break;
        case KC_Y: 
            SEND_STRING("git cherry6pick "); break;
        case KC_S: 
            SEND_STRING("git stqsh sqve "); break;
        case KC_O: 
            SEND_STRING("git stqsh pop "); break;
    }
}

typedef struct {
    uint16_t tap;
} tap_dance_tap_hold_t;

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            hold_map_translate(tap_hold->tap);
            //switch (tap_hold->tap){
            //    case KC_C:
            //        SEND_STRING("git commit ");
            //        break:
            //}
        } else {
            register_code16(tap_hold->tap);
        }
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap)                                        \
    {                                                                               \
        .fn        = {NULL, tap_dance_tap_hold_finished},                           \
        .user_data = (void *)&((tap_dance_tap_hold_t){tap}),                  \
    }
tap_dance_action_t tap_dance_actions[] = {
    [TD_C] = ACTION_TAP_DANCE_TAP_HOLD(KC_C),
    [TD_P] = ACTION_TAP_DANCE_TAP_HOLD(KC_P),
    [TD_H] = ACTION_TAP_DANCE_TAP_HOLD(KC_H),
    [TD_U] = ACTION_TAP_DANCE_TAP_HOLD(KC_U),
    [TD_B] = ACTION_TAP_DANCE_TAP_HOLD(KC_B),
    [TD_K] = ACTION_TAP_DANCE_TAP_HOLD(KC_K),
    [TD_Y] = ACTION_TAP_DANCE_TAP_HOLD(KC_Y),
    [TD_S] = ACTION_TAP_DANCE_TAP_HOLD(KC_S),
    [TD_O] = ACTION_TAP_DANCE_TAP_HOLD(KC_O),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;
    tap_dance_state_t* state;

    switch (keycode) {
        case TD(TD_C):
        case TD(TD_P):
        case TD(TD_H):
        case TD(TD_U):
        case TD(TD_B):
        case TD(TD_K):
        case TD(TD_Y):
        case TD(TD_S):
        case TD(TD_O):
            action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
            state = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
            if (!record->event.pressed && state != NULL && state->count && !state->finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }
    return true;
}



//%%%%%%%%%%%%%%%%%%%%%%%%% END TAP DANCE FUNCTION %%%%%%%%%%%%%%%%%%%%%%%%%% 
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% KEYBOARD LIGHTING %%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 

uint8_t rgb_no_light[]       = {0x00, 0x00, 0x00};
uint8_t rgb_std_blue[]       = {0x00, 0x00, 0xFF}; // Red, standard azery mode
uint8_t rgb_stdfn_blue[]     = {0x00, 0x20, 0xFF}; // Red, FN azery mode 
uint8_t rgb_macfn_rose[]     = {0xFF, 0x4F, 0x4F}; // Red, MAC FN azery mode 
uint8_t rgb_eo_green[]       = {0x00, 0xFF, 0x00}; // Green, EO Linux mode
uint8_t rgb_eofn_green[]     = {0x00, 0xFF, 0x20}; // Green, EO FN Linux mode 
uint8_t rgb_eowin_blue[]     = {0x00, 0xFF, 0xFF}; // Blue, EO windows mode
uint8_t rgb_eowinfn_blue[]   = {0x20, 0xFF, 0xFF}; // Blue, EO FN windows mode 
uint8_t rgb_mac_white[]      = {0xFF, 0x6F, 0x6F}; // White, EO mac mode
uint8_t rgb_eomac_white[]    = {0xFF, 0xFF, 0xFF}; // White, EO mac mode
uint8_t rgb_eomacfn_white[]  = {0xAA, 0xAA, 0xAA}; // Blue, EO FN mac mode 
uint8_t rgb_basefn_white[]   = {0xFF, 0xFF, 0xFF}; // White, it means we use the classical F1-F12 keys.
uint8_t rgb_basefn_blue[]    = {0x00, 0x00, 0xFF}; // Blue, it means wwe used the numeric keypad mod.


/*Manage the colors for the F1-F12 indicators. 
 * 
 * */
void rgb_matrix_F1F12_indicators(void){
    uint8_t* color = rgb_no_light;
    //First part, select the desired color.
    if (!rgb_matrix_is_enabled()){
        color = rgb_no_light;
    }
    else if(layer_state_is(FN_KEY)) {
        color = rgb_basefn_blue;
    }
    else{ 
        color = rgb_basefn_white;
    }
    uint8_t upper_line_last_led = 14;
    //Second part, apply it to the matrix elements.
    for (uint8_t i = 0; i < upper_line_last_led; i++) {
            rgb_matrix_set_color(i, color[0], color[1], color[2]);
    }
}

/* Manage the main mode information (AZERTY or EO). */
void rgb_matrix_main_mode_keys(void){
    uint8_t main_mode_keys[] = {72, 80, 81, 82, 83};
    uint8_t size = sizeof(main_mode_keys)/sizeof(main_mode_keys[0]);
    uint8_t* color = rgb_no_light;
    uint8_t cur_default_layer = get_highest_layer(default_layer_state);
    //First part, select the desired color.
    if (!rgb_matrix_is_enabled()){
        color = rgb_no_light;
    }
    //Manage the FN mods
    else if (layer_state_is(WINAZ_FN)){
        color = rgb_stdfn_blue;
    }
    else if (layer_state_is(MAC_FN)){
        color = rgb_macfn_rose;
    }
    else if (layer_state_is(AZEO_FN)){
        if(get_unicode_input_mode()== UNICODE_MODE_LINUX){
            color = rgb_eofn_green;
        }
        else if(get_unicode_input_mode() == UNICODE_MODE_WINCOMPOSE){
            color = rgb_eowinfn_blue;
        }
        else{
            color = rgb_eomacfn_white;
        }
    }
    //Manage the standards mods
    else if (cur_default_layer == WINAZ_BASE){
        color = rgb_std_blue;
    }
    else if(cur_default_layer == MAC_BASE){
        color = rgb_mac_white;
    }
    else{ //We are either in AZEL_BASE or MACEO_BASE, we then check the unicode mode.
        if(get_unicode_input_mode()== UNICODE_MODE_LINUX){
            color = rgb_eo_green;
        }
        else if(get_unicode_input_mode()== UNICODE_MODE_WINCOMPOSE){
            color = rgb_eowin_blue;
        }
        else if(get_unicode_input_mode() == UNICODE_MODE_MACOS){
            color = rgb_eomac_white;
        }
    }
    //Second part, apply it to the matrix elements.
    for (uint8_t i = 0; i < size; i++) {
        uint8_t key = main_mode_keys[i];
        rgb_matrix_set_color(key, color[0], color[1], color[2]);
    }
}

bool rgb_matrix_indicators_user() {
    rgb_matrix_F1F12_indicators();
    rgb_matrix_main_mode_keys();
    return false;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% END KEYBOARD LIGHTING %%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% KNOB ENCODER  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
//
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(MS_WHLU);
        } else {
            tap_code(MS_WHLD);
        }
    } 
    return false;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% END KNOB ENCODER  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
