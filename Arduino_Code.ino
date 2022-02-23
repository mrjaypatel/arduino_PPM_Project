#include <LiquidCrystal.h>

#define fan 7
int LED = 13; // Use the onboard Uno LED
int analog_IN = A0; // This is our input pin
const int rs = 12,
          en = 11,
          d4 = 5,
          d5 = 4,
          d6 = 3,
          d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(fan, OUTPUT);
  pinMode(analog_IN, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("  Welcome   To  ");
  lcd.setCursor(0, 1);
  lcd.print("  Air  Ionizer  ");
  delay(5000);
  lcd.clear();

  //digitalWrite(fan, HIGH);

}

void loop() {
  int Value = analogRead(analog_IN);
  Serial.println(Value);
  if (Value < 330) {
    digitalWrite(fan, LOW);
    Serial.println("----Air Not Polluted");
  }
  Value = analogRead(analog_IN);
  if (Value > 340) {
    digitalWrite(fan, HIGH);
    Serial.println("----Air Polluted");
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("POLLUTION LEVEL:");
  lcd.setCursor(0, 1);
  lcd.print(Value);
  delay(2000);
  Value = analogRead(analog_IN);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("POLLUTION LEVEL:");
  lcd.setCursor(0, 1);
  lcd.print(Value);

}
