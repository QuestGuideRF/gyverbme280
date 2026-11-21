#include <GyverBME280.h>
GyverBME280 bme;
void setup() {
  Serial.begin(9600);
  bme.setFilter(FILTER_COEF_8);
  bme.setTempOversampling(OVERSAMPLING_8);
  bme.setPressOversampling(OVERSAMPLING_16);
  bme.setStandbyTime(STANDBY_500MS);
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