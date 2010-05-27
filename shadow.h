#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>      
//#include <GL/glut.h> 
#include "models.h"
#ifndef M_PI
#define M_PI 3.14159265
#endif

/* Variable controlling various rendering modes. */
static int stencilShadow = 1, offsetShadow = 1;
static int renderShadow = 1;
static int forceExtension = 0;

enum {M_NONE, M_MOTION, M_LIGHT, M_TEXTURE, M_SHADOWS, M_REFLECTION, M_DINOSAUR,
	  M_STENCIL_REFLECTION, M_STENCIL_SHADOW, M_OFFSET_SHADOW,
	  M_POSITIONAL, M_DIRECTIONAL, M_PERFORMANCE};
enum {X, Y, Z, W};
enum {A, B, C, D};
enum {MISSING, EXTENSION, ONE_DOT_ONE};

static GLfloat floorPlane[4];
static GLfloat floorShadow[4][4];
static GLfloat floorVertices[4][3] = 
{
  { -20.0, 0.0, 20.0 },
  { 20.0, 0.0, 20.0 },
  { 20.0, 0.0, -20.0 },
  { -20.0, 0.0, -20.0 },
};

static GLfloat light_Position[4] = {1.5, 2.5, 1.5, 1.0};


void shadowMatrix(GLfloat shadowMat[4][4],GLfloat groundplane[4],GLfloat lightpos[4]);
static int supportsOneDotOne(void);
void draw_shadow(int shad);
void findPlane(GLfloat plane[4],GLfloat v0[3], GLfloat v1[3], GLfloat v2[3]);