class motor {
  private:
    int16_t bMappedSpeed;
    uint8_t unOutputPins[2] = {ENBL, PHASE};
    void setPhase(int8_t);
    uint16_t NewSpeed(int16_t, int16_t&);
    int16_t nextSpeed;

  public:
    int16_t bSpeed;
    uint8_t ubMaxSpeed = 255;
    //AENBL 2 APHASE 23 BENBL 0 BPHASE 26
    uint8_t ENBL;
    uint8_t PHASE;
    uint8_t ubEngineSwitch;

    void drive(int8_t);

    void initPins(){
      for(uint8_t i = 0; i <= (sizeof(unOutputPins) / sizeof(uint8_t)); i++){
        pinMode(unOutputPins[i], OUTPUT);
      }
    }
};

void motor::drive(int8_t nInputSpeed){
  bMappedSpeed = map(nInputSpeed, -100, 100, -255, ubMaxSpeed);
  nextSpeed = NewSpeed(bMappedSpeed, bSpeed);
  setPhase(nextSpeed);
  analogWrite(ENBL, abs(nextSpeed));
}

void motor::setPhase(int8_t nInputSpeed){
  if (nInputSpeed < 0){
    digitalWrite(PHASE, LOW);
    }
  else if (nInputSpeed > 0){
    digitalWrite(PHASE, HIGH);
    }
  }

uint16_t motor::NewSpeed(int16_t nInputSpeed, int16_t& nCurrentSpeed){
  if (nInputSpeed > nCurrentSpeed){
    nCurrentSpeed += 5;
    return nCurrentSpeed;
  }
  else if (nInputSpeed < nCurrentSpeed){
    nCurrentSpeed -= 5;
    return nCurrentSpeed;
  }
  else {
    return nCurrentSpeed;
  }
}
