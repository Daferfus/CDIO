#include <Arduino.h>
#include "libreria.sensorSalinidad.h"
#include <Adafruit_ADS1015.h>

#define sisal 1400  // Medimos valor en seco
#define nosal 100  // Medimos valor en agua


Adafruit_ADS1115 ads1417(0x48);

sensorSalinidad::sensorSalinidad(int _pin){
  pin = _pin;
}


int sensorSalinidad::leeSalinidad() {
  int vdigital;

  vdigital = ads1417.readADC_SingleEnded(pin);

  return vdigital; //Tensión en digital
}



void sensorSalinidad::imprimirSalinidad() {

  int vdigital = leeSalinidad();
  int salinidad = 100 * nosal / (nosal - sisal) - vdigital * 100 / (nosal - sisal);
  if(salinidad>100){salinidad=100;}
  else if(salinidad<0){salinidad=0;}
  //Serial.println(vdigital);
  Serial.print("Salinidad: ");
  Serial.print(salinidad);
  Serial.println("%");
}
