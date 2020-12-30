#include <LiquidCrystal.h>

//setup LCD pins
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

//setup echo sensor
int trigPin = 4;
int echoPin = 3;
  int pingTime;
  float pingAvg;
  float pings = 1000.;
  int j;
float speedSoundMPH = 767.;
float speedSoundKMPH = 1235.;
float speedSoundinpms = 0.00675;
float speedSoundcmpms = 0.017153;
float distInch;
float distCM;

int buttPin = 2;
  int buttNew;
  int buttOld;
int dt = 100;


void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buttPin,INPUT);
    digitalWrite(buttPin,HIGH);
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  
  buttNew = digitalRead(buttPin);
  if(buttNew==1 && buttOld==0){

    pingAvg=0.;
    for(j=1;j<=pings;j+=1){
      digitalWrite(trigPin,LOW);
      delayMicroseconds(10);
      digitalWrite(trigPin,HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin,LOW);
      pingTime=pulseIn(echoPin,HIGH);
      pingAvg+=pingTime;
    }
    pingAvg=pingAvg/pings;
    distInch = pingAvg*speedSoundinpms;
    distCM = pingAvg*speedSoundcmpms;
     
  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Inches: ");
    lcd.print(distInch);
    lcd.setCursor(0,1);
    lcd.print("cm: ");
    lcd.print(distCM);

    Serial.print(" Inches: ");
    Serial.print(distInch);
    Serial.print(" cm: ");
    Serial.println(distCM);  
  }
  buttOld=buttNew;
  delay(dt);
}
