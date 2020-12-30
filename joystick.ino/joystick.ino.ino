int xPin = A0;
int yPin = A1;
int swPin = 2;
int rledPin = 5;
int yledPin = 6;
int gledPin = 7;

int xVal;
int yVal;
int swVal;
int swOld = 1;
int swledState = 0;
int dt = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(xPin,INPUT);
  pinMode(yPin,INPUT);
  pinMode(swPin,INPUT);
  pinMode(rledPin,OUTPUT);
  pinMode(yledPin,OUTPUT);
  pinMode(gledPin,OUTPUT);
  
  digitalWrite(swPin,HIGH);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  swVal = digitalRead(swPin);
  if(swOld==0&& swVal == 1){
    if(swledState ==0){
      digitalWrite(gledPin,HIGH);
      swledState = 1;
    }
    else{
      digitalWrite(gledPin,LOW);
      swledState = 0;
    }
  }
  swOld=swVal;
  
  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print("  Y: ");
  Serial.print(yVal);
  Serial.print("  Switch: ");
  Serial.println(swVal);

  analogWrite(rledPin,xVal);
  analogWrite(yledPin,yVal);
  
  delay(dt);
}
