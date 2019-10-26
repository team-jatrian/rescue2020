class motor {
  private:
    uint8_t ubMappedSpeed;
    uint8_t unOutputPins[2] = {ENBL, PHASE};
    //genaue assignments noch fixen
    void setPhase(int8_t);
    uint8_t NewSpeed(uint8_t, uint8_t&);

  public:
    uint8_t ubSpeed;
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
  ubMappedSpeed = map(abs(nInputSpeed), 0, 100, 0, ubMaxSpeed);
  setPhase(nInputSpeed);
  if (ubEngineSwitch == 1){
    analogWrite(ENBL, NewSpeed(ubMappedSpeed, ubSpeed));
  }
  else {
    digitalWrite(AENBL, LOW);
    digitalWrite(BENBL, LOW);
  }
}

void motor::setPhase(int8_t nInputSpeed){
  if (nInputSpeed < 0){
    digitalWrite(PHASE, HIGH);
    }
  else if (nRightSpeed > 0){
    digitalWrite(PHASE, LOW);
    }
  }

uint8_t motor::NewSpeed(uint8_t nInputSpeed, uint8_t& nCurrentSpeed){
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
