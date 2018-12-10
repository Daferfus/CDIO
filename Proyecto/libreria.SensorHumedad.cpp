#include <Arduino.h>
#include "libreria.SensorHumedad.h"
#include <Adafruit_ADS1015.h>

#define AirValue 13936  // Medimos valor en seco
#define WaterValue 6730  // Medimos valor en agua

Adafruit_ADS1115 ads1416(0x48);

sensorHumedad::sensorHumedad(int _pin){
  pin = _pin;
}


int sensorHumedad::leeHumedad() {
  int vdigital;

  vdigital = ads1416.readADC_SingleEnded(pin);

  return vdigital; //Tensión en digital
}



void sensorHumedad::imprimirHumedad() {

  int vdigital = leeHumedad();
  int humedad = 100 * AirValue / (AirValue - WaterValue) - vdigital * 100 / (AirValue - WaterValue);
  if(humedad>100){humedad=100;}
  else if(humedad<0){humedad=0;}
  //Serial.println(vdigital);
  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.println("%");
}
