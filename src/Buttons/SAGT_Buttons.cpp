#include "Arduino.h"
#include <SAGT_Buttons.h>

  Button Button::&add(byte pin) {
    if (this->index == NUM) return *this;

    this->buttonList[this->index] = pin;
    pinMode(pin, INPUT_PULLUP);
    this->index++;

    return *this;
  }


  uint8_t Button::IsPress_Task(){
    index %= NUM + 1;
    /*
    while(index != NUM){
      switch( digitalRead(buttonList[index]) ){
        case 0:
          return index;
        case 1:
          index++;
      }
    }
    */


    return !digitalRead(buttonList[index]) * index;
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
  
  bool Button::IsPress_Raw(uint8_t button) {
    return !digitalRead(button);
  }



  #pragma message "Included SAGT_Buttons.h"
