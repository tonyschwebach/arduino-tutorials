
int rPin = 4;
int yPin = 5;
int wait = 500;
int rBlink = 5;
int yBlink = 3;
int j;

void setup() {
  // put your setup code here, to run once:
  pinMode(rPin,OUTPUT);
  pinMode(yPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(j=1;j<=rBlink;j+=1){
    digitalWrite(rPin,HIGH);
    delay(wait);
    digitalWrite(rPin,LOW);
    delay(wait);
  }

  for (j=1;j<=yBlink;j+=1){
    digitalWrite(yPin,HIGH);
    delay(wait);
    digitalWrite(yPin,LOW);
    delay(wait);
  }
  
}
