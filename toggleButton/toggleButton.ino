int buttPin = 2;
int buttVal = 0;
int buttNew;
int buttOld = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttPin,INPUT);
  digitalWrite(buttPin,HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(buttVal);

  buttNew = digitalRead(buttPin);
  if(buttOld==0 && buttNew ==1){
    if(buttVal ==0){
      //action here
      buttVal = 1;
    }
    else{
      //action2 here
      buttVal = 0;
    }
  }
  buttOld=buttNew;
}
