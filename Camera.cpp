#include "Camera.h"
namespace vtd_cam{
  const float CAM_SPD = 0.15;
  const float ROT_SPD = 0.15;
  const float ZOOM_SPD = 0.01;
}
namespace controls{
  std::map<char, bool> keyMap;
  const char FOREWARD = 'w';
  const char BACKWARD = 's';
  const char LEFT = 'a';
  const char RIGHT = 'd';
  const char ZOOM_IN = 'z';
  const char ZOOM_OUT = 'x';
}
using namespace vtd_cam;

Camera::Camera(void):
cam(0.0, -10.0, -10.0, 0.0, 10.0, 10.0),
u(-1.0, 0.0, 0.0),v(0.0, 1.0, 0.0), w(0.0, 0.0, -1.0)
{
}

Camera::~Camera(void)
{
}

void Camera::moveForward(){
  cam.setPosition(cam.getX() + CAM_SPD*w.getI(),
                  cam.getY() + CAM_SPD*w.getJ(),
                  cam.getZ() + CAM_SPD*w.getK());
}

void Camera::moveBackward(){
  cam.setPosition(cam.getX() - CAM_SPD*w.getI(),
                  cam.getY() - CAM_SPD*w.getJ(),
                  cam.getZ() - CAM_SPD*w.getK());
}

void Camera::moveLeft(){
  cam.setPosition(cam.getX() + CAM_SPD*u.getI(),
                  cam.getY() + CAM_SPD*u.getJ(),
                  cam.getZ() + CAM_SPD*u.getK());
}

void Camera::moveRight(){
  cam.setPosition(cam.getX() - CAM_SPD*u.getI(),
                  cam.getY() - CAM_SPD*u.getJ(),
                  cam.getZ() - CAM_SPD*u.getK());
}

void Camera::zoomIn(){
  if(cam.getY() > 0){
    cam.setPosition(cam.getX() + ZOOM_SPD*cam.getI(),
                  cam.getY() + ZOOM_SPD*cam.getJ(),
                  cam.getZ() + ZOOM_SPD*cam.getK());
  }
}

void Camera::zoomOut(){
 cam.setPosition(cam.getX() - ZOOM_SPD*cam.getI(),
                  cam.getY() - ZOOM_SPD*cam.getJ(),
                  cam.getZ() - ZOOM_SPD*cam.getK());
}

void Camera::rotateUp(){
}

void Camera::rotateDown(){
}

void Camera::rotateLeft(){}

void Camera::rotateRight(){}