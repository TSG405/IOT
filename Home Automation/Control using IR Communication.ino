//# Arduino Code  ( requires Adruino UNO, IR Receiver (TSOP1738), Single channel Relay Module [5V-DC], LED Bulb/LAMP 230V AC ) #

----------------------------------------------

#include<IRremote.h>
int RECV_PIN=10;
int r=8;
int led=13;
int i=1;
int j=1;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
 Serial.begin(9600);
 irrecv.enableIRIn();
 pinMode(r,OUTPUT);
 pinMode(led, OUTPUT);
}

void loop()
{

 if (irrecv.decode(&results))
 {
  Serial.println(results.value, HEX);
  if (results.value==0x1FE00FF)             //button 7
  {
  i++;
  inta a=i%2;
  digitalWrite(r,a);
  }
 else if (results.value==0x1FE9867)                //button 9
 {
  j++;
  int b=j%2;
  digitalWrite(led,b);
 }
 irrecv.resume();                          //receive the next value
 
 }
} 
