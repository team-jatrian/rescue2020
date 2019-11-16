class sensor {
  private:
    uint8_t port;
    uint16_t buffer;
    
  public:
    uint16_t treshold;
    uint16_t value();
    bool read();
    void debug();
    sensor(uint8_t, uint16_t);
};

sensor::sensor(uint8_t x, uint16_t y) {
  port = x;
  treshold = y;
  pinMode(x, INPUT);
}

bool sensor::read() {
  buffer = 0;
  for (uint8_t i = 0; i < 10; i++) {
    buffer += ar(port);
  }
  if (buffer / 10 < treshold) {
    return true;
  }
  else {
    return false;
  }
}

uint16_t sensor::value() {
  buffer = 0;
  for (uint8_t i = 0; i < 10; i++) {
    buffer += ar(port);
  }
  return (buffer / 10);
}

void sensor::debug(){
  sp(port);
  sp(": ");
  sp(value());
  sp("/t");
}
