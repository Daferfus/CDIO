#define libreria.sensorTemperatura.h

#include <Arduino.h>

class sensorIluminacion
{
  public:
    sensorIluminacion(int);
    
    
    void imprimirIluminacion();

    double iluminacion_para_enviar;


  private:
    int pin;

    
    double convertirVoltiosAIluminacion(double);
    
    int leeIluminacion();

    double convertirBitsAVoltios(int);

};
