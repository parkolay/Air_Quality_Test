/*  This sketch sets up a small OLED display and pulls analog signals from two sensors 
 * (HTM1735LF (RH && Temp) && MQ135(air quality --> SnO2 detects CO2 && VOC))
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
 *  //  SCL                 --> A04 Tied HIGH W/ 3k3 Ohm resistor
 *  //  SDA                 --> A05 Tied HIGH W/ 3k3 Ohm resistor
 * (value of I2C pull up can vary, check out the link below) 
 * https://electronics.stackexchange.com/questions/1849/is-there-a-correct-resistance-value-for-i2c-pull-up-resistors
 *   
 *   
 *   
 *   
 *   Created: Feb 6, 2019 by Dan Parkolay (with a lot of help from a lot of other people)
*/
