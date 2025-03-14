#ifndef H_CLASS_H_
#define H_CLASS_H_

namespace Supla {
namespace Html {


const char *show(bool isShown) {
  return isShown ? "block\">" : "none\">";
}

//---------------------------------------------------------------------------//
//                                                                   myCheckBox                                                          
class myCheckBox : public Supla::HtmlElement { 
 public:
  myCheckBox() : HtmlElement(HTML_SECTION_FORM) {}

  void send(Supla::WebSender* sender) {
    auto cfg = Supla::Storage::ConfigInstance();
    
    if (cfg) {
      cfg->getUInt8(MAGIC_SWITCH_IS_ON_KEY, &inCfgTagMS);
      cfg->getUInt8(DEBUG_CH_IS_ON_KEY, &inCfgTagDC);
      cfg->getUInt8(FILTER_LIMIT_IS_ON_KEY, &inCfgTagFL);

      // - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼ - ▼

      // ---------- magic switch
      sender->send("<div class=\"form-field right-checkbox\">");
      sender->sendLabelFor(MAGIC_SWITCH_IS_ON_KEY, "Magic Switch Active");
      sender->send("<label>");
      sender->send("<span class=\"switch\">");

      sender->send("<input type=\"hidden\" id=\"hidden_"); //hiden field to send
      sender->send(MAGIC_SWITCH_IS_ON_KEY);
      sender->send("\" name=\"");
      sender->send(MAGIC_SWITCH_IS_ON_KEY);
      sender->send("\" value=\"");
      sender->send(inCfgTagMS ? "on" : "off");
      sender->send("\">");
      
      sender->send("<input type=\"checkbox\" value=\"on\" ");
      sender->send(checked(inCfgTagMS));
      sender->sendNameAndId(MAGIC_SWITCH_IS_ON_KEY);
      sender->send(" onclick=\"magicMenuShow()\">");
      sender->send("<span class=\"slider\"></span>");
      sender->send("</span>");
      sender->send("</label>");
      sender->send("</div>");

      sender->send("<div id=\"hiddenMagicMenu\" style=\"display: "); 
      sender->send(show(inCfgTagMS));

      // hidden menu
        // ---------- filter value field
        sender->send("<div class=\"form-field\">");
        sender->sendLabelFor(FILTER_KEY, "Filter value");
        sender->send("<input type=\"number\" min=\"800\" max=\"");
        if (filterLimitIsOn == 1) {
          sender->send(limit-margin);
        } else {
          sender->send(50000);
        }
        sender->send("\" step=\"10\" ");
        sender->sendNameAndId(FILTER_KEY);
        sender->send(" value=\"");
        inCfgValue = filter; // default value
        cfg->getUInt32(FILTER_KEY, &inCfgValue);
        sender->send(inCfgValue);
        sender->send("\">");
        sender->send("</div>");

       // ---------- debug switch
        sender->send("<div class=\"form-field right-checkbox\">");
        sender->sendLabelFor(DEBUG_CH_IS_ON_KEY, "Debug channel");
        sender->send("<label>");
        sender->send("<span class=\"switch\">");

        sender->send("<input type=\"hidden\" id=\"hidden_"); //hiden field to send
        sender->send(DEBUG_CH_IS_ON_KEY);
        sender->send("\" name=\"");
        sender->send(DEBUG_CH_IS_ON_KEY);
        sender->send("\" value=\"");
        sender->send(inCfgTagDC ? "on" : "off");
        sender->send("\">");
        
        sender->send("<input type=\"checkbox\" value=\"on\" ");
        sender->send(checked(inCfgTagDC));
        sender->sendNameAndId(DEBUG_CH_IS_ON_KEY);
        sender->send(" onclick=\"debugChShow()\">");
        sender->send("<span class=\"slider\"></span>");
        sender->send("</span>");
        sender->send("</label>");
        sender->send("</div>");

        // ---------- filter limit switch
        sender->send("<div class=\"form-field right-checkbox\">");
        sender->sendLabelFor(FILTER_LIMIT_IS_ON_KEY, "Filter Limit Active");
        sender->send("<label>");
        sender->send("<span class=\"switch\">");

        sender->send("<input type=\"hidden\" id=\"hidden_"); //hiden field to send
        sender->send(FILTER_LIMIT_IS_ON_KEY);
        sender->send("\" name=\"");
        sender->send(FILTER_LIMIT_IS_ON_KEY);
        sender->send("\" value=\"");
        sender->send(inCfgTagFL ? "on" : "off");
        sender->send("\">");

        sender->send("<input type=\"checkbox\" value=\"on\" ");
        sender->send(checked(inCfgTagFL));
        sender->sendNameAndId(FILTER_LIMIT_IS_ON_KEY);
        sender->send(" onclick=\"limitMenuShow()\">");
        sender->send("<span class=\"slider\"></span>");
        sender->send("</span>");
        sender->send("</label>");
        sender->send("</div>");

        sender->send("<div id=\"hiddenLimitMenu\" style=\"display: "); 
        sender->send(show(inCfgTagFL));

        // hidden menu2
          // ---------- limit value field
          sender->send("<div class=\"form-field\">");
          sender->sendLabelFor(LIMIT_KEY, "Limit value");
          sender->send("<input type=\"number\" min=\"");
          sender->send(filter+margin);
          sender->send("\" max=\"120000\" step=\"10\" ");
          sender->sendNameAndId(LIMIT_KEY);
          sender->send(" value=\"");
          inCfgValue =limit; // default value
          cfg->getUInt32(LIMIT_KEY, &inCfgValue);
          sender->send(inCfgValue);
          sender->send("\">");
          sender->send("</div>");


        sender->send("</div>"); // hidden div end
      sender->send("</div>"); // hidden div end
      
      // ---------- scripts 
      sender->send("<script>"
        "function magicMenuShow() {"
          "var dp_checkBox = document.getElementById(\"");
      sender->send(MAGIC_SWITCH_IS_ON_KEY);
      sender->send("\");"
          "var dp_content = document.getElementById(\"hiddenMagicMenu\");"
          "var hidden_field = document.getElementById(\"hidden_");
      sender->send(MAGIC_SWITCH_IS_ON_KEY);
      sender->send("\");"
          "if (dp_checkBox.checked == true) {"
            "dp_content.style.display = \"block\";"
            "hidden_field.value = \"on\";"
          "} else {"
            "dp_content.style.display = \"none\";"
            "hidden_field.value = \"off\";"
          "}"
        "}"
      "</script>");

      sender->send("<script>"
        "function debugChShow() {"
          "var dp_checkBox = document.getElementById(\"");
      sender->send(DEBUG_CH_IS_ON_KEY);
      sender->send("\");"
          "var hidden_field = document.getElementById(\"hidden_");
      sender->send(DEBUG_CH_IS_ON_KEY);
      sender->send("\");"
          "if (dp_checkBox.checked == true) {"
            "hidden_field.value = \"on\";"
          "} else {"
            "hidden_field.value = \"off\";"
          "}"
        "}"
      "</script>");

      sender->send("<script>"
        "function limitMenuShow() {"
          "var dp_checkBox = document.getElementById(\"");
      sender->send(FILTER_LIMIT_IS_ON_KEY);
      sender->send("\");"
          "var dp_content = document.getElementById(\"hiddenLimitMenu\");"
          "var hidden_field = document.getElementById(\"hidden_");
      sender->send(FILTER_LIMIT_IS_ON_KEY);
      sender->send("\");"
          "if (dp_checkBox.checked == true) {"
            "dp_content.style.display = \"block\";"
            "hidden_field.value = \"on\";"
          "} else {"
            "dp_content.style.display = \"none\";"
            "hidden_field.value = \"off\";"
          "}"
        "}"
      "</script>");

    }
  }

  bool handleResponse(const char* key, const char* value) {
    auto cfg = Supla::Storage::ConfigInstance();
    
    if (cfg && strcmp(key, MAGIC_SWITCH_IS_ON_KEY) == 0) {
      uint8_t inCfgValue = (strcmp(value, "on") == 0 ? 1 : 0);
      magicSwitchIsOn = inCfgValue;
      cfg->setUInt8(MAGIC_SWITCH_IS_ON_KEY, inCfgValue);
      return true;
    }

    if (cfg && strcmp(key, FILTER_KEY) == 0) {
      uint32_t inFormValue = stringToUInt(value);
      filter = inFormValue;
      cfg->setUInt32(FILTER_KEY, inFormValue);
      return true;
    }
    
    if (cfg && strcmp(key, DEBUG_CH_IS_ON_KEY) == 0) {
      uint8_t inCfgValue = (strcmp(value, "on") == 0 ? 1 : 0);
      debugChannelIsOn = inCfgValue; 
      cfg->setUInt8(DEBUG_CH_IS_ON_KEY, inCfgValue);
      return true;
    }
    
    
    if (cfg && strcmp(key, FILTER_LIMIT_IS_ON_KEY) == 0) {
      uint8_t inCfgValue = (strcmp(value, "on") == 0 ? 1 : 0);
      filterLimitIsOn = inCfgValue;
      cfg->setUInt8(FILTER_LIMIT_IS_ON_KEY, inCfgValue);
      return true;
    }

    if (cfg && strcmp(key, LIMIT_KEY) == 0) {
      uint32_t inFormValue = stringToUInt(value);

      cfg->setUInt32(LIMIT_KEY, inFormValue);
      limit = inFormValue;
      return true;
    }

    return false;
  }

 protected:
  uint8_t inCfgTagMS = 0;
  uint8_t inCfgTagDC = 0;
  uint8_t inCfgTagFL = 0;
  uint32_t inCfgValue = 0;
};  // class myCheckBox



};  // namespace Html
};  // namespace Supla

#endif