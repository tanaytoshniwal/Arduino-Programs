int frontRight1=25,frontRight2=23,frontRightVel=6;
int frontLeft1=51,frontLeft2=53,frontLeftVel=8;
int backRight1=29,backRight2=27,backRightVel=7;
int backLeft1=49,backLeft2=47,backLeftVel=9;
int ch1=A0;
int ch2=A1;
void setup() 
{
  Serial.begin(9600);
  pinMode(frontRight1,OUTPUT);
  pinMode(frontRight2,OUTPUT);
  pinMode(frontRightVel,OUTPUT);
  pinMode(frontLeft1,OUTPUT);
  pinMode(frontLeft2,OUTPUT);
  pinMode(frontLeftVel,OUTPUT);
  pinMode(backRight1,OUTPUT);
  pinMode(backRight2,OUTPUT);
  pinMode(backRightVel,OUTPUT);
  pinMode(backLeft1,OUTPUT);
  pinMode(backLeft2,OUTPUT);
  pinMode(backLeftVel,OUTPUT);
  pinMode(ch1,INPUT);
  pinMode(ch2,INPUT);
}
void loop() 
{
  if(Serial.available()>0)
  {
    int input1=pulseIn(ch1,HIGH);
    int input2=pulseIn(ch1,HIGH);
    int maximum1=0,minimum1=9999;
    int maximum2=0,minimum2=9999;
    
    if(input1>maximum1) maximum1=input1;
    if(input2>maximum2) maximum2=input2;
    if(input1<minimum1) minimum1=input1;
    if(input2<minimum2) minimum2=input2;

    /*Serial.print(minimum1);Serial.print(" ");Serial.print(maximum1);Serial.println("   ");
    
    Serial.print(minimum2);Serial.print(" ");Serial.print(maximum2);Serial.println("   ");*/
    
    input1=map(input1,minimum1,maximum1,-100,100);
    input2=map(input2,minimum2,maximum2,-100,100);

    //Serial.print(input1);Serial.print(" ");Serial.println(input2);
    
    giveOutput(input1,input2);
    
    setRpm(input1,input2);
  }
}
void writeValue(int pin1,int pin2,int pin3,int pin4,int pin5,int pin6,int pin7,int pin8)
{
  digitalWrite(pin1,HIGH);  digitalWrite(pin5,LOW);
  digitalWrite(pin2,HIGH);  digitalWrite(pin6,LOW);
  digitalWrite(pin3,HIGH);  digitalWrite(pin7,LOW);
  digitalWrite(pin4,HIGH);  digitalWrite(pin8,LOW);
}
void writePwm(int pin1,int value1,int pin2,int value2,int pin3,int value3,int pin4,int value4)
{
  analogWrite(pin1,value1);
  analogWrite(pin2,value2);
  analogWrite(pin3,value3);
  analogWrite(pin4,value4);
}
void giveOutput(int a,int b)
{
  if(a>10&&a<101) 
  {
    writeValue(frontRight1,frontLeft1,backRight1,backLeft1,frontRight2,frontLeft2,backRight2,backLeft2);
  }
  else if(a<-10&&a>-101)
  { 
    writeValue(frontRight2,frontLeft2,backRight2,backLeft2,frontRight1,frontLeft1,backRight1,backLeft1);
  }
  else if(b<-10&&b>-101)
  { 
    writeValue(frontRight1,frontLeft2,backRight1,backLeft2,frontRight2,frontLeft1,backRight2,backLeft1);
  }
  else if(b>10&&b<101)
  { 
    writeValue(frontRight2,frontLeft1,backRight2,backLeft1,frontRight1,frontLeft2,backRight1,backLeft2);
  }
}
void setRpm(int a,int b)
{
    if(a<0) a=-a;
    if(b<0) b=-b;
    if((a<10)||(b<10))
      writePwm(frontRightVel,0,frontLeftVel,0,backRightVel,0,backLeftVel,0);
    else if(a>10&&b<10)
      writePwm(frontRightVel,a,frontLeftVel,a,backRightVel,a,backLeftVel,a);
    else if(b>10&&a<10)
      writePwm(frontRightVel,b,frontLeftVel,b,backRightVel,b,backLeftVel,b);
    else
      writePwm(frontRightVel,(a+b)/2,frontLeftVel,(a+b)/2,backRightVel,(a+b)/2,backLeftVel,(a+b)/2);
}

