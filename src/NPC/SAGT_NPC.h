#ifndef LiquidCrystal_PCF8574_h
#include <LiquidCrystal_PCF8574.h>
#endif

class NPC{
  byte x, old_x;
  byte y, old_y;

  byte min_x, min_y;

  byte spawn_x, spawn_y;

  byte sprite1, sprite2, sprite3;

  byte repl;

  LiquidCrystal_PCF8574 &lcd;

  public:

  NPC(byte spawn_x_, byte spawn_y_, byte min_x_, byte min_y_, LiquidCrystal_PCF8574 &lcd_){
    x = old_x = spawn_x = spawn_x_;
    y = old_y = spawn_y = spawn_y_;

    min_x = min_x_;
    min_y = min_y_;

    lcd = lcd_;
  }

  void setSprite(byte sprite1_, byte sprite2_, byte sprite3_) {
    sprite1 = sprite1_;
    sprite2 = sprite2_;
    sprite3 = sprite3_;
  }

  uint16_t get_coord() {
    return ((uint16_t)x << 8) | y;
  }

  uint16_t get_coord(byte x_edit) {
    return ((uint16_t)(x + x_edit) << 8) | y;
  }

  void move_auto(short delay, unsigned long &timer, char front) {
    if (millis() - timer >= delay) { //таймер
      timer = millis();

      switch(front) {//обработчик ввода
        case 'u':
          if (y < ROWS) y++;
          break;

        case 'd':
          if (y != min_y) y--;
          break;
        
        case 'r':
          if (x > min_x) x--;
          break;

        case 'l':
          if (x < COLS) x++;
          break;
      }

      lcd.setCursor(old_x, old_y); //убираем из виду персонажа на старых координатах (курсор как в текстовом редакторе сам перемещается)
      lcd.write(repl);
      lcd.write(repl);
      lcd.write(repl);

      lcd.setCursor(x, y); //отрисовываем персонажа на новых координатах и далее запоминаем текущие координаты как старые
      lcd.write(sprite1);
      lcd.write(sprite2);
      lcd.write(sprite3);

      old_x = x;
      old_y = y;
    }
  }

  void spawn() {
    lcd.setCursor(spawn_x, spawn_y);
    lcd.write(sprite1);
    lcd.write(sprite2);
    lcd.write(sprite3);

    old_x = x = spawn_x;
    old_y = y = spawn_y;
  }

  void hide() {
    lcd.setCursor(x, y);
    lcd.write(repl);
    lcd.write(repl);
    lcd.write(repl);
  }

  void post(byte x_, byte y_) {
    old_x = x = x_;
    old_y = y = y_;

    lcd.setCursor(x, y);
    lcd.write(sprite1);
    lcd.write(sprite2);
    lcd.write(sprite3);
  }
};
