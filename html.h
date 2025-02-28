#ifndef HTML_H_
#define HTML_H_

void addHtml () {
  new Supla::Html::DeviceInfo (&SuplaDevice);
  new Supla::Html::WifiParameters;
  new Supla::Html::ProtocolParameters;
  new Supla::Html::StatusLedParameters;
  Supla::Html::StatusLedParameters htmlStatusLed;
  SuplaDevice.setName("Yo -");
  SuplaDevice.setCustomHostnamePrefix("Supla-Yo-");
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

  // new Supla::Html::DivBegin("box");
  // new Supla::Html::H3Tag("Config");
  // new Supla::Html::buttonPara;
  // new Supla::Html::DivEnd();
}
#endif