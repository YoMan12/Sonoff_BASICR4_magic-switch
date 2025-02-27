#ifndef CLASS_H_
#define CLASS_H_

class customIterate : public Supla::Element {
 public: customIterate() {}


  void iterateAlways() {

    if (!webServer) {
      if (Supla::Network::IsReady()) {
        SuplaDevice.handleAction(0, Supla::START_LOCAL_WEB_SERVER); //webserver 24/7
        webServer = true;
      }
    }

    if (tick + 1000 < millis()) {
      tick = millis();
    //   toggle(STATUS_LED_GPIO);
    }
  }

 protected:
  bool webServer = false;
  uint32_t tick = 0;
  uint32_t licznik = 0;

};

customIterate customIterate;

// class customButton : public Supla::Control::Button {
//   public: customButton () {}



// };

#endif