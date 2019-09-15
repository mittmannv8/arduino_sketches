#include <DHT.h>

#define RED 11
#define GREEN 8
#define BLUE 9

DHT dht(A2, DHT11);

void setup() {
  Serial.begin(9600);
  Serial.println("Serial started");
  dht.begin();

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void setColor(int r, int g, int b) {
  analogWrite(RED, r);
  analogWrite(GREEN, g);
  analogWrite(BLUE, b);
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  
  Serial.println(h);
  
  if (h >= 50.0) {
    Serial.println("OK");
    setColor(255, 0, 255);
  } else if (h > 30 && h < 50) {
    Serial.println("Alerta");
    setColor(0, 0, 255);
  } else {
    Serial.println("Perigo");
    setColor(0, 255, 255);
  }
 
  delay(1000); 
}
