//************************************
// define output installed in the board
//*************************************

enum outputType:uint8_t {
  DIG = 0,
  PWM = 1
};

typedef struct {
  char key[MAX_KEY];
  outputType type;
  uint8_t pin ;
  uint16_t value ;
  uint8_t newData ;
} O_Config;


O_Config outPin[NUMOUTPUTS] = {
  {"LED",DIG,ANA1,0,0},
  {"LED2",PWM,PWM1,0,0}
};
