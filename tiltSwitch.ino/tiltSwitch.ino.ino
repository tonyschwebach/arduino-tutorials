int tiltPin = 2;
  int tiltVal;
int rPin = 10;
int gPin = 12;
int dt = 100;

void setup() {
  pinMode(tiltPin,INPUT);
    digitalWrite(tiltPin,HIGH);
  pinMode(rPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  tiltVal = digitalRead(tiltPin);
  Serial.println(tiltVal);
  
  if(tiltVal==0){
    digitalWrite(rPin,LOW);
    digitalWrite(gPin,HIGH);
  }
    else{
      digitalWrite(rPin,HIGH);
      digitalWrite(gPin,LOW);
    }

  delay(dt);
}
