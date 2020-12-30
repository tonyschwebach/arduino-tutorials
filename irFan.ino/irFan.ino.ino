#include <IRremote.h>

  int rcvrPin = 6;
    IRrecv IR(rcvrPin);
    decode_results cmd;
    String myCom;
  
  int speedPin = 5;
    int dcSpeed;
    int dcDir = 1;
    int dcMin = 100;
    int dcMax = 255;
    int dcInc = 25;
  int dirPin2 = 4;
  int dirPin7 = 2;
  
  int dt = 50;
  



void setup() {
  pinMode(rcvrPin,INPUT);
  pinMode(speedPin,OUTPUT);
  pinMode(dirPin2,OUTPUT);
  pinMode(dirPin7,OUTPUT);
  
  Serial.begin(9600);
  IR.enableIRIn();
}

void loop() {
  Serial.println(myCom);
  Serial.print("  dir: ");
  Serial.print(dcDir);
  Serial.print("  speed: ");
  Serial.println(dcSpeed);


  while(IR.decode(&cmd)==0){
  }

  if(cmd.value==0xFFA25D){
    myCom="pwr";
    if (dcSpeed==0){
      dcSpeed=dcMax;
    }
    else{
      dcSpeed=0;
    }
  }
  else if(cmd.value==0xFF629D){
    myCom="v+";
    if(dcSpeed<(dcMax-dcInc)){
      dcSpeed+=dcInc;
    }
  }
  else if(cmd.value==0xFFA857){
    myCom="v-";
    if(dcSpeed>(dcMin+dcInc)){
      dcSpeed-=dcInc;
    }
  }
  else if(cmd.value==0xFF22DD){
    myCom="rwd";
    dcDir=-1;
  }
  else if(cmd.value==0xFFC23d){
    myCom="ff";
    dcDir=1;
  }



    digitalWrite(dirPin2,LOW*dcDir);
    digitalWrite(dirPin7,HIGH*dcDir);
    analogWrite(speedPin,dcSpeed);
 

  delay(dt);
  IR.resume();
}
