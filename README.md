# DHT22_433Mhz
Wireless thermometer with 7-seg output. 

### Transmitter

Connecting arduino and C1101 Transceiver

Arduino | C1101
------- | -----
GND | GND
D12 | GOD1 (SO)
D11 | MCSI (SI)
D10 | CSN
D13 | SCK
D2 | GOD0
3.3V | VCC

Connecting arduino and DHT22 Temperature and Humidity sensor

Arduino | DHT22
------- | -----
GND | GND
D3 | Out
5V | VCC

10kOhm resistor between _Out_ and _Vcc_

### Receiver