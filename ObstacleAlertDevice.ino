#include <LiquidCrystal.h>
#define led2Pin 10
#define led3Pin 9
#define loa 13
int RS = 11, EN = 12, D4 = 2, D5 = 3, D6 = 4, D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
float duration, distance;
void setup() {
Serial.begin(9600);
pinMode(6, OUTPUT);
pinMode(7, INPUT);
pinMode(9, OUTPUT);
pinMode(led2Pin, OUTPUT);
pinMode(led3Pin, OUTPUT);
pinMode(loa, OUTPUT);
analogWrite(8, 15);
lcd.begin(16, 2);
}
void loop() {
digitalWrite(6, HIGH);
delayMicroseconds(10);
digitalWrite(6, LOW);
duration = pulseIn(7, HIGH);
distance = 0.017 * duration;
if (distance > 70.0) {
digitalWrite(led2Pin, LOW);
}
else {
digitalWrite(led2Pin, HIGH);
}
if (distance < 50.0) {
digitalWrite(led3Pin, HIGH);
digitalWrite(loa, HIGH);
lcd.setCursor(0, 0);
lcd.print("Distance");
lcd.setCursor(9, 0);
lcd.print(distance);
lcd.setCursor(13, 0);
lcd.print("cm");
lcd.setCursor(0, 1);
lcd.print("DANGER ");
}
else if (distance < 70.0) {
digitalWrite(led3Pin, LOW);
digitalWrite(loa, LOW);
lcd.setCursor(0, 0);
lcd.print("Distance");
lcd.setCursor(9, 0);
lcd.print(distance);
lcd.setCursor(14, 0);
lcd.print("cm");
lcd.setCursor(0, 1);
lcd.print("STANDARD");
}
else {
digitalWrite(led3Pin, LOW);
digitalWrite(loa, LOW);
lcd.setCursor(0, 0);
lcd.print("Distance");
lcd.setCursor(9, 0);
lcd.print(distance);
lcd.setCursor(14, 0);
lcd.print("cm");
lcd.setCursor(0, 1);
lcd.print("SAFE ");
}
}
