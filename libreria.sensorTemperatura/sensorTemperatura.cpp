#include<Arduino.h>
#include<libreria.sensorTemperatura.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads1415(0x48);

void sensorTemperatura::pinTemperatura(int pin) {
  pinMode(pin, OUTPUT);
}


int sensorTemperatura::leeTemperatura(int bitMIN, int bitMAX) {
  int adc4;

  adc4 = ads1415.readADC_SingleEnded(2);

  return adc4;
}


int sensorTemperatura::convertirBitsAVoltios(int val) {
  int voltaje;
  int adc4 = val;

  voltaje = (adc4 * 2.14) / 17200;

  return voltaje;
}


int sensorTemperatura::convertirVoltiosATemperatura(int val) {
  int voltaje = val;
  int temperatura;

  temperatura = 0.68 + (voltaje - 0.79) / 0.0345;

  return temperatura;
}


int sensorTemperatura::imprimirTemperatura(int val) {
  int temperatura = val;

  Serial.print(temperatura);
  Serial.println("ºC");
}
