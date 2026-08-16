#ifndef SAGT_Music_
#define SAGT_Music_

#ifndef MUSIC_MAX_USE_SRAM
#define MUSIC_MAX_USE_SRAM 600 //макрос для регулировки границ музыкального массива
#endif



 //занимает 8+ байтов оперативной памяти
class Music{          //класс музыкального сопровождения. ОСТОРОЖНО С ВЫДЕЛЕНИЕМ РАЗМЕРА
  private:            //Так как класс загружает мелодию из flash в оперативную память
  bool display = false;
  bool crash = false;

  unsigned long delay_ = 0;
  unsigned long start_ = 0;
  short *copy_music = nullptr;
  uint8_t speaker;

  uint8_t i = 0;
  uint8_t cols;
  uint16_t rows;

  void newArr(short*, uint8_t, uint16_t);
  void deleteArr(short*);
  uint16_t index(uint8_t cols_, uint16_t rows_);

  public:
  
  //void Music(short int *add_music)  {
  Music(uint16_t size, const short **musicArr, uint8_t pin);
  Music();


  void start();

  void update();

  uint16_t len();

  void log();

  ~Music();
  
};

#include "SAGT_Music.cpp"



#endif

