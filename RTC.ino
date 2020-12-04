void SetupRTC()
{
  //initialize RTC
  rtc.begin();
      //rtc.adjust(DateTime(__DATE__, __TIME__));   //--> this is to force the time is it is set to something already
    if (! rtc.isrunning()) 
    {
      Serial.println("RTC is NOT running!");
      // following line sets the RTC to the date & time this sketch was compiled
      rtc.adjust(DateTime(__DATE__, __TIME__));
      
    }

  Serial.println("RTC has begun");
}

void UpdateRTC()
{
    DateTime now = rtc.now();
    char buf[100];          //buffer for the RTC TimeDate Stamp
    strncpy(buf,"DD.MM.YYYY  hh:mm:ss\0",100);
    Serial.println(now.format(buf));
    delay(1000);
}
