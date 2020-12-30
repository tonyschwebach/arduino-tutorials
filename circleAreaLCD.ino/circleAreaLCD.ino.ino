#include <LiquidCrystal.h>

//pin setup
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

String msg1 = "Radius?";
  float rad;
String msg2 = "Area of Circle:";
float area;

int dt = 2000;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);

}
void loop() {
  //first num
    Serial.println(msg1);
      lcd.setCursor(0,0);
      lcd.print(msg1);
    while(Serial.available()==0){
        }
    rad=Serial.parseFloat();
    area=3.14*rad*rad;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(msg2);
    lcd.setCursor(0,1);
    lcd.print(area);

    delay(dt);
    lcd.clear();
}
