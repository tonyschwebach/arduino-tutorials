int ledPin = 5;
int potPin = A1;
int readVal;
float ledVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  pinMode(potPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(potPin);
  ledVal = (255./1023.)*readVal;
  analogWrite(ledPin,ledVal);
  Serial.println(ledVal);
}
