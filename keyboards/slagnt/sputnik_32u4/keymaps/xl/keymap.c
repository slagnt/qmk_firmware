#include "sputnik.h"
//#include "action_layer.h"
#include <print.h>
#include <string.h>
#include QMK_KEYBOARD_H

//extern keymap_config_t keymap_config;

enum custom_layers {
  _DVORAK,
  _QWERTY,
  _NUMBER,
  _PUNCT,
  _NAV,
  _OTHER
};

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  RUS,
  ENG,
  GENPASS,
  PASS1,
  PASS2,
  CLR_KB
};

// //LALT_T(KC_DOT)
// //C_S_T(kc)       Left Control and Shift when held, kc when tapped
// //LCTL(KC_LSFT)   Left Control and Shift
// //RCTL(KC_RSFT)
// //PUNCT_BSPC LT(_PUNCT, KC_BSPC)
// /*
//   {MO(_NAV),            RUS,            LGUI_T(KC_QUES),  LALT_T(KC_COMM),  LT(_NUMBER, KC_DOT),  LT(_PUNCT, KC_BSPC),
//    LT(_OTHER, KC_ENT),  KC_SPC,         KC_BTN1,          RALT_T(KC_BTN2),  ENG,                  MO(_NAV)}
//    */

//  * .-----------------------------------------------------------------------------------.
//  * | Esc  |   X  |   C  |   V  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |      |
//  * |      |  Win |      |      |  Win |      |      |  Win |      |      |  Win |      |
//  * |------+------+------+------+------+-------------+------+------+------+------+------|
//  * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |      |
//  * |      | Ctrl |      |      | Ctrl |      |      | Ctrl |      |      | Ctrl |      |
//  * '------+------+------+------+------+------|------+------+------+------+------+------'
//  *        |      |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |
//  *        |  Alt |      |      |  Alt |      |      |  Alt |      |      |  Alt |
//  *        '------+------+------+------+------+------+------+------+------+------'
//  *                      |      |  BS  | Space| Space|Return|      |
//  *                      | Shift|Punct |Number|Number|  Nav | Shift|
//  *                      '-----------------------------------------'
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT(
    KC_ESC, LGUI_T(KC_X), KC_C, KC_V, LGUI_T(KC_P), KC_Y, KC_F, RGUI_T(KC_G), KC_C, KC_R, RGUI_T(KC_L), XXXXXXX,
    KC_TAB, LCTL_T(KC_A), KC_O, KC_E, LCTL_T(KC_U), KC_I, KC_D, RCTL_T(KC_H), KC_T, KC_N, RCTL_T(KC_S), XXXXXXX,
            LALT_T(KC_S), KC_Q, KC_J, LALT_T(KC_K), KC_X, KC_B, RALT_T(KC_M), KC_W, KC_V, RALT_T(KC_Z),

     KC_LSFT, LT(_PUNCT, KC_BSPC), LT(_NUMBER, KC_SPC), LT(_NUMBER, KC_SPC), LT(_NAV, KC_ENT), KC_RSFT
  ),

//  * .-----------------------------------------------------------------------------------.
//  * |      |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |
//  * |------+------+------+------+------+-------------+------+------+------+------+------|
//  * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   "  |
//  * '------+------+------+------+------+------|------+------+------+------+------+------'
//  *        |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   ]  |
//  *        '------+------+------+------+------+------+------+------+------+------'
//  *                      |      |  BS  |      |      |      |   `  |
//  *                      |      |      |      |      |      | Shift|
//  *                      '-----------------------------------------'
  [_QWERTY] = LAYOUT(
    _______, LGUI_T(KC_Q), KC_W, KC_E, LGUI_T(KC_R), KC_T, KC_Y, RGUI_T(KC_U), KC_I,    KC_O,   RGUI_T(KC_P),    KC_LBRC,
    _______, LCTL_T(KC_A), KC_S, KC_D, LCTL_T(KC_F), KC_G, KC_H, RCTL_T(KC_J), KC_K,    KC_L,   RCTL_T(KC_SCLN), KC_QUOT,
             LALT_T(KC_Z), KC_X, KC_C, LALT_T(KC_V), KC_B, KC_N, RALT_T(KC_M), KC_COMM, KC_DOT, RALT_T(KC_RBRC),
                           _______, _______, _______, _______, _______, RSFT_T(KC_GRV)
  ),

//  * .-----------------------------------------------------------------------------------.
//  * |      |  F1  |  F2  |  F3  |  F4  | PrSc | NuLo |   7  |   8  |   9  |   /  |   *  |
//  * |------+------+------+------+------+-------------+------+------+------+------+------|
//  * |      |  F5  |  F6  |  F7  |  F8  | ScLo |   .  |   4  |   5  |   6  |   -  |   +  |
//  * '------+------+------+------+------+------|------+------+------+------+------+------|
//  *        |  F9  |  F10 |  F11 |  F12 | PaBr |   0  |   1  |   2  |   3  |  Ins |
//  *        '------+------+------+------+------+------+------+------+------+------'
//  *                      |      |      |CLR_KB|CLR_KB|      |      |
//  *                      '-----------------------------------------'
  [_NUMBER] = LAYOUT(
    _______, LGUI_T(KC_F1), KC_F2,  KC_F3,  LGUI_T(KC_F4),  KC_PSCR, KC_NUM, RGUI_T(KC_7), KC_8, KC_9, RGUI_T(KC_PSLS), KC_PAST,
    _______, LCTL_T(KC_F5), KC_F6,  KC_F7,  LCTL_T(KC_F8),  KC_SCRL, KC_DOT, RCTL_T(KC_4), KC_5, KC_6, RCTL_T(KC_PMNS), KC_PPLS,
             LALT_T(KC_F9), KC_F10, KC_F11, LALT_T(KC_F12), KC_PAUS, KC_0,   RALT_T(KC_1), KC_2, KC_3, RALT_T(KC_INS),
                                 _______, _______, _______, _______, _______, _______
  ),
//  * .-----------------------------------------------------------------------------------.
//  * |      |   &  |   |  |   \  |   /  |   +  |   =  |   [  |   ]  |   <  |   >  |   ^  |
//  * |------+------+------+------+------+-------------+------+------+------+------+------|
//  * |      |   ~  |   `  |   '  |   "  |   _  |   -  |   (  |   )  |   .  |   ,  |   $  |
//  * '------+------+------+------+------+------|------+------+------+------+------+------'
//  *        |   #  |   ?  |   !  |   *  |   :  |   ;  |   {  |   }  |   @  |   %  |
//  *        '------+------+------+------+------+------+------+------+------+------'
//  *                      |      |      |      |      |      |      |
//  *                      '-----------------------------------------'
  [_PUNCT] = LAYOUT(
    _______, KC_AMPR, KC_PIPE, KC_BSLS, KC_SLSH, KC_PLUS, KC_EQL,  KC_LBRC, KC_RBRC, KC_LABK, KC_RABK, KC_CIRC,
    _______, KC_TILD, KC_GRV,  KC_QUOT, KC_DQUO, KC_UNDS, KC_MINS, KC_LPRN, KC_RPRN, KC_DOT,  KC_COMM, KC_DLR,
             KC_HASH, KC_QUES, KC_EXLM, KC_ASTR, KC_COLN, KC_SCLN, KC_LCBR, KC_RCBR, KC_AT,   KC_PERC,
                               _______, _______, _______, _______, _______, _______
  ),

//  * .-----------------------------------------------------------------------------------.
//  * |      |      | Vol+ |  ENG |      |GENPAS|ClHome| Home |PgDown| PgUp | ClEnd|ClHome|
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      | Vol- |  RUS |      | PASS1|ClLeft| Left | Down |  Up  | Right|CRight|
//  * '------+------+------+------+------+------+------+------+------+------+------+------'
//  *        |      | Mute | DEBUG|      | PASS2|  Del |AlLeft|AlDown| AlUp |AlRght|
//  *        '------+------+------+------+------+------+------+------+------+------'
//  *                      |      |      |      |      |      |      |
//  *                      '-----------------------------------------'
  [_NAV] = LAYOUT(
    _______,LGUI_T(XXXXXXX),KC_VOLU,ENG,    LGUI_T(XXXXXXX),GENPASS,LCTL(KC_HOME),KC_HOME,        KC_PGDN,      KC_PGUP,    KC_END,         LCTL(KC_END),
    _______,LCTL_T(XXXXXXX),KC_VOLD,RUS,    LCTL_T(XXXXXXX),PASS1,  LCTL(KC_LEFT),RCTL_T(KC_LEFT),KC_DOWN,      KC_UP,      RCTL_T(KC_RGHT),LCTL(KC_RGHT),
            LALT_T(XXXXXXX),KC_MUTE,DB_TOGG,LALT_T(XXXXXXX),PASS2,  KC_DEL,       LALT(KC_LEFT),  LALT(KC_DOWN),LALT(KC_UP),LALT(KC_RGHT),
                                            _______,_______,_______,_______,_______,_______
  )/*,

//  * .-----------------------------------------------------------------------------------.
//  * | Reset| Debug|      |      |      |      |      |      |      |      |      |      |
//  * |------+------+------+------+------+------+------+------+------+------+------+------|
//  * |      |      |      |      |      |      |      |      |      |      |      |      |
//  * '------+------+------+------+------+------+------+------+------+------+------+------'
//  *        |      |      |      |      |      |      |      |      |      |      |
//  *        '------+------+------+------+------+------+------+------+------+------'
//  *                      |      |      |      |      |      |      |
//  *                      '-----------------------------------------'
  [_OTHER] = LAYOUT(
    RESET,  DEBUG,  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
            XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                            _______,_______,_______,_______,_______,_______
  )*/
};

// const rgblight_segment_t PROGMEM DVORAK_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 1, HSV_BLUE}
// );
// const rgblight_segment_t PROGMEM QWERTY_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 1, HSV_RED}
// );
// const rgblight_segment_t PROGMEM NUMBER_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 1, RGB_WHITE}
// );
// const rgblight_segment_t PROGMEM PUNCT_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 1, HSV_GREEN}
// );
// const rgblight_segment_t PROGMEM NAV_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 1, HSV_MAGENTA}
// );
// const rgblight_segment_t PROGMEM MOD_D_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 1, HSV_CYAN}
// );
// const rgblight_segment_t PROGMEM MOD_Q_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 1, HSV_YELLOW}
// );
// // const rgblight_segment_t PROGMEM OTHER_layer[] = RGBLIGHT_LAYER_SEGMENTS(
// //     {0, 1, HSV_PURPLE}
// // );

// // Now define the array of layers. Later layers take precedence
// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     // MOD_D_layer,
//     // MOD_Q_layer,
//     DVORAK_layer,
//     QWERTY_layer,
//     NUMBER_layer,
//     PUNCT_layer,
//     NAV_layer
// );

// void keyboard_post_init_user(void) {
//     // rgblight_layers = my_rgb_layers;


//         clock_configure(clk_sys,
//                         CLOCKS_CLK_SYS_CTRL_SRC_VALUE_CLKSRC_CLK_SYS_AUX,
//                         CLOCKS_CLK_SYS_CTRL_AUXSRC_VALUE_CLKSRC_PLL_USB,
//                         1 * MHZ,
//                         1 * MHZ);
// }

// layer_state_t default_layer_state_set_user(layer_state_t state) {
//     return state;
// }

layer_state_t layer_state_set_user(layer_state_t state) {
    // dprintf("state %d\t(%d, %d, %d, %d, %d)\n", state,
    //     layer_state_cmp(state, _DVORAK),
    //     layer_state_cmp(state, _QWERTY),
    //     layer_state_cmp(state, _NUMBER),
    //     layer_state_cmp(state, _PUNCT),
    //     layer_state_cmp(state, _NAV));
    // // rgblight_set_layer_state(keyboard_report->mods?0:2, layer_state_cmp(state, _DVORAK));
    // // rgblight_set_layer_state(keyboard_report->mods?1:3, layer_state_cmp(state, _QWERTY));
    // rgblight_set_layer_state(0, layer_state_cmp(state, _DVORAK));
    // rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
    // rgblight_set_layer_state(2, layer_state_cmp(state, _NUMBER));
    // rgblight_set_layer_state(3, layer_state_cmp(state, _PUNCT));
    // rgblight_set_layer_state(4, layer_state_cmp(state, _NAV));
    return state;
}


// const rgblight_segment_t PROGMEM my_layer0[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 0, HSV_ORANGE}
// );
// const rgblight_segment_t PROGMEM my_layer1[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 7, HSV_RED}
// );
// const rgblight_segment_t PROGMEM my_layer2[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 7, HSV_GREEN}
// );
// const rgblight_segment_t PROGMEM my_layer3[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 7, HSV_CYAN}
// );
// const rgblight_segment_t PROGMEM my_layer4[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 7, HSV_CYAN}
// );

// // Now define the array of layers. Later layers take precedence
// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     my_layer0,
//     my_layer1,
//     my_layer2,
//     my_layer3,
//     my_layer4// Overrides other layers
// );

// void keyboard_post_init_user(void) {
//     // Enable the LED layers
//     rgblight_layers = my_rgb_layers;
// };

// layer_state_t layer_state_set_user(layer_state_t state) {
//     // Both layers will light up if both kb layers are active
//     rgblight_set_layer_state(1, layer_state_cmp(state, 1));
//     rgblight_set_layer_state(2, layer_state_cmp(state, 2));
//     rgblight_set_layer_state(3, layer_state_cmp(state, 3));
//     rgblight_set_layer_state(4, layer_state_cmp(state, 4));
//     return state;
// };

// void matrix_init_user(void) {
//   set_unicode_input_mode(UC_WIN);
// }

void eng_on(void)
{
  dprintf("Eng on\n");
  SEND_STRING(SS_LCTL(SS_TAP(X_LSFT)));
  SEND_STRING(SS_LALT(SS_TAP(X_LSFT)));
  // SEND_STRING(SS_LCTRL(SS_LSFT("1")));
  layer_off(_QWERTY);
}

void rus_on(void)
{
  dprintf("Rus on\n");
  SEND_STRING(SS_LCTL(SS_TAP(X_LSFT)));
  SEND_STRING(SS_LALT(SS_TAP(X_LSFT)));
  // SEND_STRING(SS_LCTRL(SS_LSFT("2")));
  layer_on(_QWERTY);
}

void gen_password(char *password, uint16_t size)
{
  char symbols[94] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890%&|\\/+=[]<>^@~`'\"_-().,$#?!*:;{}";
  uint16_t n = sizeof(symbols);
  static bool seed_ok = false;

  if(!seed_ok)
  {
    //dprintf("%d\n", seed);
    srand(timer_read());
    seed_ok = true;
  }

  for(uint16_t i=0; i<size-1; i++)
  {
    password[i] = symbols[rand() % n];
  }
  password[size-1] = '\0';
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  //static bool dotcomm_mods = false;
  //static bool bsdel_mods = false;
  static bool is_rus_on = false;
  static char password1[16] = {};
  static char password2[16] = {};

  // dprintf("%b\t%X\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", keycode, keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.reserved2, record->tap.reserved1, record->tap.reserved0, record->tap.count);

  //dprintf("D %X\tQ %X\tP %X\tNu %X\tNa %X\tO %X\t%X\t%X\n", IS_LAYER_ON(_DVORAK), IS_LAYER_ON(_QWERTY), IS_LAYER_ON(_PUNCT), IS_LAYER_ON(_NUMBER), IS_LAYER_ON(_NAV), IS_LAYER_ON(_OTHER), keycode, keyboard_report->mods);


    //dprintf("%d\t%X\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", keycode, keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.reserved2, record->tap.reserved1, record->tap.reserved0, record->tap.count);
  //dprintf("%X\t%X\t%X\t%lu\n", record->event.pressed, keyboard_report->mods, keycode, clock_get_hz(clk_sys));

  if( keycode==LT(_PUNCT, KC_BSPC) )
  {
    if (record->event.pressed)
    {
      is_rus_on = IS_LAYER_ON(_QWERTY);
      if( is_rus_on )
      {
        eng_on();
      }
    }
    else
    {
      if( is_rus_on )
      {
        rus_on();
      }
    }
  }
  else if( keyboard_report->mods && (keyboard_report->mods & (MOD_BIT (KC_LSFT) | MOD_BIT (KC_RSFT)))==0 )
  {
    if (record->event.pressed)
    {
      is_rus_on = IS_LAYER_ON(_QWERTY);
      if( is_rus_on )
      {
        dprintf("QWERTY off\n");
        layer_off(_QWERTY);
        // rgblight_set_layer_state(1, true);
        //dprintf("Q Down\n");
      }
    //   else
    //   {
    //     // rgblight_set_layer_state(0, true);
    //     dprintf("D Down\n");
    //   }
    }
    else
    {
      if( is_rus_on )
      {
        dprintf("QWERTY on\n");
        layer_on(_QWERTY);
        // rgblight_set_layer_state(3, true);
        //dprintf("Q Up\n");
      }
    //   else
    //   {
    //     //rgblight_set_layer_state(2, true);
    //     dprintf("D Up\n");
    //   }
    }
  }

  switch (keycode) {
    // case DVORAK:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_DVORAK);
    //   }
    //   return false;
    //   break;
    // case QWERTY:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_QWERTY);
    //   }
    //   return false;
    //   break;
    case ENG:
      if (record->event.pressed) {
        eng_on();
      }
      return false;
      break;
    case RUS:
      if (record->event.pressed) {
        rus_on();
      }
      return false;
      break;
    case GENPASS:
      if (record->event.pressed) {
        strcpy(password2, password1);
        gen_password(password1, sizeof(password1));
        //snprintf(password, sizeof(password), "123");
      }
      return false;
      break;
    case PASS1:
      if (record->event.pressed) {
        send_string(password1);
      }
      return false;
      break;
    case PASS2:
      if (record->event.pressed) {
        send_string(password2);
      }
      return false;
      break;
    case CLR_KB:
      if (record->event.pressed) {
        clear_keyboard();
      }
      return false;
      break;
  }

  return true;
}
