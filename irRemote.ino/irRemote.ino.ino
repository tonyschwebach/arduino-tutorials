#include <IRremote.h>

  int rcvrPin = 3;
    IRrecv IR(rcvrPin);
    decode_results cmd;
    String myCom;
  
   int dt = 500;
  
void setup() {
  Serial.begin(9600);
  IR.enableIRIn();
}

void loop() {
  while(IR.decode(&cmd)==0){
  }
  Serial.print(cmd.value,HEX);
  Serial.print("  ");
  Serial.println(cmd.value);

  if(cmd.value==0xFFA25D){
    myCom="pwr";
  }
  if(cmd.value==0xFF629D){
    myCom="v+";
  }
  if(cmd.value==0xFFE21D){
    myCom="fnct";
  }
  if(cmd.value==0xFF22DD){
    myCom="rwd";
  }
  if(cmd.value==0xFF02FD){
    myCom="play";
  }
  if(cmd.value==0xFFC23d){
    myCom="ff";
  }
  if(cmd.value==0xFFE01F){
    myCom="down";
  }
  if(cmd.value==0xFFA857){
    myCom="v-";
  }
  if(cmd.value==0xFF906F){
    myCom="up";
  }
  if(cmd.value==0xFF6897){
    myCom="zero";
  }
  if(cmd.value==0xFF9867){
    myCom="eq";
  }
  if(cmd.value==0xFFB04F){
    myCom="st";
  }
  if(cmd.value==0xFF30CF){
    myCom="one";
  }
  if(cmd.value==0xFF18E7){
    myCom="two";
  }
  if(cmd.value==0xFF7A85){
    myCom="three";
  }
  if(cmd.value==0xFF10EF){
    myCom="four";
  }
  if(cmd.value==0xFF38C7){
    myCom="five";
  }
  if(cmd.value==0xFF5AA5){
    myCom="six";
  }
  if(cmd.value==0xFF42BD){
    myCom="seven";
  }
  if(cmd.value==0xFF4AB5){
    myCom="eight";
  }
  if(cmd.value==0xFF52AD){
    myCom="nine";
  }
  
  Serial.println(myCom);
  
  delay(dt);
  IR.resume();
}
