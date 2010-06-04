#pragma once
#define VTD_SOUND
#include "include/irrKlang.h"
#include "MyVector.h"
#pragma comment(lib, "C:\\Users\\Andy\\Documents\\Programs and Source Files\\Libraries\\irrKlang-1.3.0\\lib\\Win32-visualStudio\\irrKlang.lib")

using namespace irrklang;

namespace gamesounds{
  void playSound(const char* filename, float x, float y, float z);

  void setListenerPosition(MyVector& camPos);
}

class GameSounds
{
public:
  GameSounds(void);
  ~GameSounds(void);
  void playSound(const char* fileName, vec3df pos);
  void toggleMusic();
private:
#ifdef VTD_SOUND
  ISoundEngine* engine;
  ISound* music;
  //irrklang::
#endif
};
