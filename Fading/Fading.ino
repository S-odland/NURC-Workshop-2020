
// esp32 pwm involves ledcwrite setup and attachpin 

const int r_motor_channel = 7; // right motor PWM channel
const int led_channel = 3;

const int frequency = 5000; // PWM frequency
const int resolution = 8; // resolution in bits

int ledPin = 21;    // LED connected to digital pin 21

void setup() {

  ledcSetup(led_channel, frequency, resolution); // setting up pwm channel with 5000 Hz frequency 8 bit resolution
  ledcAttachPin(ledPin, led_channel); // connecting gpio pin 15 to channel 0
  pinMode(ledPin, INPUT);
  ledcWrite(led_channel, 0); // setting initial motor duty cycles to 0 (motor no move at start)
  Serial.begin(9600);
}

void loop() {

   for (int i = 0; i <= 255; i+=5){
    ledcWrite(led_channel,i); 
    delay(30);   
   }
   for(int i = 255; i >= 0; i-=5){
    ledcWrite(led_channel,i);
    delay(30);
   }

}
