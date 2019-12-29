class DRV8834 {
  private:
    int16_t mappedSpeed;
    int16_t speed = 0;
    uint8_t steps = 17;

    void setPhase();
    void newSpeed();
    void initPins();

  public:
    uint8_t ENBL;
    uint8_t PHASE;

    void drive(int16_t);
    DRV8834(uint8_t, uint8_t, uint8_t);
};

DRV8834::DRV8834(uint8_t x, uint8_t y, uint8_t z) : ENBL{x}, PHASE{y}, steps{z} {
  initPins();
}

void DRV8834::initPins() {
  pinMode(ENBL, OUTPUT);
  pinMode(PHASE, OUTPUT);
}

void DRV8834::drive(int16_t x) {
  mappedSpeed = map(x, -100, 100, -255, 255);
  newSpeed(); setPhase();
  analogWrite(ENBL, abs(speed));
}

void DRV8834::newSpeed() {
  if (speed < mappedSpeed) {
    speed += steps;
  }
  if (speed > mappedSpeed) {
    speed -= steps;
  }
}

void DRV8834::setPhase() {
  if (speed < 0) {
    dw(PHASE, HIGH);
  }
  if (speed > 0) {
    dw(PHASE, LOW);
  }
}
