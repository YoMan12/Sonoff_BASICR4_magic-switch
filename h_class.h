#ifndef H_CLASS_H_
#define H_CLASS_H_

namespace Supla {
namespace Html {
  
//---------------------------------------------------------------------------//
//                                                                  temperature                                                           
class buttonPara : public Supla::HtmlElement { 
 public:
  buttonPara()
    : HtmlElement(HTML_SECTION_FORM) {}

  void send(Supla::WebSender* sender) {
    auto cfg = Supla::Storage::ConfigInstance();
    
    if (cfg) {

      // - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼
      sender->send("<div class=\"form-field\">");
      sender->sendLabelFor(FILTER_KEY, "Filter");
      sender->send(
              "<input type=\"number\" min=\"0\" max=\"");
      sender->send(100);
      sender->send("\" step=\"1\" ");
      sender->sendNameAndId(FILTER_KEY);
      sender->send(" value=\"");
      inCfgValue = 5;
      cfg->getUInt32(FILTER_KEY, &inCfgValue);
      sender->send(inCfgValue);
      sender->send("\">");
      sender->send("</div>");
      // - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲
      
      // - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼
      sender->send("<div class=\"form-field\">");
      sender->sendLabelFor(DEBOUNCE_KEY, "Debounce");
      sender->send(
                 "<input type=\"number\" min=\"0\" max=\"2000\" step=\"1\" ");
      sender->sendNameAndId(DEBOUNCE_KEY);
      sender->send(" value=\"");
      inCfgValue = 300;
      cfg->getUInt32(DEBOUNCE_KEY, &inCfgValue);
      sender->send(inCfgValue);
      sender->send("\">");
      sender->send("</div>");
      // - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲

      // - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼
      sender->send("<div class=\"form-field\">");
      sender->sendLabelFor(PULLUP_KEY, "Pull-up");
      sender->send(
              "<input type=\"number\" min=\"0\" max=\"");
      sender->send(1);
      sender->send("\" step=\"1\" ");
      sender->sendNameAndId(PULLUP_KEY);
      sender->send(" value=\"");
      inCfgValue = 1;
      cfg->getUInt32(PULLUP_KEY, &inCfgValue);
      sender->send(inCfgValue);
      sender->send("\">");
      sender->send("</div>");
      // - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲

      // - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼
      sender->send("<div class=\"form-field\">");
      sender->sendLabelFor(INVERTED_KEY, "inverted");
      sender->send(
              "<input type=\"number\" min=\"0\" max=\"");
      sender->send(1);
      sender->send("\" step=\"1\" ");
      sender->sendNameAndId(INVERTED_KEY);
      sender->send(" value=\"");
      inCfgValue = 1;
      cfg->getUInt32(INVERTED_KEY, &inCfgValue);
      sender->send(inCfgValue);
      sender->send("\">");
      sender->send("</div>");
      // - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲

    }  // if cfg
  }    // sender

  bool handleResponse(const char* key, const char* value) {
    auto cfg = Supla::Storage::ConfigInstance();
    
    if (cfg && strcmp(key, FILTER_KEY) == 0) {
      uint32_t inFormValue = stringToUInt(value);

      cfg->setUInt32(FILTER_KEY, inFormValue);
      filter = inFormValue;
      for (int i = 0; i < relayQty; i++) {
        button_[i]->setSwNoiseFilterDelay(filter);
      }
      return true;
    }
          
    if (cfg && strcmp(key, DEBOUNCE_KEY) == 0) {
      uint32_t inFormValue = stringToUInt(value);
      cfg->setUInt32(DEBOUNCE_KEY, inFormValue);
      debounce = inFormValue;
      for (int i = 0; i < relayQty; i++) {
        button_[i]->setDebounceDelay(debounce);
      }
      return true;
    }          

    if (cfg && strcmp(key, PULLUP_KEY) == 0) {
      uint32_t inFormValue = stringToUInt(value);
      cfg->setUInt32(PULLUP_KEY, inFormValue);
      pullup = inFormValue;
      return true;
    }          

    if (cfg && strcmp(key, INVERTED_KEY) == 0) {
      uint32_t inFormValue = stringToUInt(value);
      cfg->setUInt32(INVERTED_KEY, inFormValue);
      inverted = inFormValue;
      return true;
    }


    return false;
  }

 protected:
  uint32_t inCfgValue = 0;
};  // class buttonPara


};  // namespace Html
};  // namespace Supla

#endif