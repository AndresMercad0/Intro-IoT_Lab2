#define LDRpin A0
#define LEDlow 11
#define LEDmedium 10
#define LEDhigh 9

int LDRValue = 0;

void setup() {
  Serial.begin(9600);

  pinMode(LEDlow, OUTPUT);
  pinMode(LEDmedium, OUTPUT);
  pinMode(LEDhigh, OUTPUT);

  digitalWrite(LEDlow, LOW);
  digitalWrite(LEDmedium, LOW);
  digitalWrite(LEDhigh, LOW);
}

void loop() {
  LDRValue = analogRead(LDRpin);
  Serial.println(LDRValue);
  if (LDRValue<255) {
    digitalWrite(LEDlow, LOW);
    digitalWrite(LEDmedium, LOW);
    digitalWrite(LEDhigh, LOW);
  }
  else if (LDRValue>=255 && LDRValue<510) {
    digitalWrite(LEDlow, HIGH);
    digitalWrite(LEDmedium, LOW);
    digitalWrite(LEDhigh, LOW);
  }
  else if (LDRValue>=510 && LDRValue<765) {
    digitalWrite(LEDlow, HIGH);
    digitalWrite(LEDmedium, HIGH);
    digitalWrite(LEDhigh, LOW);
  }
  else if (LDRValue>=765 && LDRValue<=1023) {
    digitalWrite(LEDlow, HIGH);
    digitalWrite(LEDmedium, HIGH);
    digitalWrite(LEDhigh, HIGH);
  }
  delay(2);
}
