#include "DFRobotDFPlayerMini.h"
#include "Arduino.h"
#include "SoftwareSerial.h"
SoftwareSerial mySoftwareSerial(10, 9); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
int k=0;
int vl=3;
int Var;
int D2 = 3;
int D3 = 4;
int D4 = 5;
int D5 = 6;
int D6 = 7;
int D7 = 8;
int D1 = 2;
String new1;
String new2;
String new3;
String new4;
String new5;
String new6;
String new7;
String new8;
String new9;
int old;
int old1;
void setup()
{

  mySoftwareSerial.begin(9600);

  Serial.begin(115200);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms

   myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
 //
   myDFPlayer.enableDAC();
  //

//


  pinMode(D7, OUTPUT);
  digitalWrite(D7,LOW);
  pinMode(D1, OUTPUT);
  digitalWrite(D1,LOW);
  pinMode(D2, OUTPUT);
  digitalWrite(D2,LOW);
  pinMode(D3, OUTPUT);
  digitalWrite(D3,LOW);
  pinMode(D4, OUTPUT);
  digitalWrite(D4,LOW);
  pinMode(D5, OUTPUT);
  digitalWrite(D5,LOW);
  pinMode(D6, OUTPUT);
  digitalWrite(D6,LOW);
}
void loop()
{

while (Serial.available()) {
   IncomingChar(Serial.read());
  }
}
void IncomingChar (const byte InChar)
{
  static char InLine [300];
  static unsigned int Position = 0;
  switch (InChar)
  {

    case '\r':

          break;
    case '\n':   // ket thuc mot ban tin
      InLine [Position] = 0;
      ProcessCommand(String(InLine));
      Position = 0;
      break;
    default:
       InLine [Position++] = InChar;
  }
}
void ProcessCommand(String InLine)
{
  Serial.println(InLine);
         if (InLine.indexOf("Sp1=0") != -1)
    {
      digitalWrite(D1,LOW);
      new1="0";
    }
    if (InLine.indexOf("Sp1=1") != -1)
    {
     digitalWrite(D1,HIGH);
   new1="1";
    }
    if (InLine.indexOf("Sp2=0") != -1)
    {
      new2="0";
      digitalWrite(D2,LOW);

    }if (InLine.indexOf("Sp2=1") != -1)
    {
       digitalWrite(D2,HIGH);
       new2="1";
    }
    if (InLine.indexOf("Sp3=0") != -1)
    {
      new3="0";
      digitalWrite(D3,LOW);

    }
    if (InLine.indexOf("Sp3=1") != -1)
    {
      digitalWrite(D3,HIGH);
     new3="1";

    }
    if (InLine.indexOf("Sp4=0") != -1)
    {
      new4="0";
   digitalWrite(D4,LOW);

    }
    if (InLine.indexOf("Sp4=1") != -1)
    {
       digitalWrite(D4,HIGH);
     new4="1";
    }
    if (InLine.indexOf("Sp5=0") != -1)
    {
      new5="0";
     digitalWrite(D5,LOW);

    }

        if (InLine.indexOf("Sp5=1") != -1)
    {
      digitalWrite(D5,HIGH);
    new5="1";
    }
    if (InLine.indexOf("Sp6=0") != -1)
    {
      new6="0";
     digitalWrite(D6,LOW);

    }
        if (InLine.indexOf("Sp6=1") != -1)
    {
      digitalWrite(D6,HIGH);
       new6="1";
    }

    if (InLine.indexOf("Sp7=0") != -1)
    {
      new7="0";
    digitalWrite(D7,LOW);

    }
        if (InLine.indexOf("Sp7=1") != -1)
    {
         digitalWrite(D7,HIGH);
        new7="1";
    }
  if (InLine.indexOf("Var=0") != -1)
    { if(old !=0)
    {
      old=0;
      myDFPlayer.volume(0);
      vl=0;
     new8="0";
    }
    }
      if (InLine.indexOf("Var=1") != -1)
    {
       if(old !=1)
    {
      old=1;
      myDFPlayer.volume(4);
      vl=4;
      new8="1";
    }
    }
      if (InLine.indexOf("Var=2") != -1)
    {

     if(old !=2)
    {
      old=2;
      myDFPlayer.volume(8);
      vl=8;
      new8="2";
         }
    }
      if (InLine.indexOf("Var=3") != -1)
    {
       if(old !=3)
    {
      old=3;
      myDFPlayer.volume(14);
      vl=14;
      new8="3";;
    }
    }
       if (InLine.indexOf("Var=4") != -1)
    {
       if(old !=4)
    {
      old=4;
      myDFPlayer.volume(16);
      vl=16;
      new8="4";
    }
    }
    if (InLine.indexOf("Var=5") != -1)
    {
       if(old !=5)
    {
      old=5;
     myDFPlayer.volume(20);
     vl=20;
     new8="5";
    }
    }  if (InLine.indexOf("Var=6") != -1)
    {
       if(old !=6)
    {
      old=6;
      myDFPlayer.volume(22);
      vl=22;
     new8="6";
    }
    }
      if (InLine.indexOf("Var=7") != -1)
    {
       if(old !=7)
    {
      old=7;
      myDFPlayer.volume(24);
      vl=24;
      new8="7";
    }
    }
      if (InLine.indexOf("Var=8") != -1)
    {
       if(old !=8)
    {
      old=8;
      myDFPlayer.volume(27);
      vl=27;
      new8="8";
    }
    }
      if (InLine.indexOf("Var=9") != -1)
    {
       if(old !=9)
    {
      old=9;
      myDFPlayer.volume(30);
      vl=30;
     new8="9";
    }
    }
    if (InLine.indexOf("Status=1") != -1)
    {
       if(old1 !=1)
    {
      old1=1;
      myDFPlayer.previous();
      myDFPlayer.volume(vl);
      new9="1";
    }
    }
      if (InLine.indexOf("Status=2") != -1)
    {
       if(old1 !=2)
    {
      old1=2;
      myDFPlayer.pause();
       myDFPlayer.volume(vl);
      new9="2";
    }
    }
      if (InLine.indexOf("Status=3") != -1)
    {
       if(old1 !=3)
    {
      old1=3;
     myDFPlayer.start();
      myDFPlayer.volume(vl);
      new9="3";
    }
    }
      if (InLine.indexOf("Status=4") != -1)
    {
       if(old1 !=4)
    {
      old1=4;
    myDFPlayer.next();
     myDFPlayer.volume(vl);
     new9="4";
    }
    }
          if (InLine.indexOf("Status=5") != -1)
    {
       if(old1 !=5)
    {
      old1=5;
    myDFPlayer.enableLoopAll();
     myDFPlayer.volume(vl);
     new9="6";
    }
    }
      if (InLine.indexOf("Status=6") != -1)
    {
       if(old1 !=6)
    {
      old1=6;
    myDFPlayer.disableLoopAll();
     myDFPlayer.volume(vl);
     new9="6";
     }
    }
  }
