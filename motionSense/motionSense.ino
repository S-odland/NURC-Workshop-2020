#include <stdio.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT; //defining an instance of BluetoothSerial to be SerialBT

const int motionSensePin = A4; // phototransistor on pin A4 of the Huzzah
const int onBoardLED = 13; // built in LED on the esp32 HUZZAH
 
void setup()
{
  pinMode(onBoardLED, OUTPUT); // make red led an ouput indicator for accelerometer movement
  pinMode(motionSensePin, INPUT);
  Serial.begin(9600); // Serial baud rate of 9600
  SerialBT.begin("MotionSense"); // begins bluetooth for esp named MotionSense -- allowing you 
  // to pair with your computer
}

void loop()
{
  int motionSense;
  motionSense = analogRead(motionSensePin);

  if (motionSense < 50){ // threshold value to detect an "intruder"
    digitalWrite(onBoardLED, HIGH); // light goes on if "intruder" is detected
    SerialBT.println("INTRUDER");
  }
  delay(100);
}
