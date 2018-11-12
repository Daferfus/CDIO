#include<Wire.h>
#include<Adafruit_ADS1015.h>

Adafruit_ADS1115 ads1115(0x48);
const int nosal=1200;
const int sisal= 1820;

void setup() {

  Serial.begin(9600);
  Serial.println("inicializando...");
  ads1115.begin();
  Serial.println("Ajustando la ganancia...");
  ads1115.setGain(GAIN_ONE);

  Serial.println("Tomando medidas del canal AINO");
  Serial.println("Rango del ADC: +/- 4.096v (1 bit=2mv)");

}

void loop() {
  
int16_t adc0;
int16_t salinidad;
adc0= ads1115.readADC_SingleEnded(1);
salinidad= 100*nosal/(nosal-sisal)-adc0*100/(nosal-sisal);

Serial.print("AINO: ");
Serial.println(adc0);
Serial.print("Salinidad: ");
if(salinidad > 100){
  Serial.print(100);
}
else if(salinidad < 0){
  Serial.print(0)
}
else{
Serial.print(salinidad);
}
Serial.println("%");

delay(5000);
}
