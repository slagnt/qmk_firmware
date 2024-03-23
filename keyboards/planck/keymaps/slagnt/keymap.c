#include "planck.h"
#include "action_layer.h"
#include <print.h>

extern keymap_config_t keymap_config;

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
  /*
  NUMBER,
  PUNCT,
  NAV,
  OTHER,
  */
  RUS,
  ENG,
  /*
  DOTCOMM,
  BSDEL,
  UC_TEST,
  LALT_DOT
  */
  GENPASS,
  PASS1,
  PASS2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak (Default)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   X  |   C  |   V  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |      |
 * |  Win |      |      |      |      |      |      |      |      |      |      |  Win |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |      |
 * | Ctrl | Ctrl |      |      | Ctrl |      |      | Ctrl |      |      | Ctrl | Ctrl |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | CL   |      |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |      |
 * |  Alt |  Alt |      |      |  Alt |      |      |  Alt |      |      |  Alt |  Alt |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  CAD |      |      |  BS  | Space| Space|Return|      |  App |WinLck|      |
 * |  Nav |      |      | Shift| Punct|Number|Number|  Nav | Shift|      |      |  Nav |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {LGUI_T(KC_ESC),      KC_X,               KC_C,             KC_V,             KC_P,                 KC_Y,
   KC_F,                KC_G,               KC_C,             KC_R,             KC_L,                 RGUI_T(XXXXXXX)},

  {LCTL_T(KC_TAB),      LCTL_T(KC_A),       KC_O,             KC_E,             LCTL_T(KC_U),         KC_I,
   KC_D,                RCTL_T(KC_H),       KC_T,             KC_N,             RCTL_T(KC_S),         KC_RCTL},

  {LALT_T(KC_CLCK),     KC_LALT,            KC_Q,             KC_J,             LALT_T(KC_K),         KC_X,
   KC_B,                RALT_T(KC_M),       KC_W,             KC_V,             RALT_T(KC_Z),         KC_RALT},

  {MO(_NAV),            LALT(LCTL(KC_DEL)), XXXXXXX,          KC_LSHIFT,        LT(_PUNCT, KC_BSPC),  LT(_NUMBER, KC_SPC),
  LT(_NUMBER, KC_SPC),  LT(_NAV, KC_ENT),   KC_RSHIFT,        KC_APP,           LGUI(KC_L),           MO(_NAV)}
},

//LALT_T(KC_DOT)
//C_S_T(kc)       Left Control and Shift when held, kc when tapped
//LCTL(KC_LSFT)   Left Control and Shift
//RCTL(KC_RSFT)
//PUNCT_BSPC LT(_PUNCT, KC_BSPC)
/*
  {MO(_NAV),            RUS,            LGUI_T(KC_QUES),  LALT_T(KC_COMM),  LT(_NUMBER, KC_DOT),  LT(_PUNCT, KC_BSPC),
   LT(_OTHER, KC_ENT),  KC_SPC,         KC_BTN1,          RALT_T(KC_BTN2),  ENG,                  MO(_NAV)}
   */

/* Qwerty for Russian
 * ,-----------------------------------------------------------------------------------.
 * |      |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   "  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   `  |   ]  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {_______, KC_Q,         KC_W,           KC_E,           KC_R,             KC_T,
   KC_Y,    KC_U,         KC_I,           KC_O,           KC_P,             RGUI_T(KC_LBRC)},
  {_______, LCTL_T(KC_A), KC_S,           KC_D,           LCTL_T(KC_F),     KC_G,
   KC_H,    RCTL_T(KC_J), KC_K,           KC_L,           RCTL_T(KC_SCLN),  RCTL_T(KC_QUOT)},
  {_______, LALT_T(KC_Z), KC_X,           KC_C,           LALT_T(KC_V),     KC_B,
   KC_N,    RALT_T(KC_M), KC_COMM,        KC_DOT,         RALT_T(KC_GRV),   RALT_T(KC_RBRC)},
  {_______, _______,      _______,        _______,        _______,          _______,
   _______, _______,      _______,        _______,        _______,          _______}
},

/* Number
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  | PrSc | NuLo |   7  |   8  |   9  |   /  |   *  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  | ScLo |   .  |   4  |   5  |   6  |   -  |   +  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 | PaBr |   0  |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_NUMBER] = {
  {_______, KC_F1,        KC_F2,   KC_F3,   KC_F4,          KC_PSCR, KC_NLCK, KC_7,         KC_8,    KC_9,     KC_PSLS,         RGUI_T(KC_PAST)},
  {_______, LCTL_T(KC_F5),KC_F6,   KC_F7,   LCTL_T(KC_F8),  KC_SLCK, KC_DOT,  RCTL_T(KC_4), KC_5,    KC_6,     RCTL_T(KC_PMNS), RCTL_T(KC_PPLS)},
  {_______, LALT_T(KC_F9),KC_F10,  KC_F11,  LALT_T(KC_F12), KC_PAUS, KC_0,    RALT_T(KC_1), KC_2,    KC_3,     RALT_T(XXXXXXX), _______},
  {_______, _______,      _______, _______, _______,        _______, _______, _______,      _______, _______,  _______,         _______}
},

/* Punct
 * ,-----------------------------------------------------------------------------------.
 * |      |   &  |   |  |   \  |   /  |   +  |   =  |   [  |   ]  |   <  |   >  |   ^  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   ~  |   `  |   '  |   "  |   _  |   -  |   (  |   )  |   .  |   ,  |   $  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   #  |   ?  |   !  |   *  |   :  |   ;  |   {  |   }  |   @  |   %  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PUNCT] = {
  {_______, KC_AMPR,KC_PIPE,KC_BSLS,KC_SLSH,KC_PLUS,KC_EQL, KC_LBRC,KC_RBRC,KC_LABK,KC_RABK,KC_CIRC},
  {_______, KC_TILD,KC_GRV, KC_QUOT,KC_DQUO,KC_UNDS,KC_MINS,KC_LPRN,KC_RPRN,KC_DOT, KC_COMM,KC_DLR},
  {_______, KC_HASH,KC_QUES,KC_EXLM,KC_ASTR,KC_COLN,KC_SCLN,KC_LCBR,KC_RCBR,KC_AT,  KC_PERC,KC_RALT},
  {_______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______}
},

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |  ENG |      |GENPAS|ClHome| Home |PgDown| PgUp | ClEnd|ClHome|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  RUS |      | PASS1|ClLeft| Left | Down |  Up  | Right|CRight|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | RESET| DEBUG|      |      | PASS2|  Del |AlLeft|AlDown| AlUp |AlRght|  Ins |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_NAV] = {
  {_______,         XXXXXXX,        XXXXXXX,      ENG,          XXXXXXX,        GENPASS,
   LCTL(KC_HOME),   KC_HOME,        KC_PGDN,      KC_PGUP,      KC_END,         LCTL(KC_END)},

  {_______,         LCTL_T(XXXXXXX),XXXXXXX,      RUS,          LCTL_T(XXXXXXX),PASS1,
   LCTL(KC_LEFT),   RCTL_T(KC_LEFT),KC_DOWN,      KC_UP,        RCTL_T(KC_RGHT),LCTL(KC_RGHT)},

  {_______,         RESET,          DEBUG,        XXXXXXX,      LALT_T(XXXXXXX),PASS2,
   KC_DEL,          LALT(KC_LEFT),  LALT(KC_DOWN),LALT(KC_UP),  LALT(KC_RGHT),  KC_INS},

  {_______,         _______,        _______,      _______,      _______,        _______,
   _______,         _______,        _______,      _______,      _______,        _______}
},

/* Other
 * ,-----------------------------------------------------------------------------------.
 * | Reset| Debug|      |      |      |      |      | Mute |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  ENG |      |      |  RUS |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_OTHER] = {
  {RESET,  DEBUG,  XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,MU_TOG, XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX},
  {XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,ENG,    XXXXXXX,XXXXXXX,RUS,    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX},
  {XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX},
  {_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/*
[_ADJUST] = {
  {_______, RESET,   DEBUG,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}
*/

};
/*
#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif
*/

uint32_t layer_state_set_user(uint32_t state) {
  return state;
}

void matrix_init_user(void) {
  set_unicode_input_mode(UC_WIN);
}

//IS_LAYER_ON
// bool altmod(uint16_t kc_0, uint16_t kc_1, keyrecord_t *record, bool mods)
// {
//   uint16_t kc = kc_0;
//     // if ((keyboard_report->mods & MOD_BIT (KC_LSFT)) || (keyboard_report->mods & MOD_BIT (KC_RSFT))) {

//   if (record->event.pressed) {
//     mods = keyboard_report->mods;
//     if (mods) {
//       kc = kc_1;
//     }
//     register_code (kc);
//   }
//   else {
//     if (mods) {
//       kc = kc_1;
//     }
//     unregister_code (kc);
//   }

//   return mods;
// }

void eng_on(void)
{
  dprintf("Eng on\n");
  SEND_STRING(SS_LCTRL(SS_TAP(X_LSHIFT)));
  SEND_STRING(SS_LALT(SS_TAP(X_LSHIFT)));
  // SEND_STRING(SS_LCTRL(SS_LSFT("1")));
  layer_off(_QWERTY);
}

void rus_on(void)
{
  dprintf("Rus on\n");
  SEND_STRING(SS_LCTRL(SS_TAP(X_LSHIFT)));
  SEND_STRING(SS_LALT(SS_TAP(X_LSHIFT)));
  // SEND_STRING(SS_LCTRL(SS_LSFT("2")));
  layer_on(_QWERTY);
}

void gen_password(char *password, uint16_t size, uint16_t seed)
{
  char symbols[94] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890%&|\\/+=[]<>^@~`'\"_-().,$#?!*:;{}";
  uint16_t n = sizeof(symbols);
  static bool seed_ok = false;

  if(!seed_ok)
  {
    dprintf("%d\n", seed);
    srand(seed);
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
  static uint16_t prev_keycode = 0;
  static bool is_rus_on = false;
  static char password1[16] = {};
  static char password2[16] = {};

  // dprintf("%b\t%X\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", keycode, keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.reserved2, record->tap.reserved1, record->tap.reserved0, record->tap.count);

  //dprintf("D %X\tQ %X\tP %X\tNu %X\tNa %X\tO %X\t%X\t%X\n", IS_LAYER_ON(_DVORAK), IS_LAYER_ON(_QWERTY), IS_LAYER_ON(_PUNCT), IS_LAYER_ON(_NUMBER), IS_LAYER_ON(_NAV), IS_LAYER_ON(_OTHER), keycode, keyboard_report->mods);
  dprintf("%X\t%X\n", keyboard_report->mods, keycode);

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
      }
    }
    else
    {
      if( is_rus_on )
      {
        dprintf("QWERTY on\n");
        layer_on(_QWERTY);
      }
    }
  }
     //if ((keyboard_report->mods & MOD_BIT (KC_LSFT)) || (keyboard_report->mods & MOD_BIT (KC_RSFT))) {

  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    // case LALT_DOT:
    //   if (record->event.pressed)
    //   {
    //     is_rus_on = IS_LAYER_ON(_QWERTY);
    //     if( is_rus_on )
    //     {
    //       register_code(LALT_T(KC_SLSH));
    //     }
    //     else
    //     {
    //       register_code(LALT_T(KC_DOT));
    //     }
    //   }
    //   else
    //   {
    //     if( is_rus_on )
    //     {
    //       unregister_code(LALT_T(KC_SLSH));
    //     }
    //     else
    //     {
    //       unregister_code(LALT_T(KC_DOT));
    //     }
    //   }
    //   return false;
    //   break;
    // case PUNCT_BSPC:
    //   if (record->event.pressed)
    //   {
    //     qwerty_on = IS_LAYER_ON(_QWERTY);
    //     if( qwerty_on )
    //     {
    //       layer_off(_QWERTY);
    //     }
    //   }
    //   else
    //   {
    //     if( qwerty_on )
    //     {
    //       layer_on(_QWERTY);
    //     }
    //   }
    //   break;
    // case UC_TEST:
    //   if (record->event.pressed) {
    //     unicode_input_start();
    //     register_hex(0x03C7);
    //     unicode_input_finish();
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
        gen_password(password1, sizeof(password1), prev_keycode);
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
    // case DOTCOMM:
    //   dotcomm_mods = altmod(KC_DOT, KC_COMM, record, dotcomm_mods);
    //   return false;
    //   break;
    // case BSDEL:
    //   bsdel_mods = altmod(KC_BSPC, KC_DEL, record, bsdel_mods);
    //   return false;
    //   break;
      /*
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;


    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        PORTE &= ~(1<<6);
      } else {
        unregister_code(KC_RSFT);
        PORTE |= (1<<6);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
      */
  }

  if(keycode!=LT(_NAV, KC_ENT))
  {
    prev_keycode = keycode;
  }

  return true;
}
/*
bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
*/
/*
const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(0),  // Calls action_function()
};
*/