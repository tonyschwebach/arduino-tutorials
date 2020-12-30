int rPin = 11;
int buttPin = 6;
int buttVal;
int rVal = 1;
int wait = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(rPin,OUTPUT);
  pinMode(buttPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttVal = digitalRead(buttPin);
  Serial.println(buttVal);

  if(buttVal==0){
    rVal=rVal*-1;
  }

  if(rVal==1){
    digitalWrite(rPin,HIGH);
  }
  if(rVal==-1){
    digitalWrite(rPin,LOW);
  }

delay(wait);
  
//  if(buttVal==1){
//    digitalWrite(rPin,HIGH);
//  }
//  if(buttVal==0){
//    digitalWrite(rPin,LOW);
//  }
//  delay(wait);
}
