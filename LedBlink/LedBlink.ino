//short led=13;
byte led=13;
byte c=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  //for(byte i=0;i<50;i++)
  for(;;)
  {
    digitalWrite(led,HIGH);
    delay(50);
    digitalWrite(led,LOW);
    delay(50);
    c++;
    if(c==50)
    {
      c=0;
      break;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  /*digitalWrite(led,HIGH);
  delay(1000);*/
  /*digitalWrite(led,LOW);
  delay(500);*/
  c++;
  if(digitalRead(led)==LOW)
  {
    digitalWrite(led,HIGH);
    delay(1000);
  }
  else
    digitalWrite(led,LOW);
  delay(250);
  if(c==10)
    exit(0);
}
