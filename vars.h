#ifndef VARS_H_
#define VARS_H_


const char* BEHAVIOUR_KEY = "behaviour";
int32_t behaviour = 0;
const char* MAGIC_SWITCH_IS_ON_KEY = "MS is ON";
uint8_t magicSwitchIsOn = 0;
const char* FILTER_KEY = "filter value";
uint32_t filter = 3000;
const char* DEBUG_CH_IS_ON_KEY = "DS is ON";
uint8_t debugChannelIsOn = 0;
const char* FILTER_LIMIT_IS_ON_KEY = "FL is ON";
uint8_t filterLimitIsOn = 0;
const char* LIMIT_KEY = "limit value";
uint32_t limit = 50000;

uint32_t debounce = 5;
int32_t difference = 0;
uint32_t margin = 1000;

#endif
