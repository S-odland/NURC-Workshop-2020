int ledPin = 21;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.print("Hello World!");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("on");
  digitalWrite(ledPin, HIGH);

  delay(500);

  Serial.println("off");
  digitalWrite(ledPin, LOW);

  delay(500);
}
