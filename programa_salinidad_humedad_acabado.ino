#include<Wire.h>
#include<Adafruit_ADS1015.h>

Adafruit_ADS1115 ads1115(0x48);
const int nosal = 100;
const int sisal = 1400;
const int AirValue = 20810;
const int WaterValue = 10854;

void setup() {
  Serial.begin(9600);
  Serial.println("Inicializando...");
  ads1115.begin(); //Initialize ads1115
  Serial.println("Ajustando la ganancia...");
  ads1115.setGain(GAIN_ONE);

  Serial.println("Tomando medidas del canal AINO");
  Serial.println("Rango del ADC: +/- 4.096v (1 bit=2mv)");
}

void loop() {

  int16_t adc0;
  int16_t adc1;
  int16_t humedad;
  int16_t salinidad;

  adc0 = ads1115.readADC_SingleEnded(0);
  humedad = 100 * AirValue / (AirValue - WaterValue) - adc0 * 100 / (AirValue - WaterValue);


  adc1 = ads1115.readADC_SingleEnded(1);
  salinidad = 100 * nosal / (nosal - sisal) - adc0 * 100 / (nosal - sisal);


  Serial.print("AINO: ");
  Serial.println(adc0);
  Serial.print("HR (%): ");
  Serial.print(humedad);
  Serial.print(salinidad);
  Serial.println("%");

  delay(5000);
}
