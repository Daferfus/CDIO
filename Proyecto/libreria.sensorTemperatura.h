#define libreria.sensorTemperatura.h

#include <Arduino.h>

class sensorTemperatura
{
  public:
    sensorTemperatura(int);
    
    
    void imprimirTemperatura();

    double temperatura_para_enviar;


  private:
    int pin;

    
    
    int leeTemperatura();

    double convertirBitsAVoltios(int);

    double convertirVoltiosATemperatura(double);
};
