#include <stdio.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT; //defining an instance of BluetoothSerial to be SerialBT

const int motionSensePin = A4; // phototransistor on pin A4 of the Huzzah
const int dotLed = 21 // Dot LED pointed at phototransistor
const int rLed = 14; // red LED to indicate motion sense
 
void setup()
{
  pinMode(rLed, OUTPUT); // make red led an ouput indicator motion sense
  pinMode(dotLed,OUTPUT); // dot led pointed at phototransistor an output
  pinMode(motionSensePin, INPUT);
  digitalWrite(dotLED,HIGH); // Turning on dotLed
  Serial.begin(9600); // Serial baud rate of 9600
  SerialBT.begin("MotionSense"); // begins bluetooth for esp named MotionSense -- allowing you 
  // to pair with your computer
}

void loop()
{
  int motionSense;
  motionSense = analogRead(motionSensePin);

  if (motionSense < 50){ // threshold value to detect an "intruder"
    digitalWrite(rLed, HIGH); // light goes on if "intruder" is detected
    SerialBT.println("INTRUDER");
  }
  delay(100);
}
