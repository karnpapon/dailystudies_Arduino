#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte customChar[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

void setup()
{
  lcd.createChar(0, customChar);
  lcd.begin(16, 2);
  lcd.setCursor(2, 0); //(x axis,y axis) not allowed decimal numbers.
  lcd.print("The");
  lcd.write((uint8_t)0); //unsigned int type
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)0);
 }

void loop() {
   lcd.cursor();
  delay(500);
  lcd.noCursor();
  delay(500);
}
