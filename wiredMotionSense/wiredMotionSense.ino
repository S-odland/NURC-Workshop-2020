#include <stdio.h>

const int motionSensePin = A4; // phototransistor on pin A4 of the Huzzah
const int onBoardLED = 13; // built in LED on the esp32 HUZZAH
 
void setup()
{
  pinMode(onBoardLED, OUTPUT); // make red led an ouput indicator for accelerometer movement
  pinMode(motionSensePin, INPUT);
  Serial.begin(9600); // Serial baud rate of 9600

}

void loop()
{
  int motionSense;
  motionSense = analogRead(motionSensePin); // reading the value of the phototransistor

  if (motionSense < 50){ // threshold value to detect an "intruder"
    digitalWrite(onBoardLED, HIGH); // light goes on if "intruder" is detected
    Serial.println("INTRUDER");
  }
  delay(100);
}
