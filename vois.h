
void toggle(uint8_t _relay) {
  if (digitalRead(_relay) == HIGH) {
    digitalWrite(_relay, LOW);
  } else {
    digitalWrite(_relay, HIGH);
  }
}

void hop(uint32_t stop, uint32_t start) {
  if (stop != 0) {
    static int32_t debounceTime = 0;
    difference = (stop - start);
    if (millis() - debounceTime > debounce) {
      if (difference > filter) {
        relay->toggle();
        debounceTime = millis();
      }
    }
  }
}