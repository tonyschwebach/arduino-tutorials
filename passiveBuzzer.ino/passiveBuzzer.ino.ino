int buzzPin = 2;
int potPin = A1;
int potVal;
float tune;
float buzzT1 = 60.;
float buzzT2 = 10000.;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin,OUTPUT);
  pinMode(potPin,INPUT);
//  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  tune = (buzzT1-buzzT2)/1023.*potVal +buzzT2;
  
//  Serial.print(potVal);
//  Serial.print("  ");
//  Serial.println(tune);

  digitalWrite(buzzPin,HIGH);
  delayMicroseconds(tune);
  digitalWrite(buzzPin,LOW);
  delayMicroseconds(tune); 
   
}
