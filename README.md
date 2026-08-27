# Automated-Irrigation-System
A simple controller and watering timer used for your greenhouse or any other gardening project.
Designed for custom enclosures featuring a 4-button pad (**M**, **R**, **+**, **-**) and an 7-LED status ring.

## Features

- **Automated Scheduling:** Select watering intervals from 1 to 7 days in 24-hour steps.
- **Non-Blocking Logic:** Uses `millis()` for timer management instead of `delay()`, keeping button inputs responsive.
- **Manual Override Toggle:** Press **M** to trigger a 1 minute manual watering cycle. Press **M** again to cancel it immediately without disrupting your background schedule.
- **Visual Ring Display:** 8 status LEDs show the configured interval and flash simultaneously during active pump cycles.
- **Instant Reset:** Dedicated **R** button restarts the countdown baseline on demand.

## Pinout Configuration

| Function | Pin | Type | Notes |
| :--- | :--- | :--- | :--- |
| **M** Button (Water Now) | `16` | Input | Manual toggle switch |
| **R** Button (Reset) | `17` | Input | Resets schedule timer |
| **-** Button (Decrease) | `15` | Input | Decreases interval (-6h) |
| **+** Button (Increase) | `14` | Input | Increases interval (+6h) |
| **Pump Relay** | `10` | Output | Active-HIGH relay control |
| **LED Array** | `9–3` | Output | Pins 9 down to 2 sequentially |

## Setup & Installation

1. Clone or download this repository.
2. Open the project file in the **Arduino IDE**.
3. Select your microcontroller target (e.g., Arduino Nano, Uno).
4. Connect hardware components according to the pinout table above.
5. Upload the code and open the Serial Monitor at `115200 baud` for live system diagnostics.
