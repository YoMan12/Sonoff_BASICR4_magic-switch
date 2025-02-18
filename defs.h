/*
SuplaDevice:
  25.01.03 (2024-11-26) 
espboards: 
  esp8266 3.1.2 
  esp32:3.1.1
*/

#define SOFT_VERSION "25.02.1 - beta"

#ifdef ESP8266
  #define STATUS_LED_GPIO 2
  #define cfgButtonPin 0

#elif defined ARDUINO_ARCH_ESP32
  #ifdef LOLIN_C3_PICO 
    #define STATUS_LED_GPIO 7
  #elif defined ESP32_C3_SUPERMINI
    #define STATUS_LED_GPIO 8   
  #else
    #define STATUS_LED_GPIO 6
  #endif
  #define cfgButtonPin 9  
#endif

#ifdef ESP8266
  #define DEF_RELAY_QTY 2
  #define RELAY_PIN_1 14
  #define RELAY_PIN_2 12
  #define BUTTON_PIN_1 5
  #define BUTTON_PIN_2 4
#elif defined ARDUINO_ARCH_ESP32
  #define DEF_RELAY_QTY 1
  #define RELAY_PIN_1 4
  #define RELAY_PIN_2 18
  #define BUTTON_PIN_1 5
  #define BUTTON_PIN_2 19
#endif