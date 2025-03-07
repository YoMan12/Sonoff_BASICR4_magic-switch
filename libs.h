#ifndef LIBS_H_
#define LIBS_H_

#include <SuplaDevice.h>
//----------------------------------------------------------------------------//


#include <supla/device/status_led.h>
Supla::Device::StatusLed statusLed(STATUS_LED_GPIO, false); // inverted state
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
#include <supla/network/html/button_type_parameters.h>
#include <supla/network/html/button_hold_time_parameters.h>
#include <supla/network/html/button_multiclick_parameters.h>
#include <supla/network/html/button_update.h>
#include <supla/device/enter_cfg_mode_after_power_cycle.h>
//---------------------------------------------------------------------------//

#include <HTTPUpdateServer.h>
HTTPUpdateServer httpUpdater;

//---------------------------------------------------------------------------//

#include <supla/control/button.h>
Supla::Control::Button *cfgButton = nullptr;
Supla::Control::Button *button = nullptr;
#include <supla/control/relay.h>
Supla::Control::Relay *relay = nullptr;
#include <supla/control/action_trigger.h>
#include <supla/sensor/general_purpose_measurement.h>
Supla::Sensor::GeneralPurposeMeasurement *timeValue = nullptr;
//---------------------------------------------------------------------------//

#include <supla/storage/eeprom.h>
Supla::Eeprom eeprom;
//---------------------------------------------------------------------------//



#endif