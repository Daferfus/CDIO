#include <Arduino.h>
#include "libreria.sensorTemperatura.h"
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads1415(0x48);

sensorTemperatura::sensorTemperatura(int _pin){
  pin = _pin;
}


int sensorTemperatura::leeTemperatura() {
  int vdigital;

  vdigital = ads1415.readADC_SingleEnded(pin);

  return vdigital; //Tensión en digital
}


double sensorTemperatura::convertirBitsAVoltios(int _vdigital) {
  double vanalogica;
  int vdigital = _vdigital;

  vanalogica = (vdigital * 4.096) / 32767;

  return vanalogica;
}


double sensorTemperatura::convertirVoltiosATemperatura(double _vanalogica) {
  double vanalogica = _vanalogica;
  double temperatura;

  //temperatura = (vanalogica - 0.79) / 0.0345;
  temperatura = ((vanalogica - 0.75) / 0.036) + 14;

  temperatura_para_enviar = temperatura;
  return temperatura;
}


void sensorTemperatura::imprimirTemperatura() {

  int vdigital = leeTemperatura();
  double vanalogica = convertirBitsAVoltios(vdigital);
  double temperatura = convertirVoltiosATemperatura(vanalogica);

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println("ºC");
}
