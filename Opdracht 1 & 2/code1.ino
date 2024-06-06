void setup()
{
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
}


void loop()
{
  digitalWrite(10, HIGH);
  delay(1500);
  digitalWrite(10, LOW);
  delay(1500);
  digitalWrite(8, HIGH);
  delay(1500);
  digitalWrite(8, LOW);
  delay(1500);
}
