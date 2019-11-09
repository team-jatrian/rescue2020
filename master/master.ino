#define spn(x) Serial.print(x); Serial.print("\n");
#define sp(x) Serial.print(x)
#include "classMotor.hpp"
#include "classSensor.hpp"
motor left;
motor right;
sensor L;
sensor LI;
sensor R;
sensor RI;
#define drv(x, y) delay(5); left.drive(x); right.drive(y);

void setup() {
  left.ENBL = 2;
  left.PHASE = 23;
  right.ENBL = 4;
  right.PHASE = 26;
  left.initPins();
  right.initPins();

  L.ubPort = A0;
  LI.ubPort = A1;
  R.ubPort = A3;
  RI.ubPort = A2;

  L.unTreshold = 120;
  LI.unTreshold = 120;
  R.unTreshold = 120;
  RI.unTreshold = 120;

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
}

void loop() {
  drv(100, -100);
  /*if (L.read()) {
    drv(-100, 100);
  }
  else if (R.read()) {
    drv(100, -100);
  }
  else {
    drv(100, 100);
  }
  /*sp(L.value());
  sp("\t");
  sp(LI.value());
  sp("\t");
  sp(R.value());
  sp("\t");
  sp(RI.value());
  sp("\n");*/
}
