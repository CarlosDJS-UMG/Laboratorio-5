import processing.serial.*;

Serial myPort;
int val;

void setup() {
  size(200, 200);
  myPort = new Serial(this, "COM3", 9600); // cambia "COM3" por el nombre de puerto que esté utilizando tu placa de Arduino
}

void draw() {
  background(0);
  myPort.write('R'); // envía un comando a Arduino para que lea el sensor
  if (myPort.available() > 0) {
    val = myPort.read(); // lee el valor del sensor
    text("Distancia: " + val + " cm.", 50, 100); // muestra el valor del sensor en la pantalla
  }
}
