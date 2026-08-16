#include <Arduino.h>
//#include <SAGT_Music.h>

void Music::newArr(short*& arr, uint16_t rows_, uint8_t cols_) {
  arr = (short*)malloc( (uint16_t)cols_ * rows_ * sizeof(short) );
  cols = cols_;
  rows = rows_;
}

void Music::deleteArr(short*& arr) {
  free(arr);
  arr = nullptr;
}

uint16_t Music::index(uint16_t rows_, uint8_t cols_) {
  return rows_ * cols + cols_;
}

Music::Music(uint16_t size, const short **musicArr, uint8_t pin) {
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
    return;
  }
  speaker = pin;

  newArr(copy_music, 2, size);

  for(uint16_t i = 0; i < cols; i++){
    copy_music[index(0, i)] = pgm_read_word( &musicArr_P[0][i] );
    copy_music[index(1, i)] = pgm_read_word( &musicArr_P[1][i] );
  }
  Serial.print("Musical class using "); Serial.print(size * 2 + 14); Serial.println(" bytes, leaving "); Serial.println("Music arr");
  for(int i = 0; i < cols; i++){
    for(int j = 0; j < rows; j++) {
      Serial.print(copy_music[index(i, j)]);
    }
    Serial.print('\n');
  }
  start_ = millis();

}

Music::Music(){
  crash = true;
  Serial.print("???");
}

void Music::start(){
  if(crash) return;

  delay_ = millis();
}

void Music::update(){
  start_ = millis();

  if(crash) return;

  if(i >= cols) {
    i = 0;
    Serial.println("next note");
  }

  if(millis() - delay_ >= copy_music[index(1, i)] ) {
    tone(speaker, copy_music[index(0, i)] );
    delay_ = millis();
    i++;
  }
}

uint16_t Music::len(){
    return cols;
}

void Music::log() {
  if(delay_ == 0) {
    Serial.print( f("Music class is ") );
    if(!crash) {
      Serial.println( f("work.") );
    }
    else {
      Serial.println( f("not work.") );
    }

    if(!crash) {
      Serial.print( f("Using ") ); Serial.print(cols * rows); Serial.println( f(" bytes.") );

      Serial.println( f("Which class contains the data:") )
      Serial.println( f("{") )
      for(int i = 0; i < 2; i++) {
        Serial.print( f("[") )
        for(int j = 0; j < rows; j++) {
          Serial.print( copy_music[ index(i, j) ] );
          Serial.print( f(" ") );
        }
        Serial.println( f("]") );
      }
      Serial.println( f("}") );
    }
  }
  else {
    Serial.print( f("Note #") ); Serial.println(i); Serial.print( f(".") );
    if(i == 1) Serial.println( f("Melody repetition.") );

    if(millis() - start_ > 300) Serial.println( f("Having too long delay") );
  }
}

Music::~Music() {
  if(!crash) {
    deleteArr(copy_music);
  }
}
