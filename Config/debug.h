
#if defined(DEBUG_PORT) || defined(ECHO_PORT)
  #if defined( ARDUINO_AVR_MOTEINO) || defined(ARDUINO_AVR_MOTEINOMEGA) || defined(ARDUINO_AVR_NANO)
    char buf[100];
  #endif
#endif
#ifdef DEBUG_PORT

    #if defined( ARDUINO_AVR_MOTEINO) || defined(ARDUINO_AVR_MOTEINOMEGA) || defined(ARDUINO_AVR_NANO)
      #define DEBUG_MSG(...) sprintf( buf,__VA_ARGS__ );DEBUG_PORT.print(buf);
    #else
      #define DEBUG_MSG(...) DEBUG_PORT.printf( __VA_ARGS__ );
    #endif
#else
    #define DEBUG_MSG(...)
#endif

#ifdef ECHO_PORT

  #if defined( ARDUINO_AVR_MOTEINO) || defined(ARDUINO_AVR_MOTEINOMEGA) || defined(ARDUINO_AVR_NANO)
    #define ECHO_MSG(...) sprintf( buf,__VA_ARGS__ );ECHO_PORT.print(buf);
  #else
    #define ECHO_MSG(...) ECHO_PORT.printf( __VA_ARGS__ );
  #endif
#else
  #define ECHO_MSG(...)
#endif
