// ******************************
// by Lemmy
// ******************************

#define BTCDEBUG 0

// **************************************************
String btc_getprice() {
  if (BTCDEBUG == 1 ) DEBUG_SERIAL.println("btc_getprice");
  String price = "0";
  String get = "GET /v1/bpi/currentprice.json HTTP/1.1\r\nHost: api.coindesk.com\r\nConnection: close\r\n";
  wifi_buffclr();
  WIFI_SERIAL.println("AT+CIPSTART=2,\"TCP\",\"api.coindesk.com\",80");
  delay(1);
  if (WIFI_SERIAL.find("OK")) {
    wifi_buffclr();
    WIFI_SERIAL.println("AT+CIPSEND=2,85");
    delay(1);
    if (WIFI_SERIAL.find(">")) {
      wifi_buffclr();
      WIFI_SERIAL.println(get);
      delay(1);
      if (WIFI_SERIAL.find("SEND OK")) {
        wifi_buffclr();
        if (WIFI_SERIAL.find("+IPD,2,") and WIFI_SERIAL.find("EUR") and WIFI_SERIAL.find("rate_float\":")) {
          price = WIFI_SERIAL.readString();
          price = price.substring(0, price.indexOf("}"));
          if (BTCDEBUG == 1 ) DEBUG_SERIAL.println("price : " + price);
          wifi_buffclr();
        }
      }
    }
  }
  WIFI_SERIAL.println("AT+CIPCLOSE=1");
  delay(250);
  wifi_buffclr();
  return price;
}
