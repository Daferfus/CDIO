#include <Arduino.h>
#include "libreria.sensorIluminacion.h"
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads1418(0x48);

sensorIluminacion::sensorIluminacion(int _pin) {
  pin = _pin;
}


int sensorIluminacion::leeIluminacion() {
  int vdigital2;

  vdigital2 = ads1418.readADC_SingleEnded(pin);

  return vdigital2; //Tensión en digital
}


double sensorIluminacion::convertirBitsAVoltios(int _vdigital2) {
  double vanalogica2;
  int vdigital2 = _vdigital2;

  vanalogica2 = (vdigital2 * 4.096) / 32767;

  return vanalogica2;
}


double sensorIluminacion::convertirVoltiosAIluminacion(double _vanalogica2) {
  double vanalogica2 = _vanalogica2;
  double iluminacion;

  //temperatura = (vanalogica - 0.79) / 0.0345;
  iluminacion = ((vanalogica2 - 0.75) / 0.036) + 14;

  iluminacion_para_enviar = iluminacion;
  return iluminacion;
}


void sensorIluminacion::imprimirIluminacion() {
  double iluminacion;
  int vdigital2 = leeIluminacion();
  double vanalogica2 = convertirBitsAVoltios(vdigital2);
  // double temperatura = convertirVoltiosATemperatura(vanalogica);
  double valor = 25;
  double valor2= 65;
  if (iluminacion <= valor) {
    Serial.println("Está oscuro");
  }
  else if (iluminacion <= valor2 && iluminacion > valor) {
    Serial.println("Está nublado");
  }
  else if (iluminacion > valor2) {
    Serial.println("Está soleado");
  }

  Serial.print("Iluminacion: ");
  Serial.print(iluminacion);
  //Serial.println("ºC");
  delay(5000);
}
