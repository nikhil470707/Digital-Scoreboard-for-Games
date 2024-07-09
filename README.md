# Digital Scoreboard for 2-Player Games

## Overview

This project implements a digital scoreboard for two-player games like table tennis using an ESP32 microcontroller and MAX7219 Digital Tube Display Modules. The scoreboard can be controlled wirelessly via a smartphone application using Wi-Fi communication.

## Team Members

- A.D.V.M.S.Nikhil – 2022EEB1165
- J Naveen Prasad – 2022EEB1176
- A. Sujesh Gnani – 2022EEB1159
- Aman Y Bhagat – 2022EEB1152
- Abass Ali – 2022EEB1146

## Components

- ESP32 microcontroller board
- 2 x MAX7219 Digital Tube Display Module (8-digit 7-segment display)
- MicroUSB cable
- Battery
- Connecting wires
- Breadboard
- Smartphone (with Wi-Fi capability)

## Setup

1. Connect the ESP32 board to the MAX7219 display modules:
   - GPIO18 to DIN
   - GPIO5 to CS
   - GPIO19 to CLK

2. Install the required libraries in Arduino IDE:
   - ESP32 board package
   - CP2102 driver package (for port detection)
   - DigitLedDisplay library (for controlling the MAX7219 modules)

3. Set up the Blynk app:
   - Create a new project in the Blynk app
   - Note down the Auth Token, Template ID, and Template Name

4. Update the Wi-Fi credentials and Blynk details in the code:
   - Replace the `ssid` and `pass` variables with your Wi-Fi credentials
   - Update the `BLYNK_TEMPLATE_ID`, `BLYNK_TEMPLATE_NAME`, and `BLYNK_AUTH_TOKEN` with your Blynk project details

5. Upload the code to your ESP32 board.

## Usage

1. Power on the ESP32 board.
2. The board will automatically connect to the specified Wi-Fi network and the Blynk server.
3. Open the Blynk app on your smartphone and navigate to your project.
4. Use the following virtual pins to control the scoreboard:
   - V0: Increase Home score
   - V1: Decrease Home score
   - V2: Increase Guest score
   - V3: Decrease Guest score
   - V4: Reset both scores to zero

5. The scores will be displayed on the MAX7219 modules, with the home score on the right and the guest score on the left.

## Features

- Wireless control via smartphone
- 8-digit display (4 digits for each player)
- Score increase and decrease functionality
- Score reset option
- Bright and clear LED display

## Customization

You can customize the code to add features such as:
- Setting a winning score limit
- Adding a timer functionality
- Implementing different scoring rules for various games

## Troubleshooting

If you encounter any issues:
1. Ensure all connections are correct and secure
2. Verify that you're using the correct Wi-Fi credentials
3. Double-check the Blynk Auth Token and other Blynk-related details
4. Make sure all required libraries are installed in your Arduino IDE
