#include "UI.h"
#include "Player.h"

#define info_font GLUT_BITMAP_HELVETICA_10
#define info_font_height 12
#define info_font_bold GLUT_BITMAP_HELVETICA_12
#define info_font_bold_height 14
const char tower_names[6][10] = {"Basic", "Fast","Freeze","Slow","Trap","Wall"};

extern MyVector camera, newCam;
extern int GH, GW;
extern std::vector<Button *> buttons;
extern bool clicked;
GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates
extern int tlx, tly, ulx, uly;
extern Player p1;
int curBtn = -1;
GLfloat mx,my;
int test = 0;
GLuint panel_tex;
GLuint button_tex[18];
GLuint info_tex[10];

Button::Button(int bNum, GLfloat bColor[3], GameObject * obj) {
   buttonNumber = bNum;
   color[0] = bColor[0];
   color[1] = bColor[1];
   color[2] = bColor[2];
   gameObj = obj;
}

Button::~Button(void) {
}

void Button::drawButton(int width, int height, GLuint bIcon) {
   glColor3f( color[0],color[1],color[2] );
   drawRectangle(0, 0, width, height, bIcon);
}

int Button::getButtonNumber() {
   return buttonNumber;
}
     
void Button::setButtonNumer(int num) {
   buttonNumber = num;
}

void Button::setButtonColor(GLfloat newColor[3]) {
   color[0] = newColor[0];
   color[1] = newColor[1];
   color[2] = newColor[2];
}

GameObject * Button::getObject() {
   return gameObj;
}

void Button::setObject(GameObject * gObj){
   gameObj = gObj;
}

void initializeUI()
{
	panel_tex = LoadTexture("GUI.bmp");
   // Unit Icons
	button_tex[0] = LoadTexture("Button.bmp");
	button_tex[1] = LoadTexture("Button.bmp");
	button_tex[2] = LoadTexture("Button.bmp");
	button_tex[3] = LoadTexture("Button.bmp");
	button_tex[4] = LoadTexture("Button.bmp");
	button_tex[5] = LoadTexture("Button.bmp");
	button_tex[6] = LoadTexture("Button.bmp");
    button_tex[7] = LoadTexture("Button.bmp");
	button_tex[8] = LoadTexture("Button.bmp");
   // Tower Icons
	button_tex[9] = LoadTexture("Button.bmp");
	button_tex[10] = LoadTexture("Button.bmp");
	button_tex[11] = LoadTexture("Button.bmp");
	button_tex[12] = LoadTexture("Tower6.bmp");
	button_tex[13] = LoadTexture("Tower5.bmp");
	button_tex[14] = LoadTexture("Tower4.bmp");
	button_tex[15] = LoadTexture("Tower3.bmp");
	button_tex[16] = LoadTexture("Tower2.bmp");
	button_tex[17] = LoadTexture("Tower1.bmp");
   //button_tex = LoadTexture("SecurityIcons1.bmp");
	info_tex[0] = LoadTexture("info_tlcorner.bmp");
	info_tex[1] = LoadTexture("info_trcorner.bmp");
	info_tex[2] = LoadTexture("info_brcorner.bmp");
	info_tex[3] = LoadTexture("info_blcorner.bmp");
	info_tex[4] = LoadTexture("info_tlcorner.bmp");
	info_tex[5] = LoadTexture("info_middle.bmp");
	info_tex[6] = LoadTexture("info_left.bmp");
	info_tex[7] = LoadTexture("info_right.bmp");
	info_tex[8] = LoadTexture("info_top.bmp");
	info_tex[9] = LoadTexture("info_bottom.bmp");
}

void renderUI(int w, int h, GLuint mode)
{
   int bNumber = 0;

	setOrthographicProjection(w, h);
	glPushMatrix();
	glLoadIdentity();
   
   // Draws left Panel + 9 Buttons
   glPushMatrix();
   glColor4f( 1.0, 1.0, 1.0, 1.0 );
	drawPanel(200, 200);

   for (int i = 0; i < 3; i++) {
      if (i == 0) {
         glTranslatef(0, 5, 0.5);
      } else {
         glTranslatef(0, 65, 0);
      }

      glPushMatrix();
      glTranslatef(5, 0, 0);
      buttons.at(bNumber)->drawButton(60, 60, button_tex[bNumber]);
      bNumber++;
      glTranslatef(65, 0, 0);
      buttons.at(bNumber)->drawButton(60, 60, button_tex[bNumber]);
      bNumber++;
      glTranslatef(65, 0, 0);
      buttons.at(bNumber)->drawButton(60, 60, button_tex[bNumber]);
      bNumber++;
      glPopMatrix();
   }
   glPopMatrix();
   
   // Draws right panel + 9 buttons
   glPushMatrix();
   //setMaterial(Black);
   glTranslatef(w - 200, 0, 0);
   glColor4f( 1.0, 1.0, 1.0, 1.0 );
   drawPanel(200, 200);
   glTranslatef(140, 0, 0);
   //setMaterial(Teal);
   for (int i = 0; i < 3; i++) {
      if (i == 0) {
         glTranslatef(0, 5, 0.01);
      } else {
         glTranslatef(0, 65, 0);
      }

      glPushMatrix();
      glTranslatef(-5, 0, 0);
      buttons.at(bNumber)->drawButton(60, 60, button_tex[bNumber]);
      bNumber++;
      glTranslatef(-65, 0, 0);
      buttons.at(bNumber)->drawButton(60, 60, button_tex[bNumber]);
      bNumber++;
      glTranslatef(-65, 0, 0);
      buttons.at(bNumber)->drawButton(60, 60, button_tex[bNumber]);
      bNumber++;
      glPopMatrix();
   }
   glPopMatrix();

   glPushMatrix();
   glLoadIdentity();
     setMaterial(Black);
//   sprintf(timeRemainingString, "Time Remaining: %d", timeRemaining);
 //  sprintf(currencyString, "Objects Remaining: %d", currency);

   renderBitmapString(1.0 * GW / 4.0, GH - 25, GLUT_BITMAP_TIMES_ROMAN_24 , "Time until next wave:");

   renderBitmapString(1.0 * GW / 4.0, 20.0, GLUT_BITMAP_TIMES_ROMAN_24 , "Currency:");

   if(curBtn != -1)
	drawInfoPanel(mx,my,GW,GH,curBtn);

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
void drawRectangle(float xp, float yp, float w, float h, GLuint texture)
{
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

	glBegin(GL_QUADS);
    glTexCoord2f(0,1);
    glVertex2f(xp,yp+h);
    glTexCoord2f(1,1);
    glVertex2f(xp+w,yp+h);
    glTexCoord2f(1,0);
    glVertex2f(xp+w,yp);
    glTexCoord2f(0,0);
    glVertex2f(xp,yp);
    glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
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
      ulx = tlx;
      uly = tly;
      glTranslatef(xForm, (int)worldY, yForm);
      if (test <= 17 && test >= 12/* 11 to 9 missing */) {
         // tower on cursor
         buttons.at(test)->getObject()->draw();
      } /*else if (test == 8 && test) {
         // unit on cursor
         buttons.at(test)->getObject()->draw();
      }*/
      glPopMatrix();
   }
}

void drawPanel(int w, int h) {
	drawRectangle(0, 0, w, h, panel_tex);
}

/*
info_tex[0] = LoadTexture("info_tlcorner.bmp");
info_tex[1] = LoadTexture("info_trcorner.bmp");
info_tex[2] = LoadTexture("info_brcorner.bmp");
info_tex[3] = LoadTexture("info_blcorner.bmp");
info_tex[4] = LoadTexture("info_tlcorner.bmp");
info_tex[5] = LoadTexture("info_middle.bmp");
info_tex[6] = LoadTexture("info_left.bmp");
info_tex[7] = LoadTexture("info_right.bmp");
info_tex[8] = LoadTexture("info_top.bmp");
info_tex[9] = LoadTexture("info_bottom.bmp");
*/
void drawInfoPanel(GLfloat x, GLfloat y, GLfloat GW, GLfloat GH, int buttonNumber)
{
	char name[80];
	const int sep = 12;
   /* Option 1: button number layout
      6 7 8         17 16 15
      3 4 5         14 13 12
      0 1 2         11 10 9
   */
	if(buttonNumber < 0 || buttonNumber > 17) {
		printf("Invalid button number in drawInfoPanel\n");
		return;
	}
	if(buttonNumber >= 12 && buttonNumber <= 17) {
		buttonNumber = 8 - (buttonNumber - 9);
		strcpy(name,getTowerName(buttonNumber));
		strcat(name," Tower");

		char desc[400];
		char cost[30] = "Cost: ";
		char damage[30] = "Damage: ";
		char speed[30] = "Speed : ";
		char num[10];
		strcpy(desc,getTowerDescription(buttonNumber));
		int len = 1;
		for(char* c = &desc[0]; *c != '\0'; c++) {
			if (*c == '\n')
				len++;
		}
		itoa(getTowerCost(buttonNumber),num,10);
		strcat(cost,num);
		itoa(getTowerDamage(buttonNumber),num,10);
		strcat(damage,num);
		itoa(getTowerSpeed(buttonNumber),num,10);
		strcat(speed,num);

		//float w = (float)getBitmapStringWidth(info_font_bold,name);
		float w = (float)getBitmapStringWidth(info_font,desc);
		float h = 4*sep + 4 + len*info_font_height;
		int yp = y + h;

		float xp = x - w/2;
		if(xp + w + 16 > GW)
			xp = GW - w - 16;
		else if (xp < 0)
			xp = 0;

	    renderBitmapString(xp, yp, info_font_bold, name);
		yp -= sep;
		renderBitmapString(xp, yp, info_font, cost);
		yp -= sep;
		renderBitmapString(xp, yp, info_font, damage);
		yp -= sep;
		renderBitmapString(xp, yp, info_font, speed);
		yp -= (sep + 4);
		renderBitmapString(xp, yp, info_font, desc);

		yp = y + h;
		glPushMatrix();
		glTranslatef(0,0,0.1);
		//Draw Corners
		//TL
		drawRectangle(xp - 8,yp + 2,16,16,info_tex[0]);
		//TR
		drawRectangle(xp + w - 8,yp + 2,16,16,info_tex[1]);
		//BR
		drawRectangle(xp + w - 8,yp + 2 - h,16,16,info_tex[2]);
		//BL
		drawRectangle(xp - 8,yp + 2 - h,16,16,info_tex[3]);

		//Top
		drawRectangle(xp - 8 + 16,yp + 2,w - 16,16,info_tex[8]);
		//Bottom
		drawRectangle(xp - 8 + 16,yp + 2 - h,w - 16,16,info_tex[9]);
		//Left
		drawRectangle(xp - 8,yp + 2 + 16 - h,16,h - 16,info_tex[6]);
		//Left
		drawRectangle(xp + w - 8,yp + 2 + 16 - h,16,h - 16,info_tex[7]);
		//Middle
		drawRectangle(xp - 8 + 16,yp + 2 + 16 - h,w - 16,h - 16,info_tex[5]);
		glPopMatrix();
	}
}

void mouseClick(int button, int state, int x, int y) {
  int click = determineClickedButton(x, GH - y);
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
      if (test >= 9 && test <= 17) {
        p1.placeTower(tlx, tly, test);
      } 

      clicked = !clicked;
    }

    test = click;

    if (test != -1) {
      GLfloat col[] = {0.6,0.6,0.6};
      buttons.at(test)->setButtonColor(col);
    }
  }else if (click >= 0 && click <= 8) {
    p1.spawnUnit(click);
  }

  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
    if (test != -1) {
      GLfloat col[] = {1.0,1.0,1.0};
      buttons.at(test)->setButtonColor(col);
      clicked = !clicked;
    }

  }

  glutPostRedisplay();
}

void mouseMotion(int x, int y) {
   mx = x;
   my = GH - y;
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
         
         // everythign below reorients the screen so there is -0.5x to 0.5x and -0.5 y to 0.5y
         // then it calculates mouse position
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

   int btn = determineClickedButton(x,GH- y);
   if(curBtn != -1 && btn != curBtn)
   {
	   GLfloat col[] = {1.0,1.0,1.0};
       buttons.at(curBtn)->setButtonColor(col);
   }
   if(btn != -1)
   {
	   GLfloat col[] = {0.8,0.8,0.8};
       buttons.at(btn)->setButtonColor(col);
   }
   curBtn = btn;

   
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

   int i;
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
  glPushMatrix();
  char *c;
  glRasterPos3f(x, y, 0.1);
  for (c=string; *c != '\0'; c++) {
	  if(*c == '\n') {
		  y -= info_font_height;
		  glRasterPos3f(x, y, 0.1);
	  }
	  else
		  glutBitmapCharacter(font, *c);
  }
  glPopMatrix();
}

int getBitmapStringWidth(void *font,char *string) {
  int w = 0;
  int maxW = 0;
  char *c;
  for (c=string; *c != '\0'; c++) {
	  if(*c == '\n') {
		  if(w > maxW)
			  maxW = w;
		  w = 0;
	  }
	  else
		  w += glutBitmapWidth(font, *c);
  }
  if(w > maxW)
	  return w;
  return maxW;
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
