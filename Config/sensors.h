/*
*/


//------------------------------------------------------------
//  Temperature defines
//-----------------------------------------------------------

#define TMP_CELSIUS             0
#define TMP_FAHRENHEIT          1
#define TMP_UNITS               TMP_CELSIUS



//--------------------------------------------------------------------------------
// DHTXX temperature/humidity sensor
// Enable support by passing ENABLE_DHT=1 build flag
//--------------------------------------------------------------------------------


#if defined(ENABLE_DHT) == 1
  #define DHT_PIN                 14
  #define DHT_UPDATE_INTERVAL     6000
  #define DHT_TYPE                DHT22
  #define DHT_TIMING              11
  #define DHT_TEMPERATURE_TOPIC   "temperature"
  #define DHT_HUMIDITY_TOPIC      "humidity"

  #define HUMIDITY_NORMAL         0
  #define HUMIDITY_COMFORTABLE    1
  #define HUMIDITY_DRY            2
  #define HUMIDITY_WET            3
#endif
