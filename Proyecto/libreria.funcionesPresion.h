//SENSOR DE PRESIÓN

SFE_BMP180 bmp180;

void configuracion_SensorPresion(){
  if(bmp180.begin()){
    Serial.println("Se ha inicializado correctamente");
  }else{
    Serial.println("Fallo de inicializacion");
    while(1);
  }
}

void imprimirPresion(double temperatura) {
  char status;
  double P, T;
  T = temperatura;

  status = bmp180.startPressure(3);
  if(status != 0){
    delay(status);
    status = bmp180.getPressure(P, T);
    Serial.print("Presion: ");
    Serial.print(P, 2);
    Serial.println(" mb\n");
    
  }
  else{
    Serial.println("Error");
  }
}
