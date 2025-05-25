# Anti-Burglar Security System 🔐

![Project Type](https://img.shields.io/badge/Type-Arduino%20Security%20System-blue)
![Platform](https://img.shields.io/badge/Platform-Arduino-green)
![Language](https://img.shields.io/badge/Language-C%2FC++-yellow)

## Overview

This repository contains the code and logic for an **Arduino-based Anti-Burglar Security System**, designed as a smart intrusion detection and access control mechanism. The system utilizes an **ultrasonic sensor**, **keypad**, **LCD display**, and **alarm** to detect unauthorized entries and allow secure access using a passcode.

The idea is to simulate a basic electronic lock system that alerts and prevents intruders while allowing authorized users to deactivate the alarm through a password interface.

## Objective

To design a DIY Arduino security project that:
- Detects motion or proximity using an **ultrasonic sensor**
- Triggers a **buzzer/alarm** if an intruder is detected
- Provides a **keypad input** for the user to enter a password
- Deactivates the alarm upon entering the correct passcode
- Displays relevant status messages on an **LCD screen**

## Features

- 🧠 Motion detection via **ultrasonic sensor**
- 🔐 Password-protected disarm system using **keypad**
- 📟 Real-time feedback via **LCD**
- 🔊 Loud alarm on intrusion detection
- ⚙️ Fully programmable and customizable logic

## Components Used

- Arduino UNO
- **Ultrasonic Sensor (HC-SR04)**
- **4x4 Keypad**
- **16x2 LCD Display**
- **Buzzer**
- Breadboard, jumper wires, resistors

## How It Works

1. The **ultrasonic sensor** detects the presence of an object/person within a certain range.
2. If motion is detected:
   - The system **triggers an alarm** (buzzer).
   - The LCD displays an **intrusion alert**.
3. The user must enter the **correct password** via the keypad to deactivate the alarm.
4. Upon correct entry:
   - The **alarm stops**.
   - The LCD shows an **access granted** message.

If the password is incorrect, the alarm continues and may be configured to lock the system after multiple failed attempts.

## Code

📄 [Download the Arduino Code](https://github.com/ferrindsouza/anti-burglar-security-system/blob/main/Door_lock_project.ino)

> You can open the `.ino` file using the Arduino IDE. Adjust pin numbers based on your specific circuit configuration.

## Setup Instructions

1. Wire the components as per your circuit design.
2. Connect the ultrasonic sensor to measure distance from intruders.
3. Upload the code to your Arduino board.
4. Power on and test:
   - Enter the preset password (in code) via keypad to disable the alarm.
   - Modify the password in the code if needed.

## Potential Enhancements

- Add **GSM module** to send intrusion SMS alerts
- Use **EEPROM** to store password permanently
- Add **RFID/NFC** access system
- Track failed password attempts and trigger lockdown

## License

This project is intended for educational and personal DIY purposes.

---

## Credits

👤 **Creator:** Ferrin Dsouza  
🔗 **LinkedIn:** [https://www.linkedin.com/in/ferrindsouza](https://www.linkedin.com/in/ferrindsouza)
