#define RX_PIN  12 // GPS RXI
#define TX_PIN  13 // GPS TX0
#define INIT_PIN 15 // Pin para  Inicializar el GPS
#define GPS_BAUD  4800

TinyGPSPlus gps;

SoftwareSerial ss(RX_PIN,TX_PIN);

// Función espera 1s para leer del GPSº 

static void smartDelay(unsigned long ms){
  unsigned long start = millis();
  do
  {
    while(ss.available())
    {
      gps.encode(ss.read());  // leemos del gps
    }
  } while(millis() - start < ms);
}

// Función para encender/apagar mediante un pulso

void switch_on_off(){
   // Power on pulse
  digitalWrite(INIT_PIN,LOW);
  delay(200);
  digitalWrite(INIT_PIN,HIGH);
  delay(200); 
  digitalWrite(INIT_PIN,LOW);
 }

 /////////////////////////////////////////////////////////////////////////
// CONFIGURACION
////////////////////////////////////////////////////////////////////////
void ConfiguracionGPS() {
  ss.begin(GPS_BAUD); // Inicializar la comunicación con el GPS
 
  pinMode(INIT_PIN,OUTPUT); 
  switch_on_off(); // Pulso para encender el GPS
}

/////////////////////////////////////////////////////////////////////////
// BUCLE
////////////////////////////////////////////////////////////////////////
void imprimirGPS(){
  /*char gpsDate[10]; 
  char gpsTime[10];*/

  if(gps.location.isValid()){ // Si el GPS está recibiendo los mensajes NMEA

    /*sprintf(gpsDate,"%d/%d/%d", gps.date.month(),gps.date.day(),gps.date.year()); // Construimos string de datos fecha
    sprintf(gpsTime,"%d/%d/0%d", gps.time.hour(),gps.time.minute(),gps.time.second());  // Construimos string de datos hora*/

    /*Serial.print(gpsDate); Cositas para la hora y la fecha.
    Serial.print('\t');
    Serial.print(gpsTime);
    Serial.print('\t');*/
    Serial.print(gps.location.lat(),6);
    Serial.print('\t');
    Serial.print(gps.location.lng(),6);
    Serial.print('\t');
    Serial.print(gps.altitude.feet()); //tarda un rato en calibrarse solo
    Serial.print('\t');
    /*Serial.print(gps.course.deg(),2);
    Serial.println('\t');*/
    //Serial.println(gps.speed.mph(),2);
  }
  else  // Si no recibe los mensajes
  {
    
    Serial.println("No se encuentran satelites, recalculando... ");
    Serial.println(gps.satellites.value());
  }
}
