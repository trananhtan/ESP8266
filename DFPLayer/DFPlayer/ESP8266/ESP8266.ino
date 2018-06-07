//chuong trinh gao tiep esp voi mang va may tinh
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "EEPROM.h"
int port =80;
const char* host= "anhtantr.000webhostapp.com";
ESP8266WebServer server(80);
const char*     ssid           = "AnhTaniot";//ten wifi o che do phat wifi
const char*     passphrase     = "123698745";
String          st;
String          content;
int             statusCode;
static String Status;

static String Sp1 = "0";
static String Sp2 = "0";
static String Sp3 = "0";
static String Sp4 = "0";
static String Sp5 = "0";
static String Sp6 = "0";
static String Sp7 = "0";
static String Var = "0";
String new1;
String new2;
String new3;
String new4;
String new5;
String new6;
String new7;
String new8;
String new9;
static int New;
int k=1;
void setup()
{
  Serial.begin(115200);
     EEPROM.begin(512);

    Serial.println("Startup");
    // read eeprom for ssid, pass and blynk
    Serial.println("Reading EEPROM ssid");
    String esid;
    for (int i = 0; i < 32; ++i)
    {
        esid += char(EEPROM.read(i));// do noi dung tu bo nho erom
    }
    Serial.print("SSID: ");
    Serial.println(esid.c_str());
    esid.trim();
     Serial.println("Reading EEPROM pass");
    String epass = "";
    for (int i = 32; i < 96; ++i)
    {
        epass += char(EEPROM.read(i));
    }
    Serial.print("PASS: ");
    Serial.println(epass.c_str());
    epass.trim();
    EEPROM.end();
    if ( esid.length() > 1 )
    {
        WiFi.begin(esid.c_str(), epass.c_str());
           if (!testWifi())
   {
      setupAP();
      int z=1;
      while(z)
      {
    server.handleClient();//khoi tao sever
    if(WiFi.status() == WL_CONNECTED)
    {z=0;}
      }
      EEPROM.end();
     }
}
WiFi.softAPdisconnect(true);//tat cho do phat wifi
}
bool testWifi(void)
{
    int c = 0;
    Serial.println("Xin vui long doi ket noi WIFI");
    while ( c < 20 )
    {
        if (WiFi.status() == WL_CONNECTED)
        {
          Serial.println("");
           Serial.println("Connected");
            return true;
        }
        delay(1000);
        Serial.print(WiFi.status());
        c++;
    }
    Serial.println("");
    Serial.println("Thoi gian ket noi cham, Mo AP");
    return false;
}
void setupAP(void)
{
    WiFi.mode(WIFI_STA);//cai dat che do wifi
    WiFi.disconnect();
    delay(100);
    int n = WiFi.scanNetworks();// quet cac wifi gan day
    Serial.println("Tim hoan tat");
    if (n == 0)
    {
        Serial.println("no networks found");
    }
    else
    {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i)
        {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
            delay(10);
        }
    }
    Serial.println("");
    st = "<ol>";
    for (int i = 0; i < n; ++i)
    {
        // Print SSID and RSSI for each network found
        st += "<li>";
        st += WiFi.SSID(i);
        st += " (";
        st += WiFi.RSSI(i);
        st += ")";
        st += (WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*";
        st += "</li>";
    }
    st += "</ol>";
    delay(100);
    Serial.println("softap");
    Serial.println(ssid);
    Serial.println(passphrase);
    WiFi.softAP(ssid, passphrase, 6);

    launchWeb(1);
    Serial.println("over");
}
void launchWeb(int webtype)//chay trang web sever khi co yeu cau
{
    Serial.println("");
    Serial.println("WiFi ket noi");
    Serial.print("Dia chi IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("SoftAP IP: ");
    Serial.println(WiFi.softAPIP());
    createWebServer(webtype);
    // Start the server
    server.begin();
    Serial.println("May chu bat dau");
}
void createWebServer(int webtype)
{
    if ( webtype == 1 )
    {
        server.on("/", []()
        {
            IPAddress ip = WiFi.softAPIP();
            String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
            content = "<!DOCTYPE HTML>\r\n<html><h2>XSwitch</h2>";
            content += "<form method=\"get\" action=\"setting\">";
            content += "<div>Wifi</div>";
            content += "<div><input name=\"ssid\" size=\"40\"></div>";
            content += "<div>Mat Khau</div>";
            content += "<div><input name=\"pass\" size=\"40\"></div>";
            content += "<div><input type='submit'></div>";
             content += "<p>";
            content += st;
            content += "</p>";
            content += "</html>";
            server.send(200, "text/html", content);
        });
        server.on("/setting", []()
        {
            String qsid = server.arg("ssid");
            String qpass = server.arg("pass");
               if (qsid.length() > 0 && qpass.length() > 0)
            {
                EEPROM.begin(512);
                Serial.println("clearing eeprom");
                for (int i = 0; i < 128; ++i)
                {
                    EEPROM.write(i, 0);
                }
                EEPROM.commit();
                Serial.println(qsid);
                Serial.println("");
                Serial.println(qpass);
                Serial.println("");
                 Serial.println("writing eeprom ssid:");
                for (int i = 0; i < qsid.length(); ++i)
                {
                    EEPROM.write(i, qsid[i]);
                    Serial.print("Wrote: ");
                    Serial.println(qsid[i]);
                }
                 Serial.println("writing eeprom pass:");
                for (int i = 0; i < qpass.length(); ++i)
                {
                    EEPROM.write(32 + i, qpass[i]);
                    Serial.print("Wrote: ");
                    Serial.println(qpass[i]);
                }
                EEPROM.commit();
                EEPROM.end();
                content = "{\"Success\":\"Luu vao he thong. Khoi dong lai ten wifi moi\"}";
                statusCode = 200;
            }
            else
            {
                content = "{\"Error\":\"404 not found\"}";
                statusCode = 404;
                Serial.println("Sending 404");
            }
            server.send(statusCode, "application/json", content);
        });
    }
        }






void loop()
{


     while(WiFi.status() == WL_CONNECTED)
     { //Check WiFi connection status
     String    link ="/espget.php?";
          WiFiClient client;  //Declare an object of class HTTPClient
                                                                //Send the request
        if (!client.connect(host,port))

      {
         Serial.print("Loi Ket Noi");
      }
      while(!client.available())
      {
               client.print(String("GET ") + link + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
               String request = client.readString();
               request.remove(0,250);
              // Serial.println(request);
               ProcessCommand(request);

     delay(200);
     break;
          }
  }

 if(WiFi.status() != WL_CONNECTED)
  {
    setup();
  }
}
void IncomingChar (const byte InChar)
{
  static char InLine [300];
  static unsigned int Position = 0;
  switch (InChar)
  {
    case '\r':
    k=0;// Don't care about carriage return so throw away.
      break;
    case '\n':   // ket thuc mot ban tin
      InLine [Position] = 0;
      Position = 0;
         break;
    default:
    k=0;
      InLine [Position++] = InChar;
  }
}
void ProcessCommand(String InLine)
{

  if (InLine.indexOf("end") !=-1)
  {

    if (InLine.indexOf("Sp1=0") != -1)
    {
      Sp1 = "0";
    }
    if (InLine.indexOf("Sp1=1") != -1)
    {
      Sp1 = "1";
    }
    if (InLine.indexOf("Sp2=0") != -1)
    {
      Sp2 = "0";
    }if (InLine.indexOf("Sp2=1") != -1)
    {
      Sp2 = "1";
    }
    if (InLine.indexOf("Sp3=0") != -1)
    {
      Sp3 = "0";
    }
    if (InLine.indexOf("Sp3=1") != -1)
    {
      Sp3 = "1";
    }
    if (InLine.indexOf("Sp4=0") != -1)
    {
      Sp4 = "0";
    }
    if (InLine.indexOf("Sp4=1") != -1)
    {
      Sp4 = "1";
    }
    if (InLine.indexOf("Sp5=0") != -1)
    {
      Sp5 = "0";
    }
        if (InLine.indexOf("Sp5=1") != -1)
    {
      Sp5 = "1";
    }
    if (InLine.indexOf("Sp6=0") != -1)
    {
      Sp6 = "0";
    }
        if (InLine.indexOf("Sp6=1") != -1)
    {
      Sp6 = "1";
    }

    if (InLine.indexOf("Sp7=0") != -1)
    {
      Sp7 = "0";
    }
        if (InLine.indexOf("Sp7=1") != -1)
    {
      Sp7 = "1";
    }
  if (InLine.indexOf("Var=0") != -1)
    {
      Var = "0";
    }
      if (InLine.indexOf("Var=1") != -1)
    {
      Var = "11";
    }
      if (InLine.indexOf("Var=2") != -1)
    {
      Var = "2";
    }
      if (InLine.indexOf("Var=3") != -1)
    {
      Var = "3";
    }
      if (InLine.indexOf("Var=4") != -1)
    {
      Var = "4";
    }  if (InLine.indexOf("Var=5") != -1)
    {
      Var = "5";
    }  if (InLine.indexOf("Var=6") != -1)
    {
      Var = "6";
    }
    if (InLine.indexOf("Var=7") != -1)
    {
      Var = "7";
    }
      if (InLine.indexOf("Var=8") != -1)
    {
      Var = "8";
    }
      if (InLine.indexOf("Var=9") != -1)
    {
      Var = "9";
    }
      if (InLine.indexOf("Status=1") != -1)
    {
      Status = "1";
    }
          if (InLine.indexOf("Status=2") != -1)
    {
      Status = "2";
    }
              if (InLine.indexOf("Status=3") != -1)
    {
      Status = "3";
    }
              if (InLine.indexOf("Status=4") != -1)
    {
      Status = "4";
    }
              if (InLine.indexOf("Status=5") != -1)
    {
      Status = "5";
    }
              if (InLine.indexOf("Status=6") != -1)
    {
      Status = "6";
    }
              if (InLine.indexOf("Status=7") != -1)
    {
      Status = "7";
    }
    String Request=" Sp1=" + Sp1 +" Sp2=" + Sp2 +" Sp3=" + Sp3 +" Sp4=" + Sp4 +" Sp5=" + Sp5 +" Sp6=" + Sp6 +" Sp7=" + Sp7 +" Var=" + Var+ " Status="+ Status;
    Serial.println(Request);
    delay(500);
  k=1;
 String Link1="&room=3&new1="+Sp1+"&new2="+Sp2+"&new3="+Sp3+"&new4="+Sp4+"&new5="+Sp5+"&new6="+Sp6+"&new7="+Sp7+"&new8="+Var+"&new9="+Status;
  conn(Link1);
  }




}

void conn(String link)

{
      if(link.indexOf("room=") !=-1)
    {

           WiFiClient client;  //Declare an object of class HTTPClient
                                                               //Send the request
      if (!client.connect(host,port))

      {
        // Serial.print("Loi Ket Noi");
      }
      while(!client.available())
      {
        String link1="/esppost.php?&"+link;
               client.print(String("GET ") + link1 + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
       delay(100);
               String request = client.readString();
               //Serial.println(request);


     k=1;

     break;
          }
          delay(300);
    }

}
