#include "vfc.h"

namespace vfc{
void getPlanes(float matrix[], plane_t planes[]){
  //Left
  planes[0].a = matrix[3] + matrix[0];
  planes[0].b = matrix[7] + matrix[4];
  planes[0].c = matrix[11] + matrix[8];
  planes[0].d = matrix[15] + matrix[12];
  //Right
  planes[1].a = matrix[3] - matrix[0];
  planes[1].b = matrix[7] - matrix[4];
  planes[1].c = matrix[11] - matrix[8];
  planes[1].d = matrix[15] - matrix[12];
  //Bottom
  planes[2].a = matrix[3] + matrix[1];
  planes[2].b = matrix[7] + matrix[5];
  planes[2].c = matrix[11] + matrix[9];
  planes[2].d = matrix[15] + matrix[13];
  //Top
  planes[3].a = matrix[3] - matrix[1];
  planes[3].b = matrix[7] - matrix[5];
  planes[3].c = matrix[11] - matrix[9];
  planes[3].d = matrix[15] - matrix[13];
  //Near
  planes[4].a = matrix[3] + matrix[2];
  planes[4].b = matrix[7] + matrix[6];
  planes[4].c = matrix[11] + matrix[10];
  planes[4].d = matrix[15] + matrix[14];
  //Far
  planes[5].a = matrix[3] - matrix[2];
  planes[5].b = matrix[7] - matrix[6];
  planes[5].c = matrix[11] - matrix[10];
  planes[5].d = matrix[15] - matrix[14];
  float mag;
  for(int i = 0; i < 6; i++){
    mag = sqrt(planes[i].a * planes[i].a + 
               planes[i].b * planes[i].b + 
               planes[i].c * planes[i].c);
    planes[i].a = planes[i].a/mag;
    planes[i].b = planes[i].b/mag;
    planes[i].c = planes[i].c/mag;
    planes[i].d = planes[i].d/mag;
  }
}
plane_t planes[6];
void extractPlanes(){
  GLfloat matrix[16], m[16], p[16];
  
  glGetFloatv(GL_PROJECTION_MATRIX, p);
  glGetFloatv(GL_MODELVIEW_MATRIX, m);
  //Get the viewspace matrix
  glPushMatrix();
	glLoadMatrixf(p);
	glMultMatrixf(m);
	glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
	glPopMatrix();
  getPlanes(matrix, planes);
}

float radius = 0.5;
float getPlaneDist(float x, float y, float z, plane_t plane){
  return x*plane.a + y*plane.b + z*plane.c + plane.d;
}

bool viewFrustumCull(plane_t vf_planes[], MyVector* obj){
  bool isDrawn;
  if(getPlaneDist(obj->getX(), obj->getY(), obj->getZ(), vf_planes[0]) < -radius ||
     getPlaneDist(obj->getX(), obj->getY(), obj->getZ(), vf_planes[1]) < -radius ||
     getPlaneDist(obj->getX(), obj->getY(), obj->getZ(), vf_planes[2]) < -radius ||
     getPlaneDist(obj->getX(), obj->getY(), obj->getZ(), vf_planes[3]) < -radius ||
     getPlaneDist(obj->getX(), obj->getY(), obj->getZ(), vf_planes[4]) < -radius ||
     getPlaneDist(obj->getX(), obj->getY(), obj->getZ(), vf_planes[5]) < -radius ){
    isDrawn = false;
  }
  else{
    isDrawn = true;
  }
  return isDrawn;
}

bool viewFrustumCull(plane_t vf_planes[], GLfloat *position, GLfloat radius){
  bool isDrawn;
  if(getPlaneDist(position[0], position[1], position[2], vf_planes[0]) < -radius ||
     getPlaneDist(position[0], position[1], position[2], vf_planes[1]) < -radius ||
     getPlaneDist(position[0], position[1], position[2], vf_planes[2]) < -radius ||
     getPlaneDist(position[0], position[1], position[2], vf_planes[3]) < -radius ||
     getPlaneDist(position[0], position[1], position[2], vf_planes[4]) < -radius ||
     getPlaneDist(position[0], position[1], position[2], vf_planes[5]) < -radius ){
    isDrawn = false;
  }
  else{
    isDrawn = true;
  }
  return isDrawn;
}

}