#include "Arduino.h"
#include "GameButtonsTool.h"


  Button Button::&add(byte pin) {
    if (this->index == NUM) return *this;

    this->buttonList[this->index] = pin;
    pinMode(pin, INPUT_PULLUP);
    this->index++;

    return *this;
  }

  uint8_t Button::IsPress(){
    index = 0;
    while(index != NUM){
      switch( digitalRead(buttonList[index]) ){
        case 0:
          return index;
        case 1:
          index++;
      }
    }
    index = 0;
    return 0;
  }

  bool Button::IsPress(uint8_t button){
    if( (millis() - timer >= timeOut) && !digitalRead(buttonList[button]) == 0){
      timer = millis();
      return !digitalRead(buttonList[button]);
    }
    else{
      return 0;
    }
  }
  
  bool Button::IsPressRaw(uint8_t button) {
    return !digitalRead(button);
  }


