#define spn(x) Serial.println(x)
#define sp(x) Serial.print(x)
#define ar(x) analogRead(x)
#define aw(x, y) analogWrite(x, y)
#define dr(x) digitalReadFast(x)
#define dw(x, y) digitalWriteFast(x, y)
#define STOP while(1){drv(0, 0);}
#define SWITCH 3
#define CAM Serial4
#define repeatMillis(x) for(uint32_t tx = millis(); millis() < tx + x;)
