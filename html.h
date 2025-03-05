#ifndef HTML_H_
#define HTML_H_

void addHtml () {
  new Supla::Html::DeviceInfo (&SuplaDevice);
  new Supla::Html::WifiParameters;
  new Supla::Html::ProtocolParameters;
  new Supla::Html::StatusLedParameters;
  Supla::Html::StatusLedParameters htmlStatusLed;
  SuplaDevice.setName("YoMan - Sonoff basic R4");
  SuplaDevice.setCustomHostnamePrefix("Supla-YoMan-Sonoff-basicR4");
  SuplaDevice.setSwVersion(SOFT_VERSION);
  SuplaDevice.setSuplaCACert(suplaCACert);
  SuplaDevice.setSupla3rdPartyCACert(supla3rdCACert);
  SuplaDevice.setProtoVerboseLog(false);
  httpUpdater.setup(suplaServer.getServerPtr(), "/update");


  auto textCmd =
              new Supla::Html::TextCmdInputParameter("cmd1", 
                                        "Reset to factory <br> type \"RESET\"");
  textCmd->registerCmd("RESET", Supla::ON_EVENT_1);
  textCmd->addAction(Supla::RESET_TO_FACTORY_SETTINGS,
                                                SuplaDevice, Supla::ON_EVENT_1);
  new Supla::Html::DivEnd();

  new Supla::Html::DivBegin("box");
  new Supla::Html::H3Tag("Config");
  auto rb = new Supla::Html::SelectInputParameter(
                            BEHAVIOUR_KEY, "Relay behaviour after reset");
  rb->registerValue("Always off", 0);
  rb->registerValue("Always on", 1);
  rb->registerValue("Restore", 2);
  new Supla::Html::buttonPara;
  new Supla::Html::DivEnd();
  new Supla::Html::ButtonUpdate(&suplaServer);
}
#endif