#include<Arduino.h>
#include<libreria.sensorSalinidad.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads1315(0x48);

void sensorSalinidad::pinSalinidad(int pin) {
  pinMode(pin, OUTPUT);}

int sensorSalinidad::leeSalinidad(int sisal, int nosal) {
  int16_t adc1;
  int16_t salinidad;
  adc1 = ads1315.readADC_SingleEnded(1);
  salinidad = 100 * nosal / (nosal - sisal) - adc1 * 100 / (nosal - sisal);
  return salinidad;
}


int sensorSalinidad::imprimirSalinidad(int salinidad) {
  Serial.print("salinidad(%):");
  if (salinidad < 0) {
    Serial.print(0);
  }
  else if (salinidad > 100) {
    Serial.print(100);
  }
  Serial.print(salinidad);
  Serial.print("%");
}
