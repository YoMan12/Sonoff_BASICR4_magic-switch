#ifndef VARS_H_
#define VARS_H_

// uint32_t buttonQty = DEF_BUTTON_QTY;
uint32_t relayQty = DEF_RELAY_QTY;


int relayPin[2] = {RELAY_PIN_1,RELAY_PIN_2};
int buttonPin[2] = {BUTTON_PIN_1, BUTTON_PIN_2};
int interruptPin = INTERRUPT_PIN;
int count = 0;

volatile uint32_t startTime = 0;
volatile uint32_t stopTime = 0;
int32_t difference = 0;

const char* FILTER_KEY = "filter";
uint32_t filter = 780;
const char* DEBOUNCE_KEY = "debounce";
uint32_t debounce = 3;

const char* PULLUP_KEY = "pullup";
uint32_t pullup = 0;
const char* INVERTED_KEY = "inverted";
uint32_t inverted = 1;


#endif
