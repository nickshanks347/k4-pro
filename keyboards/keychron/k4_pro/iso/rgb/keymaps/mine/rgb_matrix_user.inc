#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
RGB_MATRIX_EFFECT(esc_red_effect)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// Define the effect to color the Esc key and Backspace key red and all other keys white
static bool esc_red_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    if (i == 0) { // Assuming the Esc key is at index 0 and Backspace key is at index 32
      rgb_matrix_set_color(i, 0xff, 0x00, 0x00); // Red color
    } else {
      rgb_matrix_set_color(i, 0xff, 0xff, 0xff); // White color
    }
  }
  return rgb_matrix_check_finished_leds(led_max);
}
#endif // RGB_MATRIX_KEYREACTIVE_ENABLED
#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS