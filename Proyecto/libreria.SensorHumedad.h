#define libreria.SensorHumedad.h

#include <Arduino.h>

class sensorHumedad
{
  public:
    sensorHumedad(int);
    
    void imprimirHumedad();

  private:
    int pin;

    int leeHumedad();

};
