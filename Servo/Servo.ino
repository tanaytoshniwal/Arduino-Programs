#include<Servo.h>
int servoPin=3;
Servo s1;
void setup() {
  // put your setup code here, to run once:
s1.attach(servoPin);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0)
{
  int a=Serial.read();
  if(a>=0&&a<181)
  s1.write(a);
  else
  rotate();
}
}
void rotate()
{
  for(int i=0;i<181;i++)
  {s1.write(i);delay(5);}
  for(int i=179;i>=0;i--)
  {s1.write(i);delay(5);}
}

