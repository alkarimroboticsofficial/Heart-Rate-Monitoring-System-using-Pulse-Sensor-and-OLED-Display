# ❤️ Heart Rate Monitoring System using Pulse Sensor and OLED Display

## Project Overview

The **Heart Rate Monitoring System** is an ESP32-based biomedical monitoring project that measures a user's heart rate using a **Pulse Sensor** and displays the real-time pulse signal and calculated **Beats Per Minute (BPM)** on a **0.96-inch SSD1306 OLED Display**.

The system continuously reads analog data from the pulse sensor, detects heartbeats using a threshold-based algorithm, calculates BPM, and provides visual feedback on both the OLED display and Serial Monitor.

This project is ideal for learning biomedical sensing, analog signal processing, ESP32 programming, and OLED interfacing.

---

## Circuit Diagram

### Pulse Sensor Connections

| Pulse Sensor Pin | ESP32 Pin |
| ---------------- | --------- |
| VCC              | 3.3V      |
| GND              | GND       |
| Signal           | GPIO 13   |

### OLED Display (SSD1306 I2C)

| OLED Pin | ESP32 Pin |
| -------- | --------- |
| VCC      | 3.3V      |
| GND      | GND       |
| SDA      | GPIO 21   |
| SCL      | GPIO 20   |

---

## Components Used

* ESP32 Development Board
* Pulse Sensor
* SSD1306 OLED Display (128×64)
* Jumper Wires
* Breadboard
* USB Cable

---

## Working Principle

1. The Pulse Sensor detects blood volume changes caused by heartbeats.
2. The sensor generates an analog signal corresponding to pulse activity.
3. The ESP32 continuously reads the sensor signal using its ADC.
4. When the signal crosses a predefined threshold, a heartbeat is detected.
5. The time interval between consecutive heartbeats is measured.
6. BPM is calculated using:

```text
BPM = 60000 / Beat Interval (ms)
```

7. The OLED display shows:

   * Current pulse signal value
   * Heartbeat indicator (<3)
   * Calculated BPM

8. The same information is sent to the Serial Monitor for debugging and analysis.

---

## Pin Connections

| Device              | ESP32 GPIO |
| ------------------- | ---------- |
| Pulse Sensor Signal | GPIO 13    |
| OLED SDA            | GPIO 21    |
| OLED SCL            | GPIO 20    |

---

## Features

* Real-time heart rate monitoring
* BPM calculation using pulse intervals
* OLED display interface
* Heartbeat detection indicator
* Serial Monitor data output
* Low-cost biomedical project
* ESP32-based implementation
* Beginner-friendly design

---

## OLED Display Output

### Normal Operation

```text
HEART RATE MONITOR
------------------------

Signal: 37250        <3

BPM: 72
```

### Waiting for Valid Heartbeat

```text
HEART RATE MONITOR
------------------------

Signal: 35100

BPM: ---
```

---

## Code Logic

### Initialization

* Initialize Serial Communication.
* Initialize I2C communication.
* Initialize OLED display.
* Configure display settings.
* Initialize heartbeat tracking variables.

### Main Loop

1. Read analog signal from Pulse Sensor.
2. Check whether signal exceeds threshold.
3. Detect heartbeat event.
4. Measure time between consecutive beats.
5. Calculate BPM.
6. Update OLED display.
7. Send data to Serial Monitor.
8. Repeat continuously.

---

## BPM Calculation Formula

```text
BPM = 60000 / Beat Duration (milliseconds)
```

### Example

```text
Beat Interval = 800 ms

BPM = 60000 / 800

BPM = 75
```

---

## Algorithm

```text
Start
│
├── Initialize ESP32
├── Initialize OLED Display
├── Initialize Pulse Sensor
│
└── Loop
     │
     ├── Read Pulse Signal
     │
     ├── Signal > Threshold ?
     │      │
     │      ├── Yes
     │      │    ├── Detect Heartbeat
     │      │    ├── Calculate Beat Interval
     │      │    ├── Compute BPM
     │      │    └── Update Display
     │      │
     │      └── No
     │
     ├── Show Signal Value
     ├── Show BPM
     ├── Send Data to Serial Monitor
     │
     └── Repeat
```

---

## Installation Steps

1. Connect the Pulse Sensor and OLED display according to the wiring table.
2. Install the required libraries.
3. Open the Arduino IDE.
4. Select the appropriate ESP32 board.
5. Upload the code to the ESP32.
6. Open the Serial Monitor at **115200 baud**.
7. Place your finger on the Pulse Sensor.
8. Observe BPM readings on the OLED display.

---

## Required Libraries

Install the following libraries using Arduino IDE Library Manager:

```cpp
Adafruit GFX Library
Adafruit SSD1306
Wire
```

---

## Serial Monitor Output

```text
Signal:37210,BPM:72
Signal:37450,BPM:73
Signal:37620,BPM:72
Signal:37180,BPM:74
```

---

## Applications

* Heart Rate Monitoring
* Biomedical Engineering Projects
* Health Monitoring Systems
* Wearable Device Prototyping
* IoT Healthcare Solutions
* Educational Electronics Projects
* Embedded Systems Learning

---

## Future Improvements

* Add Pulse Waveform Graph on OLED
* Store BPM History
* Add Wi-Fi Data Logging
* Upload Data to Cloud Dashboard
* Bluetooth Mobile Monitoring
* Abnormal BPM Alert System
* Integration with MAX30102 Sensor
* Real-Time Health Analytics

---

## Author

**Muhammad Zulqarnain Khandapa**

Robotics Engineering Student
IoT Developer | Embedded Systems Enthusiast
ESP32, Arduino, Automation, and Robotics Projects

---

## License

This project is open-source and available under the MIT License.
