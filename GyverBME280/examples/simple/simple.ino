#include <GyverBME280.h>
GyverBME280 bme;
void setup() {
  Serial.begin(9600);
  bme.begin();
}
void loop() {
  Serial.print("Temperature: ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");
  Serial.print("Humidity: ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");
  float pressure = bme.readPressure();
  Serial.print("Pressure: ");
  Serial.print(pressure / 100.0F);
  Serial.print(" hPa , ");
  Serial.print(pressureToMmHg(pressure));
  Serial.println(" mm Hg");
  Serial.print("Altitide: ");
  Serial.print(pressureToAltitude(pressure));
  Serial.println(" m");
  Serial.println("");
  delay(1000);
}