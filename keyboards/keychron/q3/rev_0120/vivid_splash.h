RGB_MATRIX_EFFECT(VIVID_SPLASH)
RGB_MATRIX_EFFECT(VIVID_SPLASH_WITH_BG)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV VIVID_SPLASH_math(HSV hsv, uint16_t offset)
{
    hsv.h = qsub8(169, offset);
    return hsv;
}

static HSV VIVID_SPLASH_CYCLE_math(HSV hsv, uint8_t i, uint8_t time) {
    hsv.h = time;
    hsv.v = 127;
    return hsv;
}
static bool VIVID_SPLASH_impl(effect_params_t* params, bool bg)
{
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t time = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed / 4, 1));
    uint16_t max_tick = 65535 / qadd8(rgb_matrix_config.speed, 1);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        uint16_t tick = max_tick;
        bool found = false;

        uint8_t count = g_last_hit_tracker.count;
        uint8_t lastDist = 255;
        for (uint8_t j = 0; j < count; j++) {
            if (g_last_hit_tracker.tick[j] < max_tick) {
                int16_t dx = g_led_config.point[i].x - g_last_hit_tracker.x[j];
                int16_t dy = g_led_config.point[i].y - g_last_hit_tracker.y[j];
                uint8_t dist = sqrt16(dx * dx + dy * dy);
                if (dist <= 20 && dist <= lastDist) {
                    tick = g_last_hit_tracker.tick[j] + dist * 10;
                    lastDist = dist;
                    if (tick < max_tick) {
                        found = true;
                    }
                }
            }
        }

        uint16_t offset = scale16by8(tick, qadd8(rgb_matrix_config.speed, 1));
        RGB rgb;
        if (found) {
            rgb = rgb_matrix_hsv_to_rgb(VIVID_SPLASH_math(rgb_matrix_config.hsv, offset));
        }
        else if (bg) {
            rgb = rgb_matrix_hsv_to_rgb(VIVID_SPLASH_CYCLE_math(rgb_matrix_config.hsv, i, time));
        }
        else {
            rgb.r = 0;
            rgb.g = 0;
            rgb.b = 0;
        }
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

bool VIVID_SPLASH(effect_params_t* params)
{
    return VIVID_SPLASH_impl(params, false);
}

bool VIVID_SPLASH_WITH_BG(effect_params_t* params)
{
    return VIVID_SPLASH_impl(params, true);
}


#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
