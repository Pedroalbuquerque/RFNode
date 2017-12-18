// Json object
#include <ArduinoJson.h>

StaticJsonBuffer<200> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();
uint16_t JsonLen = 0; // number of char loaded to radioJsonBuf

// buffer to support data tp be sent

char sendJsonBuf[MAX_JSON];
char recvJsonBuf[MAX_JSON];
bool recvComplete = true;

// node info and data storages
typedef struct{
  uint8_t nodeID;
  char topicName[50];
  char topicValue[200];
  uint8_t complete;
} NODEINFO;

NODEINFO node;

// input activity control

bool newDataFlag = false;
