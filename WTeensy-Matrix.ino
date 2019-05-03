// ******************************
// WTeensy-Matrix by Lemmy
// ******************************


/* modify this in \hardware\teensy\avr\cores\teensy3\serial1.c
 *  #define TX_BUFFER_SIZE 4096 // number of outgoing bytes to buffer
 *  #define RX_BUFFER_SIZE 4096 // number of incoming bytes to buffer
 *  #define IRQ_PRIORITY  32  // 0 = highest priority, 255 = lowest */ 

#include <TimeLib.h>

#define DEBUG_SERIAL Serial
#define LED 13

#include "./matrix.h"
#include "./wifi.h"
#include "./ntp.h"
#include "./http.h"

// **************************************************
void setup() {
  DEBUG_SERIAL.begin(115200);
  WIFI_SERIAL.begin(115200);
  DEBUG_SERIAL.setTimeout(2000);
  WIFI_SERIAL.setTimeout(2000);
  delay(500);
  DEBUG_SERIAL.println("WTeensy Matrix init");
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  pinMode(WRESET, OUTPUT);
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    digitalWrite(col[thisPin], HIGH); // LEDs OFF
  }
  matrix_init();
  wifi_init();
  setSyncProvider(ntp_gettime);
  setSyncInterval(10800); // sync every 3 hours
  matrix_set(wifi_getlink());
  DEBUG_SERIAL.println("WTeensy Matrix ready");
  digitalWrite(LED, LOW);
}

// **************************************************
void loop() {
  if (display_time) {
    if (timeStatus() < 2) setSyncProvider(ntp_gettime);
    txt = ntp_ftime();
    matrix_set(txt);
  }
  for (int i = 0; i <= txt_size; i++) {
    for (int x = 0; x < 8; x++) {
      for (int y = 0; y < 8; y++) {
        display_matrix[x][y] = matrix[x][y + i];
      }
    }
    matrix_draw(display_matrix);
    if (DEBUG_SERIAL.available() > 0) {
      txt = DEBUG_SERIAL.readStringUntil(10);
      txt = alpha_removespecial(txt);
      DEBUG_SERIAL.print("Display : ");
      DEBUG_SERIAL.println(txt);
      matrix_set(txt);
      break;
    }
    if (http_listener()) break;
  }
}
