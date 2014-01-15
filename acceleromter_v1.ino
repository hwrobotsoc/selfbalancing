const int STABILITY = 10;

long axe_x=0;
long axe_y=0;
long axe_z=0;

const int motorApin1 = 10;
const int motorApin2 = 11;

const int motorBpin1 = 5;
const int motorBpin2 = 4;

const int enable = 13;
const int level1 = 8;
const int error = 7;
const int level2 = 6;


void setup()
{
  pinMode(motorApin1, OUTPUT);
  pinMode(motorApin2, OUTPUT);
  pinMode(motorBpin1, OUTPUT);
  pinMode(motorBpin1, OUTPUT);
  pinMode(enable, OUTPUT);
  pinMode(level1, OUTPUT);
  pinMode(error, OUTPUT);
  pinMode(level2, OUTPUT);
  digitalWrite(enable, HIGH);
  Serial.begin(9600);
}


void loop()
{
  axe_x = analogRead(A0)-333;
  axe_y = analogRead(A1)-374;
  axe_z = analogRead(A2)-449;
  
  digitalWrite(error, LOW);
  digitalWrite(level1, LOW);
  digitalWrite(level2, LOW);
  
  if (axe_y < 0)
  {
      analogWrite(motorApin1, 150);
      analogWrite(motorApin2, 0);
      analogWrite(motorBpin1, 150);
      analogWrite(motorBpin2, 0);
      digitalWrite(level1, HIGH);
      delay (50);
  }
  else if (axe_y > 0)
  {
      analogWrite(motorApin1, 0);
      analogWrite(motorApin2, 150);
      analogWrite(motorBpin1, 0);
      analogWrite(motorBpin2, 150);
      digitalWrite(level2, HIGH);
      delay (50);
  }
  
  /*
  
  else if (axe_z < 410 && axe_z > 390)
  {
    digitalWrite(level1, LOW);
    digitalWrite(level2, LOW);
    digitalWrite(error, HIGH);
    analogWrite(motorApin1, 0);
    analogWrite(motorApin2, 0);
    analogWrite(motorBpin1, 0);
    analogWrite(motorBpin2, 0);
  }
  
  */
  
  delay (10);

  Serial.print("STABILITY X=");
  Serial.print(axe_x);
  
  Serial.print("\tY=");
  Serial.print(axe_y);
  
  Serial.print("\tZ=");
  Serial.println(axe_z);
  
  Serial.println();

}
