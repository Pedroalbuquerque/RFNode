#include <RFM69.h>
#include <SPI.h>

RFM69 radio;

#define MAX_CHARS 59
typedef struct{
  char msg[MAX_CHARS+1]; // 59 char+NULL to break message if necessary (61 max payload)
  uint8_t complete ; // 1 char to signal if msg contains full load
} Payload;

Payload data;

// -----------------------------------------------------------------------------
// RFM69
// -----------------------------------------------------------------------------

void radioSetup() {
    delay(10);
    radio.initialize(RADIO_FREQUENCY, RADIO_NODEID, RADIO_NETWORKID);
    radio.setHighPower(RADIO_HIGHPOWER);
    radio.encrypt(RADIO_ENCRYPTKEY);
    //radio.setFrequency(RADIO_FREQUENCY);
    radio.promiscuous(RADIO_PROMISCUOUS);

}


void radioSendLoop( unsigned long interval){
  static uint32_t timer = 0;

  if(timer > millis()) timer= millis();
  if (timer == 0 || millis()-timer > interval) {
    int bufLeft=JsonLen ,numChars=0;
    uint8_t i =0;
    while(newDataFlag && (bufLeft > 0)){
      numChars = bufLeft>MAX_CHARS? MAX_CHARS: bufLeft;
      strMid(data.msg,sendJsonBuf,i*MAX_CHARS,numChars);

      //DEBUG_MSG("sub msg:%s \ni:%d , #chars:%d \n", data.msg,i,numChars);

      i++; // position on next 60 chars
      bufLeft -= MAX_CHARS ;
      if (bufLeft > 0) data.complete = false;
      else {
        data.complete = true;
      };
      if(radio.sendWithRetry(RADIO_GATEWAYID, (const void*)&data, sizeof(data),RADIO_NUMRETRIES, RADIO_RETRYTIME)) {
        // sucess
        if(data.complete) ECHO_MSG("[RF]Sent %s\n",sendJsonBuf);
      }
      else {
        ECHO_MSG("[RF-Err] GTW:%d Bytes:%d\n\n",RADIO_GATEWAYID,sizeof(data))
        break;
      };
    } // while loop
    newDataFlag = false;
  } //if interval

}

bool radioReceiveLoop(){
  static unsigned long oldtimer;

  if (radio.receiveDone()){//If some packet was received by the radio, wait for all its contents to come trough
    DEBUG_MSG("[radio] received target:%d\n",radio.TARGETID);
    oldtimer = millis(); //For data link loss timeout calculation
    //DEBUG_MSG("Packet received \t #Bytes:%d\n", radio.PAYLOADLEN);
    if (radio.TARGETID == RADIO_NODEID){//Check if the packet destination is the GATEWAY radio (NODE 1)
      if (radio.ACKRequested()){
        radio.sendACK();
      }
      //check if node info is complete, if so reset info to load newMode
      if(recvComplete){
        strcpy(recvJsonBuf,"");
      }
      //Retrieve the data from the received Payload
      data = *(Payload *)radio.DATA; //assume radio.DATA actually contains our struct and not something else

      strcat(recvJsonBuf,data.msg);
      recvComplete = data.complete;

      ECHO_MSG("msg:%s \ncomplete:%d \n\n",data.msg, data.complete);

      blinkPin(LED,10);
    }
    else { // If no packets received

      //if no packet received for the last 5 sec consider Link Lost
      if (millis() > (oldtimer + 5000)) {
        Serial.println(F("missing packets!"));
        oldtimer=millis();
        }

    }


    return data.complete;

  }
  else
    return false;
  //  DEBUG_MSG("nothing received \n");

}
