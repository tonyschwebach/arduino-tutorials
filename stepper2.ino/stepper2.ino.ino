#include<Stepper.h>
int stepsPerRev = 2048;
int stepSpeed = 5;
int dt = 100;
Stepper myStepper(stepsPerRev, 8,10,9,11);

int buttPin = 2;
//int buttVal = 0;
int stepDir = 1;
int buttNew;
int buttOld = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttPin,INPUT);
  digitalWrite(buttPin,HIGH);
  Serial.begin(9600);
  myStepper.setSpeed(stepSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(stepDir);
  //myStepper.step(stepsPerRev);
  
  buttNew = digitalRead(buttPin);
  if(buttOld==1 && buttNew ==0){
    stepDir = stepDir*-1;
  }
  myStepper.step(stepDir*1);
  buttOld=buttNew;
}
