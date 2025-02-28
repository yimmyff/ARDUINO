// Definición de variables
float temp; 
int sensorValue;

// Definición de pines
const int ledPin = 13;        // Pin del LED
const int motorPin = 12;      // Pin del ventilador

void setup() {
  pinMode(ledPin, OUTPUT);     // Configura el pin del LED como salida
  pinMode(motorPin, OUTPUT);   // Configura el pin del motor como salida
  Serial.begin(9600);          // Inicializa la comunicación serial
  Serial.println("###Temperature monitor###");
}

void loop() {
  sensorValue = analogRead(A0); // Lee el valor del sensor
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);
  delay(2000);

  // Conversión a grados Celsius
  // El LM35DZ da 10 mV por grado Celsius, por lo que se multiplica por 100 para obtener la temperatura
  temp = sensorValue * (5.0 / 1023.0) * 100.0; 
  Serial.print("Temp value: ");
  Serial.println(temp);
  delay(2000);
  
  // Validación 1: Temperatura inferior a 5 °C
  if (temp < 5) {
    digitalWrite(ledPin, HIGH); // Enciende el LED
    delay(500);                 // Espera 0.5 segundos
    digitalWrite(ledPin, LOW);  // Apaga el LED
    delay(500);                 // Espera 0.5 segundos
  }
  // Validación 2: Temperatura entre 6 °C y 25 °C
  else if (temp >= 6 && temp <= 25) {
    digitalWrite(ledPin, LOW);  // Apaga el LED
    digitalWrite(motorPin, LOW); // Apaga el ventilador
  }
  // Validación 3: Temperatura mayor a 25 °C
  else if (temp > 25) {
    digitalWrite(ledPin, HIGH); // Enciende el LED
    digitalWrite(motorPin, HIGH); // Enciende el ventilador
  }

  delay(1000); // Espera 1 segundo antes de la siguiente lectura
}
