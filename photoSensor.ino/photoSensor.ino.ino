int photoPin = A1;
int rPin = 11;
int gPin = 13;
int lightVal;
int limit = 100;
int wait = 250;

void setup() {
  // put your setup code here, to run once:
  pinMode(photoPin,INPUT);
  pinMode(rPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal=analogRead(photoPin);
  Serial.println(lightVal);
  delay(wait);

  while(lightVal<=limit){
    digitalWrite(rPin,HIGH);
    digitalWrite(gPin,LOW);
    lightVal=analogRead(photoPin);
    Serial.println(lightVal);
    delay(wait);
  }

  while(lightVal>limit){
    digitalWrite(rPin,LOW);
    digitalWrite(gPin,HIGH);
    lightVal=analogRead(photoPin);
    Serial.println(lightVal);
    delay(wait);
  }
}
