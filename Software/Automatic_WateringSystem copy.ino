// Buttons 
const int rst = 17; // Reset
const int waterNow = 16; // Water Now
const int lessTime = 15; // - Button
const int moreTime = 14; // + Button

// Pump Relay Control Pin
const int pumpRelay = 10; // Pin 10 controls the water pump relay

// Changing Variables
int buttonState_MoreTime = 0;  // variable for reading the pushbutton status
int buttonState_LessTime = 0;  
int buttonState_WaterNow = 0;
int buttonState_Reset = 0;

int lastButtonState_MoreTime = 0; // Tracks previous state to detect a single press
int lastButtonState_LessTime = 0; 
int lastButtonState_WaterNow = 0;
int lastButtonState_Reset = 0;

// Timing Variables
// 1 hour = 3,600,000 milliseconds. 'Unsigned long' for huge numbers.
const unsigned long ONE_HOUR = 3600000UL; 
const unsigned long WATER_DURATION = 60000UL; // 60 seconds or 1 minute of watering

int currentIntervalHours = 24; // MIN at 24 hours (1 day) - MAX at 168 hours (7 days)
unsigned long previousMillis = 0; 
unsigned long pumpStartMillis = 0; // Tracks the 60 - second pump cycle independently

bool isWatering = false;

// LED Array - Managing 7 - for 7 days
const int ledPins[] = {9, 8, 7, 6, 5, 4, 3}; 
const int totalLEDs = 7;

void setup() {
  Serial.begin(115200);

  // Initialize the Pump Relay Pin
  pinMode(pumpRelay, OUTPUT);
  digitalWrite(pumpRelay, LOW); // Start with pump safely turned OFF

  // Initialize all 7 LEDs as outputs
  for (int i = 0; i < totalLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(moreTime, INPUT);
  pinMode(lessTime, INPUT);
  pinMode(waterNow, INPUT);
  pinMode(rst, INPUT);

  // Set initial LED display for 24 hours
  updateLEDDisplay();
}

void loop() {

  // Read Buttons
  buttonState_MoreTime = digitalRead(moreTime);
  buttonState_LessTime = digitalRead(lessTime);
  buttonState_WaterNow = digitalRead(waterNow);
  buttonState_Reset    = digitalRead(rst);

  // Increase Time (+ 24 Hours)
  if (buttonState_MoreTime == HIGH && lastButtonState_MoreTime == LOW) {
    if (currentIntervalHours < 168) { // FIXED: Maximum 168 hours (7 LEDs max)
      currentIntervalHours += 24;
      updateLEDDisplay();
      Serial.print("Timer increased to: ");
      Serial.print(currentIntervalHours);
      Serial.println(" hours");
    }
    delay(50); // Debounce
  }
  lastButtonState_MoreTime = buttonState_MoreTime;

  // Decrease Time (- 24 Hours)
  if (buttonState_LessTime == HIGH && lastButtonState_LessTime == LOW) {
    if (currentIntervalHours > 24) { // Minimum 24 hours (1 LED min)
      currentIntervalHours -= 24;
      updateLEDDisplay();
      Serial.print("Timer decreased to: ");
      Serial.print(currentIntervalHours);
      Serial.println(" hours");
    }
    delay(50); // Debounce
  }
  lastButtonState_LessTime = buttonState_LessTime;

  // Water Now (Manual Override)
  if (buttonState_WaterNow == HIGH && lastButtonState_WaterNow == LOW) {
    if (!isWatering) {
      isWatering = true;
      pumpStartMillis = millis(); // Record exact moment manual watering started
      turnPumpOn();
      Serial.println("Manual override triggered! Pumping for 60 seconds...");
    }
    delay(50);
  }
  lastButtonState_WaterNow = buttonState_WaterNow;

  // Reset Button (Resets countdown, leaves LEDs alone)
  if (buttonState_Reset == HIGH && lastButtonState_Reset == LOW) {
    previousMillis = millis(); // Updates the baseline timestamp to "right now"
    Serial.print("Countdown reset! Next watering in exactly ");
    Serial.print(currentIntervalHours);
    Serial.println(" hours.");
    delay(50);
  }
  lastButtonState_Reset = buttonState_Reset;

  // ==========================================
  //  Water Timer Logic
  // ==========================================
  unsigned long currentMillis = millis();
  
  // FIXED: Explicitly cast to unsigned long to prevent 16-bit integer overflow
  unsigned long targetWaitTime = (unsigned long)currentIntervalHours * ONE_HOUR; 

  // 1. Handle Automatic Countdown Trigger
  if (!isWatering) {
    if (currentMillis - previousMillis >= targetWaitTime) {
      isWatering = true;
      pumpStartMillis = currentMillis; // Bookmark exactly when the pump turned on
      turnPumpOn();
      Serial.println("Automatic cycle triggered! Pumping for 60 seconds...");
    }
  } 
  
  // 2. Handle Running the Pump for Exactly 60 seconds
  if (isWatering) {
    if (currentMillis - pumpStartMillis >= WATER_DURATION) { 
      isWatering = false;
      turnPumpOff();
      
      // FIXED: Cleanly reset previousMillis when watering completes
      previousMillis = currentMillis;
      Serial.println("Watering finished. System monitoring countdown.");
    }
  }
}

// Helper function to turn on the pump relay
void turnPumpOn() {
  digitalWrite(pumpRelay, HIGH); // Send power to the relay on Pin 10
  
  // Visual effect: Light up all status LEDs to show watering is active
  for (int i = 0; i < totalLEDs; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
}

// Helper function to turn off the pump relay
void turnPumpOff() {
  digitalWrite(pumpRelay, LOW); // Cut power to the relay on Pin 10
  updateLEDDisplay(); // Restore the standard level indicator lights
}

// Helper function to light up LEDs based on current hours selected
void updateLEDDisplay() {
  if (isWatering) return; 

  int ledsToLight = currentIntervalHours / 24; 

  for (int i = 0; i < totalLEDs; i++) {
    if (i < ledsToLight) {
      digitalWrite(ledPins[i], HIGH); 
    } else {
      digitalWrite(ledPins[i], LOW);  
    }
  }
}