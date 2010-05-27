#pragma once
#ifndef LIGHTING
#include <stdlib.h>
#ifdef __unix__
     #include <GL/glut.h>
 #endif

 #ifdef __APPLE__
     #include "GLUT/glut.h"
 #endif

 #ifdef _WIN32
     #include <gl/glut.h>
 #endif
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

extern materialStruct BlueFlat;
extern materialStruct RedFlat;
extern materialStruct GreenShiny;
extern materialStruct Metal;
extern materialStruct Exp;
extern materialStruct Exp2;
extern materialStruct Grey;
extern materialStruct Black;
extern materialStruct Teal;
extern materialStruct Purple;
extern materialStruct Fuschia;
extern materialStruct FieryOrange;
extern materialStruct White;
extern materialStruct PureRed;
extern materialStruct PureBlue;
extern materialStruct Brown;
extern materialStruct ShinyMetal;
extern materialStruct DarkGrey;
extern materialStruct DarkDarkGrey;
extern materialStruct Yellow;
extern materialStruct Grid;
extern materialStruct EnemyGrid;
extern materialStruct PlayerGrid;

//sets up a specific material
void setMaterial(materialStruct materials);
#endif