# Smart Motion Detection and Alert System

## Overview

This project is a simple IoT-based motion detection and alert system built using Arduino, a PIR (Passive Infrared) sensor, an I2C LCD display, and a buzzer.

The system continuously monitors its surroundings for movement. When motion is detected, an alert message is displayed on the LCD, the buzzer is activated, and the event is logged through the Serial Monitor. The system also maintains a count of detected motion events.

## Features

* Motion detection using a PIR sensor
* Real-time status display on a 16x2 I2C LCD
* Audible alert using a buzzer
* Motion event counter
* Serial Monitor logging for debugging and monitoring
* Automatic PIR sensor calibration on startup
* LCD updates only when state changes to reduce screen flickering

## Components Used

| Component                    | Quantity    |
| ---------------------------- | ----------- |
| Arduino Uno/Nano             | 1           |
| PIR Motion Sensor (HC-SR501) | 1           |
| 16x2 I2C LCD Display         | 1           |
| Active Buzzer                | 1           |
| Jumper Wires                 | As Required |
| Breadboard                   | 1           |

## Circuit Connections

### PIR Sensor

| PIR Pin | Arduino |
| ------- | ------- |
| VCC     | 5V      |
| GND     | GND     |
| OUT     | D2      |

### Buzzer

| Buzzer Pin | Arduino |
| ---------- | ------- |
| +          | D9      |
| -          | GND     |

### I2C LCD

| LCD Pin | Arduino Uno |
| ------- | ----------- |
| VCC     | 5V          |
| GND     | GND         |
| SDA     | A4          |
| SCL     | A5          |

## Working

1. The system starts and calibrates the PIR sensor.
2. The LCD displays a startup message.
3. The PIR sensor continuously monitors for movement.
4. When motion is detected:

   * The buzzer is activated.
   * The LCD displays an alert message.
   * The motion counter is incremented.
   * The event is printed to the Serial Monitor.
5. When no motion is detected:

   * The buzzer is turned off.
   * The LCD displays "No Motion".

## Libraries Used

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
```

Install the **LiquidCrystal_I2C** library through the Arduino IDE Library Manager before uploading the code.

## Future Improvements

* Add a real-time clock (RTC) module for timestamps
* Store detection logs on an SD card
* Send alerts via Wi-Fi using ESP8266/ESP32
* Add an arm/disarm button
* Display "Last Motion Detected" time
* Integrate with a mobile application

## Learning Outcomes

This project demonstrates:

* Digital input handling
* Sensor interfacing
* LCD communication using I2C
* Event-driven programming
* State change detection
* Basic IoT system design

## Author

Developed as an Arduino IoT learning project using a PIR sensor, buzzer, and I2C LCD display.
