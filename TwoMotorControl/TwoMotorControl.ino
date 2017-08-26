int rightPin1=8,rightPin2=7,rightPwm=3;
int leftPin1=6,leftPin2=5,leftPwm=4;
void setup() 
{
  Serial.begin(9600);
  pinMode(leftPin1,OUTPUT);pinMode(leftPin2,OUTPUT);pinMode(leftPwm,OUTPUT);pinMode(rightPin1,OUTPUT);pinMode(rightPin2,OUTPUT);pinMode(rightPwm,OUTPUT);
}
void loop() 
{
  if(Serial.available()>0)
  {
    initValue(rightPin1,rightPin2,leftPin1,leftPin2);
    char a=Serial.read();
    giveOutput(a);
    setRpm(a);
  }
}
void initValue(int pin1,int pin2,int pin3,int pin4)
{
  digitalWrite(pin1,LOW);digitalWrite(pin2,LOW);digitalWrite(pin3,LOW);digitalWrite(pin4,LOW);
}
void writeValue(int pin1,int pin2)
{
  digitalWrite(pin1,HIGH);digitalWrite(pin2,HIGH);
}
void writePwm(int pin1,int value1,int pin2,int value2)
{
  analogWrite(pin1,value1);analogWrite(pin2,value2);
}
void giveOutput(char a)
{
  if(a=='w') writeValue(rightPin1,leftPin1);
  else if(a=='s') writeValue(rightPin2,leftPin2);
  else if(a=='a') writeValue(rightPin1,leftPin1);
  else if(a=='d') writeValue(rightPin1,leftPin1);
}
void setRpm(char a)
{
  if(a=='w') writePwm(rightPwm,1023,leftPwm,1023);
  else if(a=='s') writePwm(rightPwm,1023,leftPwm,1023);
  else if(a=='a') writePwm(rightPwm,1023,leftPwm,511);
  else if(a=='d') writePwm(rightPwm,511,leftPwm,1023);
  else if(a==' ') writePwm(rightPwm,0,leftPwm,0);
}

