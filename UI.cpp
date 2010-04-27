#include "UI.h"
#include "Player.h"

extern MyVector camera, newCam;
extern int GH, GW;
extern std::vector<Button *> buttons;
extern bool clicked;
GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates
extern int tlx, tly;
extern Player p1;
int test = 0;

Button::Button(int bNum, materialStruct bColor, GameObject * obj) {
   buttonNumber = bNum;
   buttonColor = bColor;
   gameObj = obj;
}

Button::~Button(void) {
}

void Button::drawButton(int width, int height) {
   char * num;

   setMaterial(buttonColor);
   drawRectangle(0, 0, width, height);
}

int Button::getButtonNumber() {
   return buttonNumber;
}
     
void Button::setButtonNumer(int num) {
   buttonNumber = num;
}

void Button::setButtonColor(materialStruct color) {
   buttonColor = color;
}

GameObject * Button::getObject() {
   return gameObj;
}

void Button::setObject(GameObject * gObj){
   gameObj = gObj;
}


void renderUI(int w, int h, GLuint mode)
{
   int bNumber = 0;

	setOrthographicProjection(w, h);
	glPushMatrix();
	glLoadIdentity();
   
   // Draws left Panel + 9 Buttons
   glPushMatrix();
   setMaterial(Black);

   drawPanel(200, 200);
   for (int i = 0; i < 3; i++) {
      if (i == 0) {
         glTranslatef(0, 5, 0.01);
      } else {
         glTranslatef(0, 65, 0);
      }

      glPushMatrix();
      glTranslatef(5, 0, 0);
      buttons.at(bNumber)->drawButton(60, 60);
      bNumber++;
      glTranslatef(65, 0, 0);
      buttons.at(bNumber)->drawButton(60, 60);
      bNumber++;
      glTranslatef(65, 0, 0);
      buttons.at(bNumber)->drawButton(60, 60);
      bNumber++;
      glPopMatrix();
   }
   glPopMatrix();
   
   // Draws right panel + 9 buttons
   glPushMatrix();
   setMaterial(Black);
   glTranslatef(w - 200, 0, 0);
   drawPanel(200, 200);
   glTranslatef(140, 0, 0);
   setMaterial(Teal);
   for (int i = 0; i < 3; i++) {
      if (i == 0) {
         glTranslatef(0, 5, 0.01);
      } else {
         glTranslatef(0, 65, 0);
      }

      glPushMatrix();
      glTranslatef(-5, 0, 0);
      buttons.at(bNumber)->drawButton(60, 60);
      bNumber++;
      glTranslatef(-65, 0, 0);
      buttons.at(bNumber)->drawButton(60, 60);
      bNumber++;
      glTranslatef(-65, 0, 0);
      buttons.at(bNumber)->drawButton(60, 60);
      bNumber++;
      glPopMatrix();
   }
   glPopMatrix();

   glPushMatrix();
   glLoadIdentity();
     setMaterial(Black);
//   sprintf(timeRemainingString, "Time Remaining: %d", timeRemaining);
 //  sprintf(currencyString, "Objects Remaining: %d", currency);
   glPushMatrix();
   renderBitmapString(1.0 * GW / 4.0, GH - 25, GLUT_BITMAP_TIMES_ROMAN_24 , "Time until next wave:");
   glPopMatrix();
   glPushMatrix();
   renderBitmapString(1.0 * GW / 4.0, 20.0, GLUT_BITMAP_TIMES_ROMAN_24 , "Currency:");
   glPopMatrix();
   glPopMatrix();

	glPopMatrix();
	resetPerspectiveProjection();
}

void setOrthographicProjection(int w, int h) {
	// switch to projection mode
	glMatrixMode(GL_PROJECTION);
	// save previous matrix which contains the 
	//settings for the perspective projection
	glPushMatrix();
	// reset matrix
	glLoadIdentity();
	// set a 2D orthographic projection
	glOrtho(0, w, 0, h, -5, 5);
	// invert the y axis, down is positive
//	glScalef(1, -1, 1);
	// mover the origin from the bottom left corner
	// to the upper left corner
//	glTranslatef(0, -h, 0);
	glMatrixMode(GL_MODELVIEW);
}

void resetPerspectiveProjection() {
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

/*
 * param xp: x start point 
 * param yp: y start point 
 * param w: width
 * param h: height
 */
void drawRectangle(float xp, float yp, float w, float h)
{
	//NOTE: There's quite a bit of commented out code right now.
	//      All of that is for when I get the loading of images
	//      working. Then those commands will actually texture the
	//      rectangle
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_BLEND);

	//glBindTexture(GL_TEXTURE_2D, texture[0]);
   glMatrixMode(GL_MODELVIEW);
	glBegin(GL_QUADS);  //tells OpenGL that we're going to start drawing triangles

	//glTexCoord2f(0.0f, 0.0f);
	glVertex3f(xp,yp, 0.0); 

	//glTexCoord2f(1.0f, 0.0f);
	glVertex3f(xp+w,yp,0.0); 

	//glTexCoord2f(1.0f, 1.0f);
	glVertex3f(xp+w,yp+h,0.0); 

	//glTexCoord2f(0.0f, 1.0f);
	glVertex3f(xp,yp+h,0.0); 
	glEnd();                //tells OpenGL that we've finished drawing
	//glDisable(GL_BLEND);
}

void drawMouseBox(bool click) {
   if (click) {
      double xForm, yForm;
      glPushMatrix();
      setMaterial(Teal);
      xForm = ((int)worldX + camera.getX() - newCam.getX());
      yForm = ((int)worldZ + camera.getZ() - newCam.getZ() + 0.5);
      // tly and tlx increment in 0.5 not 1
      tlx = xForm * 2 + 7;
      tly = ((int)worldZ + camera.getZ() - newCam.getZ()) * 2 + 16;
      glTranslatef(xForm, (int)worldY, yForm);
      if (test <= 17 && test >= 12) {
         buttons.at(test)->getObject()->draw();
      }
      glPopMatrix();
   }
}

void drawPanel(int w, int h) {
	drawRectangle(0, 0, w, h);
}

void mouseClick(int button, int state, int x, int y) {
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    //  int BUFSIZE = 512;
   //   GLuint selectBuf[BUFSIZE];

   /* gl selection code */
   //   startPicking(x, y, selectBuf, BUFSIZE);
   //   gluLookAt(camera.getX(), camera.getY(), camera.getZ(), 
   //         camera.getI(), camera.getJ(), camera.getK(),
  //          0.0, 1.0, 0.0);
  //    renderUI(GW, GH, GL_SELECT);
  //    stopPicking(selectBuf);

/* !!!!!! remember to invert y with (GH - y) so that it is on the bottom instead of the top */
      fprintf(stderr, "click: x: %d y: %d\n", x, GH- y);

      if (clicked == true) {
         p1.placeTower(tlx, tly, test);
         clicked = !clicked;
      }

      test = determineClickedButton(x, GH - y);

      if (test != -1) {
         buttons.at(test)->setButtonColor(White);
      }
   }
   
   if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
      if (test != -1) {
         buttons.at(test)->setButtonColor(Teal);
         clicked = !clicked;
      }

   }
   
   glutPostRedisplay();
}

void mouseMotion(int x, int y) {
   if (clicked) {
	     GLint viewport[4]; //var to hold the viewport info
        GLdouble modelview[16]; //var to hold the modelview info
        GLdouble projection[16]; //var to hold the projection matrix info
        GLdouble nearv[3], farv[3]; //variables to hold screen x,y,z coordinates
       
        glGetDoublev( GL_MODELVIEW_MATRIX, modelview ); //get the modelview info
        glGetDoublev( GL_PROJECTION_MATRIX, projection ); //get the projection matrix info
        glGetIntegerv( GL_VIEWPORT, viewport ); //get the viewport info
	
	     //get the world coordinates from the screen coordinates
        // Everything below may break if window or camera changes direction
        gluUnProject( x, viewport[1] + viewport[3] - y, 0.95, modelview, projection, viewport, &nearv[0], &nearv[1], &nearv[2]);
        gluUnProject( x, viewport[1] + viewport[3] - y, 0.976, modelview, projection, viewport, &farv[0], &farv[1], &farv[2]);

//        GLfloat xt = (nearv[0] - z) / (nearv[0] - farv[0]);
  //              yt = (nearv[1] - z) / (nearv[1] - farv[1]);

            //    worldX = nearv[0] + (farv[0] - nearv[0]) * ((float)x / (float)GW),
            //    worldZ = nearv[1] + (farv[1] - nearv[1]) * ((float)y / (float)GH);
         float xTemp, yTemp;
         
         xTemp = x - (GW / 2);
         yTemp = (GH - y) - (GH / 3.2);  
            if (xTemp <= (GW / 2.5) && xTemp >= 0) {
               xTemp = (GW / 2.5);
            }
            
            if (xTemp >= -(GW / 2) && xTemp < 0) {
               xTemp = -(GW / 2);
            }
         
            if (yTemp <= (GH / 3.2) && yTemp >= 0) {
               yTemp = (GH / 3.2);
            }
            
            if (yTemp >= -(GH / 3.4) && yTemp < 0) {
               yTemp = -(GH / 3.4);
            }

            if (xTemp >= 0) {
                worldX = (nearv[0] * ((float)xTemp / ((float)GW / 2)));
            } else {
                worldX = -(nearv[0] * ((float)xTemp / ((float)GW / 2)));
            }
            
            if (yTemp >= 0) {
                worldZ = -(farv[1] * ((float)yTemp / ((float)GH / 2)));
            } else {
                worldZ = (farv[1] * ((float)yTemp / ((float)GH / 2)));
            }

            worldY = 0;
   //    fprintf(stderr, "xTemp: %f yTemp: %f   %.2lf, %.2lf\n", xTemp, yTemp, worldX, worldZ);
   }
   
   glutPostRedisplay();
}

void startPicking(int cursorX, int cursorY, GLuint buffer[], int buffSize) {
	GLint viewport[4];

	glGetIntegerv(GL_VIEWPORT,viewport);
   glSelectBuffer(buffSize, buffer);

	(void) glRenderMode(GL_SELECT);
	glInitNames();
   glPushName(0);

	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPickMatrix((GLdouble)cursorX, (GLdouble)viewport[3]-cursorY, 0.5, 0.5, viewport);
   gluPerspective(45.0, 1.0 * viewport[2] / viewport[3], 1.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void stopPicking(GLuint buffer[]) {
	int hits;
	GLint viewport[4];

	glGetIntegerv(GL_VIEWPORT,viewport);
	// restoring the original projection matrix
   glPopMatrix();
	glFlush();
	// returning to normal rendering mode
	hits = glRenderMode(GL_RENDER);
	// if there are hits process them
   processHits(hits, buffer);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0, 1.0 * viewport[2] / viewport[3], 1.0, 100.0);
}

void processHits(GLint hits, GLuint buffer[])
{
   // this function goes through the selection hit list of object names

   int i, j;
   GLuint *ptr, *closestPtr;
   GLfloat closestFront = 0.0;
   

   printf("hits = %d\n", hits);
   if(hits==0) printf("You have not selected any object.\n");
   ptr = (GLuint *) buffer;
   for(i=0; i<hits; i++) {
      ptr++;
      printf("  front at %g\n",(float) *ptr/0x7fffffff);
      
      if (closestFront == 0.0 || ((float) *ptr/0x7fffffff < closestFront)) {
         closestFront = (float) *ptr/0x7fffffff;
         closestPtr = ptr+2;
      }
      
      ptr++;
      printf("  back at = %g\n",(float) *ptr/0x7fffffff);
      ptr++;

      if(ptr) {
         printf("You have picked the %d.\n", *ptr);
      }
      
      ptr++;
   }

   printf("**************************************************************\n");
}

/* 
 * This function takes the window coordinates of a mouse click
 * and determiens which GUI button was clicked. 
 * (This function may break if window size is changed)
 *
 * @return the button number (0 - 17) or -1 if there is no button.
 */
int determineClickedButton(int mouseX, int mouseY) {
   int buttonNum = 0;

   /* Option 1: button number layout
      6 7 8         17 16 15
      3 4 5         14 13 12
      0 1 2         11 10 9
   */
   for (int i = 65; i <= 195; i+=65) {
      for (int j = 65; j <= 195; j+=65) {
         if (mouseY <= i && mouseX <= j) {
            return buttonNum;
         } else {
            buttonNum++;
         }

      }
   }

   for (int i = 65; i <= 195; i+=65) {
      for (int j = GW - 65; j >= GW - 195; j-=65) {
         if (mouseY <= i && mouseX >= j) {
            return buttonNum;
         } else {
            buttonNum++;
         }

      }
   }
   
   return -1;
}

void renderBitmapString(float x, float y, void *font,char *string) {
  
  char *c;
  glRasterPos2f(x, y);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}

float p2w_x(int x){
   float scale = ((float)2 / GH);
   float transform = (-1 * ((float)GW / GH)) + (1 / (float)GH);
   return ((scale * x) + transform);
}

float p2w_y(int y){
   float scale = ((float) 2 / GH);
   float transform = (1 / (float) GH) + (-1);
   return ((y * scale) + transform);
}
