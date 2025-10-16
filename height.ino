#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD address 0x27 or 0x3F (check your module)
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define TRIG_PIN 9
#define ECHO_PIN 10

// Adjust this to the height (in cm) where sensor is mounted
#define SENSOR_HEIGHT 200   // Example: sensor mounted 200 cm from the ground

void setup() {
  lcd.init();
  lcd.backlight();
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  lcd.setCursor(0, 0);
  lcd.print("Height Measuring");
  delay(2000);
  lcd.clear();
}

void loop() {
  long duration;
  float distance, height;

  // Send trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo pulse
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance (cm)
  distance = (duration * 0.0343) / 2;

  // Calculate height
  height = SENSOR_HEIGHT - distance;
  if (height < 0) height = 0; // avoid negative readings

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance, 1);
  lcd.print("cm   ");

  lcd.setCursor(0, 1);
  lcd.print("Height: ");
  lcd.print(height, 1);
  lcd.print("cm   ");

  delay(500);
}
