
const int buzzer = 12;
const int redLed = 11;
const int blueLed = 10;
const int greenLed = 9;
const int echoPin = 5;
const int trigPin = 6;

long duration;
long distance;

void setup() {
  // Initialize serial communication at 9600 bites per sec
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delay(5);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;

  if(distance >= 20 && distance < 30) {
    setPinLow(buzzer);
    setColor(255, 255, 0);
    Serial.println("yellow");
    return;
  }
  else if(distance >= 10 && distance < 20) {
    setPinLow(buzzer);
    setColor(255, 165, 0);
    Serial.println("orange");
    return;
  }
  else if(distance >= 5 && distance < 10) {
    setPinLow(buzzer);
    setColor(255, 0, 0);
    Serial.println("red");
    return;
  }
  else if(distance < 5) {
    digitalWrite(buzzer, HIGH);
    blink(50, 255, 0, 0);
    return;
  }
  else {
    setPinLow(buzzer);
    setColor(0, 0, 255);
    Serial.println("green");
    return;
  }
}

void setColor(int red, int green, int blue) {
  if(red > 255)   red   = 255;
  if(blue > 255)  blue  = 255;
  if(green > 255) green = 255;
  if(red < 0)     red   = 0;
  if(blue < 0)    blue  = 0;
  if(green < 0)   green = 0;

  analogWrite(redLed, red);
  analogWrite(blueLed, blue);
  analogWrite(greenLed, green);
}

void blink(int milisecs, int red, int green, int blue) {
   setColor(red, green, blue);
   delay(milisecs);
   setColor(0, 0, 0);
   delay(milisecs);
}

void setPinLow(int pin) {
  if(digitalRead(pin) == HIGH) digitalWrite(pin, LOW);
}
