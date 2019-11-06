#include "classMotor.hpp"
#include "classSensor.hpp"
#define spn(x) Serial.print(x); Serial.print("\n");
motor left;
motor right;
sensor test;
#define drv(x, y) delay(5); left.drive(x); right.drive(y);

void setup() {
  left.ENBL = 2;
  left.PHASE = 26;
  left.initPins();
  test.ubPort = A0;
  test.unTreshold = 90;
}

void loop() {
  int value = test.value();
  spn(value)
  if (value < test.unTreshold) {
    drv(100, 100);
  }
  else {
    drv(100, 100);
  }
}
