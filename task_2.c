#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int redProbe = A0;
int blueProbe = A1;

void setup() {
  // put your setup code here, to run once:
  pinMode(redProbe, INPUT_PULLUP);
  pinMode(blueProbe, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  int redReading = analogRead(redProbe);
  int blueReading = analogRead(blueProbe);
  float Vcalc = (5.0/1023)*(redReading - blueReading);
  lcd.setCursor(0,0);
  lcd.print("BATT ");
  lcd.print(Vcalc);
}