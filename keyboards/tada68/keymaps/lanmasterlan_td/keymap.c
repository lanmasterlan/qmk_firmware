#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1

#define _______ KC_TRNS

enum custom_keycodes {
  MAC_PRT = SAFE_RANGE
};

//Tap Dance Declarations
enum {
  TD_A = 0,
  TD_U,
  TD_O,
  TD_SS
};

void td_a_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    if(keyboard_report->mods & MOD_BIT(KC_LSFT)) {
          clear_keyboard();
          SEND_STRING(SS_LALT("u") SS_LSFT("a"));
        } else {
          SEND_STRING(SS_LALT("u")"a");
        }
    } else {
    register_code (KC_A);
  }
}

void td_a_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count != 2) {
    unregister_code (KC_A);
  }
}

void td_u_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    if(keyboard_report->mods & MOD_BIT(KC_LSFT)) {
          clear_keyboard();
          SEND_STRING(SS_LALT("u") SS_LSFT("u"));
        } else {
          SEND_STRING(SS_LALT("u")"u");
        }
    } else {
    register_code (KC_U);
  }
}

void td_u_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count != 2) {
    unregister_code (KC_U);
  }
}

void td_o_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    if(keyboard_report->mods & MOD_BIT(KC_LSFT)) {
          clear_keyboard();
          SEND_STRING(SS_LALT("u") SS_LSFT("o"));
        } else {
          SEND_STRING(SS_LALT("u")"o");
        }
    } else {
    register_code (KC_O);
  }
}

void td_o_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count != 2) {
    unregister_code (KC_O);
  }
}

void td_ss_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    SEND_STRING(SS_LALT("s"));
    } else {
    register_code (KC_S);
  }
}

void td_ss_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count != 2) {
    unregister_code (KC_S);
  }
}

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // complex tap dance function (to specify what happens when key is pressed 3+ times, for example). See https://docs.qmk.fm/tap_dance.html for how to define
    [TD_A] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_a_finished, td_a_reset),
    [TD_U] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_u_finished, td_u_reset),
    [TD_O] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_o_finished, td_o_reset),
    [TD_SS] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_ss_finished, td_ss_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |FN   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp  |
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Alt |Win |         Space           |Win|Alt|FN|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = LAYOUT_ansi(
  KC_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,      KC_8,   KC_9,    KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_GRV, \
  KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   TD(TD_U),  KC_I,   TD(TD_O),KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_DEL, \
  MO(_FL), TD(TD_A),TD(TD_SS),   KC_D,   KC_F,   KC_G,   KC_H,      KC_J,   KC_K,    KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,KC_PGUP,  \
  KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,      KC_COMM,KC_DOT,  KC_SLSH,   KC_RSFT,KC_UP,KC_PGDN, \
  KC_LCTL, KC_LALT, KC_LGUI,                KC_SPC,                        KC_RGUI, KC_RALT,MO(_FL), KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Scr |
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   | Up|   |   |Bl-|Bl+|BlTG |Hme |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   |Lef|Dow|Rig|   |   |        |End |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |MUT|VU-|VU+|   |   McL|MsU|McR |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   */
[_FL] = LAYOUT_ansi(
  _______, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, MAC_PRT ,  \
  _______,_______,_______,_______,_______, _______,_______,_______,KC_UP,_______,_______,BL_DEC,BL_INC,BL_BRTG,KC_HOME, \
  _______,_______,_______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,_______,KC_END, \
  KC_CAPS,_______,_______,_______,_______,_______, _______,KC_MUTE,KC_VOLD,KC_VOLU,_______,KC_BTN1, KC_MS_U, KC_BTN2, \
  _______,_______,_______,                 _______,               _______,_______,_______,KC_MS_L,KC_MS_D, KC_MS_R)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch(keycode) {
      case MAC_PRT:
        SEND_STRING(SS_LSFT(SS_LGUI("5")));
        return false;
		}
	}
	return true;
};
