# Here you find MY recurring and example ChatGPT Prompts for Software-Engineering for this project

## Do your own prompts!

This is an iterative approach. Their are bugs and failures in the prompts and in ChatGPT answers, which have to be corrected in your next prompt iteration.

## Basics

This is always needed, to prepare ChatGPT for what is to come. Every line is needed.

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
- include comment lines for author <Author>, Date of creation, and Licence "MIT-Licence on all boiler plates together with the file name.

## Hardware

Read the ESP32-C6 doc first, to define what you want. ChatGPT can not do this for you.

- GPIO10 is used as an inverted push-button switch input with internal pull-up. Used for a straigth keyer input and paddle input dit
- GPIO11 is used as an invertet push-button switch input with internal pull-up. Used for paddle input dah
- GPIO8 is used as a digital RGB led output. The RGB Led is digitally addressed by only one GPIO output. 
- Use Hardware interupts for switch inputs and define ISR's

## Some WIP prompts (Work in Progress)

Use all your available knowledge to specify the requirements. If you don't, ChatGPT will be sometimes ok, sometimes far off.

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

- show all classes generated so far and their connection. Also use a class for ISR handler and the ISR service routines.
- you lost the networkManager class
- also create a errorhandller class and pipeline used by all other classes to comunicate and prosess errors.
- i miss the main class "rvkeyer"
- also i forgot the audio output class which calls 3 methods (or classes): Analog GPIO output to a local audio amp. switching of an external tranceiver with keyer GPIO output (hardware comes later). Or signaling by websocket to a host.
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

## scaffolding in new branch

**at that step I created a new branch and used the scaffolding method to set up the class structure**

To proceed from here, we have two main approaches:

1. **Step-by-Step Development**: 
   - We can proceed incrementally, coding each class and function in a step-by-step manner. This allows for careful validation and testing at each stage. This approach is ideal if you want to ensure correctness and refine the design as you go along.

2. **Full Project Scaffolding**: 
   - We can scaffold the entire project upfront, creating all classes with placeholder functions (void methods) for the features not yet fully defined. This approach allows you to have a complete project structure in place, and then you can incrementally fill in the details of each class and method.

### Recommendation

Given the complexity and the number of components involved, I recommend a **hybrid approach**:
- **Step 1**: Scaffold the entire project, including all classes and methods, with placeholders where necessary. This provides a clear structure.
- **Step 2**: Implement specific functionalities (like GPIO input/output, RGB LED control, FreeRTOS task creation) in a step-by-step manner.

This approach gives you a complete structure to work within and allows for detailed development and testing of individual features.

### Project Structure and CMake Configuration

Let's start by scaffolding the project with the necessary classes and functions, along with a `CMakeLists.txt` file to configure the build system.

### Project Directory Structure
```
/rvkeyer
│
├── CMakeLists.txt
├── include/
│   ├── rvkeyer.h
│   ├── esp32_init.h
│   ├── morse_symbol_input.h
│   ├── morse_output.h
│   ├── morse_decode.h
│   ├── dynset.h
│   ├── shutdown.h
│   ├── log_handler.h
│   ├── watch_dog_timer.h
│   ├── nvm_store.h
│   ├── database_handler.h
│   ├── morse_translator.h
│   └── isr_handler.h
│
└── src/
    ├── rvkeyer.cpp
    ├── esp32_init.cpp
    ├── morse_symbol_input.cpp
    ├── morse_output.cpp
    ├── morse_decode.cpp
    ├── dynset.cpp
    ├── shutdown.cpp
    ├── log_handler.cpp
    ├── watch_dog_timer.cpp
    ├── nvm_store.cpp
    ├── database_handler.cpp
    ├── morse_translator.cpp
    └── isr_handler.cpp
```

Of course let ChatGPT generate a bash script to make that dir structure and run it once.

### CMakeLists.txt

Here’s a basic `CMakeLists.txt` to set up the project:

```cmake
cmake_minimum_required(VERSION 3.16)
set(PROJECT_NAME "rvkeyer")
project(${PROJECT_NAME})

# Set the standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Add include directories
include_directories(include)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link against necessary libraries (e.g., FreeRTOS, ESP-IDF components)
# target_link_libraries(${PROJECT_NAME} freertos idf_component)
```

### Example Class Implementations

#### `rvkeyer.h`
```cpp
#ifndef RVKEYER_H
#define RVKEYER_H

#include "esp32_init.h"
#include "morse_symbol_input.h"
#include "morse_output.h"
#include "morse_decode.h"
#include "dynset.h"
#include "shutdown.h"
#include "log_handler.h"
#include "watch_dog_timer.h"

class RVKeyer {
public:
    void initializeSystem();
    void startKeying();
    void handleMorseInput();
    void processMorseOutput();
    void shutdownSystem();
    void decodeMorse();
    void dynamicallySetParameters();

private:
    ESP32Init esp32Init;
    MorseSymbolInput morseSymbolInput;
    MorseOutput morseOutput;
    MorseDecode morseDecode;
    DynSet dynSet;
    Shutdown shutdown;
    LogHandler logHandler;
    WatchDogTimer watchDogTimer;
};

#endif
```

#### `rvkeyer.cpp`
```cpp
#include "rvkeyer.h"

void RVKeyer::initializeSystem() {
    esp32Init.initGPIO();
    esp32Init.initWiFi();
    esp32Init.initBluetooth();
    esp32Init.initNetSocket();
    esp32Init.initWatchDogTimer();
    logHandler.logInfo("System initialized");
}

void RVKeyer::startKeying() {
    // Implement keying logic
    logHandler.logInfo("Keying started");
}

void RVKeyer::handleMorseInput() {
    morseSymbolInput.readGPIOKeyer();
    // More handling logic
}

void RVKeyer::processMorseOutput() {
    morseOutput.outputAnalogGPIO();
    // More output logic
}

void RVKeyer::shutdownSystem() {
    shutdown.performShutdown();
    logHandler.logInfo("System shutdown");
}

void RVKeyer::decodeMorse() {
    morseDecode.decodeMessage("");
    // Decoding logic
}

void RVKeyer::dynamicallySetParameters() {
    dynSet.setParameter("swpm", 20);
    // Dynamic setting logic
}
```

### GPIO and RGB LED Control (GPIO 8, GPIO 10)
In the `esp32_init.cpp`:

```cpp
#include "esp32_init.h"
#include <driver/gpio.h>
#include <Adafruit_NeoPixel.h>

#define RGB_PIN GPIO_NUM_8
#define INPUT_PIN GPIO_NUM_10

void ESP32Init::initGPIO() {
    gpio_pad_select_gpio(INPUT_PIN);
    gpio_set_direction(INPUT_PIN, GPIO_MODE_INPUT);

    gpio_pad_select_gpio(RGB_PIN);
    gpio_set_direction(RGB_PIN, GPIO_MODE_OUTPUT);

    // Initialize the RGB LED (assuming use of Adafruit NeoPixel library)
    Adafruit_NeoPixel rgb_led = Adafruit_NeoPixel(1, RGB_PIN, NEO_GRB + NEO_KHZ800);
    rgb_led.begin();
    rgb_led.setPixelColor(0, rgb_led.Color(255, 0, 0)); // Example: Red color
    rgb_led.show();
}
```

### Next Steps
1. **Implement Core Functionalities**: Start filling in the core functionalities for each component based on the system requirements.
2. **Testing**: As you implement each feature, testing should be done on actual hardware or using simulation tools like QEMU.
3. **Task Integration with FreeRTOS**: Create FreeRTOS tasks corresponding to the components, ensuring proper task management and synchronization.

Would you like to start with specific features or proceed with implementing a particular class in detail?


---

First create the scaffolding, but of course not manually. ask for a script. bash or fish?

### ReadMe.md creation

Write an extensive Readme.md to publish this project on github in a positive and encorage tone to get many contributors.
Make a section on the Hardware Joice with these points:
- Minimal HW based solely on the ESP32-C6-Devkit-1
- Inputs: Keyer, Keyboard (through C6 USB)
- Outputs: Audio Level AUX, Speaker (3W), Keyer (Tranceiver Input, Isolated)
- Connectivity: C6 integrated WiFi and BT
- Customization (CallSign, Defaults) with irreversible OTP in eFuse.

And a section on GUI or HMI philosophy:
- Minimal HW
- Extensive HMI on host system. Desktop, Laptop, Mobile (Later)
- Device Persistance on Device Flash

And a section on the SW Engineering Approach:
- Github use mandatory. Install Github Desktop. Learn Github.
- Commit and Pull frequently
- Top Down following state-of-the-art approach (Jacob Bengio, "Embedded SW Design)
- Architecture first, Coding by ChatGPT
- Design Flow: Requirements -> Architecture -> UML Diagrams -> KI Coding -> Testing
- All Diagrams to be produced in Mermaid or PlantUML by ChatGPT
- Frequent Refactoring
- Read the Docs (ESP32-C6 Refernce Manual)
- Share your prompting history
- Full Project Scaffolding:
Scaffold the entire project upfront, creating all classes with placeholder functions (void methods) for the features not yet fully defined. This approach allows you to have a complete project structure in place, and then you can incrementally fill in the details of each class and method.Step 1: Scaffold the entire project, including all classes and methods, with placeholders where necessary. This provides a clear structure.
Step 2: Implement specific functionalities (like GPIO input/output, RGB LED control, FreeRTOS task creation) in a step-by-step manner.
- Use all Github tools (Issues, Wiki, Discussions, branches) for project communication
- All SW will be released under MIT Licence (Free Use)
- Ask ChatGPT explitly to follow MISRA CPP coding guideline and comment all classes. Include a boilerplate on all code file stubs.

And a section on SW Design:
- Use OOP predominantly with CPP.
- Open Source ToolChain based on Microsft Code
- Espressif EDS-IDE platform with CMake scripts (By ChatGPT) and Ninja
- FreeRTOS (Read the Docs)
- Use Ubuntu/Linux as host development system (or you go nuts)
- Work with class diagrams partitioned to FreeRTOS tasks
- Extensive diagnostics and error logging with the LogHandler Class
- Design interprocess communication with FreeRTOS properly

And have fun and don't be afraid of failures. Everything can be rolled back. But test your commits thouraghly.


