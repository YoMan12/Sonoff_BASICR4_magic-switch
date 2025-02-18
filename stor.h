#ifndef STOR_H_
#define STOR_H_

Supla::Storage::Init();
auto cfg = Supla::Storage::ConfigInstance();

if (cfg->getUInt32(FILTER_KEY, &filter)) {
  SUPLA_LOG_DEBUG("# Param [%s]: %d", FILTER_KEY, filter);
} else {
  SUPLA_LOG_DEBUG("# Param[%s] is not set", FILTER_KEY);
}

if (cfg->getUInt32(DEBOUNCE_KEY, &debounce)) {
  SUPLA_LOG_DEBUG("# Param [%s]: %d", DEBOUNCE_KEY, debounce);
} else {
  SUPLA_LOG_DEBUG("# Param[%s] is not set", DEBOUNCE_KEY);
}

if (cfg->getUInt32(PULLUP_KEY, &pullup)) {
  SUPLA_LOG_DEBUG("# Param [%s]: %d", PULLUP_KEY, filter);
} else {
  SUPLA_LOG_DEBUG("# Param[%s] is not set", PULLUP_KEY);
}

if (cfg->getUInt32(INVERTED_KEY, &inverted)) {
  SUPLA_LOG_DEBUG("# Param [%s]: %d", INVERTED_KEY, debounce);
} else {
  SUPLA_LOG_DEBUG("# Param[%s] is not set", INVERTED_KEY);
}

#endif