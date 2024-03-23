#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

#undef VENDOR_ID
#undef PRODUCT_ID
#undef DEVICE_VER
#undef MANUFACTURER
#undef PRODUCT
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    Slg
#define PRODUCT         Izot

//#define AUDIO_CLICKY

#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#define MATRIX_ROW_PINS { C7, D3, D1, B7, F0 }
#define MATRIX_COL_PINS { B4, B2, B0, F4, F1, F6, F7, D2, C6, D0, B6, D6 } //F1, F4, F6, F0,

#undef QMK_ESC_OUTPUT
#undef DIODE_DIRECTION
#define DIODE_DIRECTION ROW2COL
#define SOLENOID_ENABLE

/*
#define MATRIX_ROW_PINS { D2, D5, B5, B6, D3 }
#define MATRIX_COL_PINS { F1, F0, B0, C7, F4, F5, F6, F7, D4, D6, B4, D7 }
#define QMK_ESC_OUTPUT F1
#define QMK_ESC_INPUT B5
#define QMK_LED     E6
#define QMK_SPEAKER C6
#define BACKLIGHT_PIN B7
#define RGB_DI_PIN D1
*/


//#undef QMK_SPEAKER
#undef BACKLIGHT_PIN
//#define QMK_SPEAKER C6
#define BACKLIGHT_PIN F4

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PREONIC_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

#endif