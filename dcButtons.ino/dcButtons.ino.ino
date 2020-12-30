int speedPin = 5;  
  int dcSpeed = 0;
  int speedStep = 25;
int dirPin2 = 4;
int dirPin7 = 3;

int butt1Pin = 9;
  int butt1Old = 1;
  int butt1New;
int butt2Pin = 10;
  int butt2Old = 1;
  int butt2New;

int dt = 100;

void setup() {
  pinMode(speedPin,OUTPUT);
  pinMode(dirPin2,OUTPUT);
  pinMode(dirPin7,OUTPUT);

  pinMode(butt1Pin,INPUT);
    digitalWrite(butt1Pin,HIGH);
  pinMode(butt2Pin,INPUT);
    digitalWrite(butt2Pin,HIGH);

  Serial.begin(9600);
}

void loop() {
  Serial.print(dcSpeed);
  Serial.print("  butt1: ");
  Serial.print(butt1Old);
  Serial.print("  butt2: ");
  Serial.println(butt1Old);
    
  if(dcSpeed>=0){
    digitalWrite(dirPin2,HIGH);
    digitalWrite(dirPin7,LOW);
    analogWrite(speedPin,dcSpeed);
  }

  if(dcSpeed<0){
    digitalWrite(dirPin2,LOW);
    digitalWrite(dirPin7,HIGH);
    analogWrite(speedPin,dcSpeed*-1);
  }
  
  butt1New = digitalRead(butt1Pin);
  if(butt1Old==0 && butt1New==1 && dcSpeed<= 255-speedStep){
    dcSpeed+=speedStep;
  }
  butt1Old = butt1New;
  
  butt2New = digitalRead(butt2Pin);
  if(butt2Old==0 && butt2New==1 && dcSpeed>= -255+speedStep){
    dcSpeed-=speedStep;
  }
  butt2Old = butt2New;
  
delay(dt);

}
