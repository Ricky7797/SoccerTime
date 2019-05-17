// ask_transmitter.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to transmit messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) transmitter with an TX-C1 module

#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;


struct dataStruct{
  float press_norm ; 
  unsigned long counter;
   
}myData;

byte tx_buf[sizeof(myData)] = {0};

int trigPin = 10;    // Trigger
int echoPin = 11;    // Echo
long duration, cm, inches;

void setup()
{
    Serial.begin(9600);    // Debugging only
    if (!driver.init())
         Serial.println("init failed");
         
     
  pinMode(trigPin, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(echoPin, INPUT); 
}

void loop()
{
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  cm = (duration/2) / 29.1;    
  inches = (duration/2) / 74;
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  myData.press_norm=inches;    
  delay(250);
  if (myData.press_norm<24 && myData.press_norm>2) {
    digitalWrite(4,HIGH);
    Serial.println("Go");
    delay(1000);
    digitalWrite(4,LOW);
  
  memcpy(tx_buf, &myData, sizeof(myData) );
  byte zize=sizeof(myData);

driver.send((uint8_t *)tx_buf, zize);

   // driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    myData.counter++;
    delay(2000);
  }
}


