/*
 ______   __     __    __     ______        ______     ______   ______   ______     ______     __  __    
/\__  _\ /\ \   /\ "-./  \   /\  ___\      /\  __ \   /\__  _\ /\__  _\ /\  __ \   /\  ___\   /\ \/ /    
\/_/\ \/ \ \ \  \ \ \-./\ \  \ \  __\      \ \  __ \  \/_/\ \/ \/_/\ \/ \ \  __ \  \ \ \____  \ \  _"-.  
   \ \_\  \ \_\  \ \_\ \ \_\  \ \_____\     \ \_\ \_\    \ \_\    \ \_\  \ \_\ \_\  \ \_____\  \ \_\ \_\ 
    \/_/   \/_/   \/_/  \/_/   \/_____/      \/_/\/_/     \/_/     \/_/   \/_/\/_/   \/_____/   \/_/\/_/ 
2020 Eric Min

*/

#include <Arduino.h>

int dg1 = 12;
int dg2 = 11;
int A = 19;
int B = 18;
int C = 17;
int D = 16;
int E = 15;
int F = 14;
int G = 13;
int l1 = 25;
int l2 = 26;
int l3 = 27;
int l4 = 28;
int l5 = 29;
int left = 0;
int slct = 1;
int right = 2;
int spk = 5;

/*
A little help?
            ----A----
            |       |
            F       B
            |       |
            ----G----
            |       |
            E       C
            |       |
            ----D----
*/

int seg[7] = {A, B, C, D, E, F};
int leds[12] = {A, B, C, D, E, F, l1, l2, l3, l4, l5};

int one[8] = {F, E};
int two[8] = {A, B, G, E, D};
int three[8] = {A, B, G, C, D};
int four[8] = {F, G, B, C};
int five[8] = {A, F, G, C, D};
int six[8] = {A, F, E, D, C, G};
int seven[8] = {F, A, B, C};
int eight[8] = {A, B, C, D, E, F, G};
int nine[8] = {F, A, B, G, C, D};
int zero[8] = {A, B, C, D, E, F};
int aa[8] = {E, F, A, B, C ,G};
int bb[8] = {F, E, D, C ,G};
int cc[8] = {A, F, E, D};
int dd[8] = {B, C, D, E, G};
int ee[8] = {A, F, G, E, D};
int ff[8] = {A, F, G, E};

void write(int ledBuffer[8]) {
  for (int i=0; i<8; i++) {
    digitalWrite(ledBuffer[i], 1);
  }
}

void unWrite(int ledBuffer[8]) {
  for (int i=0; i<8; i++) {
    digitalWrite(ledBuffer[i], 0);
  }
}

void allClear() {
	digitalWrite(dg1, 1);
	digitalWrite(dg2, 1);
	for (unsigned int i=0; i<sizeof(leds); i++) {
		digitalWrite(leds[i], 0);
	}
}

void clearDigits() {
	for (unsigned int i=0; i<sizeof(seg); i++) {
		digitalWrite(seg[i], 0);
	}
}

void display(int digit, int buf[8]) {
  allClear();
  if (digit == 1) {
    digitalWrite(dg1, 0);
    digitalWrite(dg2, 1);
  }

  if (digit == 2) {
    digitalWrite(dg2, 0);
    digitalWrite(dg1, 1);
  }

  if (digit == 3) {
    digitalWrite(dg1, 0);
    digitalWrite(dg2, 0);
  }

  clearDigits();
  write(buf);
}

void showDisp(int buf1[8], int buf2[8]) {
    display(1, buf1);
    display(2, buf2);
}

void setup() {
	pinMode(17, OUTPUT);
}

int segs[6] = {E, F, A, B, C, D};
void loop() {
	allClear();
	digitalWrite(dg1, 1);
	digitalWrite(dg2, 1);
	for (int i=0; i<6; i++) {
		digitalWrite(segs[i], 1);
		delay(50);
	}
}



















