# Waveshare_ST7262_LVGL

Waveshare_ST7262_LVGL is an Arduino library designed for [Waveshare ESP32-S3-Touch-LCD-7](https://www.waveshare.com/wiki/ESP32-S3-Touch-LCD-7) using ESP32-S3 SOC with 7 inch ST7262 LCD and GT911 touchscreen to facilitate rapid GUI development using LVGL.




## Dependencies
| Library  	|   Version	| 
|---	|---	|
| [LVGL](https://github.com/lvgl/lvgl) 	|  >=8.3.0 && <=8.3.11 	| 
|   [ESP32_Display_Panel](https://github.com/esp-arduino-libs/ESP32_Display_Panel)	|  >=0.1.4 	|  
|   [ESP32_IO_Expander](https://github.com/esp-arduino-libs/ESP32_IO_Expander/)	|  0.0.3 	|  

## Usage
 To use the built-in examples and demos of LVGL uncomment the includes below respectively.
 * You need to copy `lvgl/examples` from Arduino Global Libraries folder to `lvgl/src/examples`. 
 * Similarly for the demos `lvgl/demos` to `lvgl/src/demos`.

```cpp
#include <Arduino.h>
#include <Waveshare_ST7262_LVGL.h>
#include <lvgl.h>

/**
/* To use the built-in examples and demos of LVGL uncomment the includes below respectively.
 * You also need to copy `lvgl/examples` to `lvgl/src/examples`. Similarly for the demos `lvgl/demos` to `lvgl/src/demos`.
 */
#include <demos/lv_demos.h>
// #include <examples/lv_examples.h>

int isOn = 1;
void setup()
{
    Serial.begin(115200);

    Serial.println("Initialize display and touchscreen");
    lcd_init();
    Serial.println("Create UI");

    /* Lock the mutex due to the LVGL APIs are not thread-safe */
    lvgl_port_lock(-1);
    /**
     * Or try out a demo.
     * Don't forget to uncomment header and enable the demos in `lv_conf.h`. E.g. `LV_USE_DEMOS_WIDGETS`
     */
    lv_demo_widgets();
    // lv_demo_benchmark();
    // lv_demo_music();
    // lv_demo_stress();

    /* Release the mutex */
    lvgl_port_unlock();

    /**
     * You can use toggle_backlight function to toggle lcd backlight
     * It uses IO Expander to write HIGH or LOW value based on isOn and toggles isOn value as well
     */
    // toggle_backlight(int &isOn);
}

void loop()
{
    Serial.println("IDLE loop");
    delay(500);
}
```
## Acknowledgements
Example code was sourced from Waveshare Wiki Page mentioned below. I just made it easier to implement in any sketch file.
 - [Waveshare - [WIKI] ESP32-S3-Touch-LCD-7](https://www.waveshare.com/wiki/ESP32-S3-Touch-LCD-7)