int photoPin = A1;
int photoVal;
float volt;
int buzzPin = 3;
float buzzT1 = 6000.;
float buzzT2 = 60.;
float tune;



void setup() {
  // put your setup code here, to run once:
  pinMode(photoPin,INPUT);
  pinMode(buzzPin,OUTPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  photoVal = analogRead(photoPin);
  tune = (buzzT2-buzzT1)/1023.*photoVal + buzzT1;
  digitalWrite(buzzPin,HIGH);
  delayMicroseconds(tune);
  digitalWrite(buzzPin,LOW);
  delayMicroseconds(tune);

  Serial.print(photoVal);
  Serial.print("  ");
  Serial.println(tune);

}
