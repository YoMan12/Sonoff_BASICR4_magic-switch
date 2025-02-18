#ifndef VARS_H_
#define VARS_H_

// uint32_t buttonQty = DEF_BUTTON_QTY;
uint32_t relayQty = DEF_RELAY_QTY;

int relayPin[2] = {RELAY_PIN_1,RELAY_PIN_2};
int buttonPin[2] = {BUTTON_PIN_1, BUTTON_PIN_2};

const char* FILTER_KEY = "filter";
uint32_t filter = 5;
const char* DEBOUNCE_KEY = "debounce";
uint32_t debounce = 300;

const char* PULLUP_KEY = "pullup";
uint32_t pullup = 1;
const char* INVERTED_KEY = "inverted";
uint32_t inverted = 1;
#endif