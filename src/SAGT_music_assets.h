#ifndef SAGT_music_assets_h
#define SAGT_music_assets_h

//пространства имён и сокращения
typedef const short cshort;
typedef const byte cbyte;
typedef const char cchar;

//ноты
#define c 130
#define c_ 138
#define d 146
#define d_ 155
#define e 164
#define f 174
#define f_ 185
#define g 196
#define g_ 207
#define a 220
#define a_ 233
#define h 246

#define c2 261
#define d2 293
#define e2 329

//длительности
#define dl1 1000
#define dl2 500
#define dl4 368
#define dl45 184
#define dl8 184

//мелодии
const uint16_t melody[2][6] = {
  {250, 280, 250, 280, 340},
  {100, 100, 100, 100, 120}
}; //вес 2*6*2 = 24 байт

const uint16_t menu_melody_P[2][88] PROGMEM = {
  {c, e, f, a,  
  d, e, f, a,  
  c, e, f, a,  
  d, e, f, a,  
  f, e, d, e,  
  d, e, d, 0, d, 0, 
  e, 0, e, 0, f, 0, f, 0, 
  a, 0, a, 0, d, 0, d, 0,  
  e, 0, e, 0, f, 0, f, 0,  
  a, 0, a, 0, e, 0, e, 0,  
  e, 0, e, 0, f, 0, f, 0,  
  a, 0, a, 0, e, 0, e, 0, e, e, e, e, e, e, e, e, e, e, e, e},
  {dl4, dl4, dl4, dl4,
  dl4, dl4, dl4, dl4,
  dl4, dl4, dl4, dl4,
  dl4, dl4, dl4, dl4,
  dl4, dl4, dl4, dl4,
  dl4, dl4, dl8, dl8, dl8, dl8,
  dl8, dl8, dl8, dl8, dl8, dl8, dl8, dl8,
  dl8, dl8, dl8, dl8, dl8, dl8, dl8, dl8,
  dl8, dl8, dl8, dl8, dl8, dl8, dl8, dl8,
  dl8, dl8, dl8, dl8, dl8, dl8, dl8, dl8,
  dl8, dl8, dl8, dl8, dl8, dl8, dl8, dl8,
  dl8, dl8, dl8, dl8, dl8, dl8, dl8, dl8, dl8, dl8, dl8, dl8, dl8, dl8, dl8, dl8, dl8, dl8, dl8, dl8}
}; //вес 2*88*2 = 352 байт

const uint16_t racing_melody_P[2][130] PROGMEM = {
  {h, f, h, f, h, f, h, f,  
  h, g, h, g, h, g, h, g,  
  h, a, h, a, h, a, h, a, 
  h, g, h, g, h, g, 
  h, f, h, f, h, f, h, f,  
  h, g, h, g, h, g, h, g,  
  h, a, h, a, h, a, h, a, 
  c2, a, c2, a, c2, a, 
  d2, h, d2, h, d2, h, d2, h, 
  e2, c2, e2, c2, e2, c2, e2, c2, 
  d2, h, d2, h, 
  c2, a, c2, a, 
  h, a, h, a, h, a, 
  c2, a, c2, a, c2, a, 
  d2, h, d2, h, d2, h, d2, h, 
  e2, c2, e2, c2, e2, c2, e2, c2, 
  d2, h, d2, h, 
  c2, a, c2, a, 
  h, a, h, a, h, a, 
  h, g},
  {dl45, dl45, dl45, dl45, dl45, dl45, dl45, dl45,
  dl45, dl45, dl45, dl45, dl45, dl45, dl45, dl45,
  dl45, dl45, dl45, dl45, dl45, dl45, dl45, dl45,
  dl45, dl45, dl45, dl45, dl45, dl45,
  dl45, dl45, dl45, dl45, dl45, dl45, dl45, dl45,
  dl45, dl45, dl45, dl45, dl45, dl45, dl45, dl45,
  dl45, dl45, dl45, dl45, dl45, dl45, dl45, dl45,
  dl45, dl45, dl45, dl45, dl45, dl45,
  dl45, dl45, dl45, dl45, dl45, dl45, dl45, dl45,
  dl45, dl45, dl45, dl45, dl45, dl45, dl45, dl45,
  dl45, dl45, dl45, dl45,
  dl45, dl45, dl45, dl45,
  dl45, dl45, dl45, dl45, dl45, dl45,
  dl45, dl45, dl45, dl45, dl45, dl45,
  dl45, dl45, dl45, dl45, dl45, dl45, dl45, dl45,
  dl45, dl45, dl45, dl45, dl45, dl45, dl45, dl45,
  dl45, dl45, dl45, dl45,
  dl45, dl45, dl45, dl45,
  dl45, dl45, dl45, dl45, dl45, dl45,
  dl45, dl45}
}; //вес 2*130*2 = 520 байт

const uint16_t game_over_melody_P[2][12] PROGMEM = {
  {d, a, 
  d, f,
  d, a, 
  d, f, a, 
  f, d},
  {dl4, dl4,
  dl4, dl4,
  dl4, dl4,
  dl4, dl8, dl8,
  dl8, dl4+dl8}
}; //вес 2*12*2 = 48 байт

#endif
