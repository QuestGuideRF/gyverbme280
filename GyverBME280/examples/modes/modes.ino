#include <GyverBME280.h>
GyverBME280 bme;
void setup() {
  Serial.begin(9600);
  bme.setMode(FORCED_MODE);
  bme.begin();
  while (millis() < 10000) {
    bme.oneMeasurement();
    while (bme.isMeasuring());
    Serial.print("Temperature: ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");
    Serial.print("Humidity: ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");
    Serial.print("Pressure: ");
    Serial.print(pressureToMmHg(bme.readPressure()));
    Serial.println(" mm Hg");
    Serial.println("");
    delay(1000);
  }
  bme.setMode(NORMAL_MODE);
  bme.begin();
}
void loop() {
  Serial.print("Temperature: ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");
  Serial.print("Humidity: ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");
  Serial.print("Pressure: ");
  Serial.print(pressureToMmHg(bme.readPressure()));
  Serial.println(" mm Hg");
  Serial.println("");
  delay(1000);
}