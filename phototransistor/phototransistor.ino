
const int dotLEDpin = 14; // dot led pin on esp32
const int pPin = A4; // phototransistor pin on esp32

void setup() {  
  pinMode(dotLEDpin, OUTPUT);
  pinMode(pPin, INPUT);
  Serial.begin(9600);
}

int readP(){
  int ledVal;
  ledVal = analogRead(pPin);
  return ledVal;
}

void loop() {
  // put your main code here, to run repeatedly:
    
  digitalWrite(dotLEDpin,HIGH);
  Serial.println(readP());
  delay(500);
  digitalWrite(dotLEDpin,LOW);
  Serial.println(readP());
  delay(500);
}
