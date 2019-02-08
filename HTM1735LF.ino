#define THERMISTORPIN A2         
// how many samples to take and average, more takes longer
// but is more 'smooth'
#define NUMSAMPLES 5
// the value of the 'other' resistor
#define SERIESRESISTOR 10000 

int RHRawSensorValue;
int samples[NUMSAMPLES];

float TempRawSensorValue;

float RHSensorValue;
float RHValue;

float TempSensorAverage;
float TempSensorValue;
float TempSensorValueInF;

void UpdateRH()
{
    RHRawSensorValue = analogRead(1);       // read analog input pin 0
    RHSensorValue = (RHRawSensorValue * (5.0/1023.0)); //ticks to Volts
    RHValue = (((RHSensorValue*1000) *.03892) - 41.98); //Volts to mVolts

    Serial.println(RHValue, DEC);  // prints the value read
}

void UpdateTemp()
{
  uint8_t i;
  //float average; //--> changed to TempSensorAverage above
 
  // take N samples in a row, with a slight delay
  for (i=0; i< NUMSAMPLES; i++) 
  {
     samples[i] = analogRead(THERMISTORPIN);
     delay(10);
  }
 
  // average all the samples out
  TempSensorAverage = 0;
  
 
  for (i=0; i< NUMSAMPLES; i++) 
  {
     TempSensorAverage += samples[i];
  }
  
  TempSensorAverage /= NUMSAMPLES;
 
  Serial.print("Average analog reading "); 
  Serial.println(TempSensorAverage);
  // convert the value to resistance
  TempSensorAverage = 1023 / TempSensorAverage - 1;
  TempSensorAverage = SERIESRESISTOR / TempSensorAverage;
 
  Serial.print("Thermistor resistance "); 
  Serial.println(TempSensorAverage);

  TempSensorValue = (-23.92 * log(TempSensorAverage)+248.24);//"resistance" (it is really voltage to A02) to *C 
  TempSensorValueInF = ((TempSensorValue * 9 / 5) + 32);      //*C --> *f conversion 
  
}
