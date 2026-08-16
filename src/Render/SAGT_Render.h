#ifndef SAGT_Render_h
#define SAGT_Render_h

#ifndef LiquidCrystal_PCF8574_h
#include <LiquidCrystal_PCF8574.h>
#endif

#ifndef __AVR__
#include <avr/pgmspace.h>
#endif

class Render : public LiquidCrystal_PCF8574{
    enum class Mode{CROP, FULL, ARCHIVE, UNZIP};

    byte *spritebuffer = nullptr;
    byte *mapbuffer = nullptr;
    
    uint8_t scols;
    uint8_t srows;
    
    uint8_t mcols;
    uint8_t mrows;
    
    uint8_t display_cols_;
    uint8_t display_rows_;
    
    public:
    Render(uint8_t _cols_, uint8_t _rows_); //Инициализация + получение данных о дисплее
    
    void clear_and_alloc_buffer_map(uint8_t _cols_, uint8_t _rows_);
    void clear_and_alloc_buffer_sprite(uint8_t _cols_, uint8_t _rows_);
    
    void addSpriteNum(uint8_t _cols_, uint8_t _rows_, uint8_t num);
    void addMapNum(uint8_t _cols_, uint8_t _rows_, uint8_t num);
    
    void printSprite(uint8_t x, uint8_t y, uint8_t start, uint8_t end, uint8_t _rows_);
    void printSprite(uint8_t x, uint8_t y, uint8_t _cols_, uint8_t _rows_);
    
    void printMap();
    void printMap(Mode _mode_);
    void printMap(uint8_t scroll_x, uint8_t scroll_y, Mode _mode_);
    
    
    ~Render();

};

#endif




