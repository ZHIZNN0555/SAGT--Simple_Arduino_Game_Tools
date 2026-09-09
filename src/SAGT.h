#ifndef SAGT_h
#define SAGT_h
//подключение библиотек движка
#ifdef INCOMPLETE_SET

#ifdef MUSIC
#include <Music/SAGT_Music.h>
#include <Music/SAGT_Music.cpp>
#endif

#ifdef BUTTONS
#include <Buttons/SAGT_Buttons.h>
#include <Buttons/SAGT_Buttons.cpp>
#endif

#ifdef PLAYER
#include <Player/SAGT_Player.h>
#include <Player/SAGT_Player.cpp>
#endif

#ifdef NPC
#include <NPC/SAGT_NPC.h>
#include <NPC/SAGT_NPC.cpp>
#endif

#ifdef RENDER
#include <Render/SAGT_Render.h>
#include <Render/SAGT_Render.cpp>
#endif

#else
#include <Music/SAGT_Music.h>
#include <Music/SAGT_Music.cpp>

#include <Buttons/SAGT_Buttons.h>
#include <Buttons/SAGT_Buttons.cpp>

#include <Player/SAGT_Player.h>
#include <Player/SAGT_Player.cpp>

#include <NPC/SAGT_NPC.h>
#include <NPC/SAGT_NPC.cpp>

#include <Render/SAGT_Render.h>
#include <Render/SAGT_Render.cpp>
#endif

#endif
