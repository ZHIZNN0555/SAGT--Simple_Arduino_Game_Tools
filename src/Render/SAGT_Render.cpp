#include <Arduino.h>
#include <SAGT_Render.h>

#ifndef LiquidCrystal_PCF8574_h
#include <LiquidCrystal_PCF8574.h>
#endif

#ifndef __AVR__
#include <avr/pgmspace.h>
#endif

Render::Render(uint8_t _cols_, uint8_t _rows_, uint8_t _addr_ = 0x27) :
         displ_cols(_cols_), displ_rows(_rows_), LiquidCrystal_PCF8574(_addr_) {
           
    LiquidCrystal_PCF8574::begin(_cols_, _rows_);
}
           
              
void Render::clear_and_alloc_buffer_map(uint8_t _cols_, uint8_t _rows_) 
                                     : mcols(_cols_), mrows(_rows_){
    if(mapbuffer) {
        delete[] mapbuffer;
        mapbuffer = nullptr;
    }
    mapbuffer = new byte[_cols_ * _rows_];
}

void Render::clear_and_alloc_buffer_sprite(uint8_t _cols_, uint8_t _rows_) 
                                           : scols(_cols_), srows(_rows_){
    if(spritebuffer) {
        delete[] spritebuffer;
        spritebuffer = nullptr;
    }
    spritebuffer = new byte[_cols_ * _rows_];
}

void Render::addSpriteNum(uint8_t _cols_, uint8_t _rows_, uint8_t num) {
    if (_cols_ >= scols || _rows_ >= srows) return;

    spritebuffer[_rows_ * scols + _cols_] = num;
}

void Render::printSprite(uint8_t x, uint8_t y, uint8_t start, uint8_t end, uint8_t _rows_) {
    LiquidCrystal_PCF8574::setCursor(x, y);
    
    if (_rows_ > srows) return;
    
   
    for(uint8_t i = start; i <= end || (i < scols) ; i++) {
        LiquidCrystal_PCF8574::write(spritebuffer[_rows_ * scols + i]);
    }
    
}

void Render::printSprite(uint8_t x, uint8_t y, uint8_t _cols_, uint8_t _rows_) {
    LiquidCrystal_PCF8574::setCursor(x, y);
    
    if (_rows_ >= srows || _cols_ >= scols) return;
    
    LiquidCrystal_PCF8574::write(spritebuffer[_rows_ * scols + _cols_]);
}

void Render::addMapNum(uint8_t _cols_, uint8_t _rows_, uint8_t num) {
    if (_cols_ >= mcols || _rows_ >= mrows) return;
    
    mapbuffer[_rows_ * scols + _cols_] = num;
}

void Render::addMapNum(uint8_t _cols_, uint8_t _rows_, uint8_t num, Mode mode) {
    if (_cols_ >= mcols || _rows_ >= mrows) return;
    
    if (!mode::ARCHIVE) return;
    
    
    if ( (_rows_ * mcols + _cols_) % 2 != 0) {
        mapbuffer[_rows_ * scols + _cols_ / 2] = (num << 4) | mapbuffer[_rows_ * scols + _cols_] ;
    }
    else {
        mapbuffer[_rows_ * scols + _cols_ / 2] = num | mapbuffer[_rows_ * scols + _cols_] ;
    }
    
}

void Render::printMap() {
    for(uint8_t y = 0; y < mrols; y++) {
        LiquidCrystal_PCF8574::setCursor(0, y);
        for(uint8_t x = 0; x < mcols; x++) {
            LiquidCrystal_PCF8574::write(mapbuffer[y * mcols + x]);
        }
    }
}

void Render::printMap(Mode _mode_) {
    if(!_mode_::UNZIP) return 0;
    
    for(uint8_t y = 0; y < mrols; y++) {
        LiquidCrystal_PCF8574::setCursor(0, y);
        for(uint8_t x = 0; x < mcols; x++) {
            LiquidCrystal_PCF8574::write( (spritebuffer[ (y * mcols + x) / 2] >> 4) & 0x0F);
            LiquidCrystal_PCF8574::write(spritebuffer[ (y * mcols + x) / 2] & 0x0F);
        }
    }
}

Render::~Render() {
    delete[] spritebuffer;
    delete[] mapbuffer;
    
    spritebuffer = nullptr;
    mapbuffer = nullptr;
}
