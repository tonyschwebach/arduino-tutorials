int v1ReadPin = A1;
int v1ReadVal = 0;
float v1 = 0;

int v2ReadPin = A2;
int v2ReadVal = 0;
float v2 = 0;

int wait = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(v1ReadPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  v1ReadVal = analogRead(v1ReadPin);
  v1 = (5./1023.)*v1ReadVal;
  Serial.println(v1);
  delay(wait);
  


}
