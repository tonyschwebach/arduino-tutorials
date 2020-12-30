int speedPin = 5;
  int dcSpeed;
  float dcMin = 100.;
  float dcMax = 255.;
int dirPin2 = 4;
int dirPin7 = 3;

int xPin = A0;
  int xVal;
int yPin = A1;
  int yVal;
  float yMid = 507.;
  float yFlex = 2.;
  float yMin = 0.;
  float yMax = 1023.;
int swPin = A2;

void setup() {
  pinMode(speedPin,OUTPUT);
  pinMode(dirPin2,OUTPUT);
  pinMode(dirPin7,OUTPUT);

  pinMode(xPin,INPUT);
  pinMode(yPin,INPUT);
  pinMode(swPin,INPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print(", Y: ");
  Serial.print(yVal);
  Serial.print(", Speed: ");
  Serial.println(dcSpeed);
  
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);

  if(yVal>yMid+yFlex){
    digitalWrite(dirPin2,LOW);
    digitalWrite(dirPin7,HIGH);
    dcSpeed = ((dcMax-dcMin)/(yMax-yMid))*(yVal-yMid)+dcMin;
    analogWrite(speedPin,dcSpeed);
  }
    if(yVal<yMid-yFlex){
      digitalWrite(dirPin2,HIGH);
      digitalWrite(dirPin7,LOW);
      dcSpeed = ((dcMax-dcMin)/(yMid-yMin))*(yMid-yVal)+dcMin;
      analogWrite(speedPin,dcSpeed);
    }
    if(yVal<=yMid+yFlex && yVal>=yMid-yFlex){
      dcSpeed=0; 
      analogWrite(speedPin,dcSpeed);
    }
}
