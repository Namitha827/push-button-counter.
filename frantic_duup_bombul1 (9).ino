#include <LiquidCrystal.h>

// LCD pin configuration: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tempPin = A0;     // TMP36 sensor output
const int buttonPin = 7;    // Push button input

void setup() {
  lcd.begin(16, 2);         // Initialize LCD
  pinMode(buttonPin, INPUT_PULLUP); // Internal pull-up to avoid using resistor
  lcd.print("Press button");
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) { // Button pressed (since using INPUT_PULLUP)
    int reading = analogRead(tempPin);
    float voltage = reading * (5.0 / 1023.0);
    float temperatureC = (voltage - 0.5) * 100;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperature:");
    lcd.setCursor(0, 1);
    lcd.print(temperatureC);
    lcd.print((char)223); // degree symbol
    lcd.print("C");
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Press button");
  }

  delay(500);
}