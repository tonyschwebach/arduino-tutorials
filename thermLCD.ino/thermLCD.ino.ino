#include <LiquidCrystal.h>
#include <DHT.h>
#define Type DHT11

//setup LCD pins
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

//setup DHT sensor pins and variables
int sensPin=2;
DHT HT(sensPin,Type);
float humid;
float tempF;

int dt = 500;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  HT.begin();
}

void loop() {
  humid = HT.readHumidity();
  tempF = HT.readTemperature(true);

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(tempF);
  lcd.print(" *F");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(humid);

  Serial.print("TempF: ");
  Serial.print(tempF);
  Serial.print(" Humidity: ");
  Serial.println(humid);

  delay(dt);
  lcd.clear();
  
}
