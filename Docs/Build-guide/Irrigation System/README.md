# AIS Build Guide & Assembly Manual

Step-by-step assembly guide for building the Automated Irrigation System (AIS) retro-style controller enclosure, electronics, and plumbing.

---

## 1. Preparing the 3D Printed Parts

*Insert photo of printed top shell, bottom shell, and button caps here*

1. **Remove Support Material:** Clean off any 3D printing supports from the inside of the top cap and bottom enclosure shell.
2. **Install Heat-Set Inserts:** 
   * Using a soldering iron set to ~220°C, press four **M3 brass heat-set inserts** into the mounting corner posts of the bottom shell until flush.
3. **Prep Button Openings:**
   * Test fit the 4 printed button caps inside the top shell cutouts (**M**, **R**, **+**, **-**).
   * If buttons bind, lightly sand the sides of the button caps until they press smoothly with $0.3\text{mm}$ to $0.4\text{mm}$ clearance.

---

## 2. Electronics Harnessing & WAGO Power Rail Setup

*Insert photo of completed WAGO wire harness and terminal adapter here*

1. **Mount Microcontroller:** Mount the Arduino Nano into the terminal adapter board for secure screw-terminal wiring.
2. **Setup WAGO Power Blocks:**
   * Prepare **WAGO #1 & #2** for 5V distribution.
   * Prepare **WAGO #3, #4 & #5** for ground distribution.
3. **Wire Buttons & Resistors:**
   * Connect 5V to one side of each tactile button via WAGO #1.
   * Attach signal lines to Pins `16`, `17`, `15`, and `14`.
   * Wire a **10k Ω pull-down resistor** from each signal pin to WAGO #4 (Ground).
4. **Wire LED Array:**
   * Place a **100 Ω resistor** in series with the positive lead (anode) of each of the 7 active LEDs and connect them to Pins `9` down to `3`.
   * Route all negative leads (cathodes) into WAGO #3 (Ground).

---

## 3. Relay & Pump Assembly

*Insert photo of relay module and pump with JST connector here*

1. **Mount Relay Module:** Secure the 1-channel 5V relay module into the bottom enclosure base using M2 screws.
2. **Wire Pump Control:**
   * Connect Relay `VCC` to WAGO #1, `GND` to WAGO #5, and `IN` to Arduino **Pin 10**.
   * Run 5V power from WAGO #2 through the relay's **COM** terminal and out to the **NO** terminal.
3. **Install Pump JST Lead:** 
   * Solder a **JST connector pair** in line between the pump's positive line and the relay module output to make the pump easily detachable for cleaning.

---

## 4. Final Shell Closure & Testing

*Insert photo of open enclosure right before closing here*

1. **Tidy Wiring:** Use mini zip ties to group logic wires away from the center panel split.
2. **Close Enclosure:** 
   * Align the top cap over the bottom shell, ensuring button caps remain aligned with the internal tactile switches.
   * Fasten the two halves together using **4 × M3 × 8mm machine screws** threaded into the brass heat-set inserts.

*Insert photo of the fully assembled and powered AIS controller here*

---

## 5. Plumbing & Drip Line Setup

*Insert photo of 1/4" tubing connected to the submersible pump here*

1. **Pump Connection:** Attach the **6mm ID / 3/8" PVC tubing** directly to the outlet nozzle of the 3V submersible pump.
2. **Main Line Routing:** Run the main tubing out of your water reservoir to your plant layout.
3. **Emitter & Elbow Installation:**
   * Cut tubing to length and use **Orbit 1/4" Barbed Elbows** to route lines cleanly around pot rims.
   * Insert **Raindrip Spot Drip Mini In-Line Emitters (0.5 GPH)** directly over plant soil.
   * Seal off the end of your drip line using an **Orbit 1/4" Barbed End Cap**.
