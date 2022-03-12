#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _FN1_LAYER,
  _FN2_LAYER,
  _FN3_LAYER,
  _FN4_LAYER,

  };

// Also I made another declaration here, they must be separate from the layers.
enum {
/*I declared three Tap Dance (TD) functions to make the switch from layer to layer */
/*At the end of the document are the functions and the explanation*/
  TD_TAB_LS1,
  TD_TAB_LS2,
  TD_TAB_LS3,
  TD_TAB_LS4,
  TD_LALT_LS5,

};
// * -------------------------TAP DANCE------------------------- * 
// Tap Dance Functions definitions:
// The name convention follows this logic that i made:
// TD_TAB_LS1 = Tap Dance Tab LayerSwitch 1 
// For you to know why i chose that name.

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for TAB, twice for Switch to Layer1
    [TD_TAB_LS1] = ACTION_TAP_DANCE_LAYER_MOVE(KC_TAB, _FN1_LAYER),
    // Tap once for TAB, twice for Switch to Layer2
    [TD_TAB_LS2] = ACTION_TAP_DANCE_LAYER_MOVE(KC_TAB, _FN2_LAYER),
    // Tap once for TAB, twice for Switch to Layer3
    [TD_TAB_LS3] = ACTION_TAP_DANCE_LAYER_MOVE(KC_TAB, _FN3_LAYER),
    // Tap once for TAB, twice for Switch to Base Layer
    [TD_TAB_LS4] = ACTION_TAP_DANCE_LAYER_MOVE(KC_TAB, _BASE_LAYER),
    // Tap once for LALT, twice for Switch to Layer 4
    [TD_LALT_LS5] = ACTION_TAP_DANCE_LAYER_MOVE (KC_LALT, _FN4_LAYER),
    
// Each function except TD_LALT_LSS involves tapping the TAB button twice to switch layers. Tapping once functions as a regular TAB. 
// The principle is the same for TD_LALT_LSS
// * ----------------------------------------------------------- *

};

// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* | Ltn |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  Brve|  Crcmflx | Bksp|
* |-----------------------------------------------------------------------------------------+
* | Tab    |  θ  |  ω  |  ε  |  ρ  |  τ  |  ψ  |  υ  |  ι  |  ο  |  π  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Caps    |  α  |  σ  |  δ  |  φ  |  γ  |  η  |  ξ  |  κ  |  λ  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  ζ  |  χ  |  ξ  |  ν  |  β  |  ν  |  μ  |  ,  |  .  |  /  |     UP         |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  LEFT  |  DWN  |  RGHT|
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER] = KEYMAP( /* Base */
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    TD(TD_TAB_LS1), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_DEL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_UP,
    KC_LCTL, KC_LGUI, TD(TD_LALT_LS5), KC_SPC, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
),
  /*
  * Layer _FN1_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |       |  !  | @   | # |  $   |   %  |   ^  |   &  |  * |  ( | ) | _ | ϋ |  BSPC         |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  Θ  |  Ω  |  Ε  |  Ρ  |  Τ  | Ψ  |  Υ   |  Ι   | Ο  |  Π | {  |  }  |     ᾼ    |
  * |-----------------------------------------------------------------------------------------+
  * | Caps   |  Α  |  Σ  | Δ  |  Φ  |  Γ  |  Η  |  Ξ  |  Κ |  Λ  |  ·   |  "   |     Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      | Ζ | Χ | Ξ |  Ν |  Β | Ν   |  Μ  |   <    |  >   | ?  |       UP            |
  * |-----------------------------------------------------------------------------------------+
  * | Ctril    | Windows  |   Alt |           space             |  Alt   |   LEFT  | DWN| RGHT|
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN1_LAYER] = KEYMAP( /*Layer 1 (LSFT depressed)*/ 
    LSFT(KC_ESCAPE), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), LSFT(KC_MINS), LSFT(KC_EQL), KC_BSPC,
    TD(TD_TAB_LS2), LSFT(KC_Q), LSFT(KC_W), LSFT(KC_E), LSFT(KC_R), LSFT(KC_T), LSFT(KC_Y), LSFT(KC_U), LSFT(KC_I), LSFT(KC_O), LSFT(KC_P), LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(KC_BSLS),
    KC_DEL, LSFT(KC_A), LSFT(KC_S), LSFT(KC_D), LSFT(KC_F), LSFT(KC_G), LSFT(KC_H), LSFT(KC_J), LSFT(KC_K), LSFT(KC_L), LSFT(KC_SCLN), LSFT(KC_QUOT), KC_ENT,
    KC_LSFT, LSFT(KC_Z), LSFT(KC_X), LSFT(KC_C), LSFT(KC_V), LSFT(KC_B), LSFT(KC_N), LSFT(KC_M), LSFT(KC_COMM), LSFT(KC_DOT), LSFT(KC_SLSH), KC_UP,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
),
  /*
  * Layer _FN2_LAYER
    * -----------------------------------------------------------------------------------------.
  * |    |    |    |   ͵   |     |     |     |    |       |  ϗ    | ͼ|  ͽ |  ˘|   ῀ |  BSPC   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  ϑ  | ͷ  |  ϵ  |  ϱ  |  ϛ  |  ϳ   |    | ι   |     | ϖ   | ῾    | ᾿   |   ᾿    |
  * |-----------------------------------------------------------------------------------------+
  * | Del   |    |   ϲ  | ͻ  |  ϕ   |  ϙ  |  ͱ  |  ϸ  |  ϰ   |    |      |      |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      | ϡ | ͳ |  ϟ |  ϝ |  ϐ     |  |  ϻ  |       |     |    ´      |      UP      |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  LEFT  |  DWN  | RGHT  |
  * \-----------------------------------------------------------------------------------------/
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN2_LAYER] = KEYMAP( /* AltGr Depressed */
    KC_NO, KC_NO, KC_NO, RALT(KC_F3), KC_NO, KC_NO, KC_NO, KC_NO, RALT(KC_F8), RALT(KC_F9), RALT(KC_F10), RALT(KC_F11), RALT(KC_F12), KC_BSPC,
    TD(TD_TAB_LS3), RALT(KC_Q), RALT(KC_W), RALT(KC_E), RALT(KC_R), RALT(KC_T), RALT(KC_Y), KC_NO, RALT(KC_I), KC_NO, RALT(KC_P), RALT(KC_LBRC), RALT(KC_RBRC), RALT(KC_BSLS),
    KC_DEL, KC_NO, RALT(KC_S), RALT(KC_D), RALT(KC_F), RALT(KC_G), RALT(KC_H), RALT(KC_J), RALT(KC_K), KC_NO, KC_NO, KC_NO, KC_ENT,
    LALT(KC_LSFT), RALT(KC_Z), RALT(KC_X), RALT(KC_C), RALT(KC_V), RALT(KC_B), KC_NO, RALT(KC_M), KC_NO, KC_NO, RALT(KC_SLSH), KC_UP,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
 ),
/*
  * Layer _FN3_LAYER
    * -----------------------------------------------------------------------------------------.
  * |    |    |    |   ʹ  |     |     |     |    |   Ϗ    |      | Ͼ|  Ͽ |  ¯|   ¨ |  BSPC    |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  ϴ  | Ͷ  |  ϶  |  ϼ  |  Ϛ  |     |    | ϒ   |     |    |     |    |            |
  * |-----------------------------------------------------------------------------------------+
  * | Del   |    |   Ϲ  | Ͻ  |     |  Ϙ  |  Ͱ  |  Ϸ |     |    |      |      |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      | Ϡ | Ͳ |  Ϟ |      Ϝ   |    |  |  Ϻ  |     |     |    ͺ      |      UP      |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  LEFT  |  DWN  | RGHT |
  * \-----------------------------------------------------------------------------------------/
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN3_LAYER] = KEYMAP( /* AltGr and LSFT depressed */
    KC_NO, KC_NO, KC_NO, RALT(LSFT(KC_F3)), KC_NO, KC_NO, KC_NO, RALT(LSFT(KC_F7)), KC_NO, RALT(LSFT(KC_F9)), RALT(LSFT(KC_F10)), RALT(LSFT(KC_F11)), RALT(LSFT(KC_F12)), KC_BSPC,
    TD(TD_TAB_LS4), RALT(LSFT(KC_Q)), RALT(LSFT(KC_W)), RALT(LSFT(KC_E)), RALT(LSFT(KC_R)), RALT(LSFT(KC_T)), KC_NO, RALT(LSFT(KC_U)), RALT(LSFT(KC_I)), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_DEL, KC_NO, RALT(LSFT(KC_S)), RALT(LSFT(KC_D)), KC_NO, RALT(LSFT(KC_G)), RALT(LSFT(KC_H)), RALT(LSFT(KC_J)), KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT,
    LALT(KC_LSFT), RALT(LSFT(KC_Z)), RALT(LSFT(KC_X)), RALT(LSFT(KC_C)), RALT(LSFT(KC_V)), KC_NO, KC_NO, RALT(LSFT(KC_M)), KC_NO, KC_NO, RALT(LSFT(KC_SLSH)), KC_UP,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
 ),
/*
  * Layer _FN4_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  | BT1 | BT2 | BT3 | BT4 |  LEDOF |  LEDON|  LEDN |LEDP| LEDNI | LEDS |USB | UNP  |  |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
[_FN4_LAYER] = KEYMAP( /* Bluetooth and LED settings layer */
   KC_TRNS, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_AP_LED_OFF, KC_AP_LED_ON, KC_AP_LED_NEXT_PROFILE, KC_AP_LED_PREV_PROFILE, KC_AP_LED_NEXT_INTENSITY, KC_AP_LED_SPEED, KC_AP2_USB, KC_AP2_BT_UNPAIR, KC_NO,
   TD(TD_TAB_LS1), KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, KC_TRNS,
   KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS,
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS,
   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN1_LAYER), MO(_FN2_LAYER), KC_TRNS
), 
};
const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

// Code to run after initializing the keyboard
void keyboard_post_init_user(void) {
    // Here are two common functions that you can use. For more LED functions, refer to the file "qmk_ap2_led.h"

    // annepro2-shine disables LEDs by default. Uncomment this function to enable them at startup.
    annepro2LedEnable();

    // Additionally, it also chooses the first LED profile by default. Refer to the "profiles" array in main.c in
    // annepro2-shine to see the order. Replace "i" with the index of your preferred profile. (i.e the RED profile is index 0)
    annepro2LedSetProfile(2);
}

layer_state_t layer_state_set_user(layer_state_t layer) {
  switch(get_highest_layer(layer)) {
    case _BASE_LAYER:
      annepro2LedSetProfile(0);
      break;
    case _FN1_LAYER:
      annepro2LedSetProfile(1);
      break;
    case _FN2_LAYER:
      annepro2LedSetProfile(2);
      break;
    case _FN3_LAYER:
      annepro2LedSetProfile(3);
      break; 
    case _FN4_LAYER:
      annepro2LedSetProfile(4);
      break; 
    default:
      annepro2LedSetProfile(5);
      break;
  }
  return layer;
}

// The function to handle the caps lock logic
// It's called after the capslock changes state or after entering layers 1 and 2.
bool led_update_user(led_t leds) {
  if (leds.caps_lock) {
    // Set the caps-lock to red
    const annepro2Led_t color = {
        .p.red = 0xff,
        .p.green = 0x00,
        .p.blue = 0x00,
        .p.alpha = 0xff
    };

    annepro2LedMaskSetKey(2, 0, color);
    /* NOTE: Instead of colouring the capslock only, you can change the whole
       keyboard with annepro2LedSetForegroundColor */
  } else {
    // Reset the capslock if there is no layer active
    if(!layer_state_is(_FN1_LAYER) && !layer_state_is(_FN2_LAYER)) {
      const annepro2Led_t color = {
          .p.red = 0xff,
          .p.green = 0x00,
          .p.blue = 0x00,
          .p.alpha = 0x00
      };
      annepro2LedMaskSetKey(2, 0, color);
    }
  }

  return true;
}
