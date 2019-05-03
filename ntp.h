// ******************************
// by Lemmy
// ******************************

#define TIMEDEBUG 0

// **************************************************
time_t ntp_gettime() {
  if (TIMEDEBUG == 1) DEBUG_SERIAL.println("ntp_gettime");
  unsigned long timestamp = 0;
  byte ntp_request[48];
  for (int i = 0; i < 48; i++)
  {
    ntp_request[i] = 0x00;
  }
  ntp_request[0] = 0xE3;   // LI, Version, Mode
  ntp_request[1] = 0;      // Stratum, or type of clock
  ntp_request[2] = 10;     // Polling Interval
  ntp_request[3] = 0xEC;   // Peer Clock Precision
  wifi_buffclr();
  WIFI_SERIAL.println("AT+CIPSTART=1,\"UDP\",\"fr.pool.ntp.org\",123,123");
  delay(1);
  if (WIFI_SERIAL.find("OK")) {
    wifi_buffclr();
    WIFI_SERIAL.println("AT+CIPSEND=1,48");
    delay(1);
    if (WIFI_SERIAL.find(">")) {
      wifi_buffclr();
      for (int i = 0; i < 48; i++) {
        WIFI_SERIAL.print((char)ntp_request[i]);
      }
      delay(1);
      if (WIFI_SERIAL.find("SEND OK")) {
        wifi_buffclr();
        delay(1);
        if (WIFI_SERIAL.find("+IPD,1,48:")) {
          byte result[4] = {0, 0, 0, 0};
          byte nul[32];
          WIFI_SERIAL.readBytes(nul, 32);
          WIFI_SERIAL.readBytes(result, 4);
          timestamp = 0;
          timestamp += result[0] << 24;
          timestamp += result[1] << 16;
          timestamp += result[2] << 8;
          timestamp += result[3];
          timestamp -= 2208988800; // adjusting for epoch
          timestamp += 7200;       // adjusting for GMT + 2
          timestamp += 9;          // adjusting for display delay
          if (TIMEDEBUG == 1) DEBUG_SERIAL.println(timestamp);
        }
      }
    }
  }
  wifi_buffclr();
  WIFI_SERIAL.println("AT+CIPCLOSE=1");
  delay(250);
  wifi_buffclr();
  return timestamp;
}

String ntp_ftime() {
  String h = String(hour());
  String m = String(minute());
  String s = String(second());
  if (h.length() == 1) h = "0" + h;
  if (m.length() == 1) m = "0" + m;
  if (s.length() == 1) s = "0" + s;
  return h + ":" + m + ":" + s;
}
