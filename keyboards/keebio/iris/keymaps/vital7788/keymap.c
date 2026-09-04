#include QMK_KEYBOARD_H

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
    _FKEYS,
    _SYSTEM,
    _LAYERS
};

#define OSM_SFT OSM(MOD_LSFT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_GUI OSM(MOD_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  #define LAYERS MO(_LAYERS)
  #define THUMB1 MT(_SYSTEM, KC_TAB)
  #define THUMB2 MT(MOD_LSFT, KC_SPC)
  #define THUMB3 LT(_NUMBERS, KC_BSPC)
  #define THUMB4 MT(MOD_LCTL, KC_ESC)
  #define THUMB5 LT(_SYMBOLS, KC_ENT)
  #define THUMB6 MT(MOD_LALT, KC_TAB)
  #define NAV MO(_NAVIGATION)
  #define FKEYS MO(_FKEYS)

  #define COPY LCTL(KC_INS)
  #define PASTE LSFT(KC_INS)

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5),                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  LAYERS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     PASTE,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     COPY,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_COLN, KC_PSCR,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    NAV,              FKEYS,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_CAPS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    THUMB1,  THUMB2,  THUMB3,                    THUMB4,  THUMB5,  THUMB6
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  /*
       + ( ) `    # ] [ %
     ? ' = - |    & } { " ;
     ! < * _ ~    @ $ ^ > \
  */

  #define LSG_(x) LSG(KC_##x)
  [_SYMBOLS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     OSM_GUI, LSG_(1), LSG_(2), LSG_(3), LSG_(4), LSG_(5),                            LSG_(6), LSG_(7), LSG_(8), LSG_(9), LSG_(0), OSM_GUI,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     OSM_SFT, XXXXXXX, KC_PLUS, KC_LPRN, KC_RPRN, KC_GRV,                             KC_HASH, KC_RBRC, KC_LBRC, KC_PERC, XXXXXXX, OSM_SFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     OSM_CTL, KC_QUES, KC_QUOT, KC_EQL,  KC_MINS, KC_PIPE,                            KC_AMPR, KC_RCBR, KC_LCBR, KC_DQUO, KC_SCLN, OSM_CTL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     OSM_ALT, KC_EXLM, KC_LT,   KC_ASTR, KC_UNDS, KC_TILD, _______,          _______, KC_AT,   KC_DLR,  KC_CIRC, KC_GT,   KC_BSLS, OSM_ALT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_TAB,  _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  #define N_LEFT N(KC_LEFT)
  #define N_DOWN N(KC_DOWN)
  #define N_UP N(KC_UP)
  #define N_RGHT N(KC_RGHT)
  #define N_SCLN N(KC_SCLN)
  #define N_COMM N(KC_COMM)
  #define N_DOT N(KC_DOT)
  #define N_SLSH N(KC_SLSH)

  // Define a series of layer tap keys to use for tap-hold for shifted keys on the navigation layer
  #define N(x) LT(_NAVIGATION, x)

  [_NAVIGATION] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, N(KC_1), N(KC_2), N(KC_3), N(KC_4), N(KC_5),                            N(KC_6), N(KC_7), N(KC_8), N(KC_9), N(KC_0), _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, N(KC_Q), N(KC_W), N(KC_E), N(KC_R), N(KC_T),                            N(KC_Y), N(KC_U), N(KC_I), N(KC_O), N(KC_P), N(KC_DEL),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, N(KC_A), N(KC_S), N(KC_D), N(KC_F), N(KC_G),                            N(KC_H), N(KC_J), N(KC_K), N(KC_L), N_SCLN,  N(KC_PSCR),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, N(KC_Z), N(KC_X), N(KC_C), N(KC_V), N(KC_B), _______,          _______, N(KC_N), N(KC_M), N_COMM,  N_DOT,   N_SLSH,  N(KC_CAPS),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______,N(KC_SPC),N(KC_BSPC),                _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  #define N_HOME N(KC_HOME)
  #define N_END N(KC_END)
  #define N_PGDN N(KC_PGDN)
  #define N_PGUP N(KC_PGUP)

 [_FKEYS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     OSM_GUI, _______, KC_F10,  KC_F11,  KC_F12,  _______,                            _______, _______, _______, _______, _______, OSM_GUI,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     OSM_SFT, KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______,                            _______, KC_7,    KC_8,    KC_9,    _______, OSM_SFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     OSM_CTL, KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______,                            _______, KC_4,    KC_5,    KC_6,    KC_0,    OSM_CTL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     OSM_ALT, KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______, _______,          _______, _______, KC_1,    KC_2,    KC_3,    _______, OSM_ALT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // Layer tap key with no practical use because layer 0 is always active
  #define NUM_(x) LT(0, KC_##x)
  [_NUMBERS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     OSM_GUI, _______, _______, _______, _______, _______,                            _______, KC_F10,  KC_F11,  KC_F12,  _______, OSM_GUI,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     OSM_SFT, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, _______,                            _______, NUM_(7), NUM_(8), NUM_(9), _______, OSM_SFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     OSM_CTL, OSM_GUI, OSM_ALT, OSM_CTL, OSM_SFT, KC_NUM,                             _______, NUM_(4), NUM_(5), NUM_(6), KC_0,    OSM_CTL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     OSM_ALT, _______, KC_EQL,  KC_COMM, KC_DOT,  _______, _______,          _______, _______, NUM_(1), NUM_(2), NUM_(3), _______, OSM_ALT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   KC_SPC,  KC_0,    KC_BSPC
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYSTEM] = LAYOUT(

  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     OSM_GUI, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, OSM_GUI,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     OSM_SFT, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX,                            XXXXXXX, KC_PSCR, KC_PSCR, XXXXXXX, XXXXXXX, OSM_SFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     OSM_CTL, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, OSM_CTL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     OSM_ALT, KC_MSTP, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, _______,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OSM_ALT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  #define TL_G(x) TG(_GAMING##x)
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

  #define LA_G2a MO(_GAMING2a)
  #define LA_G2b MO(_GAMING2b)
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
    rgblight_set_layer_state(3, layer_state_cmp(state, _LAYERS));
    return state;
}
#endif

#ifdef KEYBOARD_keebio_iris_rev8
/*
 * Use this to reset eeprom rgb matrix settings.
void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv(HSV_OFF);
    rgb_matrix_set_speed(127);
}
*/

void rgb_matrix_gaming_indicators(uint8_t led_min, uint8_t led_max, rgb_t rgb, int length, const int indices[]) {
    const rgb_t springgreen = {RGB_SPRINGGREEN};
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
    RGB_MATRIX_INDICATOR_SET_COLOR(34, springgreen.r, springgreen.g, springgreen.b);
    for (int i = 0; i < length; i++) {
        RGB_MATRIX_INDICATOR_SET_COLOR(indices[i], rgb.r, rgb.g, rgb.b);
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // check g_led_config.matrix_co for led positions
    // not sure if this changes. if it does, use lookups instead of hardcoded values
    const int left_wasd[] = {11, 17, 18, 19};
    const int right_wasd[] = {45, 51, 52, 53};
    const int caps_index = 15;
    const rgb_t red = {RGB_RED};
    const rgb_t blue = {RGB_BLUE};
    const rgb_t orange = {RGB_ORANGE};
    const rgb_t springgreen = {RGB_SPRINGGREEN};

    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _LAYERS:
            rgb_matrix_sethsv_noeeprom(HSV_WHITE);
            break;
        case _GAMING1:
            rgb_matrix_sethsv_noeeprom(HSV_OFF);
            RGB_MATRIX_INDICATOR_SET_COLOR(34, springgreen.r, springgreen.g, springgreen.b);
            break;
        case _GAMING2 ... _GAMING2b:
            rgb_matrix_gaming_indicators(led_min, led_max, red, 4, left_wasd);
            break;
        case _GAMING3:
            rgb_matrix_gaming_indicators(led_min, led_max, orange, 4, left_wasd);
            break;
        case _GAMING4:
            rgb_matrix_gaming_indicators(led_min, led_max, orange, 4, right_wasd);
            break;
        default:
            rgb_matrix_sethsv_noeeprom(HSV_OFF);
            if (host_keyboard_led_state().caps_lock) {
                RGB_MATRIX_INDICATOR_SET_COLOR(caps_index, blue.r, blue.g, blue.b);
            }
    }
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
                tap_code16(keycode - NUM_(1) + KC_F1);
                return false;
            }
            return true;

        case N(KC_A) ... N(KC_UP):
            if (record->event.pressed) {
                if (record->tap.count) {
                    tap_code16(keycode - N(KC_A) + KC_A);
                } else {
                    tap_code16(LSFT(keycode - N(KC_A) + KC_A));
                }
            }
            return false;

        case NAV:
            if (record->event.pressed) {
                register_code(KC_LGUI);
            } else {
                unregister_code(KC_LGUI);
            }
            return true;

        default:
            return true;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case THUMB2:
        case THUMB3:
        case THUMB4:
        case THUMB5:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case THUMB2:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}
