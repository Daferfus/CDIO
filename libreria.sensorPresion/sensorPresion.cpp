#include<Arduino.h>
#include<libreria.sensorPresion.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads1215(0x48);
void sensorPresion::pinPresion(int pin) {
  pinMode(pin, OUTPUT);
}

int sensorPresion::leePresion(int Pressmax, int Pressmin) {
  int adc3;

  adc3 = ads1215.readADC_SingleEnded(3);

  return adc3;
}


int sensorPresion::imprimirPresion(int val, int Pressmax) {
  int adc3 = val;
  double presion = adc3;

  presion = (adc3 * 1034) / Pressmax;

  Serial.print(presion);
}
