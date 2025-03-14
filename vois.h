#ifndef VOIS_H_
#define VOIS_H_

void hop(uint32_t stop, uint32_t start) {
  if (magicSwitchIsOn == 1) {
    uint32_t tempValue = 0;
    if (stop != 0) {
      static int32_t debounceTime = 0;
      difference = (stop - start);
      if (filterLimitIsOn == 1){
        tempValue = limit;
      } else {
        tempValue = 1000000;
      }
      if (millis() - debounceTime > debounce) {
        if (difference > filter && difference < (filter + tempValue)) {
          relay->toggle();
          debounceTime = millis();

          if (debugChannelIsOn) {
            Supla::Notification::SendF(-1,"Basic R4 - test", "Time: %lu\n",difference);
            timeValue->setValue(difference);
          }
        }
      }
    }
  }
}

#endif