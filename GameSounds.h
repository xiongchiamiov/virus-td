#pragma once
//#define VTD_SOUND
#ifdef VTD_SOUND
#include "include/irrKlang.h"
using namespace irrklang;
#endif
#include "MyVector.h"

namespace gamesounds{
  void playSound(const char* filename, float x, float y, float z);

  void setListenerPosition(MyVector& camPos);
}

class GameSounds
{
public:
  GameSounds(void);
  ~GameSounds(void);
  void toggleMusic();
private:
#ifdef VTD_SOUND
  ISoundEngine* engine;
  ISound* music;
  //irrklang::
#endif
};
