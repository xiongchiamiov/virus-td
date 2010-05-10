#include "lighting.h"

namespace vtd_dl{
  extern GLuint wormDL;
  extern GLuint backtrackDL;
  extern GLuint teslaDL;
  extern GLuint fanDL;
  extern GLuint shieldDL;
};

void drawWorm();
void drawBackTrack();
void drawTeslaCoil();
void drawCPUFan();

void drawShield();
void drawShieldBase(int set);

void composeDisplayLists();