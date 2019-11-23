#include <TimedAction.h>
#include <DHT.h>
#include <ELECHOUSE_CC1101.h>

#define DHTPIN 3
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
 
byte h = 0;
byte t = 0;
//byte t1 = 0;
//byte t2 = 0; 
//byte h1 = 0;
//byte h2 = 0;

void getSensorReadings()
{
  h = dht.readHumidity(); 
  t = dht.readTemperature();

  if (isnan(h) || isnan(t)) 
  {
    Serial.println("sensor failed");
  }
//  t1 = t / 10.0;
//  t2 = t % 10;
//  h1 = h / 10.0;
//  h2 = h % 10; 
}

TimedAction readSensor = TimedAction(2000, getSensorReadings);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT22 sensor testing");
  ELECHOUSE_cc1101.Init(F_433);
  dht.begin();
  getSensorReadings();
}


void loop() {
  readSensor.check();

  char msg[4];
  sprintf(msg, "%02u%02u", t, h);
  Serial.println(msg);
  
  
  ELECHOUSE_cc1101.SendData((byte*)msg, 4);
  
  delay(1000);
}
