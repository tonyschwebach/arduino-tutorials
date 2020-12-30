int redPin =4;
int potPin = A1;
int potLim = 500;
int potVal = potLim;
int wait = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin,OUTPUT);
  pinMode(potPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  Serial.println(potVal);
  delay(wait);
  
  while(potVal >= potLim){
    digitalWrite(redPin,HIGH);
    potVal = analogRead(potPin);
    Serial.println(potVal);
    delay(wait);
  }

  digitalWrite(redPin,LOW);
}
