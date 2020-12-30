int readPin  = A1;
int readVal;
float vp;
int wait = 250;

int redPin = 5;
float redLine = 4.;
int yellowPin = 6;
float yellowLine = redLine -1.;
int greenPin = 7;
float greenLine = yellowLine -1.;


void setup() {
  // put your setup code here, to run once:
  pinMode(readPin,INPUT);
  pinMode(redPin,OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(readPin);
  vp = (5./1023.)*readVal;
  Serial.print("Potentiometer voltage = ");
  Serial.println(vp);
  delay(wait);

  if(vp <= greenLine){
    digitalWrite(redPin,LOW);
    digitalWrite(yellowPin,LOW);
    digitalWrite(greenPin,HIGH);
  }

   if(vp <=redLine && vp > yellowLine){
    digitalWrite(redPin,LOW);
    digitalWrite(yellowPin,HIGH);
    digitalWrite(greenPin,LOW);
  }

  if(vp >redLine){
    digitalWrite(redPin,HIGH);
    digitalWrite(yellowPin,LOW);
    digitalWrite(greenPin,LOW);
  }

  
}
