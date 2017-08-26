int ledPin=13;
boolean b=LOW;
void setup()
{
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  Serial.println("hello");
}
boolean swap(boolean b)
{
  b=!b;
  return b;
}
void loop()
{
  b=swap(b);
  digitalWrite(ledPin,b);
  Serial.println(b);
  delay(1000);
}

