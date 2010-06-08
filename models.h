#include "lighting.h"

namespace vtd_dl{
  extern GLuint lockDL;
  extern GLuint blkhatDL;
  extern GLuint virusDL;
  extern GLuint forkbDL;
  extern GLuint wormDL;
  extern GLuint worm2DL;
  extern GLuint worm3DL;
  extern GLuint worm4DL;
  extern GLuint worm5DL;
  extern GLuint worm6DL;
  extern GLuint backtrackDL;
  extern GLuint teslaDL;
  extern GLuint fanDL;
  extern GLuint shieldDL;
  extern GLuint turretDL;
  extern GLuint trojanDL;
  extern GLuint bearDL;
  extern GLuint rootDL;
};

void drawLock();
void drawBlackHat();

void drawForkBombFork();
void drawForkBombDLAnimated(double speed);
void drawForkBomb();

void drawVirusDLAnimated(double speed);
void drawVirus();

void drawWormDLAnimated(double speed);
void drawWorm();

void drawBackTrack();
void drawTeslaCoil();

/* All functions needed for CPU Fan model*/
/* Places parts of the fan model in a display list and animates the rest outside. */
void drawFanDLAnimated(double speed); /* Use this to draw Fan. The three below are support functions */
void drawCPUFan();
void animateCPUFan(int tesallation, int speed);
void drawCPUFanBase();

void drawShield();
void drawShieldBase(int set);

void drawTurretDLAnimated(double speed);
void drawTurret();
void drawMemBase();
void drawMemStick();

void drawLeg(int tes);
void drawWheelBase(int tes);
void drawTrojan();


void drawBearLeftArm();
void drawBearRightArm();
void drawBearLeftLeg();
void drawBearRightLeg();
void drawBearDLAnimated(double rotation);

void drawRootDir();

void drawPhish();
void composeDisplayLists();
