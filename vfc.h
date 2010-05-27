#pragma once
#include <math.h>
#include "lighting.h"
#include "MyVector.h"

struct plane_t {
  float a;
  float b;
  float c;
  float d;
};
namespace vfc{
  extern plane_t planes[6];
  void extractPlanes();
  bool viewFrustumCull(plane_t vf_planes[], MyVector* obj); 
  bool viewFrustumCull(plane_t vf_planes[], GLfloat *position, GLfloat radius);
}