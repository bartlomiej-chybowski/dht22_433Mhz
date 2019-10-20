#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver(2000, 7, 8, 9, false);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT22 sensor testing");

  if (!driver.init())
    Serial.println("init failed");
}


void loop() {
  uint8_t buf[4];
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen)) // Non-blocking
  {
    int i;
    // Message with a good checksum received, dump it.
    Serial.print("Temperatura: ");
    Serial.print((char)buf[0]);
    Serial.print((char)buf[1]);
    Serial.print("°C, Wilgotnosc:");
    Serial.print((char)buf[2]);
    Serial.print((char)buf[3]);
    Serial.println("%");
  }
}
