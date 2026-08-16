#ifndef SAGT_h
#define SAGT_h
//подключение библиотек движка
#ifdef INCOMPLETE_SET

#ifdef MUSIC
#include <Music/SAGT_Music.h>
#endif

#ifdef BUTTONS
#include <Buttons/SAGT_Buttons.h>
#endif

#ifdef PLAYER
#include <Player/SAGT_Player.h>
#endif

#ifdef NPC
#include <NPC/SAGT_NPC.h>
#endif

#ifdef RENDER
#include <Render/SAGT_Render.h>
#endif

#else
#include <Music/SAGT_Music.h>
#include <Buttons/SAGT_Buttons.h>
#include <Player/SAGT_Player.h>
#include <NPC/SAGT_NPC.h>
#include <Render/SAGT_Render.h>
#endif

#endif
