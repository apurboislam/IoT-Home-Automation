# 🔌 Smart IoT Home Automation with Blynk & NodeMCU ESP8266

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-NodeMCU-blue)](#)
[![Made with Arduino](https://img.shields.io/badge/made%20with-Arduino-00979D.svg)](#)
[![Blynk Cloud](https://img.shields.io/badge/cloud-Blynk-green)](https://blynk.cloud)

[![GitHub Stars](https://img.shields.io/github/stars/apurboislam/iot-home-automation?style=social)](https://github.com/apurboislam/iot-home-automation/stargazers)
[![GitHub Issues](https://img.shields.io/github/issues/apurboislam/iot-home-automation)](https://github.com/apurboislam/iot-home-automation/issues)
[![GitHub Pull Requests](https://img.shields.io/github/issues-pr/apurboislam/iot-home-automation)](https://github.com/apurboislam/iot-home-automation/pulls)
[![Repo Insights](https://img.shields.io/badge/GitHub-Insights-orange)](https://github.com/apurboislam/iot-home-automation/pulse)

Build your own **smart home automation system** using a **NodeMCU ESP8266** and the **Blynk IoT platform**. This project lets you control home appliances like fans or lights using your smartphone — from anywhere.

---

## 📚 Table of Contents

* [Features](#features)
* [Required Components](#required-components)
* [Circuit Diagram & Connections](#circuit-diagram--connections)
* [Setting Up Blynk Cloud](#setting-up-blynk-cloud)
* [Installing Arduino IDE & Uploading Code](#installing-arduino-ide--uploading-code)
* [Connecting Device to Blynk App](#connecting-device-to-blynk-app)
* [Troubleshooting](#troubleshooting)
* [Demo](#demo)
* [License](#license)
* [Author](#author)
* [Contributing](#contributing)

---

## ✨ Features

✅ Control up to **4 devices** via smartphone <br>
✅ Remembers relay state after reboot (via cloud sync) <br>
✅ Uses Blynk cloud & app (free) <br>
✅ Modular and OTA-ready firmware structure <br>
✅ Easy for beginners to set up and understand

---

## 🧰 Required Components

| Component              | Quantity  | Description                          |
| ---------------------- | --------- | ------------------------------------ |
| NodeMCU ESP8266        | 1         | Wi-Fi enabled microcontroller        |
| 4-Channel Relay Module | 1         | For controlling appliances           |
| Jumper Wires           | As needed | For connecting modules               |
| Power Supply (5V, 2A)  | 1         | To power the NodeMCU and relay board |
| AC Appliances          | 1–4       | Fan, Light, etc.                     |

---

## 🔌 Circuit Diagram & Connections

| Relay Pin | Connect To (NodeMCU) |
| --------- | -------------------- |
| VCC       | VIN (5V)             |
| GND       | G                    |
| IN1       | D1                   |
| IN2       | D2                   |
| IN3       | D3                   |
| IN4       | D4                   |

💡 *Optional:* Add an LED to D0 and 3.3V to indicate Wi-Fi connection status.

---

## ☁️ Setting Up Blynk Cloud

1. Go to [https://blynk.cloud](https://blynk.cloud)
2. Log in or sign up
3. Create a **new template** and configure:

   * Virtual pins: `V0` = State Memory, `V1–V4` = Control pins
4. Copy these details into your Arduino sketch:

```cpp
#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "Your_Template_Name"
#define BLYNK_FIRMWARE_VERSION "1.0.0"
```

---

## 🧪 Installing Arduino IDE & Uploading Code

### ✅ Install Arduino IDE:

[Download Arduino IDE](https://www.arduino.cc/en/software)

### ✅ Add ESP8266 Board Support:

1. Go to **File → Preferences**
2. Add this to “Additional Board Manager URLs”:

   ```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```
3. Go to **Tools → Board → Boards Manager**
4. Search for `esp8266` and install it

### ✅ Upload Code:

* Open the `.ino` file from this repo
* Replace your **Template ID**, **Wi-Fi SSID**, and **password**
* Select **Board:** NodeMCU 1.0 (ESP-12E Module)
* Hit **Upload**

---

## 📲 Connecting Device to Blynk App

1. Install **Blynk IoT App**
   → [Google Play](https://play.google.com/store/apps/details?id=cloud.blynk)
   → [App Store](https://apps.apple.com/app/blynk-iot/id1558044564)

2. Log in and tap **+** to add a device

3. Select **“Discover Nearby”**

4. Choose your NodeMCU device

5. Enter Wi-Fi credentials

6. Configure the device dashboard:

   * Add **buttons for V1–V4**
   * Add **switch for V0** to enable state memory

---

## ❓ Troubleshooting

| Problem                  | Solution                                               |
| ------------------------ | ------------------------------------------------------ |
| Device not detected      | Ensure NodeMCU is in pairing mode and powered on       |
| Relay not triggering     | Check wiring and pin mapping                           |
| Frequent reboots         | Use a stable 5V 2A power supply                        |
| Upload errors            | Verify USB cable, COM port, and correct board selected |
| Blynk app not responding | Double-check virtual pin assignment and template sync  |

---

## 🧑‍💻 Contributing

We welcome contributions of any kind:

* 🐛 Report bugs → [Submit an issue](https://github.com/apurboislam/IoT-Home-Automation/issues)
* 🌟 Star the repo → [Give it a star](https://github.com/apurboislam/IoT-Home-Automation/stargazers)
* 🛠️ Submit improvements → [Open a pull request](https://github.com/apurboislam/IoT-Home-Automation/pulls)
* 📈 View repo activity → [Repo insights](https://github.com/apurboislam/IoT-Home-Automation/pulse)

---

## 📄 License

This project is licensed under the **MIT License**.
See the [LICENSE](LICENSE) file for details.

---

## 👤 Author

Developed by [**Apurbo Islam**](https://github.com/apurboislam)
For more cool projects: [On GitHub](https://github.com/apurboislam)

> 🚀 Let’s build the future of connected homes, one relay at a time!

---