/*
  Copyright (C) AC SOFTWARE SP. Z O.O.

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include "defs.h"
#include "libs.h"
#include "vars.h"
#include "vois.h"
#include "class.h"
#include "h_class.h"


void IRAM_ATTR stateChange() {
  if (ready == 1) {
    if (digitalRead(interruptPin) == LOW) {
      stopTime = micros();
    } else {
      startTime = micros();
    }
    difference = (stopTime - startTime);
    if (difference > filter) {
      relay_[0]->toggle();
      // delay(debounce);
      // Serial1.print("Filter: ");Serial1.println(filter);
      // Serial1.print("Debounce: ");Serial1.println(debounce);
    }
  }
}

void setup() {
  #include "html.h"

  pinMode(interruptPin, INPUT_PULLUP);


  #ifdef ESP8266
    Serial.begin(115200);
    SUPLA_LOG_DEBUG(SOFT_VERSION);
  #elif defined ARDUINO_ARCH_ESP32
    Serial1.begin(115200,SERIAL_8N1, 20,21);
    SUPLA_LOG_DEBUG(SOFT_VERSION);
    Serial1.println("Startujemy ............. ");
  #endif

  #include "stor.h"



  for (int i = 0; i < relayQty; i++) {
    relay_[i] = new Supla::Control::Relay(relayPin[i],true,224);
    relay_[i]->getChannel()->setChannelNumber(i);
    relay_[i]->getChannel()->setDefault(SUPLA_CHANNELFNC_POWERSWITCH);
    // relay_[i]->setDefaultStateRestore();
    relay_[i]->setDefaultStateOff();

    // button_[i] = new Supla::Control::Button(buttonPin[i], pullup, inverted);
    // button_[i]->addAction(Supla::TOGGLE, relay_[i], Supla::ON_CLICK_1);
    // // button_[i]->setButtonNumber(i+1);
    // button_[i]->setSwNoiseFilterDelay(filter);
    // button_[i]->setDebounceDelay(debounce);
    // button_[i]->setHoldTime(500);
    
    // // buttonType_[i] = new Supla::Html::ButtonTypeParameters(i);
    // // buttonType_[i]->addMonostableOption();
    // // buttonType_[i]->addBistableOption();

    // at_[i] = new Supla::Control::ActionTrigger();
    // at_[i]->getChannel()->setChannelNumber(i+10);
    // at_[i]->setRelatedChannel(relay_[i]);
    // at_[i]->attach(button_[i]);
  }

    // relay = new Supla::Control::Relay(4,true,224);
    // relay->getChannel()->setDefault(SUPLA_CHANNELFNC_POWERSWITCH);
    // relay->setDefaultStateRestore();

  cfgButton = new Supla::Control::Button(cfgButtonPin, true, true);
  cfgButton->configureAsConfigButton(&SuplaDevice);

  SuplaDevice.begin();
  
  // new Supla::Device::EnterCfgModeAfterPowerCycle(5000, 3, true);
  Serial1.print("Filter: ");Serial1.println(filter);

  attachInterrupt(interruptPin,stateChange,CHANGE);
}

void loop() {
  if (ready == 0) {
    ready = 1;
    Serial1.print("Jestem ready");
  }
  SuplaDevice.iterate();

}
