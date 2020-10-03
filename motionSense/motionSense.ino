#include <stdio.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

const int motionSensePin = A4;
//const int led1 = 27;
 
void setup()
{
  //pinMode(led1, OUTPUT); // make red led an ouput indicator for accelerometer movement
  pinMode(motionSensePin, INPUT);
  Serial.begin(9600); // Serial baud rate of 9600
  SerialBT.begin("MotionSense");
}

void loop()
{
  int motionSense;
  motionSense = analogRead(motionSensePin);

  if (motionSense < 50){
    SerialBT.println("INTRUDER");
  }
  delay(50);
}
