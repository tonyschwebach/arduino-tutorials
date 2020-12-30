int redPin = 9;
int off = 0;
int bright = 255;
int med = bright * 50%;
int low = bright * 25%;
int pause = 500;

void setup() {
  // put your setup code here, to run once:
pinMode(redPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(redPin,off);
delay(pause);

analogWrite(redPin,low);
delay(pause);

analogWrite(redPin,med);
delay(pause);

analogWrite(redPin,bright);
delay(pause);

}
