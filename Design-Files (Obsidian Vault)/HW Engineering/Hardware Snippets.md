## Keying Output

Aus MFJ-495 Manual:


[[Pasted image 20240711100801.png]]



2N7002 N-MOSFET zieht positiven Keyer Input des TRX nach unten. 5V Logik!

[[Pasted image 20240711101437.png]]


**Besser:**

**IRLML6344**: This is a logic-level MOSFET with a very low Rds(on) at Vgs = 3.3V, making it an excellent choice for 3.3V logic drive applications.

[www.mouser.de/datasheet/2/196/Infineon_IRLML6344_DataSheet_v01_01_EN-3363406.pdf](https://www.mouser.de/datasheet/2/196/Infineon_IRLML6344_DataSheet_v01_01_EN-3363406.pdf)
[[Infineon_IRLML6344_DataSheet_v01_01_EN-3363406.pdf]]


![[Pasted image 20240711102619.png]]

**Noch besser:**


[[Morserino_schematics.pdf| Morserino]]

Um einen Sender oder Transceiver tasten zu können, steuert das Signal von Pin 25 einen MOSFET-Optokoppler (OC1) als "Halbleiterrelais". Dadurch wird eine vollständige galvanische Trennung vom Sender erreicht und das Schalten von bis zu 60 V positiver oder negativer Spannung ermöglicht, so dass alle modernen Sender oder Transceiver ohne zusätzliches Interface getastet werden können.

[[TLP175A_datasheet_en_20230525-1320880.pdf|Toshiba TLP175A]]

![[Pasted image 20240715120531.png]]
![[Pasted image 20240715121337.png]]
Noch Schneller:

[[av02-2929en_2017-05-08-1827849.pdf|ACPL-P341]]

## Input Pins

The ESP32 microcontroller features internal pull-up and pull-down resistors that can be enabled on its GPIO pins. The value of these internal pull-up (and pull-down) resistors is typically around 45 kΩ to 50 kΩ.

Using an external pull-up resistor with a lower resistance value will significantly reduce the rise time of the input signal. A typical value like 10 kΩ should provide a good balance between speed and power consumption, although even lower values like 4.7 kΩ can be used for even faster rise times if necessary.

## Sound

### I2S - Sound

https://dronebotworkshop.com/esp32-i2s/

https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/peripherals/i2s.html#:~:text=I2S%20(Inter-IC%20Sound),data%20via%20the%20I2S%20driver.
#### MAX98357A I2S Amplifier Module

https://eckstein-shop.de/AdafruitI2S3WClassDAmplifierBreakout-MAX98357AEN



## Analog Sound



![[Pasted image 20240716121925.png]]
Ri = 3k3 für 100Hz Hochpass

