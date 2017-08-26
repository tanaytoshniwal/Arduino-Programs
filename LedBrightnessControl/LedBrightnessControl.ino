int ledPin=9;
int ledPinDefault=13;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  pinMode(ledPinDefault,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if(Serial.available()>0)
  {
    int input=Serial.read();
    input-=48;
    analogWrite(ledPin,input*25);
    /*digitalWrite(ledPinDefault,b);
    b=swap(b);*/
    delayLoop(input);
    Serial.println(input*25);
  }
  else delayLoop(0);
}
void delayLoop(int input)
{
  for(;;)
  {
      if(Serial.available()>0) break;
      digitalWrite(ledPinDefault,HIGH);
      delay(1000/(input+1));
      digitalWrite(ledPinDefault,LOW);
      delay(1000/(input+1));
  }
}
