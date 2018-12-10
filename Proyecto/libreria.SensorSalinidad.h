#define libreria.SensorSalinidad.h

#include <Arduino.h>

class sensorSalinidad
{
  public:
    sensorSalinidad(int);
    
    void imprimirSalinidad();

  private:
    int pin;

    int leeSalinidad();

};
