
void toggle(uint8_t _relay) {
  if (digitalRead(_relay) == HIGH) {
    digitalWrite(_relay, LOW);
  } else {
    digitalWrite(_relay, HIGH);
  }
}