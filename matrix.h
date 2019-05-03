// ******************************
// by Lemmy
// ******************************

#include "./alpha.h"

#define MATRIXDEBUG 0

const int timer = 200 ;
const int row[8] = { 5, 8, 3, 9, 20, 2, 18, 23 };
const int col[8] = { 16, 17, 21, 4, 22, 6, 7, 19 };
const int matrix_size = 5000;
bool matrix[8][matrix_size];
bool display_matrix[8][8] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};
int txt_size = 0;

// **************************************************
void matrix_scrclr() {
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    digitalWrite(col[thisPin], HIGH);
    digitalWrite(row[thisPin], LOW);
  }
}

// **************************************************
void matrix_disp(int x, int y) {
  //matrix_scrclr();
  digitalWrite(row[x], HIGH); // on
  digitalWrite(col[y], LOW);
  digitalWrite(col[y], HIGH); // off
  digitalWrite(row[x], LOW);
}

// **************************************************
void matrix_draw(bool m[8][8]) {
  elapsedMillis time;
  while (time < timer) {
    for (int x = 0; x < 8; x++) {
      for (int y = 0; y < 8; y++) {
        if (m[x][y] == true) matrix_disp(x, y);
      }
    }
  }
}

// **************************************************
void matrix_init() {
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < matrix_size; y++) {
      matrix[x][y] = 0;
    }
  }
}

// **************************************************
void matrix_set(String txt) {
  if (MATRIXDEBUG == 1) DEBUG_SERIAL.println("matrix_set");
  txt_size = 0;
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      matrix[x][y] = 0;
    }
    txt_size++;
  }
  int letternb = txt.length();
  for (int i = 0; i < letternb; i++) {
    int letter = txt.charAt(i);
    if (letter >= 32 and letter <= 128) {
      int letterSize = 5;
      if (letter == 32 or letter == 33 or letter == 39 or letter == 105 or letter == 124) letterSize = 1;
      else if (letter == 44 or letter == 46 or letter == 58 or letter == 59 or letter == 96 or letter == 108) letterSize = 2;
      else if (letter == 34 or letter == 40 or letter == 41 or letter == 45 or letter == 91 or letter == 93 or letter == 106 or letter == 110 or letter == 116) letterSize = 3;
      else if ((letter >= 60 and letter <= 62) or (letter >= 97 and letter <= 108) or (letter >= 110 and letter <= 117) or (letter >= 121 and letter <= 125)) letterSize = 4;
      for (int x = 0; x < 8; x++) {
        for (int y = 0; y < letterSize; y++) {
          matrix[x][txt_size + y] = alpha[letter - 32][x][y];
        }
      }
      for (int x = 0; x < 8; x++) {
        matrix[x][txt_size + letterSize] = 0;
      }
      txt_size = txt_size + letterSize + 1;
    }
  }
   for (int x = 0; x < 8; x++) {
    for (int y = txt_size; y < (txt_size + 8); y++) {
      matrix[x][y] = 0;
    }
  }
  if (MATRIXDEBUG == 1) {
    for (int x = 0; x < 8; x++) {
      for (int y = 8; y < txt_size; y++) {
        if (matrix[x][y] == 0) DEBUG_SERIAL.print(" ");
        else DEBUG_SERIAL.print("#");
      }
      DEBUG_SERIAL.print("\n");
    }
  }
}
