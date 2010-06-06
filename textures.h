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
#include <stdio.h>
#pragma once
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;

typedef struct Image {
  unsigned long sizeX;
  unsigned long sizeY;
  char *data;
} Image;

typedef struct RGB {
  GLubyte r;
  GLubyte g; 
  GLubyte b;
} RGB;

//forward declaration of image loading and texture set-up code
int ImageLoad(char *filename, Image *image);
GLuint LoadTexture(char* image_file);
GLuint LoadMipMapTexture(char *image_file);