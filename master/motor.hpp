class motor {
  private:
    int16_t mappedSpeed;
    int16_t speed = 0;
    uint8_t OutputPins[2] = {ENBL, PHASE};
    uint8_t InputPins[1] = {SWITCH};
    boolean engineSwitch;

    void setPhase();
    void newSpeed();
    void initPins();

  public:
    uint8_t ENBL;
    uint8_t PHASE;
    uint8_t SWITCH;

    void drive(int16_t);
    motor(uint8_t x, uint8_t y, uint8_t z);
};

motor::motor(uint8_t x, uint8_t y, uint8_t z) {
  ENBL = x;
  PHASE = y;
  SWITCH = z;
  initPins();
}

void motor::initPins() {
  for (uint8_t i = 0; i < (sizeof(OutputPins) / sizeof(uint8_t)); i++) { //outputs
    pinMode(OutputPins[i], OUTPUT);
  }
  for (uint8_t i = 0; i < (sizeof(InputPins) / sizeof(uint8_t)); i++) { //inputs
    pinMode(InputPins[i], INPUT);
  }
}

void motor::drive(int16_t x) {
  engineSwitch = dr(SWITCH);
  if (engineSwitch) {
    mappedSpeed = map(x, -100, 100, -255, 255);
    newSpeed(); setPhase();
    analogWrite(ENBL, abs(speed));
  }
  else {
    digitalWrite(ENBL, LOW);
  }
}

void motor::newSpeed() {
  if (speed < mappedSpeed) {
    ++speed;
  }
  if (speed > mappedSpeed) {
    --speed;
  }
}

void motor::setPhase() {
  if (speed < 0) {
    dw(PHASE, LOW);
  }
  if (speed > 0) {
    dw(PHASE, HIGH);
  }
}
