void setup(){
    Serial.begin(9600);
    Serial.print("Introducir un número");
}

void loop() {
    double x = 0;
    double resultado = 0;

    //Si el numero de bytes recibidos es mayor a 0...
    if (Serial.available() > 0) {
        
        //Se recoge el número introducido y se almacena en una variable
        x = Serial.parseInt();

        //Se almacena el resultado de su multiplicación.
        resultado = 2*x;
        delay(1000);

        //Se imprime el resultado luego de 1 ms de retraso.
        Serial.print(resultado);

        //Se pide un nuevo número a introducir continuando así con el bucle
        Serial.print("Introducir un número");
    }
}