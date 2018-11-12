#include <math.h>
/* Map an analog value to 8 bits (0 to 255) */
void setup() {
  Serial.begin(9600);
  }

void loop()
{
  int val;
  val = analogRead(0);
  val = map(val, 0, 1023, 0, 1000);
  
  Serial.print(" Tensión leída = ");
  Serial.print(val, DEC);
  Serial.println(" mV");
  delay(1000);
  
}
