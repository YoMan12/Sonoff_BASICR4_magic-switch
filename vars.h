#ifndef VARS_H_
#define VARS_H_


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
