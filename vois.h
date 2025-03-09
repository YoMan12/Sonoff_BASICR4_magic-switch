#ifndef VOIS_H_
#define VOIS_H_

void hop(uint32_t stop, uint32_t start) {
  if (stop != 0) {
    static int32_t debounceTime = 0;
    difference = (stop - start);
    if (millis() - debounceTime > debounce) {
      if (difference > filter && difference < (filter + 5000)) {
        relay->toggle();
        debounceTime = millis();
        // if (debugIsOn) {
        //   Supla::Notification::SendF(-1,"Basic R4 - test", "Time: %lu\n",difference);
        //   timeValue->setValue(difference);
        // }
      }
    }
  }
}

#endif