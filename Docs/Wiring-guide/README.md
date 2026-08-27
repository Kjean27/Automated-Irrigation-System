# Wiring Guide

Complete wiring guide for the Automated Irrigation System (AIS) controller configured with 7 LEDs (24-hour steps), external pull-down resistors, and WAGO connectors.

---

## Hardware Overview & Pin Mapping

This setup uses an Arduino Nano on terminal adapters, an 8\7-LED ring layout with **7 active LEDs** (each representing 24 hours for up to 168 hours / 7 days), a 4-button tactile interface using external 10k Ω pull-down resistors, and a 5V relay driving a 3V DC submersible pump. Power and ground are clean and modular using WAGO connectors.

### Master Pinout Table

| Component | Connected Pin | Type | Power/Ground Rail | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **Water Now (M) Button** | `Pin 16` (A2) | Digital Input | 5V / GND | High when pressed; external 10k Ω pull-down |
| **Reset Timer (R) Button** | `Pin 17` (A3) | Digital Input | 5V / GND | High when pressed; external 10k Ω pull-down |
| **Decrease (-) Button** | `Pin 15` (A1) | Digital Input | 5V / GND | High when pressed; external 10k Ω pull-down |
| **Increase (+) Button** | `Pin 14` (A0) | Digital Input | 5V / GND | High when pressed; external 10k Ω pull-down |
| **Pump Relay Module** | `Pin 10` | Digital Output | 5V / GND | Active-HIGH signal triggers relay |
| **7 Status LEDs** | `Pins 9–3` | Digital Outputs | GND | Individual 100 Ω resistors on each anode |

---

## Power Distribution Architecture (WAGO Connectors)

To keep enclosure wiring organized and modular, use 5 WAGO splicing connectors:

* **5V Power Distribution (2 WAGO Connectors):**
  * **WAGO #1 (5-Conductor):** Primary 5V distribution block fed directly from the main power inlet/Arduino 5V terminal. Distributes 5V to the Nano, relay board `VCC`, and the 5V input sides of all 4 buttons.
  * **WAGO #2 (2-Conductor):** Dedicated 5V inline power line reserved for splitting off to the pump's isolated supply rail.
* **Ground Distribution (3 WAGO Connectors - 5-Conductor each):**
  * **WAGO #3:** Collects cathode ground (-) connections from all 7 LEDs.
  * **WAGO #4:** Connects ground sides of the 4 external 10k Ω pull-down resistors.
  * **WAGO #5:** Ties together system ground from the Arduino Nano `GND`, relay board `GND`, pump ground line, and bridges WAGO #3 and #4 into a unified common ground network.

---

## Step-by-Step Component Wiring

### 1. Control Buttons (**M**, **R**, **+**, **-**)

1. **5V Supply:** Connect one terminal of each of the 4 tactile switches directly to **WAGO #1** (5V Rail).
2. **Signal Lines:** Connect the opposite terminal of each switch directly to its assigned Arduino Nano pin (`16`, `17`, `15`, `14`).
3. **External Pull-Down Resistors:** Connect a **10k Ω resistor** from each Arduino signal pin (`16`, `17`, `15`, `14`) down to **WAGO #4** (Ground Rail). 
   * *Operation:* Pins rest naturally at `0V (LOW)` and go `5V (HIGH)` when pressed.

### 2. Status LED Array (7 Active LEDs @ 24 Hours Each)

1. **Anodes (+):** Connect the positive leg of each of the 7 active LEDs to Digital Pins `9` down to `3`. Place a **100 Ω current-limiting resistor** in series on each positive line.
2. **Cathodes (-):** Solder/connect all 7 negative legs together and route them into **WAGO #3** (LED Ground Rail).

> [!NOTE]
> Each illuminated LED represents a 24-hour interval delay (7 active LEDs = up to a 168-hour / 7-day schedule).

### 3. Relay Module & Pump Assembly

1. **Relay Logic:**
   * `VCC` $\rightarrow$ **WAGO #1** (5V Rail)
   * `GND` $\rightarrow$ **WAGO #5** (System Ground Rail)
   * `IN` (Signal) $\rightarrow$ Arduino Nano **Pin 10**
2. **Pump Circuit:**
   * Route positive power from **WAGO #2** into the relay's **COM (Common)** terminal.
   * Connect the pump's positive lead to the relay's **NO (Normally Open)** terminal.
   * Attach a **JST male/female pair** in line with the pump cable for easy disconnects, and route the pump's ground wire back into **WAGO #5**.
