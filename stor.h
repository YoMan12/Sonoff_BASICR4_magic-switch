#ifndef STOR_H_
#define STOR_H_

void addStor () {
  Supla::Storage::Init();
  auto cfg = Supla::Storage::ConfigInstance();

  if (cfg->getInt32(BEHAVIOUR_KEY, &behaviour)) {
    Serial1.printf("# Param [%s]: %d\n", BEHAVIOUR_KEY, behaviour);
  } else {
    Serial1.printf("# Param[%s] is not set\n", BEHAVIOUR_KEY);
  }
  
  if (cfg->getUInt32(FILTER_KEY, &filter)) {
    Serial1.printf("# Param [%s]: %d\n", FILTER_KEY, filter);
  } else {
    Serial1.printf("# Param[%s] is not set\n", FILTER_KEY);
  }

  if (cfg->getUInt32(DEBOUNCE_KEY, &debounce)) {
    Serial1.printf("# Param [%s]: %d\n", DEBOUNCE_KEY, debounce);
  } else {
    Serial1.printf("# Param[%s] is not set\n", DEBOUNCE_KEY);
  }
}


#endif