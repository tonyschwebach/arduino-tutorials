int dataPin = 12;
int latchPin= 11;
int clockPin= 9;
int dt = 200;

byte LEDs = (0); 

void setup() {
  // put your setup code here, to run once:
  pinMode(dataPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  while(LEDs<=255){
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin,clockPin,LSBFIRST,LEDs);
    digitalWrite(latchPin,HIGH);
  
    Serial.print("dec: ");
    Serial.print(LEDs);
    Serial.print(" hex: ");
    Serial.print(LEDs,HEX);
    Serial.print(" binary: ");
    Serial.println(LEDs,BIN);
  
    delay(dt);
    LEDs +=1;
  }
}
