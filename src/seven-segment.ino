/*
 * Project seven-segment
 * Description: Test Seven Segment
 * Author: Ponlawat W.
 * Date: 10 November 2020
 */

#include "Grove_4Digit_Display.h"

#define CLK D2
#define DIO D3

TM1637 tm1637(CLK, DIO);

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  int8_t NumTab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  int8_t ListDisp[4];
  unsigned char i = 0;
  unsigned char count = 0;
  bool pointOn = true;
  delay(150);

  while(true) {
    i = count++;
    if (count == sizeof(NumTab)) {
      count = 0;
    }
    for (unsigned char bit = 0; bit < 4; bit++) {
      ListDisp[bit] = NumTab[i++];
      if (i == sizeof(NumTab)) {
        i = 0;
      }
    }
    tm1637.display(0, ListDisp[0]);
    tm1637.display(1, ListDisp[1]);
    tm1637.display(2, ListDisp[2]);
    tm1637.display(3, ListDisp[3]);
    tm1637.point(pointOn ? POINT_ON : POINT_OFF);
    pointOn = !pointOn;
    delay(1000);
  }
}
