/*
  WiFi Web Server LED

Pagina web simple que permite parpadear una luz led
Este ejemplo utiliza encriptado wpa



 */
#include <SPI.h>
#include <WiFi.h>

char ssid[] = "HONORX8";      //  SSID del wifi (nombre)
char pass[] = "1234567890";   // contraseña de la red
int keyIndex = 0;                 

int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  Serial.begin(9600);      // inicializa comunicacion con el serial
  pinMode(9, OUTPUT);      // poner el pin en pinmode

  // Revisa si tiene escudo la red
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true);       // no continua
  }

  String fv = WiFi.firmwareVersion();
  if (fv != "1.1.0") {
    Serial.println("Please upgrade the firmware");
  }

  // intenta conectarse a la red
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);                   // print the network name (SSID);

    // conecta a red wpa
    status = WiFi.begin(ssid, pass);
    // Espera 10 segundo para la conexion
    delay(10000);
  }
  server.begin();                           // comenzar la red
  printWifiStatus();                        // estas conectado ahora
}


void loop() {
  WiFiClient client = server.available();   // espera clientes

  if (client) {                             // si se tiene un cliente
    Serial.println("new client");           // imprime un mensaje de nuevo cliente
    String currentLine = "";                // 
    while (client.connected()) {            // entrar a ciclo mientras el cliente siga dentro del server
      if (client.available()) {             
        char c = client.read();            
        Serial.write(c);                    
        if (c == '\n') {                    


          if (currentLine.length() == 0) {

            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // escribe en el web
            client.print("Click <a href=\"/H\">here</a> turn the LED on pin 9 on<br>");
            client.print("Click <a href=\"/L\">here</a> turn the LED on pin 9 off<br>");

            
            client.println();
            // cierra el ciclo
            break;
          } else {    
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;      
        }

        // revisa si la accion del cliente fue "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(9, HIGH);               // GET /H prende el led
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(9, LOW);                // GET /L apaga el led
        }
      }
    }
    // cierra la conexion
    client.stop();
    Serial.println("client disconnected");
  }
}

void printWifiStatus() {
  // imprime el ssid donde se intenta conectar
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // imprime la ip
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // imprime la intensidad de la señal
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // imprime para ir a la direccion
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}