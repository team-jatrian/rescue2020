class sensor {
  private:
    uint8_t port;
    uint16_t buffer;

  public:
    uint16_t threshold;
    uint16_t value();
    bool read();
    void debug();
    sensor(uint8_t, uint16_t);
};

sensor::sensor(uint8_t x, uint16_t y) : port{x}, threshold{y} {
  pinMode(x, INPUT);
}

bool sensor::read() {
  delay(1);
  /*buffer = 0;
  for (uint8_t i = 0; i < 10; i++) {
    buffer += ar(port);
  }
  buffer /= 10;*/
  if (ar(port) < threshold) {
    return true;
  }
  else {
    return false;
  }
}

uint16_t sensor::value() {
  return ar(port);
  //buffer = 0;
    /*for (uint8_t i = 0; i < 10; i++) {
    buffer += ar(port);
  }
  return (buffer / 10);*/
}

void sensor::debug() {
  sp(port);
  sp(": ");
  sp(value());
  sp("\t");
}
