#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // change 0x27 to 0x3F if needed

#define BUZZER 8  // buzzer pin

// Define note frequencies
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988

void setup() {
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Send A/B/C");
  lcd.setCursor(0,1);
  lcd.print("to play song");
}

void loop() {
  if (Serial.available()) {
    char ch = Serial.read();
    lcd.clear();

    if (ch == 'B' || ch == 'b') {
      lcd.print("Happy Birthday");
      playBirthday();
    } 
    else if (ch == 'C' || ch == 'c') {
      lcd.print("Coffin Dance");
      playCoffin();
    } 
    else if (ch == 'A' || ch == 'a') {
      lcd.print("Shape of You");
      playShapeOfYou();
    } 
    else {
      lcd.print("Invalid Option");
    }

    lcd.setCursor(0,1);
    lcd.print("Done Playing");
  }
}

// --- Happy Birthday Full Version ---
void playBirthday() {
  int melody[] = {
    NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4,
    NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4,
    NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4,
    NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4
  };
  int durations[] = {
    4,4,2,2,2,1,
    4,4,2,2,2,1,
    4,4,2,2,2,2,1,
    4,4,2,2,2,1
  };
  
  for (int i=0; i<25; i++){
    int noteDuration = 1000 / durations[i];
    tone(BUZZER, melody[i], noteDuration);
    delay(noteDuration * 1.30);
  }
  noTone(BUZZER);
}

// --- Coffin Dance Full Intro ---
void playCoffin() {
  int melody[] = {
    NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
    NOTE_D4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4,
    NOTE_E4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4,
    NOTE_D4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4
  };
  int durations[] = {
    4,4,4,4,4,4,4,4,
    4,4,4,4,4,2,
    4,4,4,4,4,4,4,4,
    4,4,4,4,4,2
  };
  
  for (int i=0; i<28; i++){
    int noteDuration = 1000 / durations[i];
    tone(BUZZER, melody[i], noteDuration);
    delay(noteDuration * 1.30);
  }
  noTone(BUZZER);
}

// --- Shape of You Full Main Melody ---
void playShapeOfYou() {
  int melody[] = {
    NOTE_D4, NOTE_F4, NOTE_G4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_D4,
    NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4,
    NOTE_D4, NOTE_F4, NOTE_G4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_D4,
    NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4
  };
  int durations[] = {
    4,4,4,4,4,4,4,4,
    4,4,4,4,2,
    4,4,4,4,4,4,4,4,
    4,4,4,4,2
  };
  
  for (int i=0; i<26; i++){
    int noteDuration = 1000 / durations[i];
    tone(BUZZER, melody[i], noteDuration);
    delay(noteDuration * 1.30);
  }
  noTone(BUZZER);
}
