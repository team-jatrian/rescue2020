#include "macros.h"
#include "peripherals/motor.hpp"
#include "peripherals/sensor.hpp"
#include "peripherals/ultra.hpp"
#include "peripherals/DIP.hpp"

#include <EEPROM.h>

DRV8834 left(2, 23, 17), right(29, 26, 17); //(ENBL, PHASE, "STEPS")
sensor L(A4, 120), LI(A3, 120), R(A0, 120), RI(A1, 120), M(A2, 120); //(PORT, threshold)
PING28015 front(A8, 300); //(PIN, MINDIFF)
DIP ps(8, 7, 6, 5); //(PIN1, 2, 3, 4)

const int8_t weights[5] = { -2, -1, 0, 1, 2};
const int8_t Kp = 40;

void room();
char getDirection();
void rescue(char);

inline void drv(int8_t x, int8_t y) {
  if (digitalRead(SWITCH)) {
    //delay(2);
    left.drive(x);
    right.drive(y);
  }
  else {
    left.drive(0);
    right.drive(0);
  }
}
inline void drv(int8_t x, int8_t y, int32_t z) {
  repeatMillis(z) {
    drv(x, y);
  }
}

void crossing() {
  spn("CROSSING");
  drv(0, 0, 200);
  drv(-70, -70, 700);
  drv(0, 0, 200);
  CAM.write(3);
  while (1) {
    if (CAM.available() > 0) {
      char opcode = CAM.read();
      spn(opcode);
      switch (opcode) {
        case '1':
          drv(70, 70, 700);
          drv(70, -70, 770);
          drv(70, 70, 100);
          break;
        case '4':
          drv(70, 70, 700);
          drv(-70, 70, 770);
          drv(70, 70, 100);
          break;
        case '2':
          drv(70, 70, 700);
          drv(70, -70, 1100);
          break;
        default:
          drv(70, 70, 900);
          break;
      }
      //STOP;
      break;
    }
  }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  CAM.begin(115200, SERIAL_8O2);
  Serial.begin(9600);
  pinMode(SWITCH, INPUT);
}

void loop() {
  switch (ps.readProgram()) {
    case 1:
      debug();
      break;
    case 2:
      debug();
      piddrive();
      break;
    case 6:
      EEPROM.write(0, 0);
      EEPROM.write(1, 0);
      STOP;
    case 15:
      room();
      break;
    default:
      piddrive();
      break;
  }
  //spn(ps.readProgram());
}
