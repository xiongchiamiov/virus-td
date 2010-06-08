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
  
  extern GLuint backtrackL1LWDL;
  extern GLuint backtrackL2LWDL;
  extern GLuint backtrackL3LWDL;
  extern GLuint backtrackL1RWDL;
  extern GLuint backtrackL2RWDL;
  extern GLuint backtrackL3RWDL;
  extern GLuint backtrackL1DL;
  extern GLuint backtrackL2DL;
  extern GLuint backtrackL3DL;
  
  extern GLuint teslaL1DL;
  extern GLuint teslaL2DL;
  extern GLuint teslaL3DL;
  
  extern GLuint fanL1DL;
  extern GLuint fanL2DL;
  extern GLuint fanL3DL;
  
  extern GLuint shieldDL;

  extern GLuint turretDL;
  extern GLuint turretBaseDL;

  extern GLuint trojanL1DL;
  extern GLuint trojanL2DL;
  extern GLuint trojanL3DL;
  
  extern GLuint bearL1DL;
  extern GLuint bearL2DL;
  extern GLuint bearL3DL;
  
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

void drawBackTrackDLAnimated(double speed, int LoD);
void drawBackTrack(int tesallation);
void drawBackTrackLeftWing(int tesallation);
void drawBackTrackRightWing(int tesallation);

void drawTeslaCoil(int tesallation);

/* All functions needed for CPU Fan model*/
/* Places parts of the fan model in a display list and animates the rest outside. */
void drawFanDLAnimated(double speed, int LoD); /* Use this to draw Fan. The three below are support functions */
void drawCPUFan(int tesallation);
void animateCPUFan(int tesallation, int speed);
void drawCPUFanBase();

void drawShield();
void drawShieldBase(int set);

void drawTurretDLAnimated(double speed);
void drawTurret();
void drawMemBase();
void drawMemStick();

void drawLeg(int tesallation);
void drawWheelBase(int tesallation);
void drawTrojan();


void drawBearLeftArm(int tesallation);
void drawBearRightArm(int tesallation);
void drawBearLeftLeg(int tesallation);
void drawBearRightLeg(int tesallation);
void drawEar(int tesallation);
void drawBearCore(int tesallation);
void drawBearDLAnimated(double rotation, int LoD);

void drawRootDir();

void drawPhish(int tesallation);
void composeDisplayLists();
