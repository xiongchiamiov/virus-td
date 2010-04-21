#pragma once
#ifndef LIGHTING
#include <gl/glut.h>
#define LIGHTING
////light position
//GLfloat light_pos[4] = {1.0, 1.0, 1.5, 1.0};
////light color (ambiant, diffuse and specular)
//GLfloat light_amb[4] = {0.6, 0.6, 0.6, 1.0};
//GLfloat light_diff[4] = {0.6, 0.6, 0.6, 1.0};
//GLfloat light_spec[4] = {0.8, 0.8, 0.8, 1.0};

//Material Properties
typedef struct materialStruct {
  GLfloat ambient[4];
  GLfloat diffuse[4];
  GLfloat specular[4];
  GLfloat shininess[1];
} materialStruct;

//sets up a specific material
void setMaterial(materialStruct materials);
#endif