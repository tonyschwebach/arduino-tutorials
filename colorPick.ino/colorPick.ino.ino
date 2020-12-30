String myColor;
String msg = "red, yellow, or green";
String msg2 = "You picked :";
int rPin = 4;
int yPin = 5;
int gPin = 6;
int wait = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rPin,OUTPUT);
  pinMode(yPin,OUTPUT);
  pinMode(gPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while(Serial.available()==0){
    
  }

  myColor = Serial.readString();
  Serial.print(msg2);
  Serial.println(myColor);
  //delay(wait);

  if(myColor == "red"){
    digitalWrite(rPin,HIGH);
    digitalWrite(yPin,LOW);
    digitalWrite(gPin,LOW);
  }
 
  if(myColor == "yellow"){
    digitalWrite(rPin,LOW);
    digitalWrite(yPin,HIGH);
    digitalWrite(gPin,LOW);
  }

  if(myColor == "green"){
    digitalWrite(rPin,LOW);
    digitalWrite(yPin,LOW);
    digitalWrite(gPin,HIGH);
  }


  
}
