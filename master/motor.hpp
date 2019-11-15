#define dw digitalWriteFast
#define dr digitalReadFast

class motor {
  private:
    int16_t mappedSpeed;
    int16_t Speed = 0;
    boolean engineSwitch;
    uint8_t OutputPins[2] = {ENBL, PHASE};
    uint8_t InputPins[1] = {SWITCH};

    void setPhase();
    void newSpeed();

  public:
    uint8_t ENBL = 2;
    uint8_t PHASE = 23;
    uint8_t SWITCH = 3;

    void drive(int16_t);
};

motor::initPins(){
  for (uint8_t i = 0; i < (sizeof(OutputPins) / sizeof(uint8_t)){ //outputs
    pinMode(OutputPins[i], OUTPUT);
  }
  for (uint8_t i = 0; i < (sizeof(InputPins) / sizeof(uint8_t)){ //inputs
    pinMode(InputPins[i], INPUT);
  }
}

motor::drive(int16_t speed){
  engineSwitch = dr(SWITCH);
  if (engineSwitch){
    mappedSpeed = (speed, -100, 100, -255, 255);
    newSpeed();
    setPhase();
    analogWrite(ENBL, abs(Speed));
  }
  else {
    digitalWrite(ENBL, LOW);
  }
}

motor::newSpeed(){
  if (Speed < mappedSpeed){
     ++Speed;
  }
  if (Speed > mappedSpeed){
     --Speed;
  }
}

motor::setPhase(){
  if (Speed < 0){
    dw(PHASE, LOW);
  }
  if (Speed > 0){
    dw(PHASE, HIGH);
  }
