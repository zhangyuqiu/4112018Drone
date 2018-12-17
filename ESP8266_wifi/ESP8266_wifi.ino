/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc0
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable Serial.printlns and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


#define sfront 12
#define sfront 12
#define sback 13
#define sleft 14
#define sright 15
#define sstate 0
#define sstill 2
#define scruise 4

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "b85f4ea240e84f9e857ef924cd53558b";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "VincentGeng";
char pass[] = "gengzlafa";
int rol;
int pit;
int yaw;
int thr;
int alt;

BLYNK_WRITE(V0)
{
  rol = param.asInt(); // assigning incoming value from pin V1 to a variable

  // process received value
}

BLYNK_WRITE(V1)
{
  pit = param.asInt(); // assigning incoming value from pin V1 to a variable

  // process received value
}


BLYNK_WRITE(V2)
{
  yaw = param.asInt(); // assigning incoming value from pin V1 to a variable

  // process received value
}


BLYNK_WRITE(V3)
{
  thr = param.asInt(); // assigning incoming value from pin V1 to a variable

  // process received value
}


BLYNK_WRITE(V4)
{
  alt = param.asInt(); // assigning incoming value from pin V1 to a variable

  // process received value
}



void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(sfront,OUTPUT);
  pinMode(sleft,OUTPUT);
  pinMode(sright,OUTPUT);
  pinMode(sback,OUTPUT);
  pinMode(sstate,OUTPUT);
  pinMode(sstill,OUTPUT);
  pinMode(scruise,OUTPUT);
  
  
  

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  
  Blynk.run();
//  String yawNum = "yaw"+String(yaw)+"*";
//  String pitNum = "pit"+String(pit)+"*";
//  String rolNum = "rol"+String(rol)+"*";
//  String altNum = "alt"+String(alt)+"*";
//  String thrNum = "thr"+String(thr)+"*";

  String yawNum = "yaw"+String(yaw);
  String pitNum = "pit"+String(pit);
  String rolNum = "rol"+String(rol);
  String altNum = "alt"+String(alt);
  String thrNum = "thr"+String(thr);
  String outNum =yawNum+pitNum+rolNum+thrNum+"*";
  Serial.println(outNum);
  delay(4);  
//    Serial.println(yawNum);
//    Serial.println(pitNum);
//    Serial.println(rolNum);
//    Serial.println(altNum);
//    Serial.println(thrNum);
  //Serial.Serial.println(pinValue);
//  if(pinValue0>0){
//    left=1;
//    digitalWrite(sleft,HIGH);
//    Serial.println("LeftOn");
//  }else{
//    left=0;
//    digitalWrite(sleft,LOW);
//    Serial.println("LeftOff");
//  }
//
//  if(pinValue1>0){
//    front=1;
//    digitalWrite(sfront,HIGH);
//    Serial.println("RightOn");
//  }else{
//    front=0;
//    digitalWrite(sfront,LOW);
//    Serial.println("RightOff");
//  }
//
//  if(pinValue2>0){
//    back=1;
//    digitalWrite(sback,HIGH);
//    Serial.println("BackOn");
//  }else{
//    back=0;
//    digitalWrite(sback,LOW);
//    Serial.println("BackOff");
//  }
//
//  if(pinValue3>0){
//    right=1;
//    digitalWrite(sright,HIGH);
//    Serial.println("RightOn");
//  }else{
//    right=0;
//    digitalWrite(sright,LOW);
//    Serial.println("RightOff");
//  }
//  if(pinValue4>0){
//    state=1;
//    digitalWrite(sstate,HIGH);
//    Serial.println("StateOn");
//  }else{
//    state=0;
//    digitalWrite(sstate,LOW);
//    Serial.println("StateOff");
//  }
//
//   if(pinValue5>0){
//    still=1;
//    digitalWrite(sstill,HIGH);
//    Serial.println("Stop");
//  }else{
//    still=0;
//    digitalWrite(sstill,LOW);
//    Serial.println("Continue");
//  }
//
//  if(pinValue6>0){
//    digitalWrite(scruise,HIGH);
//    Serial.println("Cruise on");
//    cruise=1;
//  }else{
//    cruise=0;
//    digitalWrite(scruise,LOW);
//    Serial.println("Cruise off");
//  }
}

