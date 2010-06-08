#include "lighting.h"

namespace vtd_dl{
  extern GLuint lockL1DL;
  extern GLuint lockL2DL;
  extern GLuint lockL3DL;
  
  extern GLuint blkhatL1DL;
  extern GLuint blkhatL2DL;
  extern GLuint blkhatL3DL;
  
  extern GLuint forkbL1DL;
  extern GLuint forkbL2DL;
  extern GLuint forkbL3DL;
  
  extern GLuint forkbForkL1DL;
  extern GLuint forkbForkL2DL;
  extern GLuint forkbForkL3DL;

  extern GLuint virusL1DL;
  extern GLuint virusL2DL;
  extern GLuint virusL3DL;

  extern GLuint wormL1DL;
  extern GLuint wormL2DL;
  extern GLuint wormL3DL;
  
  extern GLuint backtrackLWDL;
  extern GLuint backtrackRWDL;
  extern GLuint backtrackDL;
  
  extern GLuint teslaDL;
  extern GLuint fanDL;
  extern GLuint shieldDL;
  extern GLuint turretDL;
  extern GLuint trojanDL;
  extern GLuint bearDL;
  extern GLuint rootDL;
};

void drawLock(int tesallation);

void drawBlackHat(int tesallation);

void drawForkBombDLAnimated(double speed, int LoD);
void drawForkBombFork(int tesallation);
void drawForkBomb(int tesallation);

void drawVirusDLAnimated(double speed, int LoD);
void drawVirus(int tesallation);

void drawWormDLAnimated(double speed, int LoD);
void drawWorm(int tesallation);

void drawBackTrackDLAnimated(double speed);
void drawBackTrack();
void drawBackTrackLeftWing();
void drawBackTrackRightWing();

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
void drawEar();
void drawBearCore();
void drawBearDLAnimated(double rotation);

void drawRootDir();

void drawPhish();
void composeDisplayLists();
