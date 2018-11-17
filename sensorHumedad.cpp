#include<Arduino.h>
#include<libreria.sensorHumedad.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads1115(0x48);

void sensorHumedad::pinHumedad(int pin) {
  pinMode(pin, OUTPUT);
}

int sensorHumedad::leeHumedad(int AirValue, int WaterValue) {
  int16_t adc0;
  int16_t humedad;
  adc0 = ads1115.readADC_SingleEnded(0);
  humedad = 100 * AirValue / (AirValue - WaterValue) - adc0 * 100 / (AirValue - WaterValue);
  return humedad;
}


int sensorHumedad::imprimirHumedad(int humedad) {
  Serial.print("humedad(%):");
  if (humedad < 0) {
    Serial.print(0);
  }
  else if (humedad > 100) {
    Serial.print(100);
  }
  Serial.print(humedad);
  Serial.print("%");
}
