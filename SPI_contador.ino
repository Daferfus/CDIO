#define TXO  13 // TRX SPI
#define SCL 14 // CLK SPI
#include <SPI.h>
int data = 0;
void setup() {
 pinMode(SCL, OUTPUT); // CLK
 pinMode(TXO, OUTPUT); // Data SPI TRx
// pinMode(RST, OUTPUT); // Reset del 74HC164
 SPI.beginTransaction(SPISettings(4000, MSBFIRST, SPI_MODE0)); // Velocidad, modo en el que se transmiten los bits, flanco de reloj
 SPI.begin();
 data = 0; 

}


void loop() {
 //shiftOut( TXO, SCL, MSBFIRST, data);
 SPI.transfer(data);
 data ++;

 if (data>=15)
 {
    data = 0;
  }

  delay(1000);
}
