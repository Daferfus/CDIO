#define libreria.sensorPresion.h

#include<Arduino.h>


class sensorPresion{
  public:
    sensorPresion(){

       }
      void pinPresion(int pin);
      int leePresion(int Pressmax, int Pressmin);
      int imprimirPresion(int val, int Pressmax);

  private:
       int adc3;
};
