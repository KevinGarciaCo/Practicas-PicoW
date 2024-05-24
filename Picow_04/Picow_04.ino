char letra;
const int led = 9;
void setup() {
  Serial.begin(9600);       // Inicializamos la comunicación serial
  pinMode(led, OUTPUT);     // Configura el pin del LED como salida
  Serial.println("Setup complete");
}

void loop() {
  // Check for Bluetooth input
  if (Serial.available() > 0) {
    letra = Serial.read();
    Serial.print("Received via Bluetooth: ");
    Serial.println(letra);
    switch (letra) {
      case 'a':
        digitalWrite(led, HIGH);  // Enciende el LED
        Serial.println("LED encendido");
        break;
      case 'b':
        digitalWrite(led, LOW);   // Apaga el LED
        Serial.println("LED apagado");
        break;
      default:
        Serial.println("Unknown command");
        break;
    }
  }

  // Pequeña pausa para evitar sobrecarga del bucle principal
  delay(100);
}