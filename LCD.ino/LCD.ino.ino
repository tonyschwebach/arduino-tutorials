#include <LiquidCrystal.h>

//pin setup
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

String msg1 = "Enter 1st number";
  float num1;
String msg2 = "Enter 2nd number";
  float num2;
String msg3 = "Enter operator";
  String op;
float ans;

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
    num1=Serial.parseFloat();
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(num1);

  //operator
    Serial.println(msg3);
      lcd.setCursor(0,0);
      lcd.print(msg3);
        while(Serial.available()==0){
        }
    op=Serial.readString();
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(num1);
    lcd.print(op);

  //second num
    Serial.println(msg2);
      lcd.setCursor(0,0);
      lcd.print(msg2);
        while(Serial.available()==0){
        }
    num2=Serial.parseFloat();

  //operation
    if(op=="+"){
      ans=num1+num2;
    }
    if(op=="-"){
      ans=num1-num2;
    }
    if(op=="*"){
      ans=num1*num2;
    }
    if(op=="/"){
      ans=num1/num2;
    }

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(num1);
    lcd.print(op);
    lcd.print(num2);
    lcd.print("=");
    lcd.setCursor(0,1);
    lcd.print(ans);

    delay(dt);
    lcd.clear();
}
