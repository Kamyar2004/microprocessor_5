int trig = 10;
int echo = 9;
int duration = 0;
int distance = 0;
int led = 11;
int pwmLed = 0;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) * 0.0343;

  analogWrite(led, 0);
  if (distance >= 4 && distance <= 30) {
    pwmLed = map(distance, 4, 30, 255, 0);
    analogWrite(led, pwmLed);
    Serial.println(distance);
    delay(100);
    }

    Serial.println(distance);
    delay(100);
}