#define spn(x) Serial.print(x); Serial.print("\n")
#define sp(x) Serial.print(x)
#define dw(x, y) digitalWriteFast(x, y)
#define dr(x) digitalReadFast(x)
#define ar(x) analogRead(x)
#include "motor.hpp"
#include "sensor.hpp"
motor left(2, 23, 3), right(4, 26, 3); //(ENBL, PHASE, SWITCH)
sensor L(A0, 120), LI(A1, 120), R(A3, 120), RI(A2, 120); //(PORT, TRESHOLD)
#define drv(x, y) delay(1); left.drive(x); right.drive(y)

void setup(){
}

void loop(){
  drv(100, -100);
  /*if (L.read()) {
    drv(-100, 100);
    }
    else if (R.read()) {
    drv(100, -100);
    }
    else {
    drv(100, 100);
    }*/
}
