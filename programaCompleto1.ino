#include <libreria.sensorHumedad.h>
#include <libreria.sensorPresion.h>
#include <libreria.sensorSalinidad.h>
#include <libreria.sensorTemperatura.h>


#include <Wire.h>
#include <Adafruit_ADS1015.h>

//Constantes calibrado del sensor de humedad.
Adafruit_ADS1015 ads1015(0x48); // construct an ads1115 at address 0x48
const int AirValue = 20810;  // Medimos valor en seco
const int WaterValue = 10854;  // Medimos valor en agua

//Constantes calibrado del sensor de presión.
const int Pressmax = 26834;
const int Pressmin = 23921;

//Constantes calibrado del sensor de salinidad.
const int nosal = 100;
const int sisal = 1400;

//Constantes calibrado del sensor de temperatura
const int bitMAX = 17200;     //v maximo en bits
const int bitMIN = 6500;      //v minimo en bits



void setup() {
  Serial.begin(9600);
  Serial.println("Inicializando...");
  ads1015.begin(); //Initialize ads1115
  Serial.println("Ajustando la ganancia...");
  ads1015.setGain(GAIN_ONE);

  //Sensor de humedad
  Serial.println("Tomando medidas del canal AIN0");
  Serial.println("Rango del ADC: +/- 4.096V (1 bit=2mV)");

  //Sensor de presión
  Serial.println("Tomando medidas del canal AIN1");
  Serial.println("Rango del ADC: +/- 4.096V (1 bit=2mV)");

  //Sensor de salinidad
  Serial.println("Tomando medidas del canal AIN2");
  Serial.println("Rango del ADC: +/- 4.096v (1 bit=2mv)");

  //Sensor de temperatura
}

void loop() {
  
  sensorHumedad humedad;
  sensorPresion presion;
  sensorSalinidad salinidad;
  sensorTemperatura temperatura;

  int pin1 = 1;
  humedad.pinHumedad(pin1);

  int pin2 = 2;
  presion.pinPresion(pin2);

  int pin3 = 3;
  salinidad.pinSalinidad(pin3);

  int pin4 = 4;
  temperatura.pinTemperatura(pin4);
  
  //Sensor de humedad
  int valorHumedad = humedad.leeHumedad(AirValue, WaterValue);
  
  humedad.imprimirHumedad(valorHumedad);

  //Sensor de presión
  int valorPresion = presion.leePresion(Pressmax, Pressmin);

  presion.imprimirPresion(valorPresion, Pressmax);

  //Sensor de salinidad

  int valorSalinidad = salinidad.leeSalinidad(sisal, nosal);

  salinidad.imprimirSalinidad(valorSalinidad);

  //Sensor de temperatura
  int valorBits = temperatura.leeTemperatura(bitMIN, bitMAX);

  int valorVoltios = temperatura.convertirBitsAVoltios(valorBits);

  int valorTemperatura = temperatura.convertirVoltiosATemperatura(valorVoltios);

  temperatura.imprimirTemperatura(valorTemperatura);

}
