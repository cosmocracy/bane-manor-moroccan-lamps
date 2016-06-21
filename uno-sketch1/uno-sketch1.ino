void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  ignite(9, 5);
  ignite(10, 5);
  ignite(11, 5);
}

void ignite(int pin, int delay_ms) {
  for( int i = 0; i < 255; i++ ) {
    analogWrite(pin, i);
    delay(delay_ms);
  }  
}

void loop() {
}
