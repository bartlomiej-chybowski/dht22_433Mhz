#include <TimedAction.h>
#include <DHT.h>

#include <RH_ASK.h>
#include <SPI.h> 

#define DHTPIN 2
#define DHTTYPE DHT22

RH_ASK driver(2000, 7, 8, 9, false);

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
  
  dht.begin();
  getSensorReadings();

  if (!driver.init())
    Serial.println("init failed");
}


void loop() {
  readSensor.check();

  const char msg[4];
  sprintf(msg, "%02u%02u", t, h);
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(1000);
}
