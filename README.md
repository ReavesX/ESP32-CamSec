# ESP32-CamSec

**ESP32-CamSec** is a motion-activated security camera system utilizing the ESP32-CAM and PIC16LF877A microcontroller. This project focuses on integrating the ESP32-CAM for capturing video and storing data, while delegating motion detection and other control logic to the PIC16LF877A, using UART for communication.

---

## Features

- **Motion-Activated Recording:** Captures video only when motion is detected, conserving storage and power.
- **Modular Design:** Separates tasks between the ESP32-CAM and PIC16LF877A for efficient processing.
- **UART Communication:** Reliable data exchange between the two components.
- **Custom PCB:** Includes a custom PCB design to streamline the hardware integration.

---

## Getting Started

### Prerequisites

Before starting, ensure you have the following:

- **Hardware:**
  - ESP32-CAM module
  - PIC16LF877A microcontroller
  - Motion sensor (e.g., PIR sensor)
  - Supporting components (e.g., resistors, capacitors, voltage regulators)
  - Custom PCB (optional but recommended)
  
- **Software:**
  - ESP-IDF for ESP32-CAM programming
  - MPLAB X IDE for PIC16LF877A development
  
### Repository Contents

- `/src/`: Source code for both ESP32-CAM and PIC16LF877A.
- `/pcb/`: PCB design files for the motion-activated camera system.
- `/docs/`: Documentation, including schematics and protocols.
- `/examples/`: Example configurations and sample applications.

---

## Installation

1. **Clone the Repository**
   ```bash
   git clone https://github.com/ReavesX/ESP32-CamSec.git
   cd ESP32-CamSec
2. **Set Up the ESP32-CAM**

- Install necessary libraries in  ESP-IDF.
- Upload the provided code in the /src/esp32-cam/ folder.
- Program the PIC16LF877A

3. **Setup Pic16f877a**
- Open MPLAB X IDE and load the project from /src/pic16lf877a/
- Compile and flash the firmware to the PIC16LF877A.
- Assemble Hardware

4. **Connect the ESP32-CAM, PIC16LF877A, and motion sensor as per the provided schematics in /docs/.**


5. **Test the System**
- Power up the system and monitor UART communication for debugging.
- Trigger the motion sensor to validate video recording functionality.
- Documentation

## For detailed instructions and additional resources, refer to the following:
- ESP32-CAM Documentation
- PIC16LF877A Datasheet
- UART Protocol Reference

#Contributing
  Contributions are welcome! Please open an issue for bug reports or feature requests, or fork the repository and submit a
  pull request.

# License
  This project is licensed under the MIT License.

# Acknowledgements
- Espressif Systems for the ESP32-CAM module.
- Microchip for the PIC16LF877A microcontroller.
- The open-source community for tools and resources.
