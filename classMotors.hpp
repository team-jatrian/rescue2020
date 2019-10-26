class motors {
  public:
  int8_t bLeftSpeed;
  int8_t bRightSpeed;
  int8_t bMaxLeftSpeed = 255;
  int8_t bMaxRightSpeed = 255;
  
  uint8_t AENBL = 2; 
  uint8_t APHASE = 23;
  uint8_t BENBL = 0;
  uint8_t BPHASE = 26;


  private:
  int8_t bLeftMappedSpeed;
  int8_t bRightMappedSpeed;
  uint8_t nOutputPins[4] = {AENBL, APHASE, BENBL, BPHASE};

  void initPins(){
    for(uint8_t i = 0; i <= (sizeof(nOutputPins) / sizeof(uint8_t)); i++){
      pinMode(nOutputPins[i], OUTPUT);
    }
  }
  
  void drive(int8_t nLeftSpeed, int8_t nRightSpeed){
    bLeftMappedSpeed = map(abs(nLeftSpeed), 0, 100, 0, bMaxLeftSpeed);
    bRightMappedSpeed = map(abs(nRightSpeed), 0, 100, 0, bMaxRightSpeed);
    
  }
};
