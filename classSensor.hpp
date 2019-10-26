class sensor {
  public:
    uint8_t ubPort;
    uint16_t unTreshold;
    bool read();
    uint16_t value();
};

  bool sensor::read(){
    uint16_t unBuffer = 0;
    for(uint8_t i = 0; i < 10; i++){
      unBuffer += analogRead(ubPort);
    }
    uint16_t unAverage = unBuffer / 10;
    if (unAverage < unTreshold){
      return true;
    }
    else {
      return false;
    }
  }

  uint16_t sensor::value(){
    uint16_t unBuffer = 0;
    for(uint8_t i = 0; i < 10; i++){
      unBuffer += analogRead(ubPort);
    }
    uint16_t unAverage = unBuffer / 10;
    return unAverage; 
  }
  
