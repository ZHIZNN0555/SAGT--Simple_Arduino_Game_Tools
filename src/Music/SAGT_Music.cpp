#include <Arduino.h>
#include <SAGT_Music.h>
#define INDEX(a, b, c) ( ( (a) * (c) ) + (b) )

void Music::newArr(short*& arr, uint8_t rows_, uint16_t cols_) {
  arr = (short*)malloc( (uint16_t)cols_ * rows_ * sizeof(short) );
  cols = cols_ - 2;
  rows = rows_;
}

//==============================================================================

void Music::deleteArr(short*& arr) {
  free(arr);
  arr = nullptr;
}

//==============================================================================

uint16_t Music::index(uint8_t rows_, uint16_t cols_) {
  return rows_ * cols + cols_;
}

//==============================================================================

Music::Music(uint16_t size, const uint16_t* musicArr_P, uint8_t pin) {
  if(size > MUSIC_MAX_USE_SRAM){
    Serial.println("!Warning! Array is too big for music! Acceptable max size arr 150x2 elements");
    if(display) {
      //lcd.setCursor(10, 2);
      //lcd.print("MemEr");
      for(int i = 0; i < 5; i++){
        tone(pin, 200);
        delay(500);
        noTone(pin);
        delay(500);
      }

    }
    crash = true;

    //#error "Array is too big for music! Acceptable max size arr 150x2 elements"
  }
  speaker = pin;

  newArr(copy_music, 2, size/4);

  for(uint8_t i = 0; i < rows; i++) {

    for(uint16_t j = 0; j < cols; j++){
      copy_music[ INDEX(i, j, cols) ] = pgm_read_word( &musicArr_P[ INDEX(i, j, cols) ] );
    }
  }

  Serial.print("Musical class using "); Serial.print(size + 14); Serial.println(" bytes, leaving "); Serial.println("Music arr");
  /*
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++) {
      Serial.print(copy_music[index(i, j)]);
    }
    Serial.print('\n');
  }
  */

}

//==============================================================================

Music::Music(){
  crash = true;
  Serial.print("???");
}

//==============================================================================

void Music::start(){
  if(crash) return;

  delay_ = millis();
}

//==============================================================================

void Music::update(){
  //start_ = millis();

  if(crash) return;

  if(i >= cols) {
    i = 0;
    //Serial.println("next note");
  }

  if(millis() - delay_ >= copy_music[INDEX(1, i, cols)] ) {
    tone(speaker, copy_music[ INDEX(0, i, cols) ] );
    delay_ = millis();
    i = (i % cols) + 1;
  }
}

//==============================================================================

uint16_t Music::len(){
    return cols;
}

//==============================================================================

void Music::log() {
  if(start_ == 0) {
    Serial.print( F("Music class is ") );
    if(!crash) {
      Serial.println( F("work.") );
    }
    else {
      Serial.println( F("not work.") );
    }

    if(!crash) {
      Serial.print( F("Using ") ); Serial.print(cols * rows * 2); Serial.println( F(" bytes.") );

      Serial.println( F("Which class contains the data:") );
      Serial.println( F("{") );
      for(int i = 0; i < 2; i++) {
        Serial.print( F("[") );
        for(int j = 0; j < cols; j++) {
          Serial.print( copy_music[ INDEX(i, j, cols) ] );
          Serial.print( F(" ") );
        }
        Serial.println( F("]") );
      }
      Serial.println( F("}") );
    }
  }
  else {
    Serial.print( F("Note #") ); Serial.println(i); Serial.print( F(".") );
    if(i == 1) Serial.println( F("Melody repetition.") );

    if(millis() - start_ > 200) Serial.println( F("!!!_Having too long delay_!!!") );
  }
}

//==============================================================================

Music::~Music() {
  if(!crash) {
    deleteArr(copy_music);
  }
}


#pragma message "Included SAGT_Music.h"
