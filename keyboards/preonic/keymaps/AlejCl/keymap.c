#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_spanish.h"

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _GAME,
  _DVORAK,
  _LOWER,
  _RAISE,
  _MOV,
  _NUM,
  _SHORTCUTS,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  GAME,
  DVORAK,
  LOWER,
  RAISE,
  SHORTCUTS,
  BACKLIT
};

#define SPCMOV LT(_MOV, KC_SPC)
#define TABNUM LT(_NUM, KC_TAB)
#define RAISE LT(_RAISE, KC_ENT)
#define LOWER LT(_LOWER, KC_BSPC)
#define NUM MO(_NUM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc* |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TABNUM|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CAPSLK|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | HYPR | GUI  | Alt  |Lower*|   SpaceMov  |Raise*| RAlt | RGui | RCtrl| MEH  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  LCTL_T(KC_ESC),  KC_1   , KC_2   , KC_3   , KC_4 ,  KC_5  ,  KC_6  ,  KC_7 ,  KC_8   , KC_9   , KC_0   , KC_BSPC,
  TABNUM        ,  KC_Q   , KC_W   , KC_E   , KC_R ,  KC_T  ,  KC_Y  ,  KC_U ,  KC_I   , KC_O   , KC_P   , KC_DEL ,
  KC_CAPS       ,  KC_A   , KC_S   , KC_D   , KC_F ,  KC_G  ,  KC_H  ,  KC_J ,  KC_K   , KC_L   , KC_SCLN, KC_QUOT,
  KC_LSFT       ,  KC_Z   , KC_X   , KC_C   , KC_V ,  KC_B  ,  KC_N  ,  KC_M ,  KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
  KC_LCTL       ,  KC_HYPR, KC_LGUI, KC_LALT, LOWER,  SPCMOV,  SPCMOV,  RAISE,  KC_ALGR, KC_RGUI, KC_RCTL, KC_MEH
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc* |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TABNUM|   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CAPSLK|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | HYPR | GUI  | Alt  |Lower*|   SpaceMov  |Raise*| RAlt | RGui | RCtrl| MEH  |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
  LCTL_T(KC_ESC),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  TABNUM        ,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,
  KC_CAPS       ,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT       ,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_LCTL       ,  KC_HYPR, KC_LGUI, KC_LALT, LOWER,   SPCMOV,  SPCMOV,  RAISE,   KC_ALGR, KC_RGUI, KC_RCTL, KC_MEH
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc* |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TABNUM|   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CAPSLK|   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | HYPR | GUI  | Alt  |Lower*|   SpaceMov  |Raise*| RAlt | RGui | RCtrl| MEH  |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_preonic_grid(
  LCTL_T(KC_ESC),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  TABNUM        ,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_DEL,
  KC_CAPS       ,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
  KC_LSFT       ,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT,
  KC_LCTL       ,  KC_HYPR, KC_LGUI, KC_LALT, LOWER,   SPCMOV,  SPCMOV,  RAISE,   KC_ALGR, KC_RGUI, KC_RCTL, KC_MEH
),

/* GAME
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CAPSLK|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  |  '"  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  ,<  |  .>  |  Up  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | HYPR |  GUI |  Alt |Lower*|    Space    |Raise*| RAlt | Left | Down | Right|
 * `-----------------------------------------------------------------------------------'
 *
 * This layer is supposed to be used for gaming, you normally cant Ctrl on
 * it's normal position and Space acting as normal. I moved NUM modifier to
 * where Shift is in the base layer. This is mainly thought for LoL as I can
 * have numbers and F keys close to my thumb.
 * - Tap dance Raise/Enter
 * - Tap dance Lower/Backspace
 *
 * */
 [_GAME] = LAYOUT_preonic_grid(
    KC_ESC        , KC_1    , KC_2    , KC_3     , KC_4  , KC_5  , KC_6  , KC_7   , KC_8    , KC_9    , KC_0    , KC_BSPC,
    KC_TAB        , KC_Q    , KC_W    , KC_E     , KC_R  , KC_T  , KC_Y  , KC_U   , KC_I    , KC_O    , KC_P    , KC_DEL ,
    KC_CAPS       , KC_A    , KC_S    , KC_D     , KC_F  , KC_G  , KC_H  , KC_J   , KC_K    , KC_L    , KC_SCLN , KC_QUOT,
    KC_LSFT       , KC_Z    , KC_X    , KC_C     , KC_V  , KC_B  , KC_N  , KC_M   , KC_COMM , KC_DOT  , KC_UP   , KC_ENT ,
    KC_LCTL       , KC_HYPR , KC_LGUI , KC_LALT  , LOWER , KC_SPC, KC_SPC, RAISE  , KC_ALGR , KC_LEFT , KC_DOWN , KC_RIGHT
  ),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   \  |   [  |   ]  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   =  |   +  |   -  |   {  |   }  |      | 
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Mute |ISO ~ |ISO | |  ¿   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | **** |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN   , KC_RPRN   , KC_BSPC   ,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, KC_LBRC   , KC_RBRC   , _______   ,
  _______, _______, _______, _______, _______, _______, KC_EQL , KC_PLUS, KC_MINS, KC_LCBR   , KC_RCBR   , _______   ,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, S(KC_NUHS), S(KC_NUBS), S(ES_IEXL),
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD   , KC_VOLU   , KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   |  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   =  |   +  |   _  |      |   Ñ  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |ISO # |ISO / |   ¿  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             | **** |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  _______,  KC_F1 , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11    ,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE, _______, _______, _______   ,
  _______, _______, _______, _______, _______, _______, KC_EQL , KC_PLUS, KC_UNDS, _______, KC_SCLN, KC_BSLS   ,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NUHS, KC_NUBS, S(ES_IEXL),
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* MOV
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  Up  |      |      |      | CIns | PgUp |      |      | SIns | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down | Right|      |      |      |PgDown| Home | End  |      |      | 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   *******   | Enter|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *
 * - Y outputs Control + Insert
 * - P outputs Shift + Insert
 */
[_MOV] = LAYOUT_preonic_grid(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX   , XXXXXXX   , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX   , KC_BSPC,
  XXXXXXX , XXXXXXX , KC_UP   , XXXXXXX , XXXXXXX , XXXXXXX   , C(KC_INS) , KC_PGUP , XXXXXXX , XXXXXXX  , S(KC_INS) , KC_DEL ,
  XXXXXXX , KC_LEFT , KC_DOWN , KC_RIGHT, XXXXXXX , XXXXXXX   , XXXXXXX   , KC_PGDN , KC_HOME , KC_END   , XXXXXXX   , XXXXXXX,
  _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX   , XXXXXXX   , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX   , _______,
  _______ , _______ , _______ , _______ , XXXXXXX , _______   , _______   , KC_ENT  , _______ , _______  , _______   , _______
),

/* NUM
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | **** |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |   7  |   8  |   9  |   *  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |      | Bksp |   4  |   5  |   6  |   +  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |  F11 |  F12 |      | Enter|   1  |   2  |   3  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  |   ,  |   .  |NumEnt|
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_preonic_grid(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_BSPC,
  _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , XXXXXXX , XXXXXXX , KC_7 , KC_8    , KC_9    , KC_PAST , 
  XXXXXXX , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , XXXXXXX , KC_BSPC , KC_4 , KC_5    , KC_6    , KC_PPLS , 
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F11  , KC_F12  , XXXXXXX , KC_ENT  , KC_1 , KC_2    , KC_3    , KC_PMNS , 
  XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_0 , KC_COMM , KC_DOT  , KC_PENT 
),

/* SHORTCUTS
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  | F24  | F23  | F22  |      |      |      | KP7  | KP8  | KP9  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl | F19  | F20  | F19  |      |      |      | KP4  | KP5  | KP6  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift| F18  | F17  | F16  |      |      |      | KP1  | KP2  | KP3  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | HYPR |  GUI |  Alt |Lower*|    Space    |Raise*| RAlt | RGui | RCtrl| MEH  |
 * `-----------------------------------------------------------------------------------'
 *
 * This layer is for Macro and bind purpouses, such as complicated binds for OBS.
 * - Tap dance Raise/Enter
 * - Tap dance Lower/Backspace
 *
 * */

[_SHORTCUTS] = LAYOUT_preonic_grid(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX, XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX    , KC_BSPC ,
  KC_TAB  , KC_F24  , KC_F23  , KC_F22 , XXXXXXX , XXXXXXX , XXXXXXX , KC_KP_7 , KC_KP_8 , KC_KP_9 , KC_NUMLOCK , XXXXXXX ,
  KC_LCTL , KC_F21  , KC_F20  , KC_F19 , XXXXXXX , XXXXXXX , XXXXXXX , KC_KP_4 , KC_KP_5 , KC_KP_6 , XXXXXXX    , XXXXXXX ,
  KC_LSFT , KC_F18  , KC_F17  , KC_F16 , XXXXXXX , XXXXXXX , XXXXXXX , KC_KP_1 , KC_KP_2 , KC_KP_3 , XXXXXXX    , XXXXXXX ,
  KC_LCTL , KC_HYPR , KC_LGUI , KC_LALT , LOWER  , KC_SPC  , KC_SPC  , RAISE   , KC_ALGR , KC_RGUI , KC_RCTL    , KC_MEH
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset| Debug|      |Aud cy|Aud on|AudOff|AGnorm|AGswap|      |      |      | GAME |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Qwerty|      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |SHRCUT|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | RGB+ | Bri+ |      |Dvorak|      |      |      |      |      | ACC0 | ACC1 | ACC2 |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | RGB- | Bri- |      |Colemk|      |      |      |      |      | MOUS1| MOUSU| MOUS2|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BLtogg|BLstep|      |      | **** |             | **** |      | MOUSL| MOUSD| MOUSR|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  RESET  , DEBUG  , XXXXXXX, MU_MOD , AU_ON  , AU_OFF , AG_NORM, AG_SWAP, XXXXXXX, XXXXXXX, XXXXXXX, GAME,
  XXXXXXX, QWERTY , XXXXXXX, MUV_DE , MUV_IN , MU_ON  , MU_OFF , MI_ON  , MI_OFF , XXXXXXX, XXXXXXX, SHORTCUTS, 
  RGB_HUI, RGB_VAI, XXXXXXX, DVORAK , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2,
  RGB_HUD, RGB_VAD, XXXXXXX, COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2,
  RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R
)

};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
        case GAME:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_GAME);
          }
          return false;
          break;
        case SHORTCUTS:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_SHORTCUTS);
            }
            return false;
            break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
