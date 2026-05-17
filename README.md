# IoT-Based Digital Smart Energy Meter
> Mini Project — Bachelor of Electrical Engineering, Tribhuvan University

A real-time IoT energy monitoring system using NodeMCU (ESP8266) 
and Blynk for automated billing and energy management. The system 
was designed and simulated in Proteus before hardware implementation.

## Motivation
Traditional energy meters require manual reading and billing, leading 
to inefficiency and errors. This project automates energy monitoring 
and billing using IoT technology, making it cost-effective and 
scalable for residential and commercial use.

## System Overview
Sensors → NodeMCU (ESP8266) → Cloud → Blynk Mobile App

## Proteus Simulation
![Simulation](simulation,%20pro.png)

## Hardware Components
- **Voltage Sensor:** ZMPT101B Single-phase voltage mutual inductor
- **Current Sensor:** SCT-013-060 Non-invasive AC current sensor
- **Microcontroller:** NodeMCU (ESP8266)
- **Simulation Tool:** Proteus
- **Mobile App:** Blynk

## Key Features
- Real-time monitoring of voltage and current
- Automatic electricity bill calculation
- Historical consumption data via Blynk app
- Cloud-based data transmission and storage
- Appliance control via Blynk virtual pins
- Temperature-based automatic fan control
- Cost-effective and scalable design

## How to Run
1. Open `Smart Meter.ino` in Arduino IDE
2. Replace credentials in code:
   - `YOUR_TEMPLATE_ID` → Your Blynk Template ID
   - `YOUR_AUTH_TOKEN` → Your Blynk Auth Token
   - `YOUR_WIFI_SSID` → Your WiFi name
   - `YOUR_WIFI_PASSWORD` → Your WiFi password
3. Install required libraries:
   - ESP8266WiFi
   - BlynkSimpleEsp8266
4. Upload code to NodeMCU
5. Open Blynk app and monitor real-time data

## Blynk Virtual Pin Mapping
| Virtual Pin | Function |
|-------------|----------|
| V0 | Appliance 1 control (D5) |
| V1 | Appliance 2 control (D6) |
| V2 | Appliance 3 control (D7) |
| V3 | Appliance 4 control (D8) |

## Repository Contents
- `Smart Meter.ino` — Main Arduino code
- `simulation, pro.png` — Proteus simulation diagram
- `abstract.md` — Project abstract

## Applications
- Residential and commercial energy monitoring
- Smart grid integration
- Automated billing systems
- IoT-based energy management

## Keywords
IoT, Smart Energy Meter, ZMPT101B, SCT-013-060, Blynk, 
Real-time Monitoring, Automated Billing, Energy Management, 
NodeMCU, ESP8266, Smart Grid
