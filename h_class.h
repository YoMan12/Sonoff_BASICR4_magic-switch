#ifndef H_CLASS_H_
#define H_CLASS_H_

namespace Supla {
namespace Html {
  
//---------------------------------------------------------------------------//
//                                                                   buttonPara                                                           
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
      sender->send(20000);
      sender->send("\" step=\"1\" ");
      sender->sendNameAndId(FILTER_KEY);
      sender->send(" value=\"");
      inCfgValue = 800;
      cfg->getUInt32(FILTER_KEY, &inCfgValue);
      sender->send(inCfgValue);
      sender->send("\">");
      sender->send("</div>");
      // - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲ - ▲
      
      // - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼
      sender->send("<div class=\"form-field\">");
      sender->sendLabelFor(DEBOUNCE_KEY, "Debounce");
      sender->send(
                 "<input type=\"number\" min=\"0\" max=\"1000\" step=\"1\" ");
      sender->sendNameAndId(DEBOUNCE_KEY);
      sender->send(" value=\"");
      inCfgValue = 3;
      cfg->getUInt32(DEBOUNCE_KEY, &inCfgValue);
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
      return true;
    }
          
    if (cfg && strcmp(key, DEBOUNCE_KEY) == 0) {
      uint32_t inFormValue = stringToUInt(value);
      cfg->setUInt32(DEBOUNCE_KEY, inFormValue);
      debounce = inFormValue;
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