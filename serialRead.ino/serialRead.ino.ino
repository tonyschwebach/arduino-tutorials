int myNum;
String msg = "Enter a number: ";
String msg2 = "Your number is: ";
int rPin = 4;
int yPin = 5;
int j;
int wait = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rPin,OUTPUT);
  pinMode(yPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while(Serial.available()==0){
      }
  myNum = Serial.parseInt();
  Serial.print(msg2);
  Serial.println(myNum);
  delay(wait);
  
  for(j=1;j<=myNum;j+=1){
    digitalWrite(rPin,HIGH);
    delay(wait);
    digitalWrite(rPin,LOW);
    delay(wait);
  }
  

  j-=1;
  while(j>0){
    digitalWrite(yPin,HIGH);
    delay(wait);
    digitalWrite(yPin,LOW);
    delay(wait);
    j-=1;
  }

  
}
