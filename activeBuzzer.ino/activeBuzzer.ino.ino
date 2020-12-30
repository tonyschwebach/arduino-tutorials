int buzzPin = 2;
int potPin = A1;
int rPin = 4;
int potVal;
int potLimit = 1000;
int wait = 250;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin,OUTPUT);
  pinMode(potPin,INPUT);
  pinMode(rPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  Serial.println(potVal);

  while(potVal>=potLimit){
    digitalWrite(buzzPin,HIGH);
    digitalWrite(rPin,HIGH);
    potVal = analogRead(potPin);
    delay(wait);
    Serial.println(potVal);
  }
  
  digitalWrite(buzzPin,LOW);
  digitalWrite(rPin,LOW);
}
