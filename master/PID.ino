void piddrive() {
  int8_t err = error();
  double proportional = Kp * abs(err);
  if (front.read() < 65) {
    obstacle();
  }
  else if (err < 0) {
    drv(-proportional, 100);
  }
  else if (err > 0 ) {
    drv(100, -proportional);
  }
  else {
    drv(50, 50 );
  }
}


int8_t error() {
  uint8_t sensors[5] = {L.read(), LI.read(), M.read(), RI.read(), R.read()};
  int8_t buffer = 0;
  for (uint8_t i = 0; i < 5; i++) {
    buffer += sensors[i] * weights[i];
  }
  //spn(buffer);
  return buffer;
}
