#include <ArduinoJson.h>



void JsonLoop( unsigned long interval){
  static uint32_t timer = 0;
  char bug[200];

  if(timer > millis()) timer= millis();
  if (timer == 0 || (millis()-timer > interval)) {
    // at regular <interval> read sensors and fill JsonBuffer
    strcpy(buf,JsonBuild());
    DEBUG_MSG("[JSON] Json:%s\n",buf);
    newDataFlag = true;  //signal dta new data is available to be used/sent
    timer= millis();
  }
  else{
    DEBUG_MSG("[JSon loop]%u\n",timer);
  }
}

char* JsonBuild(){
    root[F(DHT_TEMPERATURE_TOPIC)] = getDHTTemperature();
    root[F(DHT_HUMIDITY_TOPIC)] = getDHTHumidity();

    JsonLen = root.printTo(sendJsonBuf);
    return sendJsonBuf;

}


boolean JsonDecode(char * jsonStr){

  uint8_t outIndex ;

  JsonObject& root = jsonBuffer.parseObject(jsonStr);

  //DEBUG_MSG("HLLO");
  //DEBUG_MSG("[Json] Decode:");
  //Serial.print("[Json] Decode:");Serial.println(jsonStr);

  // Test if parsing succeeds.
  if (!root.success()) {
    Serial.println(F("parseObject() failed"));
    return false;
  }
  else{
    for(JsonObject::iterator it=root.begin(); it!=root.end(); ++it)
    {
        // *it contains the key/value pair
        const char* key = it->key;
        if((outIndex = outputIndex(key)) != 255 ){
            // it->value contains the JsonVariant which can be casted as usual
            switch(outPin[outIndex].type){
              case DIG:
                  outPin[outIndex].value = (uint16_t)it->value;
                  break;
              case PWM:
                  outPin[outIndex].value = (uint16_t)it->value;
                  break;
              default:
                  break;

            }
            outPin[outIndex].newData = true;
            //sprintf(buf,"[Json](IT)     key %s\t value %d\n", it->key,it->value);
            //Serial.print(buf);
            //sprintf(buf,"[Json](outPin) key %s\t value %d\t index:%d\n", outPin[outIndex].key,outPin[outIndex].value,outIndex);
            //Serial.print(buf);
          }
        else
          ECHO_MSG("[Json-err] not found:%s\n",key);
        //const char* value = it->value;
    }

  }


  return true;

}
