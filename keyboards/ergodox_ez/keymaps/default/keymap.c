#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0
#define RAISE 1
#define LOWER 2
#define ADJUST 3
#define _______ KC_TRNS

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   BS   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Adjust |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | Enter  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | CMDEI|                                       |CMKKN |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | LOWER| Space|------|       |------|  Shift |RAISE |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
	_______,    _______,   _______, _______, _______,          _______,  _______,
	KC_TAB,     KC_Q,      KC_W,    KC_E,    KC_R,             KC_T,     _______,
	KC_LCTRL,   KC_A,      KC_S,    KC_D,    KC_F,             KC_G,
	MO(ADJUST), KC_Z,      KC_X,    KC_C,    KC_V,             KC_B,     _______,
	_______,    _______,   _______, _______, LGUI_T(KC_LANG2),
	                                                           _______,  _______,
	                                                                     _______,
	                                         MO(LOWER),        KC_SPACE, _______,
	
	_______,  _______,   _______,          _______,   _______, _______,   _______,
	_______,  KC_Y,      KC_U,             KC_I,      KC_O,    KC_P,      KC_BSPACE,
	          KC_H,      KC_J,             KC_K,      KC_L,    KC_SCOLON, KC_QUOTE,
	_______,  KC_N,      KC_M,             KC_COMMA,  KC_DOT,  KC_SLASH,  KC_ENTER,
	                     LGUI_T(KC_LANG1), _______,   _______, _______,   _______,
	_______,  _______,
	_______,
	_______,  KC_RSHIFT, MO(RAISE)
),

/* 
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   `    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   BS   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| left | down |  up  |right | ESC  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      | Space|------|       |------|  Shift |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[RAISE] = LAYOUT_ergodox(
	_______,  _______, _______, _______, _______, _______,  _______,
	KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     _______,
	_______,  _______, _______, _______, _______, _______,
	_______,  _______, _______, _______, _______, _______,  _______,
	_______,  _______, _______, _______, _______,
	                                              _______,  _______,
	                                                        _______,
	                                     _______, KC_SPACE, _______,
	
	_______, _______,   _______,  _______,  _______,  _______, _______,
	_______, KC_6,      KC_7,     KC_8,     KC_9,     KC_0,    KC_BSPACE,
	         KC_LEFT,   KC_DOWN,  KC_UP,    KC_RIGHT, KC_ESC,  _______,
	_______, _______,   _______,  _______,  _______,  _______, _______,
	                    _______,  _______,  _______,  _______, _______,
	_______, _______,
	_______,
	_______, KC_RSHIFT, _______
),

/* 
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   ~    |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   (  |   )  |   BS   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   -  |   =  |   [  |   ]  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   _  |   +  |   {  |   }  |   |    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|  Shift |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[LOWER] = LAYOUT_ergodox(
	_______, _______, _______, _______, _______, _______,  _______,
	KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  _______,
	_______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______,  _______,
	_______, _______, _______, _______, _______,
	                                             _______,  _______, 
	                                                       _______, 
	                                    _______, KC_SPACE, _______,
	
	_______, _______,   _______,  _______,  _______,     _______,     _______,
	_______, KC_CIRC,   KC_AMPR,  KC_ASTR,  KC_LPRN,     KC_RPRN,     KC_BSPACE,
	         _______,   KC_MINUS, KC_EQUAL, KC_LBRACKET, KC_RBRACKET, KC_BSLASH,
	_______, _______,   KC_UNDS,  KC_PLUS,  KC_LCBR,     KC_RCBR,     KC_PIPE,  
	                    _______,  _______,  _______,     _______,     _______,
	_______, _______, 
	_______, 
	_______, KC_RSHIFT, _______
),

/* 
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | RESET|      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[ADJUST] = LAYOUT_ergodox(
	_______, _______, _______, _______, _______, _______, _______,
	_______, RESET,   _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, 
	_______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______,
	                                             _______, _______,
	                                                      _______, 
	                                    _______, _______, _______,
	
	_______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______,
	         _______, _______, _______, _______, _______, _______, 
	_______, _______, _______, _______, _______, _______, _______,
	                  _______, _______, _______, _______, _______,
	_______, _______, 
	_______, 
	_______, _______, _______
),
};



const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(RAISE)                // FN1 - Momentary Layer 1 (Symbols)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
