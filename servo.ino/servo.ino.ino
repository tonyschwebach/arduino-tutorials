#include<Servo.h>

int servoPin = 9;
int photoPin = A1;
float servoPos = 0;
float servoMin = 0.;
float servoMax = 160.;
int photoSens;
float photoMin = 0.;
float photoMax = 1023.;

int dt = 200;

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  pinMode(servoPin,OUTPUT);
  pinMode(servoPin,INPUT);
  Serial.begin(9600);
  myServo.attach(servoPin);

}

void loop() {
  // put your main code here, to run repeatedly:
  photoSens = analogRead(photoPin);
  servoPos = ((servoMax-servoMin)/(photoMax-photoMin))*photoSens + servoMin;
  Serial.print("shotoSens: ");
  Serial.print(photoSens);
  Serial.print("  servoPos: ");
  Serial.println(servoPos);
  delay(dt);
  
  
  myServo.write(servoPos);
  
}
