# outdoor-freezer-monitor


# The problem
the outside freezer sometimes randomly gets warm or someone doesnt close the door all the way and the ice cream melts. I want an early warning system that alerts me to the temp raising


# ESP32 Temperature & Security Monitor

This project uses an ESP32 to:
- Monitor inside & outside temperatures using DS18B20 sensors
- Trigger a buzzer & LED when the magnetic reed switch is activated
- Display temperature readings on a connected display (future feature)

## Hardware
- ESP32 Dev Board HTIT-WB32LA
- 2x DS18B20 temperature sensors
- Magnetic reed switch
- LED + 330Ω resistor
- Buzzer
- 4.7kΩ pull-up resistor for DS18B20 data line
- 5V UPS/Boost converter & battery pack

## Pin Assignments
| Component           | Pin   |
|--------------------|-------|
| Buzzer             | GPIO22 |
| LED                | GPIO13 |
| Magnetic reed      | GPIO36 |
| DS18B20 Data       | GPIO37 |
| Power 3.3V         | 3V3    |
| Power 5V           | 5V Pin |

## Wiring Diagram
![Freezer Sensor mk1_bb](https://github.com/user-attachments/assets/4d910350-78e9-47eb-bb75-cd98e599055e)

