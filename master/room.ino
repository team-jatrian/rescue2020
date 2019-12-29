void room() {
  front.mindiff = 20;
  rescue(getDirection());
  front.mindiff = 300;
}

char getDirection() {
  while (front.read() > 100) {
    drv(70, 70);
  }
  drv(70, -70, 700);
  drv(0, 0, 50);
  if (front.read() < 150) {
    drv(0, 0, 50);
    return 'L';
  }
  else {
    drv(0, 0, 50);
    return 'R';
  }
}

void rescue(char x) {
  spn("rescue");
  for (uint16_t d = 100; d < 400; d += 100) {
    for (uint8_t i = 0; i < 4; i++) {
      spn(i);
      while (1) {
        if (front.read() < d) {
          drv(70, -70, 700);
          break;
        }
        //spn("driving");
        drv(70, 70);
      }
    }
  }
  STOP;
}
