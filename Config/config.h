//--------------------------------------------------------------
//  define compile option here
//  if using PlatformIO compile directive -D comment out definition here
//--------------------------------------------------------------


#define DEBUG_PORT Serial   // uncomment to print Debug messages
#define ECHO_PORT Serial    // uncomment for ECHO porpuse if not defined will be Silent

//  Board or CPU used - leave only one uncommented
#define BOARD_MOTEINO
//#define BOARD_ESP8266
//#define BOARD_ESP32


// Radio
#define RADIO_HIGHPOWER      1  // 1 - 0 (True - False)
#define RADIO_FREQUENCY      RF69_433MHZ //RF69_868MHZ ; RF69_915MHZ
#define RADIO_NODEID         2  //0-254 255 is broadcast ** use only 0-19 for now
#define RADIO_GATEWAYID      1  // 0-254
#define RADIO_NETWORKID      200 //1-256
#define RADIO_PROMISCUOUS    0   // 0 - 1 (False-True)
#define RADIO_ENCRYPTKEY     "sampleEncryptKey" // 16 char key
#define RADIO_RETRYTIME      100 // ms to wait before retry
#define RADIO_NUMRETRIES     3  // number of retries before give up


// Json
#define MAX_JSON          200 // max Json message
#define MAX_KEY           15  // max Key len
#define MAX_VALUE         10  // max value len

// Inputs

#define ENABLE_DHT    1       // commnet out if sensor not available

// Outputs

#define NUMOUTPUTS 2   //number of output to be controled
