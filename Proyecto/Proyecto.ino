
#include <Adafruit_ADS1015.h>
#include <SFE_BMP180.h>
//#include <Arduino.h>
#include "libreria.SensorHumedad.h"
//#include "libreria.funcionesPresion.h"
#include "libreria.sensorSalinidad.h"
#include "libreria.sensorTemperatura.h"
#include "libreria.sensorIluminacion.h"
#include <TinyGPS++.h>  //Librería del GPS
#include <SoftwareSerial.h>
#include "SensorGPS.h"
#include "libreriaSensorAcelerometro.h"
#include <Wire.h>

//Constantes calibrado del sensor de humedad.
Adafruit_ADS1015 ads1015(0x48); // construct an ads1115 at address 0x48


//Constantes calibrado del sensor de salinidad.
const int nosal = 100;  //valor sin sal
const int sisal = 1400;  //valor con sal

void setup() {
  Serial.begin(9600);
  
  Serial.println("Inicializando...");  //inicializamos
  ads1015.begin(); //Initialize ads1115
  Serial.println("Ajustando la ganancia...");  //ajuste de ganancia
  ads1015.setGain(GAIN_ONE);

  //Sensor de humedad
  Serial.println("Tomando medidas del canal AIN0");  //toma medidas del canal 0
  Serial.println("Rango del ADC: +/- 4.096V (1 bit=2mV)");  //el rango va de -4.096V a 4.096V

 /* //Sensor de presión
  configuracion_SensorPresion();
  Serial.println("Tomando medidas del canal AIN1");  //toma medidas en el canal 1
  Serial.println("Rango del ADC: +/- 4.096V (1 bit=2mV)"); */

  //Sensor de salinidad
  Serial.println("Tomando medidas del canal AIN2");  //toma medidas en el canal 2
  Serial.println("Rango del ADC: +/- 4.096v (1 bit=2mv)");

  //Sensor de temperatura

  //Sensor GPS
  ConfiguracionGPS();

  configuracionAcelerometro();
  
}

void loop() {

  int pin0 = 0;
  //humedad.pinHumedad(pin1); //Asignamos el pin 1 para el sensor de Humedad
  sensorHumedad humedad(pin0);
 
  /*int pin4 = 4;
  //presion.pinPresion(pin4);  //Asignamos el pin 2 para el sensor de Presión*/
  
  int pin3 = 3;
  //salinidad.pinSalinidad(pin3);  //Asignamos el pin 3 para el sensor de Salinidad
  sensorSalinidad salinidad(pin3);
  
  int pin2 = 2;
  sensorTemperatura temperatura(pin2);
  
  int pin1 = 1;
  sensorIluminacion iluminacion(pin1);
  //Sensor de humedad
  //int valorHumedad = humedad.leeHumedad(AirValue, WaterValue);  //Establecemos la igualdad para leer el valorHumedad
  
  //humedad.imprimirHumedad(valorHumedad);  //Imprimiremos el valorHumedad

  //Sensor de presión
  //int valorPresion = presion.leePresion(Pressmax, Pressmin);  //Establecemos la igualdad para leer el valorPresion

  /*Serial.println("Presion:");
  presion.imprimirPresion(valorPresion, Pressmax);  //Imprimiremos el valorPresion
  Serial.println("");*/
  //Sensor de salinidad

  //int valorSalinidad = salinidad.leeSalinidad(sisal, nosal);  //Establecemos igualdad para leer el valorSalinidad

  //salinidad.imprimirSalinidad(valorSalinidad);  //Imprimiremos el valorSalinidad


  //Sensor de temperatura                   
  humedad.imprimirHumedad();  //Imprimiremos el valorHumedad

  salinidad.imprimirSalinidad();  //Imprimiremos el valorSalinidad
  
  temperatura.imprimirTemperatura();  //Imprimiremos valorTemperatura
  
  double t = temperatura.temperatura_para_enviar;
  
 // imprimirPresion(t);  //Imprimiremos el valorPresion

  iluminacion.imprimirIluminacion();  //Imprimiremos el valorIluminacion
  
  imprimirGPS();  //Imprimiremos nuestra posicion

  imprimirAcelerometro();  //Imprimiremos los valores del acelerometro
  
  delay (1000);

}
