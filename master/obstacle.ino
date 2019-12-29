//EEPROM: Addr 0: L = left, R = right
//Addr 1: 0 = Failed, 1 = Succesful

void obstacle() {
  char dir;
  if (EEPROM.read(1) == 1) {
    dir = EEPROM.read(0);
    writeAttempt(dir);
  }
  else {
    dir = EEPROM.read(0);
    if (dir == 'L') {
      dir = 'R';
    }
    else {
      dir = 'L';
    }
    writeAttempt(dir);
  }
  switch (dir) {
    case 'R':
      L.threshold = 100;
      drv(0, 0, 100);
      drv(70, -70, 600);
      drv(70, 70, 300);
      while (!L.read()) {
        drv(20, 100);
      }
      drv(0, 0, 100);
      drv(70, 70, 150);
      while (!LI.read()) {
        drv(70, -70);
      }
      EEPROM.write(1, 1);
      L.threshold = 120;
      break;

    case 'L':
      R.threshold = 100;
      drv(0, 0, 100);
      drv(-70, 70, 600);
      drv(70, 70, 300);
      while (!R.read()) {
        drv(100, 20);
      }
      drv(0, 0, 100);
      drv(70, 70, 150);
      while (!RI.read()) {
        drv(-70, 70);
      }
      EEPROM.write(1, 1);
      R.threshold = 120;
      break;
  }
}


void writeAttempt(char dir) {
  EEPROM.write(0, dir );
  EEPROM.write(1, 0);
}
