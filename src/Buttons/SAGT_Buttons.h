#ifdef SAGT_Buttons_
#define SAGT_Buttons_

template<size_t NUM> //занимает 3+ байт оперативной памяти
class Button{
  private:

  uint8_t  buttonList[NUM];
  //uint8_t  flagList[NUM];
  uint8_t  index = 0;

  unsigned long timer;
  
  
  public:
  uint16_t timeOut = 300;
  uint8_t buttons = NUM;

  /*template<typename... Args>
  Button(Args... arg) : count(sizeof...(arg)){
    static_assert(sizeof...(arg) <= NUM, "Too many pins of button");

    uint8_t temp[] = {arg...};
    memcpy(buttonList, temp, NUM * sizeof(uint8_t));

    for(index; index < NUM; index++){
      pinMode(buttonList[index], INPUT_PULLUP);
      //flagList[index] = false;
    }
    index = 0;
  }*/
  Button &add(byte pin);

  uint8_t IsPress();

  bool IsPress(uint8_t button);

  /*
  bool IsHold(uuint8_t button){
    if( (millis() - timer >= timeOut) && (flagList[button] == false) ){
      timer = millis();
      return !digitalRead(buttonList[button]);
    }
    else{
      return 0;
    }
  }*/
  
  bool IsPressRaw(uint8_t button);
};
#endif
