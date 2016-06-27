/*
 * Moroccan Lamp driver
 * 
 * Pin setup:
 *   CdS light sensor - Signal on pin A0, power from 5V
 *   LEDs - Output on pins 9, 10, 11
 */

void setup() {
  // Serial.begin(9600);
  // Set the PWM pins for output
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  // Start with the lamp lit
  ignite(9, 5);
  ignite(10, 5);
  ignite(11, 5);
}

bool lit = false;
int IGNITE_THRESHOLD = 100;
int SAMPLING_PERIOD_MS = 1000;

void ignite(int pin, int delay_ms) {
  if ( !lit) {
    for( int i = 0; i <= 255; i++ ) {
      analogWrite(pin, i);
      delay(delay_ms);
    }
    lit = true;    
  }
}

void extinguish(int pin, int delay_ms) {
  if ( lit) {
    for( int i = 255; i >= 0; i-- ) {
      analogWrite(pin, i);
      Serial.println("LED value: " + String(i));
      delay(delay_ms);
    }  
    lit = false;    
  }
}

void loop() {
  // Read the light sensor (analog pin A0)
  int value = analogRead(A0);
  // Serial.println("Analog value: " + String(value));
  // If the ambient light is less than our darkness threshold
  if (value < IGNITE_THRESHOLD) {
    // Light the LEDs in turn (will be ignored if already on)
    ignite(9, 5);
    ignite(10, 5);
    ignite(11, 5);
  } else {
    // Otherwise extinguish the LEDs in turn (will be ignroed if already off)
    extinguish(9, 5);
    extinguish(10, 5);
    extinguish(11, 5);    
  }
  // Sleep/yield the processor
  delay(SAMPLING_PERIOD_MS);
}
