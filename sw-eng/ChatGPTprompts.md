# Here you find some recurring ChatGPT Prompts for Software- Engineering

## Basics

- We are doing an embedded code project together step-by-step
- The project is a Morse Keyer
- The code is developed with a VS Code IDE and the ESP-IDF platform on Ubuntu/Gnome.
- The code is written predominantly in CPP using the OOP paradigm
- Use the MISRA C++ compliance and styling guide
- Use CPP 17
- The target system is an ESP32-C6-DevKitC-1 with a singlecore Risc-V MPU's
- The system is using FreeRTOS as an embedded OS for spawning and prioritizing tasks
- Set up a clean class structure with private and public methods.
- Class diagramms and other UML diagrams for specification are written in Mermaid.
- Use frequent refactoring
- The code uses mainly WebSockets for communication with a host system. The HW is identified by the MAC address.
- Program parameters are stored, retrieved and updated with NVM. Default values are given for first boot.
- The main program is "rvkeyer.cpp"
- use include files for additional classes adding functionality step-by-step
- comment all classes and methods
- include comment lines for author "Dr. Axel Richter, DM1AR", Date of creation, and Licence "MIT-Licence on all boiler plates together with the file name.

## Hardware

- GPIO10 is used as an inverted push-button switch input pinned high. Used for a straigth keyer input and paddle input dit
- GPIO11 is used as an invertet push-button switch input pinned high. Used for paddle input dah
- GPIO8 is used as a inverted led output, normally low
- Use Hardware interupts for switch inputs and define ISR's

## Some WIP prompts (Work in Progress)

- use also the C6 Technical Reference Dokument for further development of the code
- let's do some refactoring:
. I need a ESP32 init class as component. Here all inits of the C6 chip registers should be done.
- for the init class have several methods for GPIO, Wifi, BT, Netsocket and a separate class for nonvolatile storage NVM inits.
- First we use an sqlite database for retrieving and storing all persistant program parameters and logs.
- upon boot try to initialize all programm parameters from sqlite.db "rvkeyer.db. store the db in NV memory on the ESP32.
- Currently known parameters with default values are <Label:default_value:actual value,type,unit,min, max:>:
- Morsespeed for sending: swpm:20:20:int:wpm:5,50
- Morsespeed for decoding: dwpm:20:20:int:wpm:5,50. This speed will be dynamically adjusted by decoding algos- We wil have 4 decoding algos to select: Adaptive, Cross, LSTM, DSP
- Farnsworth speed for sending fwpm:5:20:int:wpm:5,20. This is a longer word pause for novice morse learners.
- from the speed calculate the dot "." duration sdot and ddot in milliseconds. The is the fundamental timing parameter used throughout the progran
- a dash "-" is always 3 dots "."
- words are separated by space.Space between words is 7 dots. If and only if fwpm is larger than swpm than calculate a Farnsworth pause duration and use it.
- ascii symbols are translated in morse elements, called dots and dashes.
- the pause between elements is always 1 dot
- the pause bewtween characters is always 3 dots
- prosigns or procedual signs are composed of two or more chars. these chars are converted into elements and played with a pause of 1 dot. prosigns are separetd by spaces
- as a new component create a bidirectional morse translator class which translates between symbols and elements for all applications.
- this class can use several code tables. use the ITU-Codetable as default. ARRL codetable is another one. More to come.
- first only show the new class diagram in Mermaid, and discuss your considerations therfore.

## next itertions

- show all classes generated so far and there connection. Also use a class for ISR handler and the ISR service routines.
- you lost the networkManager class
- also create a errorhandller class and pipeline used by all other classes to comunicate and prosess errors.
- i miss the main class "rvkeyer"
- also i forgot the audio output class which calls 3 methods (or classes): Analog GPIO output to a local audio amp. switching of an external tranceiver with keyer GPIO output (hardware comes later). Or signaling by wehsocket to a host.
- and  we need a morse symbol input class. The class can be fed by live input from the GPIO keyer or from a websocket message or from a keyboard connected to USB2
- the GPIO keyer  kann be straight keyer or paddle. Paddle keyers have 4 modes; lambic_A, lambic_B, Single, Ultimatic
- Analog Audio out has volume:0.8:0.8:float:Percent:0.0:1.0

## further

- nice try, but not what i want.
- rename AudioOutput class to MorseOutput
- RVKeyer will use ESP32init and MorseSympolInput and a new "Shutdown class"
- Then it will use a Morsedecode class to later decode Input messages or replay them
- and it will use a "DynSet" classe to dynamically set all paramters trough a websocket.

mermaid-diagram-2024-08-27-160031.png

- some links are missing:
- Morseoutput uses Morsetranslator
- Dynset uses Networkmanager and DatabaseHandler and NVMStore (new class)
- all classes use the error handler


---

- i need also a WatchDog Timer class to bei initiated by ESP32Init
- now update the mermaid
- remember, we are using the FreeRTOS!
- how can this be done? is every class a task or how to do it?

