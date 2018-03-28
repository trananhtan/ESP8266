//NOne
#include "DFRobotDFPlayerMini.h"
#include "Arduino.h"
#include "SoftwareSerial.h"
SoftwareSerial mySoftwareSerial(A4, A5); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
int k=0;
int vl=0;
int Var;
int D2 = 2;
int D3 = 3;
int D4 = 4;
int D5 = 5;
int D7 = 7;
int D9 = 9;
int old=0;
void setup()
{
 
  mySoftwareSerial.begin(9600);
  
  Serial.begin(115200);
   delay(15000);
 // Serial.println();
  //Serial.println(F("DFRobot DFPlayer Mini Demo"));
  //Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
  //  Serial.println(F("Unable to begin:"));
  //  Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms
  delay(1000);
   myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
    delay(1000);
   myDFPlayer.enableDAC();
     delay(1000);
   myDFPlayer.enableLoopAll();
     delay(1000);
    myDFPlayer.volume(15);
    pinMode(D7, OUTPUT);
  digitalWrite(D7,LOW);
  pinMode(D9, OUTPUT);
  digitalWrite(D9,LOW);
  pinMode(D2, OUTPUT);
  digitalWrite(D2,LOW);
  pinMode(D3, OUTPUT);
  digitalWrite(D3,LOW);
  pinMode(D4, OUTPUT);
  digitalWrite(D4,LOW);
  pinMode(D5, OUTPUT);
  digitalWrite(D5,LOW);
}
void loop()
{
while (Serial.available())
  {
    IncomingChar(Serial.read ());
    
  }
}





void IncomingChar (const byte InChar)
{
  static char InLine [300];
  static unsigned int Position = 0;
  switch (InChar)
  {
    k=0;
    case '\r':
   
          break;
    case '\n':   // ket thuc mot ban tin
      InLine [Position] = 0;
      ProcessCommand(String(InLine));
      Position = 0;
      break;
    default:
    k=0;
      InLine [Position++] = InChar;
  }
}
void ProcessCommand(String InLine)
{
 // Serial.println(InLine);

  
       if (InLine.indexOf("Sp1=0") != -1)
    {
      digitalWrite(D2,LOW);
    }
    if (InLine.indexOf("Sp1=1") != -1)
    {
     digitalWrite(D2,HIGH);
    }
    if (InLine.indexOf("Sp2=0") != -1)
    {
      digitalWrite(D3,LOW);
    }if (InLine.indexOf("Sp2=1") != -1)
    {
       digitalWrite(D3,HIGH);
    }
    if (InLine.indexOf("Sp3=0") != -1)
    {
      digitalWrite(D4,LOW);
    }
    if (InLine.indexOf("Sp3=1") != -1)
    {
      digitalWrite(D4,HIGH);
    }
    if (InLine.indexOf("Sp4=0") != -1)
    {
   digitalWrite(D5,LOW);
    }
    if (InLine.indexOf("Sp4=1") != -1)
    {
       digitalWrite(D5,HIGH);
    }
    if (InLine.indexOf("Sp5=0") != -1)
    {
     digitalWrite(D7,LOW);
    }
        if (InLine.indexOf("Sp5=1") != -1)
    {
      digitalWrite(D7,HIGH);
    }
    if (InLine.indexOf("Sp6=0") != -1)
    {
     digitalWrite(D9,LOW);
    }
        if (InLine.indexOf("Sp6=1") != -1)
    {
      digitalWrite(D9,HIGH);
    }
        
    if (InLine.indexOf("Sp7=0") != -1)
    {
    digitalWrite(D2,LOW);
    }
        if (InLine.indexOf("Sp7=1") != -1)
    {
         digitalWrite(D2,HIGH);
    }
  if (InLine.indexOf("Var=0") != -1)
    { if(old !=0)
    {
      old=0;
      myDFPlayer.volume(0);
      vl=0;
      
    }
    }
      if (InLine.indexOf("Var=11") != -1)
    {
       if(old !=1)
    {
      old=1;
      myDFPlayer.volume(5);
      vl=5;
    }
    }
      if (InLine.indexOf("Var=2") != -1)
    {
      
     if(old !=2)
    {
      old=2;
      myDFPlayer.volume(10);
      vl=10;
    }
    }
      if (InLine.indexOf("Var=3") != -1)
    {
       if(old !=3)
    {
      old=3;
      myDFPlayer.volume(15);
      vl=15;
    }
    }
       if (InLine.indexOf("Var=4") != -1)
    {
       if(old !=4)
    {
      old=4;
      myDFPlayer.volume(20);
      vl=20;
    }
    }  
    if (InLine.indexOf("Var=5") != -1)
    {
       if(old !=5)
    {
      old=5;
     myDFPlayer.volume(25);
     vl=25;
    }
    }  if (InLine.indexOf("Var=6") != -1)
    {
       if(old !=6)
    {
      old=6;
      myDFPlayer.volume(30);
      vl=30;
    }
    } 
    if (InLine.indexOf("Var=7") != -1)
    {
       if(old !=7)
    {
      old=7;
      myDFPlayer.previous(); 
      myDFPlayer.volume(vl);
    }
    }
      if (InLine.indexOf("Var=8") != -1)
    {
       if(old !=8)
    {
      old=8;
      myDFPlayer.pause();
       myDFPlayer.volume(vl);
    }
    }
      if (InLine.indexOf("Var=9") != -1)
    {
       if(old !=9)
    {
      old=9;
     myDFPlayer.start(); 
      myDFPlayer.volume(vl);
    }
    }
      if (InLine.indexOf("Var=10") != -1)
    {
       if(old !=10)
    {
      old=10;
    myDFPlayer.next();
     myDFPlayer.volume(vl);
    }
    }
  
}
