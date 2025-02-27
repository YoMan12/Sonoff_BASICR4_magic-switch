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
  }

 protected:
  bool webServer = false;

};

customIterate customIterate;

#endif