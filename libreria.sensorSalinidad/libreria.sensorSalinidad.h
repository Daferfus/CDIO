#define libreria .sensorSalinidad.h

#include <Arduino.h>

class sensorSalinidad
{
  public:
    sensorSalinidad()
    {
    }
    void pinSalinidad(int pin);          //introducir el pin para el sensor
    int leeSalinidad(int sisal, int nosal); //entrará el valor con sal y sin sal
    int imprimirSalinidad(int val);         //imprimirá el valor en pantalla

  private:
    int16_t adc1;
};
