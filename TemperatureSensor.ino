#include "DHT.h"

#define DHTPIN 9
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

float h = dht.readHumidity(); 
float t = dht.readTemperature();

void setup() {
  Serial.begin(9600);
  Serial.println(F("Starting DHT sensor"));

  dht.begin();
} 


void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor"));
    return;
  }

  float bt = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F(" % | Temperature: "));
  Serial.print(t);
  Serial.print(F(" C | Body Temperature: "));
  Serial.print(bt);
  Serial.println(F(" C"));
}
