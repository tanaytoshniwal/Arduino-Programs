int ledPin=9;
int output=0;
void setup() {
  // put your setup code here, to run once:
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
analogWrite(ledPin,output);
}
void giveValue(int a)
{
  if(a==43)
  {
    output+=25;
  }
  else if(a==45)
  {
    output-=25;
  }
  if(output<0) output=0;
  if(output>255) output=255;
}
void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0)
{
  int a=Serial.read();
  giveValue(a);
  analogWrite(ledPin,output);
  Serial.println(output);
}
}
