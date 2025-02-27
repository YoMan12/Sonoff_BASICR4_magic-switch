/*
SuplaDevice:
  25.01.03 (2024-11-26) 
espboards: 
  esp8266 3.1.2 
  esp32:3.1.1
*/

#define SOFT_VERSION "25.02.2a"

#ifdef ESP8266
  #define STATUS_LED_GPIO 2
  #define cfgButtonPin 0
#elif defined ARDUINO_ARCH_ESP32
  #define STATUS_LED_GPIO 6
  #define cfgButtonPin 9
#endif

#define DEF_RELAY_QTY 1

#ifdef ESP8266
  #define RELAY_PIN_1 4 //D2
  #define INTERRUPT_PIN 5 //D1
  #define BUTTON_PIN_1 14 //D5
#elif defined ARDUINO_ARCH_ESP32
  #define RELAY_PIN_1 4
  #define INTERRUPT_PIN 5
  #define BUTTON_PIN_1 2
#endif

#define RELAY_PIN_2 1 //D8
#define BUTTON_PIN_2 3 //D0