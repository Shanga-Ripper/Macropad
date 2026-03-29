#pragma once

// ── USB Device  ──────────────────────────────────────────────────────────
#define VENDOR_ID    0xFEED
#define PRODUCT_ID   0x6060
#define DEVICE_VER   0x0100

// ── SK6812 RGB  ──────────────────────────────────────────────────────────
#define WS2812_DI_PIN GP1   
#define RGBLIGHT_LIMIT_VAL 120       
#define RGBLIGHT_VAL_STEP 10  

// ── OLED ──────────────────────────────────────────────────────────
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7
#define OLED_BRIGHTNESS 190
#define OLED_TIMEOUT 60000

// ── Encoder ───────────────────────────────────────────────────────
#define ENCODER_RESOLUTION 4

// ── Debounce ──────────────────────────────────────────────────────
#define DEBOUNCE 5