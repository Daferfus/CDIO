#define libreria.sensorHumedad.h

#include<Arduino.h>


class sensorHumedad{
  public:
       sensorHumedad(){

       }
       void pinHumedad(int pin);  //introducir el pin para el sensor
       int leeHumedad(int AirValue, int WaterValue);  //leerá los valores en seco y en mojado del sensor
       int imprimirHumedad(int val);  //imprimirá el valor en pantalla

  private:
        int16_t adc0;
};
