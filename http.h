// ******************************
// by Lemmy
// ******************************

#include "./btc.h"

#define HTTPDEBUG 0

int display_counter = 1;
String txt = "";
bool display_time = false;

// **************************************************
void http_send(int ch_id, int http_status, String content) {
  String header;
  if (http_status == 200) {
    header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n";
    header += "Content-Length: ";
    header += (int)(content.length());  //length determined here
    header += "\r\n\r\n";    //blank line
  }
  else header = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\nConnection: close\r\nContent-Length: 0\r\n\r\n";
  String resp = "AT+CIPSEND=";
  resp += ch_id;
  resp += ",";
  resp += header.length() + content.length();
  WIFI_SERIAL.println(resp);
  delay(20);
  if (WIFI_SERIAL.find(">")) {
    WIFI_SERIAL.print(header);
    WIFI_SERIAL.print(content);
  }
  delay(1);
  WIFI_SERIAL.println("AT+CIPCLOSE=" + String(ch_id));
}

// **************************************************
String http_footer() {
  String content = "<div style=\"background-color:lightgrey; text-align:center;\">by Lemmy // Disp. : ";
  content += display_counter++;
  content += " // Uptime : ";
  content += String(millis());
  content += " ms</div></body></html>";
  return content;
}

// **************************************************
String http_header() {
  String content = "<html><head><title>WTeensy Matrix</title>";
  content += "<link rel=\"icon\" href=\"data:;base64,AAABAAEAICAQAAEABADoAgAAFgAAACgAAAAgAAAAQAAAAAEABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
  content += "pJigALystADk4OQAAAf8AR0ZHAFZWVgBlZWcAdXZzAF1f9gCDhYMAlZeVAKeppwC2ubgAxsnHANfa2AAAAAAABs3GAATN2gAArdxAIJ3tYG3u7mAN7u6gC+7u4";
  content += "gbu7ubO7u7Anu7u4i7u7ukM7u7s3t7u0a7u7uRO7u7qDe7u7b7u7rF+7u7hHu7u5wzu7ute3u1QDO7uoAnu7sAF7u7lBLy1AAGstwAAe8oAAFvLUAABEAAAERA";
  content += "AAAEAAAAAAAARm6IAEXu2AAFbuQAAS8pALe7tUBszM5AHMzPABO7u5L7u7sFjMzMyEzMzNgzu7uvO7u7RozMzNSMzMzot7u7tzu7uwZMzMzITMzM6HO7u7G7e7";
  content += "pATMzPACzMzMgfu7ucZ3tkABcM7EAGzPGAAnd2QEREQAAAQAAAAAREAAAACABAmQAAAF2AAARZyAAAGlQAa7usQFzM4YATTM5ABzu7Rnu7uoSMzM4AcMzM2Gu7";
  content += "u6s7t7tGjMzM1IzMzOhzu7u3O7u7RkzMzNSMzMzoc7u7tru7usUMzMzEcMzM2Cu7u6hvu7CAJMzNgBcMzkAG+7sEAWWEQECliAAEWcgAAFHUBABEAAAAREAAAA";
  content += "RAAAQAhAAbN2QEUvtsgAa3tYAB97ZFe7u6RDe7uwRru7uQG7u7pvu3u0X7u7uUe7u7qG+7u7c7e7tCu7e7mHu7u6xzu7u2u7t7BXu7u4h3u7ukq7u7sTe3uYRv";
  content += "u7qEH7u7CEt7u5RSstQAAe7cSIlu5EAAaukAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
  content += "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA==\">";
  content +="</head><body style=\"height:100%; margin:0px;\"><br><div style=\"height:96%; text-align:center;\"><div align=\"center\">";
  return content;
}

// **************************************************
void http_index(int ch_id) {
  String content = http_header();
  content += "<form action=\"txtmod.html\" method=GET><input style=\"line-height: 50px;font-size: 30px;\" type=\"text\" name=\"txt\" size=\"50\" value=\"";
  content += txt;
  content += "\"><br><br><input type=submit value=\"OK\" style=\"width: 70px;\"></form></div></div>";
  content += http_footer();

  http_send(ch_id, 200, content);
}

// **************************************************
void http_ssid(int ch_id, String msg) {
  String content = http_header();
  if (!msg.equals("")) content += msg + "</div></div>";
  else {
    content += "<form action=\"ssidmod.html\" method=GET>SSID : <input style=\"line-height: 50px;font-size: 30px;\" type=\"text\" name=\"ssid\" size=\"50\" value=\"";
    content += SSID;
    content += "\"><br>PASS : <input style=\"line-height: 50px;font-size: 30px;\" type=\"text\" name=\"pass\" size=\"50\">";
    content += "<br><br><input type=submit value=\"OK\" style=\"width: 70px;\"></form></div></div>";
  }
  content += http_footer();
  http_send(ch_id, 200, content);
}

// **************************************************
bool http_listener() {
  bool ret = false;
  if (WIFI_SERIAL.available() > 0) {
    if (HTTPDEBUG == 1 ) DEBUG_SERIAL.print("httplistener : ");
    if (WIFI_SERIAL.find("+IPD,")) {
      char channel = WIFI_SERIAL.read();
      if (WIFI_SERIAL.find("GET")) {
        String buffer = WIFI_SERIAL.readString();
        if (buffer.startsWith(" / HTTP", 0)) {
          if (HTTPDEBUG == 1 ) DEBUG_SERIAL.println("index...");
          http_index(channel - '0');
          wifi_buffclr();
        }
        else if (buffer.startsWith(" /ssid.html", 0)) {
          if (HTTPDEBUG == 1 ) DEBUG_SERIAL.println("ssid...");
          http_ssid(channel - '0', "");
          wifi_buffclr();
        }
        else if (buffer.startsWith(" /ssidmod.html", 0)) {
          if (HTTPDEBUG == 1 ) DEBUG_SERIAL.println("ssidmod...");
          SSID = buffer.substring(buffer.indexOf("ssid=") + 5, buffer.indexOf("&pass"));
          PASS = buffer.substring(buffer.indexOf("&pass=") + 6, buffer.indexOf("HTTP") - 1);
          http_ssid(channel - '0', "reinit ESP in 2 sec");
          wifi_buffclr();
          delay(2000);
          wifi_init();
          ret = true;
        }
        else if (buffer.startsWith(" /txtmod.html", 0)) {
          txt = alpha_transformhtml(buffer.substring(buffer.indexOf("txt=") + 4, buffer.indexOf("HTTP") - 1));
          http_index(channel - '0');
          delay(250);
          wifi_buffclr();
          if (HTTPDEBUG == 1 ) DEBUG_SERIAL.println("modify...");
          display_time = false;
          if (txt == "%time") {
            display_time = true;
            txt = ntp_ftime();
          }
          else if (txt == "%btc") txt = "@" + ntp_ftime() + " : " + btc_getprice();
          else if (txt == "%link") txt = wifi_getlink();
          matrix_set(txt);
          ret = true;
        }
        else {
          wifi_buffclr();
          if (HTTPDEBUG == 1 ) DEBUG_SERIAL.println("/!\\404");
          http_send((channel - '0'), 404, "");
          wifi_buffclr();
        }
      }
      else WIFI_SERIAL.print("AT+CIPCLOSE=" + (channel - '0'));
    }
    delay(200);
    wifi_buffclr();
  }
  return ret;
}
