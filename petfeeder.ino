#include <Servo.h>
#define TRIG_PIN 9
#define ECHO_PIN 10
Servo dispenser;
int thresholdDistance = 30; // Distance in centimeters
void setup() {
  Serial.begin(9600);
  dispenser.attach(6);  // Attach servo to pin D6
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}
long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}
void loop() {
  long distance = getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance > 0 && distance < thresholdDistance) {
    activateDispenser();
  }
  delay(2000);
}
void activateDispenser() {
  dispenser.write(90);
  delay(1000);
  dispenser.write(0);
  delay(1000);
}