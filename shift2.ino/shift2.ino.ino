int dataPin = 12;
int latchPin= 11;
int clockPin= 9;
int dt = 1000;

byte LEDs = 0b01010101; 

void setup() {
  // put your setup code here, to run once:
  pinMode(dataPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

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
   
    LEDs = 255-LEDs; //flip to shift other circle other way
}
