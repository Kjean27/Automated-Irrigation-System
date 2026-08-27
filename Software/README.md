
# Software & Firmware Documentation

This section contains the C++ source code written in the Arduino IDE to drive the Automated Irrigation System (AIS). The system handles real-time timer calculations, LED ring feedback, and button debouncing using non-blocking execution routines.

---

## Core Software Logic

* **Non-Blocking Timer (`millis()`):** Avoids using `delay()`, allowing the microcontroller to listen continuously for button presses while calculating background intervals up to 48 hours.
* **Overflow Protection:** All time-based calculations utilize explicit `(unsigned long)` casting to prevent variable overflow during long-term continuous operation.
* **State Management:** Tracks manual override events (`isManualWatering`) independently so triggering a manual cycle does not reset or corrupt the primary scheduling baseline.

---

## Control Button Interface

The software listens for four active-low / active-high inputs:

* **M (Manual Override):** Toggles an immediate 30-second pump cycle. Pressing **M** again mid-cycle cancels the pump instantly.
* **+ (Increase Interval):** Increments the background watering delay by 6 hours (up to a maximum of 48 hours).
* **- (Decrease Interval):** Decrements the background delay by 6 hours (down to a minimum of 6 hours).
* **R (Reset Timer):** Resets the background interval timer baseline to zero immediately.

---

## Output Behavior

* **LED Indicator Ring:** Updates dynamically when **+** or **-** is pressed. Illuminates 1 to 8 LEDs sequentially (each LED represents a 6-hour interval step).
* **Pump Execution:** Pulls Pin `10` HIGH for exactly 30 seconds when the schedule expires or when **M** is activated. All 8 status LEDs flash simultaneously while the pump is active.

---

## Setup & Compilation

1. Open the `.ino` file in **Arduino IDE** (v1.8.x or v2.x).
2. Select **Arduino Nano** under `Tools > Board`.
3. Set Processor to **ATmega328P** or **ATmega328P (Old Bootloader)** depending on your board revision.
4. Verify and upload the sketch to the board.
