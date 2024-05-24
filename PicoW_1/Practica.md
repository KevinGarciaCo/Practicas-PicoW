Práctica: Desarrollo de una Aplicación en C# para Control de Puerto Serial a nuestra picoW

Objetivo:
Elaborar un programa utilizando C# con una interfaz gráfica que permita interactuar con un dispositivo PicoW a través del puerto serial.

IDE de Arduino debe de desplegar en la sección de SERIAL Display boton del lado superior derecho.

Requisitos de la Interfaz: (ABIERTO A SUGERENCIAS)

ComboBox: Este componente permitirá al usuario seleccionar uno de los puertos seriales disponibles (del 1 al 10).
Botón 'Conectar': Al presionar este botón, el programa deberá establecer una conexión con el puerto serial seleccionado en el ComboBox.
Botón 'Desconectar': Este botón permitirá liberar el puerto serial que está actualmente en uso, cerrando la conexión establecida.
Botón 'Reset': Al ser activado, este botón deberá limpiar el contenido del TextBox TxtBoxMensaje, dejándolo listo para una nueva entrada.
TextBox 'TxtBoxMensaje': Este campo de texto será utilizado para ingresar mensajes que serán enviados y desplegados en la consola serial de un dispositivo Arduino.
Descripción Adicional:

La aplicación deberá ser capaz de manejar errores básicos relacionados con la conexión al puerto serial, como intentos de conexión a puertos no disponibles o errores al enviar datos.
La interfaz debe ser clara y amigable para el usuario, asegurando que los componentes sean accesibles y fácilmente identificables.
Esta práctica ayudará a los estudiantes a entender la comunicación entre aplicaciones de software y dispositivos de hardware a través de puertos seriales, utilizando C# y Windows Forms.
