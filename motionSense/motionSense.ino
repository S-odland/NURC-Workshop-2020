#include <stdio.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT; //defining an instance of BluetoothSerial to be SerialBT

const int motionSensePin = A4; // phototransistor on pin A4 of the Huzzah
const int rLed = 14; // red LED to indicate motion sense
 
void setup()
{
  pinMode(rLed, OUTPUT); // make red led an ouput indicator motion sense
  pinMode(motionSensePin, INPUT);
  Serial.begin(9600); // Serial baud rate of 9600
  SerialBT.begin("MotionSense_ex"); // begins bluetooth for esp named MotionSense -- allowing you 
  // to pair with your computer
}

void loop()
{
  int motionSense;
  motionSense = analogRead(motionSensePin);

  SerialBT.println(motionSense);

  if (motionSense < 750){ // threshold value to detect an "intruder" 
    digitalWrite(rLed, HIGH); // light goes on if "intruder" is detected
    SerialBT.println("INTRUDER");
  } else {
    digitalWrite(rLed, LOW);
  }

  delay(100);
}
