class motors {
  private:
    uint8_t ubLeftMappedSpeed;
    uint8_t ubRightMappedSpeed;
    uint8_t unOutputPins[4] = {AENBL, APHASE, BENBL, BPHASE};

    //genaue assignments noch fixen
    void setPhase(int8_t, int8_t);
    uint8_t NewSpeed(uint8_t, uint8_t&);

  public:
    uint8_t ubLeftSpeed;
    uint8_t ubRightSpeed;
    uint8_t ubMaxLeftSpeed = 255;
    uint8_t ubMaxRightSpeed = 255;

    const uint8_t AENBL = 2;
    const uint8_t APHASE = 23;
    const uint8_t BENBL = 0;
    const uint8_t BPHASE = 26;

    uint8_t ubEngineSwitch;


    void initPins(){
      for(uint8_t i = 0; i <= (sizeof(unOutputPins) / sizeof(uint8_t)); i++){
        pinMode(unOutputPins[i], OUTPUT);
      }
    }

    void drive(int8_t nLeftSpeed, int8_t nRightSpeed){
      ubLeftMappedSpeed = map(abs(nLeftSpeed), 0, 100, 0, ubMaxLeftSpeed);
      ubRightMappedSpeed = map(abs(nRightSpeed), 0, 100, 0, ubMaxRightSpeed);
      setPhase(nLeftSpeed, nRightSpeed);
      if (ubEngineSwitch == 1){
        analogWrite(AENBL, NewSpeed(ubLeftMappedSpeed, ubLeftSpeed));
        analogWrite(BENBL, NewSpeed(ubRightMappedSpeed, ubRightSpeed));
      }
      else {
        digitalWrite(AENBL, LOW);
        digitalWrite(BENBL, LOW);
      }
  }
};

void motors::setPhase(int8_t nLeftSpeed, int8_t nRightSpeed){
  if (nLeftSpeed < 0 && nRightSpeed < 0){
    digitalWrite(APHASE, HIGH);
    digitalWrite(BPHASE, LOW);
    }
  else if (nLeftSpeed < 0){
    digitalWrite(APHASE, HIGH);
    digitalWrite(BPHASE, HIGH);
    }
  else if (nRightSpeed < 0){
    digitalWrite(APHASE, LOW);
    digitalWrite(BPHASE, LOW);
    }
  else {
    digitalWrite(APHASE, LOW);
    digitalWrite(BPHASE, HIGH);
    }
  }

uint8_t motors::NewSpeed(uint8_t nSetSpeed, uint8_t& nCurrentSpeed){
  if (nSetSpeed > nCurrentSpeed){
    nCurrentSpeed += 5;
    return nCurrentSpeed;
  }
  else if (nSetSpeed < nCurrentSpeed){
    nCurrentSpeed -= 5;
    return nCurrentSpeed;
  }
  else {
    return nCurrentSpeed;
  }
}
