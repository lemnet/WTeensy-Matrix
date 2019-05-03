// ******************************
// by Lemmy
// ******************************

#define WIFI_SERIAL Serial1
#define WRESET 14
#define IPDEBUG 0

String SSID = "SSID";
String PASS = "PASS";
bool ret;
bool wifi_connected = false;

// **************************************************
void wifi_buffclr(void) {
  while ( WIFI_SERIAL.available() > 0 ) {
    char c = WIFI_SERIAL.read();
  }
}

// **************************************************
boolean already_connected() {
  WIFI_SERIAL.println("AT+CWJAP_CUR?");
  delay(1);
  if (WIFI_SERIAL.find(SSID)) ret = true;
  else ret = false;
  wifi_buffclr();
  return ret;
}

// **************************************************
boolean wifi_softreset() {
  WIFI_SERIAL.println("AT+RST");
  delay(1);
  if (WIFI_SERIAL.find("ready")) ret = true;
  else ret = false;
  wifi_buffclr();
  return ret;
}

// **************************************************
void wifi_hardreset() {
  digitalWrite(WRESET, LOW);
  delay(1);
  digitalWrite(WRESET, HIGH);
}

// **************************************************
boolean wifi_multicon() {
  WIFI_SERIAL.println("AT+CIPMUX=1");
  delay(1);
  if (WIFI_SERIAL.find("OK")) ret = true;
  else ret = false;
  wifi_buffclr();
  return ret;
}

// **************************************************
boolean wifi_startserv80() {
  WIFI_SERIAL.println("AT+CIPSERVER=1,80");
  delay(1);
  if (WIFI_SERIAL.find("OK")) ret =  true;
  else ret =  false;
  wifi_buffclr();
  return ret;
}

// **************************************************
boolean wifi_cwmode3() {
  WIFI_SERIAL.println("AT+CWMODE_CUR?");
  if (WIFI_SERIAL.find("+CWMODE_CUR:3")) ret = true;
  else
  {
    WIFI_SERIAL.println("AT+CWMODE_CUR=3");
    delay(1);
    if (WIFI_SERIAL.find("OK")) ret = true;
    else ret = false;
  }
  wifi_buffclr();
  return ret;
}

// **************************************************
boolean wifi_connect() {
  String cmd = "AT+CWJAP_CUR=\"";
  cmd += SSID;
  cmd += "\",\"";
  cmd += PASS;
  cmd += "\"";
  WIFI_SERIAL.println(cmd);
  delay(5000);
  if (WIFI_SERIAL.find("WIFI CONNECTED") and WIFI_SERIAL.find("WIFI GOT IP") and WIFI_SERIAL.find("OK")) ret = true;
  else {
    ret = false;
    delay(10000);
  }
  wifi_buffclr();
  return ret;
}

// **************************************************
String wifi_getlink() {
  if (IPDEBUG == 1 ) DEBUG_SERIAL.println("wifi_getlink");
  WIFI_SERIAL.println("AT+CIFSR");
  delay(1);
  if (WIFI_SERIAL.find("APIP,\"")) {
    String ip = WIFI_SERIAL.readString();
    String apip = ip.substring(0, ip.indexOf("\""));
    String staip = ip.substring(ip.indexOf("STAIP,\"") + 7);
    staip = staip.substring(0, staip.indexOf("\""));
    if (IPDEBUG == 1 ) {
      DEBUG_SERIAL.println("apip : " + apip);
      DEBUG_SERIAL.println("staip : " + staip);
    }
    if (!staip.equals("0.0.0.0")) return "http://" + staip;
    else return "http://" + apip;
  }
  return "IP err";
}

// **************************************************
void wifi_init() {
  DEBUG_SERIAL.println("ESP8266 init");
  wifi_hardreset();
  delay(2000); // wait for boot
  wifi_buffclr();
  if (!already_connected()) {
    if (!wifi_softreset()) DEBUG_SERIAL.println("wifi_softreset failed");
    if (!wifi_cwmode3()) DEBUG_SERIAL.println("wifi_cwmode3 failed");
    for (int i = 0; i < 2; i++) { // attempt 2 times to connect to wifi
      if (wifi_connect()) {
        wifi_connected = true;
        break;
      }
      else {
        wifi_connected = false;
        DEBUG_SERIAL.println("wifi_connect failed");
        wifi_hardreset();
        delay(2000); // wait for boot
        if (!wifi_softreset()) DEBUG_SERIAL.println("wifi_softreset failed");
        if (!wifi_cwmode3()) DEBUG_SERIAL.println("wifi_cwmode3 failed");
      }
    }
  }
  else wifi_connected = true;
  
  if (!wifi_connected) delay(2000);
  wifi_buffclr();
  
  if (!wifi_multicon()) DEBUG_SERIAL.println("wifi_multicon failed");
  delay(100);
  if (!wifi_startserv80()) DEBUG_SERIAL.println("wifi_startserver80 failed");
  delay(250);
  wifi_buffclr();
}
