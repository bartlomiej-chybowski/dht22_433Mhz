#include <ELECHOUSE_CC1101.h>

byte buffer[100] = {0};

void setup() {
  Serial.begin(9600);
  Serial.println("DHT22 sensor testing");

  ELECHOUSE_cc1101.Init(F_433);
  ELECHOUSE_cc1101.SetReceive();
}


void loop() {
  if (ELECHOUSE_cc1101.CheckReceiveFlag()) 
  {
    ELECHOUSE_cc1101.ReceiveData(buffer);
    String buf((char*) buffer);

    Serial.print("Temperatura: ");
    Serial.print((char)buf[0]);
    Serial.print((char)buf[1]);
    Serial.print("°C, Wilgotnosc:");
    Serial.print((char)buf[2]);
    Serial.print((char)buf[3]);
    Serial.println("%");
    
    ELECHOUSE_cc1101.SetReceive();
  }
}
