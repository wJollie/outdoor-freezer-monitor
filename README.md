# Outdoor Freezer Monitor

## Overview
This project is an **early warning system** for an outdoor freezer.  
The freezer sometimes warms up due to the door being left ajar or an internal fault, causing ice cream (and other contents) to melt.  
This device uses an **ESP32** with temperature sensors and a reed switch to detect both **rising temperatures** and **door open events**, triggering **LED and buzzer alerts**.

---

## Features
- **Dual temperature monitoring** (inside & outside the freezer) via **DS18B20** sensors.
- **Door open detection** using a magnetic reed switch.
- **Audible alert** with buzzer and **visual alert** with LED.
- **Battery backup** via UPS module to ensure operation during brief power outages.
- Designed for **easy hardware maintenance** using screw terminals and modular wiring.
- Future upgrades planned for:
  - OLED/LCD display for real-time readings
  - Wi-Fi/MQTT alerts
  - Data logging

---

## Hardware Components
- **ESP32 Dev Board** – HTIT-WB32LA
- **2× DS18B20** temperature sensors (waterproof, with 4.7 kΩ pull-up resistor between DATA and 3V3)
- **Magnetic reed switch** for door open/close detection
- **LED** (with 330 Ω series resistor)
- **Buzzer** (active type, driven by GPIO)
- **5 V UPS/Boost converter** with lithium battery pack
- **Screw terminals** for power and signal distribution
- **Dupont jumper wires**, hookup wire, and heat shrink tubing

---

## Pin Assignments (current build)
| Component           | ESP32 Pin | Notes |
|---------------------|-----------|-------|
| Buzzer              | GPIO22    | Active buzzer |
| LED (with 330 Ω)    | GPIO13    | Lights when door open or temp too high |
| Magnetic reed switch| GPIO32    | `INPUT_PULLUP` in code; GND on other side |
| DS18B20 Data        | GPIO25    | Both sensors share this pin |
| DS18B20 Power       | 3V3       | Shared |
| DS18B20 Ground      | GND       | Shared |
| UPS Output +        | 5V pin    | ESP32 power input |
| UPS Output –        | GND       | Ground bus |

---

## Wiring Diagram
![Freezer Sensor mk1_bb](https://github.com/user-attachments/assets/4d910350-78e9-47eb-bb75-cd98e599055e)

---

## Software Setup

### 1. Install Arduino IDE & ESP32 Support
- Download Arduino IDE from [arduino.cc](https://www.arduino.cc/en/software)
- Add ESP32 boards via  
  **File → Preferences → Additional Boards Manager URLs**: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json  
- Install “esp32” from **Tools → Board → Board Manager**.

### 2. Install Required Libraries
In Arduino IDE:
- **Sketch → Include Library → Manage Libraries…**
- Install:
- `OneWire` by Paul Stoffregen
- `DallasTemperature` by Miles Burton

### 3. Load Code
- Clone this repository:
```bash
git clone https://github.com/wJollie/outdoor-freezer-monitor.git
```
-Open in Arduino IDE.

-Select Tools → Board → ESP32 Dev Module (or your exact model).

-Select the correct COM port under Tools → Port.

-Click Upload.

# How It Works
-Boot – ESP32 initializes sensors, sets pin modes, and reports to Serial.

-Temperature check – Reads both DS18B20 sensors every 5 seconds.

-Door check – Monitors reed switch state every loop (~0.5s delay).

-Alert logic – If door is open or temp rises above threshold:

-LED turns on

-Buzzer sounds

-Logging – Data is printed to Serial Monitor for debugging.

#Build Notes
-All grounds join at a single screw terminal for easier wiring.

-DS18B20s share a single data pin with a 4.7 kΩ pull-up resistor to 3V3.

-LED has a 330 Ω resistor in series to limit current.

-Reed switch uses INPUT_PULLUP in code, so no external resistor is required.

-UPS module powers the ESP32 via 5 V pin; battery backup prevents false resets.

#Future Improvements
-Wi-Fi integration for push notifications

-OLED display module for local readings

-Waterproof enclosure for outdoor mounting

-Logging to microSD card
