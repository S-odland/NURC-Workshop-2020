#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  SerialBT.begin("MotionSense");
  Serial.begin(9600);
}

void loop() {
  SerialBT.println("Hello World!");
  Serial.println("checking");
  delay(1000);
}
