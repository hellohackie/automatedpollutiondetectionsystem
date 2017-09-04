//AUTHOR - SATYAM
#include <GPRS_Shield_Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>

#define PIN_TX    7 //GSM Tx pin
#define PIN_RX    6 //GSM rx pin
#define BAUDRATE  9600
#define PHONE_NUMBER "9686049429"
#define MESSAGE  "High Pollution detected, Please change my engine OIL to 'KEEP GREEN HEALTHY NATURE'"

GPRS gprsTest(PIN_TX,PIN_RX,BAUDRATE);//RX,TX,BaudRate
int buttonState = 0;
void setup() 
{
  Serial.begin(9600);
  while(!gprsTest.init()) 
  {
      delay(1000);
      Serial.print("init error\r\n");
  }  
  Serial.println("gprs init success");
  pinMode(12, INPUT);
  
}

void loop() 
{
  //nothing to do
  buttonState = digitalRead(12);// Pin 9 MQ135 D0 to Arduino Pin9
  if (buttonState == LOW) 
  {
    // turn LED on:
    gprsTest.sendSMS(PHONE_NUMBER,MESSAGE);
    Serial.println("start to send message ...");
    delay(50);
  }
  
}

