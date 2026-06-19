#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int pirPin = 2;
const int buzzerPin = 9;

LiquidCrystal_I2C lcd(0x27, 16, 2);

int currentState = LOW;
int previousState = LOW;
int motionCount = 0;

void setup() {
  Serial.begin(9600);

  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Motion Detector");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");

  Serial.println("Calibrating PIR...");
  delay(30000);  // PIR warm-up time

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("System Ready");

  Serial.println("System Ready");
  delay(2000);

  lcd.clear();
}

void loop() {

  currentState = digitalRead(pirPin);

  if (currentState != previousState) {

    if (currentState == HIGH) {

      motionCount++;

      Serial.print("Motion Detected! Count = ");
      Serial.println(motionCount);

      digitalWrite(buzzerPin, HIGH);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("MOTION FOUND!");
      lcd.setCursor(0, 1);
      lcd.print("Count: ");
      lcd.print(motionCount);

    } else {

      Serial.println("Area Clear");

      digitalWrite(buzzerPin, LOW);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Status:");
      lcd.setCursor(0, 1);
      lcd.print("No Motion");
    }

    previousState = currentState;
  }
}
