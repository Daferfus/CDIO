void setup(){
//inicializar el monitor serie
	Serial.begin(9600);
	Serial.print("Introducir la variable ");
}

void loop(){
	// crear variable
	int miVble;
	int multVble;
	
	
	
	 if (Serial.available() > 0) {
		
		miVble = Serial.parseInt();
		Serial.print("He leído la variable =  ");
		Serial.println(miVble, DEC);
		
		//Multiplicar la variable
		multVble = 2*miVble;
		delay(1000);
		Serial.print("El resultado será=  ");
		Serial.println(multVble, DEC);
		Serial.print("Introducir la variable ");
	 }
	
}