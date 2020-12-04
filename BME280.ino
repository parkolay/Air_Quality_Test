void GetBMEData()
{
              //Temp = (bme280.readTempF());
              //Temp = (bme280.readTempC(), 2);
              //Humidity = (bme280.readFloatHumidity(),0);
              //Serial.println(bme280.readFloatHumidity());
              //Pressure = (bme280.readFloatPressure(), 0);
              //Dewpoint = (bme280.dewPointC(), 2);
              //Dewpoint = (bme280.dewPointF(), 2);
}
void DebugBMEData()
{
  Serial.print("Humidity: ");
  Serial.print(bme280.readFloatHumidity(), 0);

  Serial.print(" Pressure: ");
  Serial.print(bme280.readFloatPressure(), 0);
  
  Serial.print(" Alt: ");
  //Serial.print(bme280.readFloatAltitudeMeters(), 1);
  Serial.print(bme280.readFloatAltitudeFeet(), 1);
  
  Serial.print(" Temp: ");
  //Serial.print(bme280.readTempC(), 2);
  Serial.print(bme280.readTempF(), 2);

  Serial.print(" Dewpoint: ");
  //Serial.print(bme280.dewPointC(), 2);
  Serial.print(bme280.dewPointF(), 2);

  Serial.println();

}
