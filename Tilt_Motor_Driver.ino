

const int motorApin1 = 10;
const int motorApin2 = 11;

const int motorBpin1 = 5;
const int motorBpin2 = 6;

const int enable = 13;
const int level = 8;
const int error = 7;

int sensorA;
int sensorB;

void setup()
{
  pinMode(motorApin1, OUTPUT);
  pinMode(motorApin2, OUTPUT);
  pinMode(motorBpin1, OUTPUT);
  pinMode(motorBpin1, OUTPUT);
  pinMode(enable, OUTPUT);
  pinMode(level, OUTPUT);
  pinMode(error, OUTPUT);
  digitalWrite(enable,HIGH);
  Serial.begin(4800);
}

void loop()
{
  sensorA = analogRead(A0);
  sensorB = analogRead(A1);


  if (sensorA>900 && sensorB>900 || sensorA<800 && sensorB<800)
  {
    Serial.println(sensorA);
    digitalWrite(level, HIGH);
    digitalWrite(error, LOW);
    analogWrite(motorApin1, 0);
    analogWrite(motorApin2, 0);
    analogWrite(motorBpin1, 0);
    analogWrite(motorBpin2, 0);
  }

  else
  {
    digitalWrite(level, LOW);
    digitalWrite(error, HIGH);

    if (sensorA>500)
    {
      analogWrite(motorApin1, 255);
      analogWrite(motorApin2, 0);
      analogWrite(motorBpin1, 255);
      analogWrite(motorBpin2, 0);
    }
    else
    {
      analogWrite(motorApin1, 0);
      analogWrite(motorApin2, 255);
      analogWrite(motorBpin1, 0);
      analogWrite(motorBpin2, 255);
    }

  }

}



