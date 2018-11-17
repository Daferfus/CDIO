#define libreria .sensorTemperatura.h

#include <Arduino.h>

class sensorTemperatura
{
  public:
    sensorTemperatura()
    {
    }
    void pinTemperatura(int pin);

    int leeTemperatura(int bitMAX, int bitMIN);

    int imprimirTemperatura(int val);

    int convertirBitsAVoltios(int val);

    int convertirVoltiosATemperatura(int val);

  private:
    int adc4;
};
