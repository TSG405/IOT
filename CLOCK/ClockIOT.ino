//BY TANMOY SENGUPTA , DATE:- 28-06/20

#include "SevSeg.h"
#include <DS3231.h>
DS3231  rtc(SDA, SCL);
Time  t;
SevSeg sevseg; 
void setup() 
{
  pinMode(A0,INPUT_PULLUP);
  pinMode(A1,INPUT_PULLUP);
  pinMode(A2,INPUT_PULLUP);
  rtc.begin();
  Serial.begin(9600);
  byte numDigits = 4;
  byte digitPins[] = {2, 5, 4, 3};
  byte segmentPins[] = {6,7,8,9,10,12,13,11};
  bool updateWithDelays = false; 
  bool leadingZeros = false;
  bool disableDecPoint = false;
  bool resistorsOnSegments = false; 
  byte hardwareConfig = COMMON_ANODE; 
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(65);
}
int start=0;
int sat=0;
int m=0;
int pom=0;
int pom1=0;
void loop() 
{
if(digitalRead(A0)==0)
{
    if(digitalRead(A1)==0)
  {
    if(pom==0)
    {
    sat=sat+1;
    if(sat>=24)
    sat=0;
    pom=1;
    }
  }
  else
  {pom=0;}
      if(digitalRead(A2)==0)
  {
    if(pom1==0)
    {
    m=m+1;
    if(m>=60)
    m=0;
    rtc.setTime(sat, m, 0);
    pom1=1;
    }
  }
  else
  {pom1=0;}
  
  sevseg.setNumber(sat*100+m);
  sevseg.refreshDisplay();
}
else
{
if(start>1600)
{
  start=0;
  }
  t = rtc.getTime();
String mi=String(t.min);
String ho=String(t.hour);

    int mt=mi.toInt();
    int h=ho.toInt();
    sat=h;
    m=mt;
    int tsg=h*100+mt;
    if(start<800)
    sevseg.setNumber(tsg, 2);
    if(start>800)
    sevseg.setNumber(tsg);
    start=start+1;
    sevseg.refreshDisplay();
}
}
//THANK YOU - -- --- - ---- - - ------- - - - - - - - - -- -- - - -- - - - - -------- - - -- - - -  - - - - - -- - - - - - - - -- 
