/*
  Copyright (C) AC SOFTWARE SP. Z O.O.

  This program is free software; you canimage.png redistribute it and/or
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
#include "html.h"
#include "stor.h"


void IRAM_ATTR stateChange() {
  static uint32_t stopTime = 0;
  static uint32_t startTime = 0;

  if (digitalRead(INTERRUPT_PIN) == LOW) {
    stopTime = micros();
    hop(stopTime,startTime);
  } else {
    startTime = micros();
  }  
}

void setup() {
  

  pinMode(INTERRUPT_PIN, INPUT_PULLUP);

  Serial1.begin(115200,SERIAL_8N1, 20,21);
  SUPLA_LOG_DEBUG(SOFT_VERSION);

  addStor();
  addHtml();
  
  delay(300);

  relay = new Supla::Control::Relay(RELAY_PIN,true,224);
  relay->getChannel()->setDefault(SUPLA_CHANNELFNC_POWERSWITCH);
  switch (behaviour) {
    case 1:
      relay->setDefaultStateOn();
      break;
    case 2:
      relay->setDefaultStateRestore();
      break;
    default:
      relay->setDefaultStateOff();
      break;
  }
   
  if (debugChannelIsOn) {
    timeValue = new Supla::Sensor::GeneralPurposeMeasurement();
    timeValue->setInitialCaption("Time");
    timeValue->setDefaultUnitAfterValue("µs");
    timeValue->setDefaultValuePrecision(0);
    timeValue->setValue(NAN);
  }

  cfgButton = new Supla::Control::Button(CFG_BUTTON_PIN, true, true);
  cfgButton->addAction(Supla::TOGGLE, relay, Supla::ON_CLICK_1);
  cfgButton->configureAsConfigButton(&SuplaDevice);

  SuplaDevice.begin();
  
  new Supla::Device::EnterCfgModeAfterPowerCycle(5000, 3, true);

  Supla::Notification::RegisterNotification(-1,true,true,true);  // notifications for device 

  attachInterrupt(INTERRUPT_PIN, stateChange, CHANGE);

}

void loop() {
  
  SuplaDevice.iterate();

}