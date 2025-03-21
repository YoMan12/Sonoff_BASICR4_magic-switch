#ifndef HTML_H_
#define HTML_H_

void addHtml () {
    new Supla::Html::DeviceInfo (&SuplaDevice);
    new Supla::Html::WifiParameters;
    new Supla::Html::ProtocolParameters;
    new Supla::Html::StatusLedParameters;
    Supla::Html::StatusLedParameters htmlStatusLed;
    auto textCmd = new Supla::Html::TextCmdInputParameter("cmd1",
                                        "Reset to factory <br> type \"RESET\"");
    textCmd->registerCmd("RESET", Supla::ON_EVENT_1);
    textCmd->addAction(Supla::RESET_TO_FACTORY_SETTINGS,
                                                SuplaDevice, Supla::ON_EVENT_1);
    

    SuplaDevice.setName("Yo - Sonoff basic R4");
    SuplaDevice.setCustomHostnamePrefix("Supla-Yo-basicR4");
    SuplaDevice.setSwVersion(SOFT_VERSION);
    SuplaDevice.setSuplaCACert(suplaCACert);
    SuplaDevice.setSupla3rdPartyCACert(supla3rdCACert);
    SuplaDevice.setProtoVerboseLog(false);
    httpUpdater.setup(suplaServer.getServerPtr(), "/update");
  new Supla::Html::DivEnd();

  new Supla::Html::DivBegin("box");
    new Supla::Html::H3Tag("Relay config");
    auto rb = new Supla::Html::SelectInputParameter(
                              BEHAVIOUR_KEY, "State after reset");
    rb->registerValue("Always OFF", 0);
    rb->registerValue("Always ON", 1);
    rb->registerValue("Restore", 2);
  new Supla::Html::DivEnd();


  new Supla::Html::DivBegin("box");
    new Supla::Html::H3Tag("Magic Switch Menu");  
    new Supla::Html::myCheckBox;
    // new Supla::Html::DivEnd();

  new Supla::Html::ButtonUpdate(&suplaServer);
  
}
#endif