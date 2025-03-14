#ifndef STOR_H_
#define STOR_H_

void addStor () {
  Supla::Storage::Init();
  auto cfg = Supla::Storage::ConfigInstance();

  if (cfg->getInt32(BEHAVIOUR_KEY, &behaviour)) {
    Serial1.printf("# Param [%s]: %d\n", BEHAVIOUR_KEY, behaviour);
  } else {
    Serial1.printf("# Param [%s] is not set\n", BEHAVIOUR_KEY);
  }

  if (cfg->getUInt8(MAGIC_SWITCH_IS_ON_KEY, &magicSwitchIsOn)) {
    Serial1.printf("# Param [%s]: %d\n", MAGIC_SWITCH_IS_ON_KEY, magicSwitchIsOn);
  } else {
    Serial1.printf("# Param [%s] is not set\n", MAGIC_SWITCH_IS_ON_KEY);
  }
  
  if (cfg->getUInt32(FILTER_KEY, &filter)) {
    Serial1.printf("# Param [%s]: %d\n", FILTER_KEY, filter);
  } else {
    Serial1.printf("# Param [%s] is not set\n", FILTER_KEY);
  }

  if (cfg->getUInt8(DEBUG_CH_IS_ON_KEY, &debugChannelIsOn)) {
    Serial1.printf("# Param [%s]: %d\n", DEBUG_CH_IS_ON_KEY, debugChannelIsOn);
  } else {
    Serial1.printf("# Param [%s] is not set\n", DEBUG_CH_IS_ON_KEY);
  }

  if (cfg->getUInt8(FILTER_LIMIT_IS_ON_KEY, &filterLimitIsOn)) {
    Serial1.printf("# Param [%s]: %d\n", FILTER_LIMIT_IS_ON_KEY, filterLimitIsOn);
  } else {
    Serial1.printf("# Param [%s] is not set\n", FILTER_LIMIT_IS_ON_KEY);
  }

  if (cfg->getUInt32(LIMIT_KEY, &limit)) {
    Serial1.printf("# Param [%s]: %d\n", LIMIT_KEY, limit);
  } else {
    Serial1.printf("# Param [%s] is not set\n", LIMIT_KEY);
  }
  
}


#endif