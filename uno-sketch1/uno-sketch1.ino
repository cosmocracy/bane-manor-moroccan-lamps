void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  for( int i = 0; i < 255; i++ ) {
    analogWrite(9, i);
    delay(30);
  }
}

void loop() {
}
