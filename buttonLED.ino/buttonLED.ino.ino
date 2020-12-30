
int brightPin = 11;
int dimPin = 9;
int redPin = 3;
int brightState = 1;
int dimState = 1;
int redState = 0;
int redChange = 20;
int dt = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(brightPin,INPUT);
  pinMode(dimPin,INPUT);
  pinMode(redPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  brightState = digitalRead(brightPin);
  dimState = digitalRead(dimPin);
  Serial.println(redState);
  
  
  if(brightState==0 && redState<=255-redChange){
    redState += redChange;
  }

  if(dimState==0 && redState>=0+redChange){
    redState -= redChange;
  }
  analogWrite(redPin,redState);
  Serial.println(redState);
  delay(dt);


}
