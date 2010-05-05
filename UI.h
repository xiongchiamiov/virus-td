#pragma once
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
//#include <png.h>
#include <stdio.h>
#include <string.h>
#include "lighting.h"
#include "MyVector.h"
#include "GameObject.h"
#include <vector>
#include "textures.h"
 
void initializeUI(void);
void renderUI(int w, int h, GLuint mode);
void mouseClick(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void setOrthographicProjection(int w, int h);
void resetPerspectiveProjection();
void drawMouseBox(bool click);
void drawPanel(int w, int h);
void drawInfoPanel(GLfloat x, GLfloat y, GLfloat GW, GLfloat GH, int buttonNumber);
void startPicking(int cursorX, int cursorY, GLuint buffer[], int bufferSize);
void stopPicking(GLuint buffer[]);
void processHits(GLint hits, GLuint buffer[]);
int determineClickedButton(int mouseX, int mouseY);
void drawRectangle(float xp, float yp, float w, float h, GLuint texture);
void renderBitmapString(float x, float y, void *font,char *string);
int getBitmapStringWidth(void *font,char *string);
float p2w_y(int y);
float p2w_x(int x);
//void readPNG(file)

class Button {
   private:
      int buttonNumber;
      GLfloat color[3];
      GameObject * gameObj;
   public:
      Button(int bNum, GLfloat bColor[3], GameObject * obj);
      ~Button(void);
      void drawButton(int width, int height);
      int getButtonNumber();
      void setButtonNumer(int num);
      void setButtonColor(GLfloat color[3]);
      GameObject * getObject();
      void setObject(GameObject * gObj);
};

