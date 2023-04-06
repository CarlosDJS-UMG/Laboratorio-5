#include <NewPing.h>

#define TRIGGER_PIN 10
#define ECHO_PIN 11
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int distance;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    if (Serial.read() == 'R') { // espera un comando de procesamiento para leer el sensor
      distance = sonar.ping_cm(); // lee la distancia del sensor en centímetros
      Serial.write(distance); // envía la distancia a Processing
    }
  }
}
