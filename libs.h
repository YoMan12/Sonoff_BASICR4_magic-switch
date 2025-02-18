#ifndef LIBS_H_
#define LIBS_H_

#include <SuplaDevice.h>
//----------------------------------------------------------------------------//


// #include <supla/sensor/gpm_esp_free_heap.h>
#include <supla/device/status_led.h>
// #ifdef ESP32_C3_SUPERMINI
  Supla::Device::StatusLed statusLed(STATUS_LED_GPIO, false); // inverted state
// #endif
#include <supla/device/supla_ca_cert.h>
#include <supla/device/notifications.h>
#include <supla/device/register_device.h>
#include <supla/io.h>
//----------------------------------------------------------------------------//

#include <supla/storage/littlefs_config.h>
Supla::LittleFsConfig configSupla(4096);
//----------------------------------------------------------------------------//

#include <supla/network/esp_wifi.h>
Supla::ESPWifi wifi;
#include <supla/network/html/device_info.h>
#include <supla/network/html/protocol_parameters.h>
#include <supla/network/html/status_led_parameters.h>
#include <supla/network/html/wifi_parameters.h>
#include <supla/network/html/custom_parameter.h>
#include <supla/network/html/div.h>
#include <supla/network/html/h2_tag.h>
#include <supla/network/html/h3_tag.h>
#include <supla/network/esp_web_server.h>
Supla::EspWebServer suplaServer;
#include <supla/network/html/text_cmd_input_parameter.h>
#include <supla/network/html/custom_checkbox_parameter.h>
#include <supla/network/html/custom_text_parameter.h>
// #include <supla/network/html/select_input_parameter.h>
// Supla::Html::SelectInputParameter *relayState_[4] = {};
#include <supla/network/html/button_type_parameters.h>
Supla::Html::ButtonTypeParameters *buttonType_[4] = {};
#include <supla/network/html/button_hold_time_parameters.h>
#include <supla/network/html/button_multiclick_parameters.h>
#include <supla/device/enter_cfg_mode_after_power_cycle.h>
//---------------------------------------------------------------------------//


#ifdef ESP8266
  #include <ESP8266HTTPUpdateServer.h>
  ESP8266HTTPUpdateServer httpUpdater;
#elif defined ARDUINO_ARCH_ESP32
  #include <HTTPUpdateServer.h>
  HTTPUpdateServer httpUpdater;
#endif



//---------------------------------------------------------------------------//

#include <supla/control/button.h>
Supla::Control::Button *cfgButton = nullptr;
Supla::Control::Button *button_[4] = {};
#include <supla/control/relay.h>
Supla::Control::Relay *relay_[4] = {};
#include <supla/control/action_trigger.h>
Supla::Control::ActionTrigger *at_[4] = {};
//---------------------------------------------------------------------------//

// #include <supla/clock/clock.h>
// Supla::Clock *zegar = nullptr;
#include <supla/storage/eeprom.h>
Supla::Eeprom eeprom;
//---------------------------------------------------------------------------//

// #include <supla/sensor/DS18B20.h>
// Supla::Sensor::DS18B20 *thermometer_ = nullptr;
// #include <supla/sensor/virtual_thermometer.h>
// #include <supla/sensor/virtual_therm_hygro_meter.h>
// #include <supla/sensor/virtual_hygromometer.h>
// #include <supla/sensor/virtual_binary.h>
// #include <supla/sensor/general_purpose_measurement.h>
// Supla::Sensor::GeneralPurposeMeasurement *temperatureBatt_[11] = {};
// Supla::Sensor::GeneralPurposeMeasurement *tempHumiBatt_[11] = {};
// Supla::Sensor::GeneralPurposeMeasurement *soilBatt_[11] = {};
// Supla::Sensor::GeneralPurposeMeasurement *binaryBatt_[11] = {};
// Supla::Sensor::GeneralPurposeMeasurement *mailboxBatt_[11] = {};
// Supla::Sensor::GeneralPurposeMeasurement *scaleBatt_[11] = {};
// #include <supla/sensor/virtual_hygromometer.h>
// //------------------------------------------------------------------------//

// #ifdef ESP8266
//   #include <SoftwareSerial.h>
//   SoftwareSerial hc12(HC12_RX_PIN, HC12_TX_PIN);
// #elif ARDUINO_ARCH_ESP32
//   #include <HardwareSerial.h>
//   HardwareSerial hc12(1);
// #endif

// //------------------------------------------------------------------------//
// class temperatureSensor;
// temperatureSensor *temperatureSensor_[11] = {};

// class tempHumiSensor;
// tempHumiSensor *tempHumiSensor_[11] = {};

// class soilSensor;
// soilSensor *soilSensor_[11] = {};

// class binarySensor;
// binarySensor *binarySensor_[11] = {};

// class binarySensor;
// binarySensor *mailboxSensor_[11] = {};

// class scaleSensor;
// scaleSensor *scaleSensor_[11] = {};

// class scaleSensor;
// scaleSensor *scaleSensor_[11] = {};

#endif