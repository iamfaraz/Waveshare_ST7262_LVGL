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