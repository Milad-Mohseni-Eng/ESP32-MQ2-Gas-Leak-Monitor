# ESP32 MQ-2 Gas Leak Monitor

ESP32-based gas and smoke monitoring system using an MQ-2 sensor, SSD1306 OLED display, LEDs, and buzzer with multi-state alert logic.

---

## Overview

The ESP32 MQ-2 Gas Leak Monitor is an embedded environmental safety monitoring system designed to detect gas and smoke concentration levels in real time.

The system continuously reads analog values from an MQ-2 gas sensor and evaluates environmental conditions using a three-state alert model:

- SAFE
- WARNING
- DANGER

Measured gas levels are displayed on an SSD1306 OLED display, while LEDs and a buzzer provide immediate visual and audible feedback.

This project demonstrates practical applications of:

- Analog sensor interfacing
- ADC measurements
- OLED display communication
- Real-time monitoring
- State-machine design
- Embedded firmware development

---

## Features

- Real-time gas monitoring
- MQ-2 gas sensor integration
- SSD1306 OLED display interface
- Three-level safety indication
- Green LED for SAFE state
- Orange LED for WARNING state
- Blue LED for DANGER state
- High-tone buzzer alarm
- Serial Monitor debugging output
- Clean and documented firmware
- ESP32 compatible

---

## Hardware Components

| Component | Quantity |
|------------|------------|
| ESP32 Development Board | 1 |
| MQ-2 Gas Sensor Module | 1 |
| SSD1306 OLED Display (128×64 I2C) | 1 |
| Green LED | 1 |
| Orange LED | 1 |
| Blue LED | 1 |
| Active / Passive Buzzer | 1 |
| 220Ω Resistors | 3 |
| Breadboard / Jumper Wires | Several |

---

## Pin Configuration

### MQ-2 Gas Sensor

| MQ-2 Pin | ESP32 Pin |
|-----------|-----------|
| VCC | VIN (5V) |
| GND | GND |
| AO | GPIO34 |

---

### OLED Display

| OLED Pin | ESP32 Pin |
|-----------|-----------|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |

---

### LEDs

| LED | ESP32 GPIO |
|--------|--------|
| Green LED | GPIO15 |
| Orange LED | GPIO2 |
| Blue LED | GPIO4 |

---

### Buzzer

| Buzzer | ESP32 GPIO |
|---------|---------|
| Positive (+) | GPIO14 |
| Negative (-) | GND |

---

## System States

The monitoring system uses a simple finite-state approach.

### SAFE State

Condition:


Gas Value < 300

Outputs:


Green LED  : ON
Orange LED : OFF
Blue LED   : OFF
Buzzer     : OFF
OLED       : SAFE


---

### WARNING State

Condition:


300 ≤ Gas Value < 500


Outputs:


Green LED  : OFF
Orange LED : ON
Blue LED   : OFF
Buzzer     : OFF
OLED       : WARNING


---

### DANGER State

Condition:


Gas Value ≥ 500


Outputs:


Green LED  : OFF
Orange LED : OFF
Blue LED   : ON
Buzzer     : ON
OLED       : DANGER

---

## How It Works

### Step 1 – System Initialization

The ESP32 initializes:

- OLED display
- MQ-2 gas sensor
- LEDs
- Buzzer

---

### Step 2 – Sensor Warm-Up

The MQ-2 contains an internal heating element.

During startup the OLED displays:


MQ-2 GAS MONITOR

Sensor Warming
Please Wait...


The sensor is allowed to stabilize before monitoring begins.

---

### Step 3 – Gas Measurement

The ESP32 continuously reads the analog output of the MQ-2 sensor.


gasValue = analogRead(MQ2_PIN);


The ADC converts sensor voltage into a digital value.

---

### Step 4 – State Evaluation

The firmware compares the measured value against predefined thresholds.


SAFE
WARNING
DANGER


---

### Step 5 – User Feedback

The OLED updates the gas concentration and system status.

LEDs indicate the current safety level.

The buzzer activates when dangerous gas concentrations are detected.

---

### Step 6 – Continuous Monitoring

The monitoring process repeats indefinitely.

---

## Example OLED Output

### SAFE


MQ-2 GAS MONITOR

Gas: 223

STATUS: SAFE


---

### WARNING


MQ-2 GAS MONITOR

Gas: 387

STATUS: WARNING


---

### DANGER


MQ-2 GAS MONITOR

Gas: 645

STATUS: DANGER
``

---

## Wiring Diagram

![Wiring Diagram](docs/wiring.png)

---

## Circuit Diagram

![Circuit Diagram](docs/circuit_diagram.png)

---

## OLED Display Preview

![OLED Active](docs/oled_active.png)

---

## Demo Video

Watch the project in action:


docs/demo.mp4


or


[Demo](docs/demo.mp4)


---

## Software Requirements

### Arduino IDE

Recommended:


Arduino IDE 2.x


---

### ESP32 Board Package

Install the ESP32 board package from Arduino Boards Manager.

---

### Required Libraries

Install the following libraries using Arduino Library Manager:


Adafruit GFX Library
Adafruit SSD1306 Library
Wire Library


---



### Open Project

Open:


src/ESP32_MQ2_Gas_Leak_Monitor.ino


in Arduino IDE.

---

### Select Board


Tools → Board → ESP32 Dev Module


---

### Upload Firmware

Connect ESP32 via USB and upload the sketch.

---

### Open Serial Monitor


115200 Baud


Observe live gas readings.

---

## Calibration

MQ-2 sensors vary between modules and environments.

Before deployment:

1. Power the sensor.
2. Allow warm-up time.
3. Observe readings in clean air.
4. Record the average value.
5. Adjust thresholds if necessary.

Example:


Clean Air:
190 - 250

Warning:
300 - 500

Danger:
>500
```

The thresholds used in this project were calibrated using actual sensor measurements.

---

## Project Structure


ESP32-MQ2-Gas-Leak-Monitor
│
├── docs
│   ├── wiring.png
│   ├── circuit_diagram.png
│   ├── oled_active.png
│   └── demo.mp4
│
├── src
│   └── ESP32_MQ2_Gas_Leak_Monitor.ino
│
├── LICENSE
│
└── README.md


---

## Educational Objectives

This project demonstrates:

- Analog-to-Digital Conversion (ADC)
- Sensor calibration
- Embedded state machines
- OLED display programming
- Real-time monitoring systems
- Embedded alarm systems
- GPIO control
- Safety monitoring applications

---

## Future Improvements

Potential upgrades include:

- Wi-Fi notifications
- MQTT integration
- Mobile alerts
- Cloud dashboard
- Data logging
- SD card storage
- Historical gas graphs
- FreeRTOS implementation
- Multi-sensor integration
- Automatic calibration

---

## Repository Topics


esp32
arduino
iot
embedded-systems
mq2
gas-sensor
smoke-detector
oled-display
ssd1306
environment-monitoring
embedded-firmware
safety-system
real-time-monitoring


---

## Author

**Milad Mohseni**

Embedded Systems & IoT Engineer

Areas of Interest:

- Embedded Systems
- ESP32 Development
- IoT Applications
- Sensor Interfacing
- Firmware Development
- Real-Time Monitoring Systems

---

## License

This project is licensed under the MIT License.

See the LICENSE file for more information.
