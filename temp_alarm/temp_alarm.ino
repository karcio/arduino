#include "DHT.h" // https://github.com/adafruit/DHT-sensor-library v 1.3.0
#define DHTPIN 5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int buzzer = 6;
const float TEMP = 19.50;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  dht.begin();
}

void loop() {
  delay(2000);

  float temperature = dht.readTemperature();

  if (temperature <= TEMP) {
    activateAlarm();
  }
}

void activateAlarm() {
  tone(buzzer, 2000);
  delay(500);
  noTone(buzzer);
}
