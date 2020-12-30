#include <IRremote.h>

  int rPin = 6;
    float rVal;
  int gPin = 10;
    float gVal;
  int bPin = 9;
    float bVal;
  float bright = 1.;
    float dimInc = .25;


  int rcvrPin = 5;
    IRrecv IR(rcvrPin);
    decode_results cmd;
    String myCom;
  
   int dt = 100;
  
void setup() {
  pinMode(rcvrPin,INPUT);
  pinMode(rPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  pinMode(bPin,OUTPUT);

  Serial.begin(9600);
  IR.enableIRIn();
}

void loop() {

  Serial.print(myCom);
  Serial.print(" R: ");
  Serial.print(rVal);
  Serial.print(" G: ");
  Serial.print(gVal);
  Serial.print(" B: ");
  Serial.print(bVal);
  Serial.print(" Bright: ");
  Serial.println(bright);
  
  analogWrite(rPin,rVal*bright);
  analogWrite(gPin,gVal*bright);
  analogWrite(bPin,bVal*bright);
  
  while(IR.decode(&cmd)==0){
  }

//read ir command
  if(cmd.value==0xFFA25D){
    myCom="pwr";
  }
  if(cmd.value==0xFF629D){
    myCom="v+";
  }
  if(cmd.value==0xFFE21D){
    myCom="stop";
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
  delay(dt);
  IR.resume();

//set pins by command
  if(myCom=="pwr"){
    rVal=255.;
    gVal=255.;
    bVal=255.;
    bright=1.;
  }

  if(myCom=="stop"){
    bright=0.;
  }
  if(myCom=="v-" || myCom=="down"){
    if(bright>0.){
      bright-=dimInc;
    }

  }
  if(myCom=="v+" || myCom=="up"){
    if(bright<1.){
      bright+=dimInc;
    }
  }

  if(myCom=="one"){
    rVal=255.;
    gVal=0.;
    bVal=0.;
  }
  if(myCom=="two"){
    rVal=0.;
    gVal=255.;
    bVal=0.;
  }
  if(myCom=="three"){
    rVal=0.;
    gVal=0.;
    bVal=255.;
  }

  if(myCom=="four"){
    rVal=0.;
    gVal=255.;
    bVal=255.;
    //cyan
  }
  if(myCom=="five"){
    rVal=255.;
    gVal=255.;
    bVal=0.;
    //yellow
  }
  if(myCom=="six"){
    rVal=255.;
    gVal=0.;
    bVal=255.;
    //magenta
  }

}
