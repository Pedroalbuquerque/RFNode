#include <arduino.h>


#include "config/all.h"

void setup(){

  Serial.begin(115200);
  pinMode(LED,OUTPUT);

  dhtSetup();
  radioSetup();
}

void loop(){

  //blinkEvery(500,500);
  //if(radioReceiveLoop()) DEBUG_MSG("Received msg:%s",recvJsonBuf);
  dhtLoop();
  JsonLoop(5000);
  radioSendLoop(500);

  // if message is complete decode it
  if(radioReceiveLoop()) {
      if(JsonDecode(recvJsonBuf)){
        outputsSet();
      }
  }
}
