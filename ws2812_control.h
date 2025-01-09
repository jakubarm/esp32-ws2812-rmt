#ifndef WS2812_CONTROL_H
#define WS2812_CONTROL_H

#include <stdint.h>
#include "sdkconfig.h"
#include "esp_err.h"

#define CONFIG_WS2812_LED_TYPE_RGB
#define CONFIG_WS2812_NUM_LEDS 2
#define CONFIG_WS2812_LED_RMT_TX_GPIO 8
#define CONFIG_WS2812_LED_RMT_TX_CHANNEL 1
#define CONFIG_WS2812_T0H 0 // 0 bit high time
#define CONFIG_WS2812_T1H 1 // 1 bit high time
#define CONFIG_WS2812_T0L 0 // 0 bit low time
#define CONFIG_WS2812_T1L 1 // 1 bit low time

#ifdef __cplusplus
extern "C" {
#endif

// This structure is used for indicating what the colors of each LED should be set to.
// There is a 32bit value for each LED. Only the lower 3 bytes are used and they hold the
// Red (byte 2), Green (byte 1), and Blue (byte 0) values to be set.
struct led_state {
    uint32_t leds[CONFIG_WS2812_NUM_LEDS];
};

// Setup the hardware peripheral. Only call this once.
esp_err_t ws2812_control_init(void);

// Update the LEDs to the new state. Call as needed.
// This function will block the current task until the RMT peripheral is finished sending 
// the entire sequence.
esp_err_t ws2812_write_leds(struct led_state new_state);

#endif

#ifdef __cplusplus
}
#endif
