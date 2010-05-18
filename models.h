#include "lighting.h"

namespace vtd_dl{
  extern GLuint blkhatDL;
  extern GLuint virusDL;
  extern GLuint forkbDL;
  extern GLuint wormDL;
  extern GLuint backtrackDL;
  extern GLuint teslaDL;
  extern GLuint fanDL;
  extern GLuint shieldDL;
  extern GLuint turretDL;
};

void drawBlackHat();
void drawForkBomb();
void drawVirus();
void drawWorm();
void drawBackTrack();
void drawTeslaCoil();
void drawCPUFan();

void drawShield();
void drawShieldBase(int set);

void drawTurret();
void drawMemBase();
void drawMemStick();

void composeDisplayLists();
