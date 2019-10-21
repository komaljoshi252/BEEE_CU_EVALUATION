float ps_milliSeconds=0;
int i,reading,state=0,lastState;
int sespim=A0;
int senval=0;
int op1_milliSeconds=100;
int op2_milliSeconds=2000;
void setup()
{
  pinMode(11,INPUT);
  Serial.begin(9600);
 for(i=2;i<8;i++)
 {
   pinMode(i,OUTPUT);
 }
}
void loop()
{
  senval=analogRead(A0);
  Serial.println(senval);
  delay(100);
  if(senval>300)
  {
    reading = digitalRead(11);
 
  while( reading ==LOW)
  { 
    delay (100);
    ps_milliSeconds=ps_milliSeconds+100;
    Serial.println(ps_milliSeconds);
  }
    if (ps_milliSeconds>=op2_milliSeconds)
    {
    for (int i=2; i<8; i++)
    {   
    digitalWrite(i, HIGH);        
    delay(100);                          
    digitalWrite(i, LOW);         
     }
  for (i=7; i>1; i--)
   {   
    digitalWrite(i, HIGH);        
    delay(100);                         
    digitalWrite(i, LOW);          
   }  
  }
  else if(ps_milliSeconds>=op1_milliSeconds)
  {
  for(i=2;i<8;i++)
  {
    if(i%2==0)
    {
      delay(250);
      digitalWrite(i, HIGH);
       delay(250);
      digitalWrite(i,LOW);
      delay(250);
    } 
  else
  { 
   
    digitalWrite(i,LOW);
   delay(250);
   
  }
}
 for(i=2;i<8;i++)
  {
    if(i%2==0)
    {
      digitalWrite(i, LOW);
     delay(250);
    }
 else
  {
   delay(250);
   digitalWrite(i,HIGH);
   delay(250);
    digitalWrite(i,LOW);
   delay(250);
  }
  }
  }
  }
}
