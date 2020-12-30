#include <DHT.h>
#define Type DHT11

int sensPin = 2;
DHT HT(sensPin,Type);
float humidity;
float tempC;
float tempF;

int dt = 500;

void setup() {
  Serial.begin(9600);
  HT.begin();
}

void loop() {
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" TempC: ");
  Serial.print(tempC);
  Serial.print(" TempF: ");
  Serial.println(tempF);

  delay(dt);
}
