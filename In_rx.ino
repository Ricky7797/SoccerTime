
#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

struct dataStruct{
  float press_norm ; 

  unsigned long counter;
   
}myData;


void setup()
{
    Serial.begin(9600);  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) // Non-blocking
    {
  int i;

  // Message with a good checksum received, dump it.
 
        memcpy(&myData, buf, sizeof(myData));
        Serial.println("");
        
                Serial.print("press_norm: ");
        Serial.println(myData.press_norm);
        if (myData.press_norm!=11.00) {
          int x=random(3)+12;
          Serial.println(x);
          if (x!=14) {
            Serial.println(x);
            digitalWrite(x,HIGH);
            delay(500);
            digitalWrite(x,LOW);  
          }
          else {
            Serial.println(99);
            digitalWrite(13,HIGH);
            digitalWrite(12,HIGH);
            delay(500);
            digitalWrite(13,LOW);
            digitalWrite(12,LOW);
          }
          
        }

    }
}


