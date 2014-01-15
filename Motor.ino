  
  
  const int motor1Pin = 3;    // H-bridge leg 1 (pin 2, 1A)
  const int motor2Pin = 4;   // H-bridge leg 2 (pin 7, 2A)
  const int enablePin = 9;    // H-bridge enable pin
  const int motor3Pin = 6;
  const int motor4Pin = 7;
  
  void setup() {

    // set all the other pins you're using as outputs:
    pinMode(motor1Pin, OUTPUT); 
    pinMode(motor2Pin, OUTPUT);
    pinMode(motor2Pin, OUTPUT); 
    pinMode(motor2Pin, OUTPUT); 
    
    
    pinMode(enablePin, OUTPUT);

    // set enablePin high so that motor can turn on:
    digitalWrite(enablePin, HIGH); 
  }
  
  void loop() {
  digitalWrite(motor1Pin, HIGH);
  digitalWrite(motor2Pin, LOW);
  
  digitalWrite(motor3Pin, HIGH);
  digitalWrite(motor4Pin, LOW);
  delay(3000);
  digitalWrite(motor1Pin, LOW);
  digitalWrite(motor2Pin, LOW);
  
  digitalWrite(motor3Pin, LOW);
  digitalWrite(motor4Pin, LOW);
  delay(3000);
  digitalWrite(motor1Pin, LOW);
  digitalWrite(motor2Pin, HIGH);
  
  digitalWrite(motor3Pin, LOW);
  digitalWrite(motor4Pin, HIGH);
  delay(3000);
  digitalWrite(motor1Pin, LOW);
  digitalWrite(motor2Pin, LOW);
  
  digitalWrite(motor3Pin, LOW);
  digitalWrite(motor4Pin, LOW);
}
