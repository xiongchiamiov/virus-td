#include "GameSounds.h"
#include <string>

using namespace std;

namespace gamesounds{

  unsigned int sound_count = 0;
#ifdef VTD_SOUND
  ISoundEngine* eng;
#endif
  //Sound filenames
  //Music
  const int MAX_TRACKS = 3;
  const string music_sound = "media/sounds/Space\ Fighter\ Loop.mp3";
  char* music_files[] = {"media/sounds/Space\ Fighter\ Loop.mp3",
                         "media/sounds/Shiny\ Tech2.mp3",
                         "media/sounds/In\ A\ Heartbeat.mp3"};
  int current_track;
  //Towers
  const char* basic_t_sound;
  const char* fast_t_sound;
  const char* freeze_t_sound;
  const char* slow_t_sound;
  const char* trap_t_sound;
  //Units
  const char* basic_u_sound;
  const char* fast_u_sound;
  const char* strong_u_sound;
  const char* strong2_u_sound;
  const char* strong3_u_sound;

  //
  
}

using namespace gamesounds;

GameSounds::GameSounds(void)
{
#ifdef VTD_SOUND
  if(sound_count <= 0){
    eng = engine = createIrrKlangDevice();
    if(engine)
      music = engine->play2D(music_files[0], false, true);
    if(music)
      music->setVolume(0.5);
  } else {
    engine = eng;
  }
  ++sound_count;
#endif
}

GameSounds::~GameSounds(void)
{
#ifdef VTD_SOUND
  if(sound_count == 1){
    eng->drop();
  } 
  --sound_count;
#endif
}

void GameSounds::toggleMusic(){
#ifdef VTD_SOUND
  if(music && music->getIsPaused()){
    music->setIsPaused(false);
  } else if(music){
    music->setIsPaused();
  }
#endif
}

void GameSounds::checkForEnd(){
#ifdef VTD_SOUND
  if(music && music->isFinished()){
    current_track = (current_track + 1)%MAX_TRACKS;
    music = engine->play2D(music_files[current_track], false, true);
    music ->setIsPaused(false);
    music->setVolume(0.5);
  }
#endif
}

namespace gamesounds{
  void playSound(const char* filename, float x, float y, float z){
#ifdef VTD_SOUND
    vec3df pos(x, y, z);
    eng->play3D(filename, pos);
#endif
  }

  void setListenerPosition(MyVector& camPos){
#ifdef VTD_SOUND
    vec3df pos(camPos.getX(), camPos.getY(), camPos.getZ());
    vec3df dir(camPos.getI(), camPos.getJ(), camPos.getK());
    eng->setListenerPosition(pos, dir);
#endif
  }
}
