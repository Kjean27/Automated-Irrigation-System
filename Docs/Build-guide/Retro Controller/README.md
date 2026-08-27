# Retro Controller Build Guide & Assembly Manual

Step-by-step assembly guide for building the Automated Irrigation System (AIS) retro-style controller enclosure and electronics.

---

## 1. Preparing the 3D Printed Parts 

*Insert photo of printed Front Panel, Back Panel and Mechanical Hardware*

1. **Remove Support Material:** Clean off any 3D printing supports from the inside of the Front Panel and Back Panel.
2. **Install Heat-Set Inserts:** 
   * Using a soldering iron set to ~220°C, press ten **M3 brass heat-set inserts** into the mounting  posts of the bottom front panel until flush.
3. **Prep Button Openings:**
   * Test fit the 4 tactile buttons inside the Front Panel cutouts (**M**, **R**, **+**, **-**).
   * If buttons fit too tight sand the edges of the cutouts.
   * Test fit the LED’s in each cutout whole, and sand if too tight.
---

## 2. Electronics Harnessing & WAGO Power Rail Setup

*Insert photo of completed WAGOs, Terminal Adapter, Arduino Nano, LEDs*

1.**Solder Microcontroller Pins:** Take the pins that came with the Arduino Nano (only if unwelded) and solder them to their designated pins.
2. **Mount Microcontroller:** Mount the Arduino Nano into the terminal adapter board for secure screw-terminal wiring.
3. **Setup WAGO Power Blocks:**
   * Prepare **WAGO #1 - 5 way connection & #2 - 2 way connection** for 5V distribution.
   * * (If your using jumper cables skip) Cut a wire and strip both ends, and twist the strands of both sides.

*Insert photo of strip wire with twist ends*

   * *Unscrew the 5V channel with a flat head, insert a twisted end into the terminal, and retighten.

*Insert photo of strip cable with twist ends*

   * *Attach the other end to the far left of the WAGO with 5 way connectors (lift the latch before inserting the wire and close once inserted to ensure proper connection).

*Insert photo of WAGO connection*

   * * Cut another smaller wire and strip both ends, and insert the wire to the far right of the 5 way WAGO and the other end in the far left of the 2 way WAGO. 

*Insert photo of WAGO connection*

   * Prepare **WAGO #3, #4 & #5** for ground distribution.
   * * Cut a wire similar in size to the power line and attach the GND Terminal.
     
*Insert photo of connection to GND*

   * * Connect the other end to one of the 3 way Connector WAGOs’.
   * * Daisy chain them together by cutting and striping smaller wires.

*Insert a photo of the daisy chained WAGO’s*
     

4. **Wire Buttons & Resistors:**
   * Fit the tactile buttons into the Front Panel.
   
* Insert photo of the buttons fit in the cutouts.


   * Cut 4 wires at similar lengths, strip both ends, and twist the ends. (Color code the wires or label the WAGO Channels with a sharpie)
* Insert a photo of the wires cut

   * Put the wires twisted ends of in the power WAGO line
 * Insert a photo of the wires cut and inserted in the power WAGO

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

