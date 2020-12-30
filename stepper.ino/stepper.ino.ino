#include<Stepper.h>
int stepsPerRev = 2048;
int stepSpeed = 5;
int dt = 100;
Stepper myStepper(stepsPerRev,8,10,9,11);

int buttPin = 2;
int buttOld = 0;
int buttNew;

void setup() {
  // put your setup code here, to run once:
  myStepper.setSpeed(stepSpeed);
  pinMode(buttPin,INPUT);
  digitalWrite(buttPin,HIGH);
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  myStepper.step(stepsPerRev);
  buttNew = digitalRead(buttPin);
  Serial.println(buttNew);
//  if(buttOld==0 && buttNew ==1){
//    if(buttOld ==0){
//      stepsPerRev = stepsPerRev*-1;
//      buttOld = 1;
//    }
//    else{
//      stepsPerRev = stepsPerRev;
//    }
//  }
//  buttOld=buttNew;
  
}
