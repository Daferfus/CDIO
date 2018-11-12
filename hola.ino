#define ESP8266_LED 5 // llamamos ESP8266_LED al pin 5

void setup()
{
	pinMode(ESP8266_LED, OUTPUT); //Configuramos el pin 5 como salida
}

void loop()
{
	digitalWrite(ESP8266_LED, HIGH); //ponemos el pin 5 en nivel alto
    delay(500); //Esperamos 500ms
    digitalWrite(ESP8266_LED, LOW); //ponemos el pin 5 a nivel básico
    delay(500); //Esperamos 500ms
}
