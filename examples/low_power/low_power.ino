#include <GyverBME280.h>
GyverBME280 bme;
void setup() {
  Serial.begin(9600);
  bme.setHumOversampling(MODULE_DISABLE);
  bme.setStandbyTime(STANDBY_1000MS);
  bme.begin();
}
void loop() {
  Serial.print("Temperature: ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");
  Serial.print("Pressure: ");
  Serial.print(pressureToMmHg(bme.readPressure()));
  Serial.println(" mm Hg");
  Serial.println("");
  delay(1000);
}