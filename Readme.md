Fujin
=====

Fujin: calculation, dataloggin and battery monitoring system

Part of: [Chinook](http://chinook.etsmtl.ca) wind-powered vehicule. 

![3d Board](https://raw.github.com/pastjean/fujin/master/hardware/3d.jpg)
  
Features
--------

* MCU : dsPIC33EP512MC806
* USB-Serial : Atmega16u2-AU
* Battery Monitoring : LM4151
* Datalogging : USB key and SD Card
* Communication :
  * CANBUS : iso1050
  * XBEE
* RealTimeClock: DS1338
* EEPROM : CAT24C256W

* Leds :
  * Uart RX
  * Uart TX
  * Can RX
  * Can TX
  * Low Bat
  * XBEE RX
  * XBEE TX
  * ON


* Power from batteries


Ideas
-----
* Power from USB???
* Spare I/O

Board
-----
Lupien : 15A
Khouya : 1.1A
P-A    : 300mA
Mic    : 400mA

Comsuption
----------

VBAT
* ltc4151: 1.2mA

5V (environ 35mA + 237mA(360mA @3V3) = 300mA)
* opamp  : 80uA
* atmega : 20mA
* ISO1050: 1.8mA + 5.2mA

3V3 (environ 360mA au max)
* xbee   : 200mA + 42mA (in,out)
* pic    : 105mA
* ds1338 : 110uA
* cat24c : 1uA + 4mA (écriture lecture)


I2C
---

* EEPROM        : 1010000
* RTC           : 1101111
* Power Monitor : 1101000
