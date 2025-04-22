#include QMK_KEYBOARD_H
#include "process_repeat_key.h"

enum layers {
    _QWERTY,
    _GAMING1,
    _GAMING2,
    _GAMING2a,
    _GAMING2b,
    _GAMING3,
    _GAMING4,
    _NAVIGATION,
    _SYMBOLS,
    _NUMBERS,
    _SYSTEM,
    _LAYERS
};

enum custom_keycodes {
    ALT_TAB = SAFE_RANGE,
};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

// Layer keys
#define LAYERS MO(_LAYERS)
#define THUMB1 MO(_NUMBERS)
#define THUMB2 MT(MOD_LSFT, KC_SPC)
#define THUMB3 MT(MOD_LCTL, KC_BSPC)
#define THUMB4 MT(MOD_LALT, KC_ESC)
#define THUMB5 LT(_SYMBOLS, KC_ENT)
#define THUMB6 LT(_SYSTEM, KC_LGUI)

#define TL_BASE TO(_QWERTY)

#define TL_G(x) TG(_GAMING##x)
#define LA_G2a MO(_GAMING2a)
#define LA_G2b MO(_GAMING2b)

#define OSM_SFT OSM(MOD_LSFT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_GUI OSM(MOD_LGUI)

// Layer tap key with no practical use because layer 0 is always active
#define NUM_(x) LT(0, KC_##x)
#define NUM_EQL LT(0, KC_EQL)
#define NUM_DOT LT(0, KC_DOT)
#define NUM_COMM LT(0, KC_COMM)

// Random unused range since regular number range is already being used by NUM_(x) macro
#define NAV_(x) LT(0, 0x0058 + 0x000##x)
#define NAV_0 LT(0, 0x0062)
#define NAV_L LT(0, KC_L)
#define NAV_H LT(0, KC_H)
#define NAV_J LT(0, KC_J)
#define NAV_K LT(0, KC_K)

#define OSL_NAV OSL(_NAVIGATION)

#define NXT_TAB LCTL(KC_PGDN)
#define PRV_TAB LCTL(KC_PGUP)

// #define CPY_PST TD(TD_COPY_PASTE)
#define CPY_PST LT(0, KC_NO)

const uint16_t PROGMEM tab[] = {THUMB2, THUMB5, COMBO_END};
const uint16_t PROGMEM caps[] = {THUMB3, THUMB4, COMBO_END};
const uint16_t PROGMEM caps2[] = {KC_LSFT, KC_RSFT, COMBO_END};

combo_t key_combos[] = {
    COMBO(tab, KC_TAB),
    COMBO(caps, KC_CAPS),
    COMBO(caps2, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  NAV_(1), NAV_(2), NAV_(3), NAV_(4), NAV_(5),                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  LAYERS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     ALT_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     NAV_(6), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_COLN, NAV_(8),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     NAV_(7), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    OSL_NAV,          KC_PSCR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, NAV_(9),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    THUMB1,  THUMB2,  THUMB3,                    THUMB4,  THUMB5,  THUMB6
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  /*
       + ( ) `    # ] [ %
     ? ' = - |    & } { " ;
     ! < * _ ~    @ $ ^ > \
  */

  [_SYMBOLS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, KC_PLUS, KC_LPRN, KC_RPRN, KC_GRV,                             KC_HASH, KC_RBRC, KC_LBRC, KC_PERC, XXXXXXX, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_QUES, KC_QUOT, KC_EQL,  KC_MINS, KC_PIPE,                            KC_AMPR, KC_RCBR, KC_LCBR, KC_DQUO, KC_SCLN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM, KC_LT,   KC_ASTR, KC_UNDS, KC_TILD, _______,          _______, KC_AT,   KC_DLR,  KC_CIRC, KC_GT,   KC_BSLS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAVIGATION] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, NAV_(6), NAV_(7), NAV_(8), NAV_(9), NAV_0,                              _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, G(KC_Q), G(KC_W), G(KC_E), G(KC_R), G(KC_T),                            G(KC_Y), G(KC_U), G(KC_I), G(KC_O), G(KC_P), _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, G(KC_A), G(KC_S), G(KC_D), G(KC_F), G(KC_G),                            NAV_H,   NAV_J,   NAV_K,   NAV_L,  G(KC_SCLN),_______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), G(KC_B), _______,          _______, G(KC_N), G(KC_M),G(KC_COMM),G(KC_DOT),G(KC_SLSH),_______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                  G(KC_ESC),G(KC_ENT),_______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMBERS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, KC_F10,  KC_F11,  KC_F12,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, _______,                            _______, NUM_(7), NUM_(8), NUM_(9), _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, OSM_ALT, OSM_CTL, OSM_SFT, OSM_GUI, KC_NUM,                             _______, NUM_(4), NUM_(5), NUM_(6), _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_EQL,  KC_COMM, KC_DOT,  _______, _______,          _______, _______, NUM_(1), NUM_(2), NUM_(3), _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   KC_SPC,  KC_0,    KC_BSPC
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYSTEM] = LAYOUT(

  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX,                            XXXXXXX, KC_PSCR, KC_PSCR, XXXXXXX, XXXXXXX, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MSTP, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, _______,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAMING1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TL_G(1),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, KC_LALT,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAMING2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TL_G(2),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     LA_G2a,  KC_G,    KC_A,    KC_S,    KC_D,    KC_F,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LA_G2b,  KC_B,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_LALT,          _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, KC_SPC,  KC_LSFT,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAMING2a] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                               _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,                               _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_BSPC, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAMING2b] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                             _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F11,  KC_F12,  _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAMING3] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TL_G(3),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_UP,   KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_LEFT, KC_DOWN, KC_RGHT, KC_SCLN, KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,          _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, KC_SPC,  KC_LSFT,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAMING4] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TL_G(4),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_T,    KC_Q,    KC_UP,   KC_E,    KC_R,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_G,    KC_LEFT, KC_DOWN, KC_RGHT, KC_F,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_B,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_LALT,          _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, KC_SPC,  KC_LSFT,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LAYERS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, TL_G(1), TL_G(2), TL_G(3), TL_G(4), XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )


/*
  [_TEMPLATE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,          _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

*/
};

#ifdef KEYBOARD_keebio_iris_rev4
const rgblight_segment_t PROGMEM swap_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_WHITE}       // Light 12 LEDs in white, starting with LED 0
);
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 2, HSV_BLUE}
);
const rgblight_segment_t PROGMEM gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_RED}
);
const rgblight_segment_t PROGMEM gaming1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM system_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_CYAN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    capslock_layer,
    gaming1_layer,
    gaming_layer,
    system_layer,
    swap_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_toggle();
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _GAMING1));
    rgblight_set_layer_state(2, layer_state_cmp(state, _GAMING2) ||
                                layer_state_cmp(state, _GAMING3) ||
                                layer_state_cmp(state, _GAMING4));
    rgblight_set_layer_state(3, layer_state_cmp(state, _NAVIGATION));
    rgblight_set_layer_state(4, layer_state_cmp(state, _LAYERS));
    return state;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LSFT:
        case KC_RSFT:
            // Detect the activation of both Shifts
            if ((get_mods() & MOD_MASK_SHIFT) == MOD_MASK_SHIFT) {
                tap_code(KC_CAPS);
            }
            return true;

        case OSM_GUI:
        case OSM_SFT:
        case OSM_CTL:
        case OSM_ALT:
            // Register both one shot mods and regular mods when hold is registered
            // This way pressing 2 one shot mods in quick succession chains them
            if (record->event.pressed) {
                // 5 and 8 bit formats are the same here, since we're only dealing with left modifiers
                add_oneshot_mods((keycode)&0xF);
                if (record->tap.count == 0) {
                    register_mods((keycode)&0xF);
                }
            } else {
                if (record->tap.count == 0) {
                    unregister_mods((keycode)&0xF);
                }
            }
            return false;

        case NUM_(1) ... NUM_(9):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_F1 - KC_1 + QK_LAYER_TAP_GET_TAP_KEYCODE(keycode));
                return false;
            }
            return true;
        case NUM_EQL:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_F11);
                return false;
            }
            return true;
        case NUM_DOT:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_F10);
                return false;
            }
            return true;
        case NUM_COMM:
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_F12);
                return false;
            }
            return true;

        case NAV_(1) ... NAV_0:
            if (record->event.pressed) {
                if (record->tap.count) {
                    tap_code16(LGUI(keycode - NAV_(1) + KC_1));
                } else {
                    tap_code16(LSG(keycode - NAV_(1) + KC_1));
                }
            }
            return false;

        case NAV_L:
            if (record->event.pressed) {
                if (record->tap.count) {
                    tap_code16(LGUI(KC_L));
                } else {
                    tap_code16(LSG(KC_L));
                }
            }
            return false;
        case NAV_H:
            if (record->event.pressed) {
                if (record->tap.count) {
                    tap_code16(LGUI(KC_H));
                } else {
                    tap_code16(LSG(KC_H));
                }
            }
            return false;
        case NAV_J:
            if (record->event.pressed) {
                if (record->tap.count) {
                    tap_code16(LGUI(KC_J));
                } else {
                    tap_code16(LSG(KC_J));
                }
            }
            return false;
        case NAV_K:
            if (record->event.pressed) {
                if (record->tap.count) {
                    tap_code16(LGUI(KC_K));
                } else {
                    tap_code16(LSG(KC_K));
                }
            }
            return false;

        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;

        case CPY_PST:
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C));
            } else if (record->event.pressed) {
                tap_code16(C(KC_V));
            }
            return false;

        default:
            return true;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case THUMB5:
        case THUMB2:
        case THUMB3:
        case THUMB4:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1000) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

// helper function to apply 8-bit mods to the given keycode
uint16_t apply_mods(uint16_t keycode, uint8_t mods) {
    // Convert 8-bit mods to the 5-bit format used in keycodes. This is lossy:
    // if left and right handed mods were mixed, they all become right handed.
    uint8_t mods_5_bit = ((mods & 0xf0) ? /* set right hand bit */ 0x10 : 0)
        // Combine right and left hand mods.
        | (((mods >> 4) | mods) & 0xf);

    return ((mods_5_bit << 8) | keycode);
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    // If Gui was held and Gui/Shift are the only mods
    if ((mods & MOD_MASK_GUI) && !(mods & ~(MOD_MASK_SG))) {
        switch (keycode) {
            case KC_J: return G(KC_K);  // Gui + J reverses to Gui + K.
            case KC_K: return G(KC_J);
            case KC_H: return G(KC_L);
            case KC_L: return G(KC_H);
            case KC_1 ... KC_0: return G(keycode);
            case NUM_(1) ... NUM_(9): return G(QK_LAYER_TAP_GET_TAP_KEYCODE(keycode));
        }
    } else if (mods == MOD_BIT_LCTRL) {
        switch (keycode) {
            case KC_R: return C(KC_F);
            case KC_C: return C(KC_V);
            case KC_V: return C(KC_C);
        }
    }

    return KC_TRNS;  // Defer to default definitions.
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
    if (!(*remembered_mods)) {
        return false;
    }

    return true;
}
