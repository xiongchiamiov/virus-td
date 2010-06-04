#pragma once
#include "constants.h"
#include "MyVector.h"
#include "GameSounds.h"
#include <map>

namespace vtd_cam{
  extern const float CAM_SPD;
  extern const float ROT_SPD;
}
namespace controls{
  extern std::map<char, bool> keyMap;
  extern const char FOREWARD;
  extern const char BACKWARD;
  extern const char LEFT;
  extern const char RIGHT;
  extern const char ZOOM_IN;
  extern const char ZOOM_OUT;
}

class Camera
{
public:
  Camera(void);
  ~Camera(void);
  void moveForward();
  void moveBackward();
  void moveLeft();
  void moveRight();
  void zoomIn();
  void zoomOut();
  void rotateUp();
  void rotateDown();
  void rotateLeft();
  void rotateRight();
  inline void setListenerPos(){ gamesounds::setListenerPosition(cam);}
  inline float getCamX(){return cam.getX();}
  inline float getCamY(){return cam.getY();}
  inline float getCamZ(){return cam.getZ();}
  inline float getLookAtX(){return cam.getX() + cam.getI();}
  inline float getLookAtY(){return cam.getY() + cam.getJ();}
  inline float getLookAtZ(){return cam.getZ() + cam.getK();}
private:
  MyVector cam;
  MyVector u;
  MyVector v;
  MyVector w;
};
