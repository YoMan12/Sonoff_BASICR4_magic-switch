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
  if (digitalRead(INTERRUPT_PIN) == LOW) {
    stopTime = micros();
  } else {
    startTime = micros();
  }
  difference = (stopTime - startTime);
  if (difference > 780) {
    relay->toggle();
    // delay(debounce);
  }
}

void setup() {
  #include "html.h"

  pinMode(INTERRUPT_PIN, INPUT_PULLUP);

  Serial1.begin(115200,SERIAL_8N1, 20,21);
  SUPLA_LOG_DEBUG(SOFT_VERSION);

  #include "stor.h"
  delay(300);

  relay = new Supla::Control::Relay(RELAY_PIN,true,224);
  relay->getChannel()->setDefault(SUPLA_CHANNELFNC_POWERSWITCH);
  // relay->setDefaultStateRestore();
  relay->setDefaultStateOff();
   
  cfgButton = new Supla::Control::Button(CFG_BUTTON_PIN, true, true);
  cfgButton->configureAsConfigButton(&SuplaDevice);

  SuplaDevice.begin();
  
  new Supla::Device::EnterCfgModeAfterPowerCycle(5000, 3, true);
  Serial1.print("Filter: ");Serial1.println(filter);

  attachInterrupt(INTERRUPT_PIN,stateChange,CHANGE);
}

void loop() {
  
  SuplaDevice.iterate();

}
