*  This sketch sets up a small OLED display and pulls analog signals from two sensors 
 * (BME280 (RH && Temp && Press) && MQ135(air quality --> SnO2 detects CO2 && VOC))
 * an RTC has also been added to this project for later use. 
 * 
 *  Requirements:
 *
 *  * Nano or other Arduino board
 *  * Arduino 1.8.8+ IDE
 *  * Library: U8g2lib.h --> u8g2 by oliver was used
 *
 * 
 * 
 *  // Pinout
 *  //  MQ135 analog Output --> A00
 *  //  RH Analog Output    --> A01
 *  //  Temp Analog Output  --> A02 Tied HIGH W/ 10k Ohm resistor 
 *  //  SCL                 --> A04
 *  //  SDA                 --> A05
 *   
 *   
 *   
 *   
 *   Created: Feb 6, 2019 by Dan Parkolay (with a lot of help from a lot of other people)
*/


#include <Arduino.h>
#include <U8g2lib.h>
#include "SparkFunBME280.h"
#include "RTClib.h"

#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

//Initialize BME280
BME280 bme280;

//Initialize SSD1306 Display
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

//Initialize RTC
DS3231 rtc;

void setup(void) 
{
  Wire.begin();
  Serial.begin(57600);
  Serial.println("initializing...");

  SetupRTC();
  
  
  u8g2.begin();
    // connect AREF to 3.3V and use that as VCC, less noisy!  
    //thank you for the tip Lady Ada
  analogReference(EXTERNAL);  

  bme280.setI2CAddress(0x76); //Connect to a second sensor
  if (bme280.beginI2C() == false) 
    {
      Serial.println("Sensor connect failed");
    }
}

void loop(void) 
{

  //UpdateRH();
  //UpdateTemp();
  UpdateMQ135();
  DebugBMEData();
  UpdateRTC();


  delay(100);
  u8g2.firstPage();
  do 
  {

    UpdateDisplay();
  } 
  while ( u8g2.nextPage() );
  //delay(1000);
}
