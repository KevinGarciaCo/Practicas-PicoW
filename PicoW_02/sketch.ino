#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//Declaración para una pantalla SSD1306 conectada a I2C (pines SDA, SCL)
#define OLED_RESET     -1 // Número de pin de reinicio (o -1 si se comparte el pin de reinicio de Arduino)
#define SCREEN_ADDRESS 0x3C ///< Consulta la hoja de datos para la dirección; 0x3D para 128x64, 0x3C para 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = Generar voltaje de pantalla de 3.3V internamente.
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // No proceder, hacer un bucle infinito
  }

  
  display.clearDisplay(); // Limpiar pantalla
  display.cp437(true); // Renderizar texto adecuadamente
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);  // Establecer el color del texto (Blanco es la unica opcion)
  
  display.setCursor(0,0); // Empieza a escribir/dibujar desde la esquina izquierda superior
  display.println("hola mundo"); // Escribe texto
  display.display();
  delay(2000);
  display.clearDisplay(); // Limpiar pantalla
  display.drawLine(0, 0, 128 , 64, SSD1306_WHITE); //dibuja una linea
  display.display(); // Actualiza la pantalla
  delay(2000);
  display.clearDisplay(); // Limpiar pantalla
  display.drawRect(20, 20, 20, 20, SSD1306_WHITE);
  display.display(); // Actualiza la pantalla
  delay(2000);
  display.clearDisplay(); // Limpiar pantalla
  display.fillRect(40, 20, 20, 20, SSD1306_WHITE);
  display.display(); // Actualiza la pantalla
  delay(2000);
  display.clearDisplay(); // Limpiar pantalla
  display.drawCircle(60, 20, 40, SSD1306_WHITE);
  display.display(); //Actualiza la pantalla
  delay(2000);
  display.clearDisplay(); // Limpiar pantalla
  display.fillCircle(80, 20, 20, SSD1306_WHITE);
  display.display(); //Actualiza la pantalla
}

void loop() {

}