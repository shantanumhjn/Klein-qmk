/* added by me */
#include QMK_KEYBOARD_H


// # define U_WIN_SCROLL_MOD KC_LALT   // windows
# define U_WIN_SCROLL_MOD KC_LCMD   // mac
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

/* The encoder_update_user is a function.
 * It'll be called by QMK every time you turn the encoder.
 *
 * The index parameter tells you which encoder was turned. If you only have
 * one encoder, the index will always be zero.
 * 
 * The clockwise parameter tells you the direction of the encoder. It'll be
 * true when you turned the encoder clockwise, and false otherwise.
 */
bool encoder_update_user(uint8_t index, bool clockwise) {
  /* With an if statement we can check which encoder was turned. */
  if (index == 0) { /* Second encoder */
    if (clockwise) {
      if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(U_WIN_SCROLL_MOD);
      }
      alt_tab_timer = timer_read();
      tap_code16(KC_TAB);
    } else {
      if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(U_WIN_SCROLL_MOD);
      }
      alt_tab_timer = timer_read();
      tap_code16(S(KC_TAB));
    }
  } else if (index == 1) { /* First encoder */
    /* And with another if statement we can check the direction. */
    if (clockwise) {
      /* This is where the actual magic happens: this bit of code taps on the
         volume up key. You can do anything QMK allows you to do here.
         You'll want to replace these lines with the things you want your
         encoders to do. */
      tap_code(KC_VOLU);
    } else {
      /* And likewise for the other direction, this time volume down is pressed. */
      tap_code(KC_VOLD);
    }
  /* You can copy the code and change the index for every encoder you have. Most
     keyboards will only have two, so this piece of code will suffice. */
  }
  return false;
}

// release alt tab if time elapsed > 1250 ms
void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1250) {
      unregister_code(U_WIN_SCROLL_MOD);
      is_alt_tab_active = false;
    }
  }
}
