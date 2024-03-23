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
  DOTCOMM,
  BSDEL,
  UC_TEST,
  LALT_DOT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak (Default)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |      |      |      |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |      |
 * |CtrlSh|      |      |      |      |      |      |      |      |      |      |CtrlSh|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |      |
 * | Ctrl |      |      |      |      |      |      |      |      |      |      | Ctrl |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | CL   |      |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |      |
 * | Shift|      |      |      |      |      |      |      |      |      |      | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  CAD |   ,  |   .  |  BS  |  Del |Return| Space|  LM  |  RM  |WinLck|      |
 * |  Nav |      |  Win |  Alt | Other|  Nav |Number| Punct|      |      |      |  Nav |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {C_S_T(KC_ESC),       DOTCOMM,            XXXXXXX,          XXXXXXX,          KC_P,                 KC_Y,
   KC_F,                KC_G,               KC_C,             KC_R,             KC_L,                 C_S_T(XXXXXXX)},

  {LCTL_T(KC_TAB),      KC_A,               KC_O,             KC_E,             KC_U,                 KC_I,
   KC_D,                KC_H,               KC_T,             KC_N,             KC_S,                 KC_RCTL},

  {LSFT_T(KC_CLCK),     XXXXXXX,            KC_Q,             KC_J,             KC_K,                 KC_X,
   KC_B,                KC_M,               KC_W,             KC_V,             KC_Z,                 KC_RSFT},

  {MO(_NAV),            LALT(LCTL(KC_DEL)), LGUI_T(KC_COMM),  LALT_T(KC_DOT),   LT(_PUNCT, KC_BSPC),  LT(_NUMBER, KC_SPC),
  LT(_NUMBER, KC_SPC),  LT(_NAV, KC_ENT),   KC_BTN1,          KC_BTN2,          LGUI(KC_L),           MO(_NAV)}
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
  {_______, KC_Q,    KC_W,    KC_E,           KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    C_S_T(KC_LBRC)},
  {_______, KC_A,    KC_S,    KC_D,           KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LCTL_T(KC_QUOT)},
  {_______, KC_Z,    KC_X,    KC_C,           KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_GRV,  RSFT_T(KC_RBRC)},
  {_______, _______, _______, LALT_T(KC_SLSH),_______, _______, _______, _______, _______, _______, _______, _______}
},

/* Number
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  | PrSc | NuLo |   7  |   8  |   9  |   /  |   *  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  | ScLo |      |   4  |   5  |   6  |   -  |   +  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 | PaBr |      |   1  |   2  |   3  | Enter|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  |   0  |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_NUMBER] = {
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_PSCR, KC_NLCK, KC_7,    KC_8, KC_9,      KC_PSLS, C_S_T(KC_PAST)},
  {_______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_SLCK, XXXXXXX, KC_4,    KC_5, KC_6,      KC_PMNS, LCTL_T(KC_PPLS)},
  {_______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PAUS, XXXXXXX, KC_1,    KC_2, KC_3,      KC_PENT, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_0,    KC_0, KC_DOT,    _______, _______}
},

/* Punct
 * ,-----------------------------------------------------------------------------------.
 * |   %  |   &  |   |  |   \  |   /  |   +  |   =  |   [  |   ]  |   <  |   >  |   ^  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   @  |   ~  |   `  |   '  |   "  |   _  |   -  |   (  |   )  |   «  |   »  |   $  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   №  |   #  |   ?  |   !  |   *  |   :  |   ;  |   {  |   }  |   „  |   “  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PUNCT] = {
  {KC_PERC,KC_AMPR,KC_PIPE,KC_BSLS,KC_SLSH,KC_PLUS,KC_EQL, KC_LBRC,KC_RBRC,KC_LABK,   KC_RABK,   KC_CIRC},
  {KC_AT,  KC_TILD,KC_GRV, KC_QUOT,KC_DQUO,KC_UNDS,KC_MINS,KC_LPRN,KC_RPRN,UC(0x00AB),UC(0x00BB),KC_DLR},
  {XXXXXXX,KC_HASH,KC_QUES,KC_EXLM,KC_ASTR,KC_COLN,KC_SCLN,KC_LCBR,KC_RCBR,UC(0x201E),UC(0x201C),XXXXXXX},
  {_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   _______,   _______}
},

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |ClHome| Home |PgDown| PgUp | ClEnd|ClHome|ClHome| Home |PgDown| PgUp | ClEnd|ClHome|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |ClLeft| Left | Down |  Up  | Right|CRight|ClLeft| Left | Down |  Up  | Right|CRight|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |AlLeft|  Ins | AlUp |AlRght|  Del |  Del |AlLeft|  Ins | AlUp |AlRght|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_NAV] = {
  {LCTL(KC_HOME),KC_HOME,      KC_PGDN,      KC_PGUP,    KC_END,       LCTL(KC_END),
   LCTL(KC_HOME),KC_HOME,      KC_PGDN,      KC_PGUP,    KC_END,       LCTL(KC_END)},

  {LCTL(KC_LEFT),KC_LEFT,      KC_DOWN,      KC_UP,      KC_RGHT,      LCTL(KC_RGHT),
   LCTL(KC_LEFT),KC_LEFT,      KC_DOWN,      KC_UP,      KC_RGHT,      LCTL(KC_RGHT)},

  {_______,      LALT(KC_LEFT),KC_INS,       LALT(KC_UP),LALT(KC_RGHT),KC_DEL,
   KC_DEL,       LALT(KC_LEFT),KC_INS,       LALT(KC_UP),LALT(KC_RGHT),_______},

  {_______,      _______,      _______,      _______,    _______,      _______,
   _______,      _______,      _______,      _______,    _______,      _______}
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

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  //static bool dotcomm_mods = false;
  //static bool bsdel_mods = false;
  static bool is_rus_on = false;

  // dprintf("%b\t%X\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", keycode, keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.reserved2, record->tap.reserved1, record->tap.reserved0, record->tap.count);

  //dprintf("D %X\tQ %X\tP %X\tNu %X\tNa %X\tO %X\t%X\t%X\n", IS_LAYER_ON(_DVORAK), IS_LAYER_ON(_QWERTY), IS_LAYER_ON(_PUNCT), IS_LAYER_ON(_NUMBER), IS_LAYER_ON(_NAV), IS_LAYER_ON(_OTHER), keycode, keyboard_report->mods);
  dprintf("%X\t%X\n", keyboard_report->mods, keycode);

  if( keycode==LT(_PUNCT, KC_SPC)
    || keycode==LGUI_T(KC_COMM)
    )
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