#ifndef STOR_H_
#define STOR_H_

Supla::Storage::Init();
auto cfg = Supla::Storage::ConfigInstance();

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

// if (cfg->getUInt32(FILTER_KEY, &filter)) {
//   SUPLA_LOG_DEBUG("# Param [%s]: %d", FILTER_KEY, filter);
// } else {
//   SUPLA_LOG_DEBUG("# Param[%s] is not set", FILTER_KEY);
// }

// if (cfg->getUInt32(DEBOUNCE_KEY, &debounce)) {
//   SUPLA_LOG_DEBUG("# Param [%s]: %d", DEBOUNCE_KEY, debounce);
// } else {
//   SUPLA_LOG_DEBUG("# Param[%s] is not set", DEBOUNCE_KEY);
// }


#endif