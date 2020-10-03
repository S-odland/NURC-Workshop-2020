#include <stdio.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT; //defining an instance of BluetoothSerial to be SerialBT

const int motionSensePin = A4; // phototransistor on pin A4 of the Huzzah
//const int led1 = 27;
 
void setup()
{
  //pinMode(led1, OUTPUT); // make red led an ouput indicator for accelerometer movement
  pinMode(motionSensePin, INPUT);
  Serial.begin(9600); // Serial baud rate of 9600
  SerialBT.begin("MotionSense"); // begins bluetooth for esp named MotionSense
}

void loop()
{
  int motionSense;
  motionSense = analogRead(motionSensePin);

  if (motionSense < 50){ // threshold value to detect an "intruder"
    SerialBT.println("INTRUDER");
  }
  delay(100);
}
