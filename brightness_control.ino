#define POTENTIOMETER_PIN 12

const byte led_gpio= 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(POTENTIOMETER_PIN, INPUT);
  ledcAttachPin(led_gpio, 0);
  ledcSetup(0,4000,8);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogVal= analogRead(POTENTIOMETER_PIN);
  int brightness= map(analogVal, 0, 4095, 0,255);
  ledcWrite(0, brightness);
  Serial.println(brightness);
  delay(31);
}
