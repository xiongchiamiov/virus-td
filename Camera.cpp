#include "Camera.h"
namespace vtd_cam{
  const float CAM_SPD = 0.0025;
  const float ROT_SPD = 0.0025;
}
namespace controls{
  const char FOREWARD = 'w';
  const char BACKWARD = 's';
  const char LEFT = 'a';
  const char RIGHT = 'd';
  const char ZOOM_IN = 'z';
  const char ZOOM_OUT = 'x';
}
using namespace vtd_cam;

Camera::Camera(void):
cam(0.0, 0.0, 0.0, 0.0, 10.0, 10.0),
u(-1.0, 0.0, 0.0),v(0.0, 1.0, 0.0), w(0.0, 0.0, -1.0)
{
}

Camera::~Camera(void)
{
}

void Camera::moveForward(){
  cam.setVector(cam.getI() + CAM_SPD*w.getI(),
                cam.getJ() + CAM_SPD*w.getJ(),
                cam.getK() + CAM_SPD*w.getK());
  cam.setPosition(cam.getX() + CAM_SPD*w.getI(),
                  cam.getY() + CAM_SPD*w.getJ(),
                  cam.getZ() + CAM_SPD*w.getK());
}

void Camera::moveBackward(){
  cam.setVector(cam.getI() - CAM_SPD*w.getI(),
                cam.getJ() - CAM_SPD*w.getJ(),
                cam.getK() - CAM_SPD*w.getK());
  cam.setPosition(cam.getX() - CAM_SPD*w.getI(),
                  cam.getY() - CAM_SPD*w.getJ(),
                  cam.getZ() - CAM_SPD*w.getK());
}

void Camera::moveLeft(){
  cam.setVector(cam.getI() + CAM_SPD*u.getI(),
                cam.getJ() + CAM_SPD*u.getJ(),
                cam.getK() + CAM_SPD*u.getK());
  cam.setPosition(cam.getX() + CAM_SPD*u.getI(),
                  cam.getY() + CAM_SPD*u.getJ(),
                  cam.getZ() + CAM_SPD*u.getK());
}

void Camera::moveRight(){
  cam.setVector(cam.getI() - CAM_SPD*u.getI(),
                cam.getJ() - CAM_SPD*u.getJ(),
                cam.getK() - CAM_SPD*u.getK());
  cam.setPosition(cam.getX() - CAM_SPD*u.getI(),
                  cam.getY() - CAM_SPD*u.getJ(),
                  cam.getZ() - CAM_SPD*u.getK());
}

void Camera::rotateUp(){}

void Camera::rotateDown(){}

void Camera::rotateLeft(){}

void Camera::rotateRight(){}

/*switch(key){
    case 'w': case 'W':
      camera.setVector(camera.getI() + GRID_SIZE*2.0*w.getI(),
                       camera.getJ() + GRID_SIZE*2.0*w.getJ(),
                       camera.getK() + GRID_SIZE*2.0*w.getK());
      camera.setPosition(camera.getX() + GRID_SIZE*2.0*w.getI(),
                         camera.getY() + GRID_SIZE*2.0*w.getJ(),
                         camera.getZ() + GRID_SIZE*2.0*w.getK());
      break;
    case 'a': case 'A':
      camera.setVector(camera.getI() + GRID_SIZE*2.0*u.getI(),
                       camera.getJ() + GRID_SIZE*2.0*u.getJ(),
                       camera.getK() + GRID_SIZE*2.0*u.getK());
      camera.setPosition(camera.getX() + GRID_SIZE*2.0*u.getI(),
                         camera.getY() + GRID_SIZE*2.0*u.getJ(),
                         camera.getZ() + GRID_SIZE*2.0*u.getK());
      break;
    case 's': case 'S':
      camera.setVector(camera.getI() - GRID_SIZE*2.0*w.getI(),
                       camera.getJ() - GRID_SIZE*2.0*w.getJ(),
                       camera.getK() - GRID_SIZE*2.0*w.getK());
      camera.setPosition(camera.getX() - GRID_SIZE*2.0*w.getI(),
                         camera.getY() - GRID_SIZE*2.0*w.getJ(),
                         camera.getZ() - GRID_SIZE*2.0*w.getK());
      break;
    case 'd': case 'D':
      camera.setVector(camera.getI() - GRID_SIZE*2.0*u.getI(),
                       camera.getJ() - GRID_SIZE*2.0*u.getJ(),
                       camera.getK() - GRID_SIZE*2.0*u.getK());
      camera.setPosition(camera.getX() - GRID_SIZE*2.0*u.getI(),
                         camera.getY() - GRID_SIZE*2.0*u.getJ(),
                         camera.getZ() - GRID_SIZE*2.0*u.getK());
      break;
    case 't': case 'T':
      p1.placeTower(tlx, tly, 16);
      break;
    case 'r': case 'R':
      p1.destroyTower(tlx, tly);
      break;
  }*/