
/*
void outputsSetup(){

}
*/

// output the values to all output if their outPin array <newData> is true and reset to false
void outputsSet(){
  for(uint8_t i =0; i< NUMOUTPUTS;i++){

    if(outPin[i].newData){
        pinMode(outPin[i].pin, OUTPUT);
        switch (outPin[i].type ){
          case DIG:
              digitalWrite(outPin[i].pin,outPin[i].value);
              break;
          case PWM:
              analogWrite(outPin[i].pin,outPin[i].value);
              break;
          default:
              DEBUG_MSG("[output SET] unknown out type \n");
              break;
        }
        outPin[i].newData = false;
        //DEBUG_MSG("[out SET] pin:%d\t type:%d\t name/key:%s\t value:%d\n",outPin[i].pin,outPin[i].type,outPin[i].key,OnOff);//,root[outPin[i].key]
        ECHO_MSG("[out SET] pin:%d\t type:%d\t name/key:%s\t value:%d\n",outPin[i].pin,outPin[i].type,outPin[i].key,outPin[i].value);//,root[outPin[i].key]
      }
  }// for
}


// Find if thes is one output (in outPin array) that matchs the key
int8_t outputIndex( const char * key){

  for(uint8_t i = 0 ; i< NUMOUTPUTS; i++){
    if((String)outPin[i].key == (String) key) {
      return i;
    }
    else
      DEBUG_MSG("[OutIdx] key:%s\t Outp:%s\n",key,outPin[i].key);
  }
  return -1;

}
