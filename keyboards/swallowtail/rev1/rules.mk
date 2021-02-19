# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
NKRO_ENABLE = no            # USB Nkey Rollover
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
SPLIT_KEYBOARD = yes
VIA_ENABLE = yes

LTO_ENABLE = yes
