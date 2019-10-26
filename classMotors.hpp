class motors {
  private:
    uint8_t ubLeftMappedSpeed;
    uint8_t ubRightMappedSpeed;
    uint8_t unOutputPins[4] = {AENBL, APHASE, BENBL, BPHASE};
  public:
    uint8_t ubLeftSpeed;
    uint8_t ubRightSpeed;
    uint8_t ubMaxLeftSpeed = 255;
    uint8_t ubMaxRightSpeed = 255;

    uint8_t AENBL = 2;
    uint8_t APHASE = 23;
    uint8_t BENBL = 0;
    uint8_t BPHASE = 26;


    void initPins(){
      for(uint8_t i = 0; i <= (sizeof(nOutputPins) / sizeof(uint8_t)); i++){
        pinMode(nOutputPins[i], OUTPUT);
      }
    }

    void setPhase(int8_t nLeftSpeed, int8_t nRightSpeed){
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
        digitalWrite(BPHASE, HIGH);
      }
      else{
        digitalWrite(APHASE, LOW);
        digitalWrite(BPHASE, HIGH);
      }
    }

    void drive(int8_t nLeftSpeed, int8_t nRightSpeed){
      ubLeftMappedSpeed = map(abs(nLeftSpeed), 0, 100, 0, ubMaxLeftSpeed);
      ubRightMappedSpeed = map(abs(nRightSpeed), 0, 100, 0, ubMaxRightSpeed);
      setPhase(nLeftSpeed, nRightSpeed);



  }
};
