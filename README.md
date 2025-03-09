# IoT based gas leakage monitoring system With Nodemcu and Blynk:
## How does this security system work?
When power on this security system, The Nodemcu board connects to the interface created in the Blynk app via the Blynk cloud. Then the system should be activated by the button created in the Blynk app interface. In this case, when a gas leak occurs, it is detected by the MQ2 sensor. Then the buzzer and LED are activated. At the same time, it notifies your smartphone via a push notification. Also, we can see the gas values on the LCD and Blynk app interface. In the absence of a gas leak, the green LED bulb turns ON and operates normally in this security system.

## Requirements:
- NodeMCU(esp8266)
- Breadboard
- Jumper wires(M to F, M to M)
- LED's x2
- 5v Active Buzzer
- Resistors(180 ohm x2, 1k ohm)
- MQ2 Gas Sensor
- Micro USB Cable
- Arduino IDE(any version)
- Blynk version 1.0.1
## Setup Guide:
- Install Arduino IDE
- Download Esp2866 borad
- Download Blynk Desktop and App both
- cp2102 Driver
- Select NodeMCU 12E Module board
- Select the COMP port
- Save and run the program

https://github.com/user-attachments/assets/4e599b04-58cc-43b5-b91e-387358e55db7

