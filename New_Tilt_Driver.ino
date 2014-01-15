
int tilt_s1 = 2;
int tilt_s2 = 3;

const int motorApin1 = 10;
const int motorApin2 = 11;

const int motorBpin1 = 5;
const int motorBpin2 = 4;

const int enable = 13;
const int level1 = 8;
const int error = 7;
const int level2 = 6;


void setup(){
  pinMode(motorApin1, OUTPUT);
  pinMode(motorApin2, OUTPUT);
  pinMode(motorBpin1, OUTPUT);
  pinMode(motorBpin1, OUTPUT);
  pinMode(enable, OUTPUT);
  pinMode(level1, OUTPUT);
  pinMode(error, OUTPUT);
  pinMode(level2, OUTPUT);
  pinMode(tilt_s1, INPUT);
  pinMode(tilt_s2, INPUT);
  digitalWrite(enable, HIGH);
  Serial.begin(9600);
}

void loop(){
  int position = getTiltPosition();
  Serial.println(position);
  digitalWrite(error, LOW);
  digitalWrite(level1, LOW);
  digitalWrite(level2, LOW);
  if (position == 0)
  {
      analogWrite(motorApin1, 150);
      analogWrite(motorApin2, 0);
      analogWrite(motorBpin1, 150);
      analogWrite(motorBpin2, 0);
      digitalWrite(level1, HIGH);
      delay (50);
  }
  else if (position == 1)
  {
      analogWrite(motorApin1, 0);
      analogWrite(motorApin2, 150);
      analogWrite(motorBpin1, 0);
      analogWrite(motorBpin2, 150);
      digitalWrite(level2, HIGH);
      delay (50);
  }
  else
  {
    digitalWrite(level1, LOW);
    digitalWrite(level2, LOW);
    digitalWrite(error, HIGH);
    analogWrite(motorApin1, 0);
    analogWrite(motorApin2, 0);
    analogWrite(motorBpin1, 0);
    analogWrite(motorBpin2, 0);
  }
  delay (10);
}

int getTiltPosition(){
   int s1 = digitalRead(tilt_s1);
   int s2 = digitalRead(tilt_s2);
   return (s1 << 1) | s2; //bitwise math to combine the values
}
