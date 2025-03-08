#ifndef VARS_H_
#define VARS_H_


const char* BEHAVIOUR_KEY = "behaviour";
int32_t behaviour = 0;
const char* FILTER_KEY = "filter";
uint32_t filter = 800;
const char* LIMIT_KEY = "limit";
uint32_t limit = 10000;
const char* LIMIT_IS_ON_KEY = "limitIsOn";
bool limitIsOn = 0;
uint32_t debounce = 5;

int32_t difference = 0;
#endif
