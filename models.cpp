#include "models.h"


namespace vtd_dl{
  GLuint lockDL;
  GLuint blkhatDL;
  GLuint forkbDL;
  GLuint virusDL;
  GLuint wormDL;
  GLuint backtrackDL;
  GLuint teslaDL;
  GLuint fanDL;
  GLuint shieldDL;
  GLuint turretDL;
  GLuint turretBaseDL;
  GLuint trojanDL;
  GLuint bearDL;
};

void drawLock()
{
	GLUquadricObj *quadObj = gluNewQuadric();
	glPushMatrix();
		
		glTranslatef(0,.2,0);
		glPushMatrix();
			setMaterial(ShinyMetal);
			gluCylinder(quadObj, .5, .5, .5, 10, 10);
		glPopMatrix();
		glPushMatrix();
			setMaterial(ShinyMetal);
			quadObj = gluNewQuadric();
			gluDisk(quadObj,0,.5,10,1);
		glPopMatrix();
		glPushMatrix();
			setMaterial(BlueFlat);
			glTranslatef(0,0,.5);
			quadObj = gluNewQuadric();
			gluDisk(quadObj,0,.5,10,1);
		glPopMatrix();
		glPushMatrix();
			setMaterial(ShinyMetal);
			glTranslatef(0,.425,.25);
			glutSolidTorus(.080,.4,10,50);
		glPopMatrix();
		glPushMatrix();
			setMaterial(ShinyMetal);
			glTranslatef(0,0,0.50);
			gluCylinder(quadObj, .25, .25, .25, 20, 20);
		glPopMatrix();
		glPushMatrix();
			setMaterial(ShinyMetal);
			glTranslatef(0,0,.75);
			quadObj = gluNewQuadric();
			gluDisk(quadObj,0,.25,20,1);			
		glPopMatrix();
		glPushMatrix();
			setMaterial(Black);
			glPushMatrix();
					glBegin(GL_LINES);
						glVertex3f(0,.5,.51);
						glVertex3f(0,.35,.51);
					glEnd();
			glPopMatrix();
			glPushMatrix();
					glBegin(GL_LINES);
						glVertex3f(0,-.5,.51);
						glVertex3f(0,-.35,.51);
					glEnd();
			glPopMatrix();
			glPushMatrix();
					glRotatef(90,0,0,1);
					glBegin(GL_LINES);
						glVertex3f(0,.475,.51);
						glVertex3f(0,.325,.51);
					glEnd();
			glPopMatrix();
			glPushMatrix();
					glRotatef(-90,0,0,1);
					glBegin(GL_LINES);
						glVertex3f(0,.475,.51);
						glVertex3f(0,.325,.51);
					glEnd();
			glPopMatrix();
			glPushMatrix();
					glRotatef(45,0,0,1);
					glBegin(GL_LINES);
						glVertex3f(0,.475,.51);
						glVertex3f(0,.325,.51);
					glEnd();
			glPopMatrix();
			glPushMatrix();
					glRotatef(-45,0,0,1);
					glBegin(GL_LINES);
						glVertex3f(0,.475,.51);
						glVertex3f(0,.325,.51);
					glEnd();
			glPopMatrix();
			glPushMatrix();
					glRotatef(135,0,0,1);
					glBegin(GL_LINES);
						glVertex3f(0,.475,.51);
						glVertex3f(0,.325,.51);
					glEnd();
			glPopMatrix();
			glPushMatrix();
					glRotatef(-135,0,0,1);
					glBegin(GL_LINES);
						glVertex3f(0,.475,.51);
						glVertex3f(0,.325,.51);
					glEnd();
			glPopMatrix();
			glPushMatrix();
					glBegin(GL_LINES);
						glVertex3f(.01,.5,.51);
						glVertex3f(.01,.35,.51);
					glEnd();
			glPopMatrix();
			glPushMatrix();
					glBegin(GL_LINES);
						glVertex3f(.01,-.5,.51);
						glVertex3f(.01,-.35,.51);
					glEnd();
			glPopMatrix();
			glPushMatrix();
					glRotatef(91,0,0,1);
					glBegin(GL_LINES);
						glVertex3f(0,.475,.51);
						glVertex3f(0,.325,.51);
					glEnd();
			glPopMatrix();
			glPushMatrix();
					glRotatef(-91,0,0,1);
					glBegin(GL_LINES);
						glVertex3f(0,.475,.51);
						glVertex3f(0,.325,.51);
					glEnd();
			glPopMatrix();
			glPushMatrix();
					glRotatef(46,0,0,1);
					glBegin(GL_LINES);
						glVertex3f(0,.475,.51);
						glVertex3f(0,.325,.51);
					glEnd();
			glPopMatrix();
			glPushMatrix();
					glRotatef(-46,0,0,1);
					glBegin(GL_LINES);
						glVertex3f(0,.475,.51);
						glVertex3f(0,.325,.51);
					glEnd();
			glPopMatrix();
			glPushMatrix();
					glRotatef(136,0,0,1);
					glBegin(GL_LINES);
						glVertex3f(0,.475,.51);
						glVertex3f(0,.325,.51);
					glEnd();
			glPopMatrix();
			glPushMatrix();
					glRotatef(-136,0,0,1);
					glBegin(GL_LINES);
						glVertex3f(0,.475,.51);
						glVertex3f(0,.325,.51);
					glEnd();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

void drawBlackHat()
{
	glPushMatrix();
   setMaterial(Black);
	glTranslatef(0,.2,0);
	glRotatef(-90,1,0,0);
	glPushMatrix();
	GLUquadricObj *quadObj = gluNewQuadric();
   gluCylinder(gluNewQuadric(), 1.0, 1.0, 0.1, 20, 1);
   glTranslatef(0.0, 0.0, 0.1);
	gluDisk(quadObj,0,1,20,1);

	glPopMatrix();
	   glPushMatrix();
         gluCylinder(gluNewQuadric(), 0.5, 0.5, 2, 20, 1);
         glTranslatef(0.0, 0.0, 0.35);
         setMaterial(RedFlat);
	      glutSolidTorus(.1,0.5,10,20);
         glTranslatef(0.0, 0.0, 1.65);
         setMaterial(Black);
         gluDisk(gluNewQuadric(), 0.0, 0.5, 20, 1);
	   glPopMatrix();

	glPopMatrix();
}

void drawForkBomb()
{
	float animate_fork = 0.25;
	glPushMatrix(); /** Entire forkbomb **/
		//insert entire forkbomb animations
		glPushMatrix(); /** Entire Bomb **/
			setMaterial(Black);
			//insert bomb animation
		    glRotatef(-90,1,0,0);
			glRotatef(22,0,1,0);
			glPushMatrix(); /** Circular Element in Bomb **/
				glutSolidSphere(1.0, 12, 12);
			glPopMatrix();
			glPushMatrix(); /** Wick to bomb transition **/
				setMaterial(DarkGrey);
				//glRotatef(-90,1,0,0);
				//glRotatef(22,0,1,0);
				glTranslatef(0,0,.95);
				GLUquadricObj *quadObj = gluNewQuadric();
				gluCylinder(quadObj, .15, .15, .25, 6, 6);				
			glPopMatrix();
			glPushMatrix();
			setMaterial(Metal);
			glPushMatrix(); /** Wick **/
				glTranslatef(0,0,1.2);
				glutSolidSphere(0.1, 3, 3);
			glPopMatrix();
			glPushMatrix(); /** Wick **/
				glTranslatef(0,0,1.3);
				glutSolidSphere(0.1, 3, 3);
			glPopMatrix();
			glPushMatrix(); /** Wick **/
				glTranslatef(0,0,1.4);
				glutSolidSphere(0.1, 3, 3);
			glPopMatrix();
			glPushMatrix(); /** Wick **/
				glTranslatef(0,0,1.5);
				glutSolidSphere(0.1, 3, 3);
			glPopMatrix();
			glPushMatrix(); /** Wick **/
				glRotatef(.1,1,0,0);
				glTranslatef(0,0,1.55);
				glutSolidSphere(0.1, 3, 3);
			glPopMatrix();
			glPushMatrix(); /** Wick **/
				glRotatef(.2,1,0,0);
				glTranslatef(0,0,1.6);
				glutSolidSphere(0.1, 3, 3);
			glPopMatrix();
			glPushMatrix(); /** Wick **/
				glRotatef(.4,1,0,0);
				glTranslatef(0,0,1.65);
				glutSolidSphere(0.1, 3, 3);
			glPopMatrix();
			glPushMatrix(); /** Wick **/
				glRotatef(.5,1,0,0);
				glTranslatef(0,0,1.7);
				glutSolidSphere(0.1, 3, 3);
			glPopMatrix();
			glPushMatrix(); /** Wick **/
				glRotatef(.7,1,0,0);
				glTranslatef(0,0,1.75);
				glutSolidSphere(0.1, 3, 3);
			glPopMatrix();
			glPushMatrix(); /** Wick **/
				glRotatef(.8,1,0,0);
				glTranslatef(0,0,1.8);
				glutSolidSphere(0.1, 3, 3);
			glPopMatrix();
			glPushMatrix(); /** Wick **/
				glRotatef(1.0,1,0,0);
				glTranslatef(0,0,1.85);
				glutSolidSphere(0.1, 3, 3);
			glPopMatrix();
			glPushMatrix(); /** Wick **/
				glRotatef(1.1,1,0,0);
				glTranslatef(0,0,1.9);
				glutSolidSphere(0.1, 3, 3);
			glPopMatrix();
			glPushMatrix(); /** Wick **/
				glRotatef(1.3,1,0,0);
				glTranslatef(0,0,1.95);
				glutSolidSphere(0.1, 3, 3);
			glPopMatrix();
			glPushMatrix(); /** Wick **/
				glRotatef(1.4,1,0,0);
				glTranslatef(0,0,2.0);
				glutSolidSphere(0.1, 3, 3);
			glPopMatrix();
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0,animate_fork,0);
		glRotatef(-90,1,0,0);
		glRotatef(-10,0,1,0);
		glScalef(.5,.5,.5);
			glPushMatrix(); /** Entire Fork **/
				setMaterial(ShinyMetal);
				quadObj = gluNewQuadric();
				//gluCylinder(quadObj, base, top, height, slices, stacks);
				gluCylinder(quadObj,.125,.125,3,10,10);
			glPopMatrix();
			glPushMatrix();
				quadObj = gluNewQuadric();
				glTranslatef(0,0,2);
				gluCylinder(quadObj,.125,.07,.5,10,10);
			glPopMatrix();
			glPushMatrix();
				glRotatef(90,1,0,0);
				glTranslatef(0,3,-.285);
				glScalef(1,.75,.125);
				glScalef(.75,.75,.75);
				//glTranslatef(0,0,2.4);
				glPushMatrix();
				quadObj = gluNewQuadric();
				glTranslatef(0,0,2.4);
				glBegin(GL_TRIANGLES);
					glVertex3f(0,-1,0);
					glVertex3f(1,1,0);
					glVertex3f(-1,1,0);
				glEnd();
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0,0,3.4);
				glBegin(GL_TRIANGLES);
					glVertex3f(0,-1,0);
					glVertex3f(1,1,0);
					glVertex3f(-1,1,0);
				glEnd();
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0,0,2.9);
				glRotatef(90,0,1,0);
				glBegin(GL_QUADS);
					glVertex3f(.5,1,1);
					glVertex3f(.5,-1,0);
					glVertex3f(-.5,-1,0);
					glVertex3f(-.5,1,1);
				glEnd();
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0,0,2.9);
				glRotatef(-90,0,1,0);
				glBegin(GL_QUADS);
					glVertex3f(.5,1,1);
					glVertex3f(.5,-1,0);
					glVertex3f(-.5,-1,0);
					glVertex3f(-.5,1,1);
				glEnd();
				glPopMatrix();
				glPushMatrix();
				glTranslatef(0,1,2.9);
				glRotatef(-90,1,0,0);
				glScalef(2,.5,1);
				glBegin(GL_QUADS);
					glVertex3f(.5,1,0);
					glVertex3f(.5,-1,0);
					glVertex3f(-.5,-1,0);
					glVertex3f(-.5,1,0);
				glEnd();
				glPopMatrix();
				//glutSolidTetrahedron();
				//gluCylinder(quadObj,.07,.5,.4,10,1);			
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-.69,0,3.56);
				gluCylinder(quadObj,.06,.06,1.5,10,10);
				glPushMatrix();
					glTranslatef(0,0,1.5);
					gluCylinder(quadObj,.06,0,.2,10,10);
				glPopMatrix();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-.245,0,3.56);
				gluCylinder(quadObj,.06,.06,1.5,10,10);	
				glPushMatrix();
					glTranslatef(0,0,1.5);
					gluCylinder(quadObj,.06,0,.2,10,10);
				glPopMatrix();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(.245,0,3.56);
				gluCylinder(quadObj,.06,.06,1.5,10,10);
				glPushMatrix();
					glTranslatef(0,0,1.5);
					gluCylinder(quadObj,.06,0,.2,10,10);
				glPopMatrix();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(.69,0,3.56);
				gluCylinder(quadObj,.06,.06,1.5,10,10);
				glPushMatrix();
					glTranslatef(0,0,1.5);
					gluCylinder(quadObj,.06,0,.2,10,10);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	if((animate_fork + 0.01)<0.95)
	{
		animate_fork = animate_fork + 0.01;
	}
	else
	{
		animate_fork =  0.1;
	}
}

void drawVirus()
{
	glPushMatrix();
	int list[6] = {60,120,180,240,300,360};
   float animate_virus = 0.25;

	setMaterial(GreenShiny);
	glutSolidSphere(1.0, 12, 12);
	glPushMatrix();
	glTranslatef(0,0,0.75);
	GLUquadricObj *quadObj = gluNewQuadric();
	//gluCylinder(quadObj, base, top, height, slices, stacks);
	//gluCylinder(quadObj, 0.125, 0, 0.5, 12, 12);
	glPopMatrix();
	int i;
	setMaterial(RedFlat);
	for(i = 0; i < 6; i++)
	{
		glPushMatrix();
		glColor3f(1,0,0);
		glRotatef(list[i],1,0,0);
		glTranslatef(0,0,animate_virus);
		quadObj = gluNewQuadric();
		//gluCylinder(quadObj, base, top, height, slices, stacks);
		gluCylinder(quadObj, 0.2, 0, 1.1, 12, 12);
		glPopMatrix();
	}
	for(i = 0; i < 6; i++)
	{
		glPushMatrix();
		glColor3f(1,0,0);
		glRotatef(list[i],0,1,0);
		glTranslatef(0,0,animate_virus);
		quadObj = gluNewQuadric();
		//gluCylinder(quadObj, base, top, height, slices, stacks);
		gluCylinder(quadObj, 0.2, 0, 1.1, 12, 12);
		glPopMatrix();
	}
	for(i = 0; i < 6; i++)
	{
		glPushMatrix();
		glColor3f(1,0,0);
		glRotatef(list[i],1,1,0);
		glTranslatef(0,0,animate_virus);
		quadObj = gluNewQuadric();
		//gluCylinder(quadObj, base, top, height, slices, stacks);
		gluCylinder(quadObj, 0.2, 0, 1.1, 12, 12);
		glPopMatrix();
	}
	glPopMatrix();
	//printf("animate virus = %f \n", animate_virus);
	if((animate_virus + 0.01)<0.95)
	{
		animate_virus = animate_virus + 0.05;
	}
	else
	{
		animate_virus =  0.25;
	}
}

void drawWorm() {
   int tesallation = 6;
   // save the transformation state
   glPushMatrix();

   // set the material
   GLfloat diffuseColor[] = {1.0, 1.0, 0.0, 1.0};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);

   // locate it in the scene
   glMatrixMode(GL_MODELVIEW);

   // Eyes
   glPushMatrix();
   setMaterial(White);
   glScaled(0.5, 2.0, 0.5);
   glTranslatef(3.5, 1.4, 2.0);
   glutSolidSphere(0.45, tesallation, tesallation);
   glTranslatef(0.0, 0.0, -4.0);
   glutSolidSphere(0.45, tesallation, tesallation);
   glPopMatrix();
   
   setMaterial(Yellow);

   // Hierarchical transforms
   glScaled(2.0, 2.0, 2.0);
   glTranslatef(0.0, 1.0, 0.0);
   glutSolidSphere(1.0, tesallation, tesallation);
   
   // Head
   for (int i = 0; i < 10; i++) {
      glScaled(0.95, 0.95, 0.95);
      glRotatef(15.0, 0.0, 0.0, 1.0);
      glTranslatef(-0.5, 0.4, 0.0);
      glutSolidSphere(1.0, tesallation, tesallation);
   }

   // Mid Section
   glTranslatef(-0.6, 0.2, 0.0);
   glutSolidSphere(1.0, tesallation, tesallation);

   glTranslatef(-0.6, 0.12, 0.0);
   glutSolidSphere(1.0, tesallation, tesallation);

   glTranslatef(-0.6, 0.17, 0.0);
   glutSolidSphere(1.0, tesallation, tesallation);

   glTranslatef(-0.6, 0.2, 0.0);
   glutSolidSphere(1.0, tesallation, tesallation);

   glTranslatef(-0.6, 0.22, 0.0);
   glutSolidSphere(1.0, tesallation, tesallation);
   
   glTranslatef(-0.7, 0.27, 0.0);
   glutSolidSphere(1.0, tesallation, tesallation);
   
   glTranslatef(-0.7, 0.3, 0.0);
   glutSolidSphere(1.0, tesallation, tesallation);
   
   glTranslatef(-0.9, 0.42, 0.0);
   glutSolidSphere(1.0, tesallation, tesallation);
   
   glTranslatef(-0.9, 0.62, 0.0);
   glutSolidSphere(1.0, tesallation, tesallation);
   
   glRotatef(180, 0.0, 1.0, 0.0);
   glRotatef(-180, 0.0, 0.0, 1.0);
   
   // Lower Front Body   
   for (int i = 0; i < 6; i++) {
      glScaled(0.95, 0.95, 0.95);
      glRotatef(15.0, 0.0, 0.0, 1.0);
      glTranslatef(-0.6, -0.4, 0.0);
      glutSolidSphere(1.0, tesallation, tesallation);
   }
   
   // Lower Mid Body
   for (int i = 0; i < 2; i++) {
      glTranslatef(-0.5, -0.6, 0.0);
      glutSolidSphere(1.0, tesallation, tesallation);
   }

   // Tail
   for (int i = 0; i < 10; i++) {
      glScaled(0.95, 0.95, 0.95);
      glRotatef(15.0, 0.0, 0.0, 1.0);
      glTranslatef(-0.6, -0.4, 0.0);
      glutSolidSphere(1.0, tesallation, tesallation);
   }

   glPopMatrix();

   return;
}

void drawBackTrack() {
   int tesallation = 3;
   // save the transformation state
   glPushMatrix();
      setMaterial(Grey);

      // locate it in the scene
      glMatrixMode(GL_MODELVIEW);
      
      // Wings
      glPushMatrix();
         glScaled(2.0, 2.0, 2.0);
         /* =========  Right Wing  ========= */
             /* Right Wing Top Branch */
         glPushMatrix();
            glRotatef(10, 0.0, 1.0, 0.0);
            glPushMatrix();
               // Wing joint rotation about Z axis
               glRotatef(-15, 0.0, 0.0, 1.0);
               // Wing joint rotation about Y axis
               glRotatef(15, 0.0, 1.0, 0.0);
               for (int i = 0; i < 25; i++) {
                  glRotatef(2, 0.0, 0.0, 1.0);
                  glTranslatef(-1.0, 0.0, 0.0);
                  glScaled(1.0, 0.93, 0.93);
                  glutSolidCube(1.0);
               }
            glPopMatrix();
                 /* Right Wing Mid Branch */
            glPushMatrix();
               glTranslatef(0.0, -1.0, 0.0);
               // Wing joint rotation about Z axis
               glRotatef(-1, 0.0, 0.0, 1.0);
               // Wing joint rotation about Y axis
               glRotatef(5.0, 0.0, 1.0, 0.0);
               for (int i = 0; i < 29; i++) {
                  glRotatef(1.7, 0.0, 0.0, 1.0);
                  glTranslatef(-1.0, 0.0, 0.0);
                  glScaled(1.0, 0.93, 0.93);
                  glutSolidCube(1.0);
               }
            glPopMatrix();
                 /* Right Wing Botton Branch */
            glPushMatrix();
               glTranslatef(0.5, -2.0, 0.0);
               // Wing joint rotation about Z axis
               glRotatef(14, 0.0, 0.0, 1.0);
               // Wing joint rotation about Y axis
               glRotatef(-10, 0.0, 1.0, 0.0);
               for (int i = 0; i < 23; i++) {
                  glRotatef(1.7, 0.0, 0.0, 1.0);
                  glTranslatef(-1.0, 0.0, 0.0);
                  glScaled(1.0, 0.93, 0.93);
                  glutSolidCube(1.0);
               }
            glPopMatrix();
            
            glPushMatrix();
               glPushMatrix();
                  // Right Wing Arm
                  glScaled(0.50, 1.0, 0.50);
                  glRotatef(-90, 1.0, 0.0, 0.0);
                  glutSolidCone(1.0, 1.5, tesallation, tesallation);
               glPopMatrix();

               for (int i = 0; i < 8; i++) {
                  glRotatef(5.0, 0.0, 0.0, 1.0); // rotate forward
                  glRotatef(5.0, 1.0, 0.0, 0.0); // rotate inward
                  glTranslatef(0.0, -0.5, 0.0); // shift
                  glScaled(0.9, 1.01, 0.9);
                  glutSolidCube(1.0);
               }
               
               for (int i = 0; i < 5; i++) {
                  glRotatef(6.0, 0.0, 0.0, 1.0); // rotate forward
                  glRotatef(2.0, 1.0, 0.0, 0.0); // rotate inward
                  glTranslatef(0.0, -0.5, 0.0); // shift
                  glScaled(1.15, 0.95, 1.15);
                  glutSolidCube(1.0);
               }
            glPopMatrix();
         glPopMatrix();

         glTranslatef(0.0, 0.0, -6);
         
         /* ===========  Left Wing  =========== */
              /* Left Wing Top Branch */
         glPushMatrix();
            glRotatef(-10, 0.0, 1.0, 0.0);
            glPushMatrix();
               // Wing joint rotation about Z axis
               glRotatef(-15, 0.0, 0.0, 1.0);
               // Wing joint rotation about Y axis
               glRotatef(-15, 0.0, 1.0, 0.0);
               for (int i = 0; i < 25; i++) {
                  glRotatef(2, 0.0, 0.0, 1.0);
                  glTranslatef(-1.0, 0.0, 0.0);
                  glScaled(1.0, 0.93, 0.93);
                  glutSolidCube(1.0);
               }
            glPopMatrix();
                 /* Left Wing Mid Branch */
            glPushMatrix();
               glTranslatef(0.0, -1.0, 0.0);
               // Wing joint rotation about Z axis
               glRotatef(-1, 0.0, 0.0, 1.0);
               // Wing joint rotation about Y axis
               glRotatef(-5.0, 0.0, 1.0, 0.0);
               for (int i = 0; i < 29; i++) {
                  glRotatef(1.7, 0.0, 0.0, 1.0);
                  glTranslatef(-1.0, 0.0, 0.0);
                  glScaled(1.0, 0.93, 0.93);
                  glutSolidCube(1.0);
               }
            glPopMatrix();
                 /* Left Wing Bottom Branch */
            glPushMatrix();
               glTranslatef(0.5, -2.0, 0.0);
               // Wing joint rotation about Z axis
               glRotatef(14, 0.0, 0.0, 1.0);
               // Wing joint rotation about Y axis
               glRotatef(10, 0.0, 1.0, 0.0);
               for (int i = 0; i < 23; i++) {
                  glRotatef(1.7, 0.0, 0.0, 1.0);
                  glTranslatef(-1.0, 0.0, 0.0);
                  glScaled(1.0, 0.93, 0.93);
                  glutSolidCube(1.0);
               }
            glPopMatrix();

            glPushMatrix();
               glPushMatrix();
                  // Wing Arm
                  glScaled(0.50, 1.0, 0.50);
                  glRotatef(-90, 1.0, 0.0, 0.0);
                  glutSolidCone(1.0, 1.5, tesallation, tesallation);
               glPopMatrix();

               for (int i = 0; i < 8; i++) {
                  glRotatef(5.0, 0.0, 0.0, 1.0); // rotate forward
                  glRotatef(-5.0, 1.0, 0.0, 0.0); // rotate inward
                  glTranslatef(0.0, -0.5, 0.0); // shift
                  glScaled(0.9, 1.01, 0.9);
                  glutSolidCube(1.0);
               }
               
               for (int i = 0; i < 5; i++) {
                  glRotatef(6.0, 0.0, 0.0, 1.0); // rotate forward
                  glRotatef(-2.0, 1.0, 0.0, 0.0); // rotate inward
                  glTranslatef(0.0, -0.5, 0.0); // shift
                  glScaled(1.15, 0.95, 1.15);
                  glutSolidCube(1.0);
               }
            glPopMatrix();
         glPopMatrix();
      glPopMatrix();

      // Transform back to Middle
      glTranslatef(23.0, -7.0, -6.0);
      
      // Head
      glPushMatrix();
         glTranslatef(-0.75, 0.1, 0.0);
         glRotatef(-1, 0.0, 0.0, 1.0);
         glScaled(0.95, 0.95, 0.95);
         for (int i = 0; i < 8; i++) {
            glRotatef(0.8, 0.0, 0.0, 1.0);
            glTranslatef(0.8, -0.1 - (i * 1.0 / 35), 0.0);
            glScaled(0.98, 0.98, 0.98);
            glutSolidSphere(1.0, tesallation, tesallation);
         }
         
         // Neck Horns
         glPushMatrix();

            glTranslatef(-1.5, 1.0, 0.0);
            glRotatef(-90, 1.0, 0.0, 0.0);
            glRotatef(-40, 0.0, 1.0, 0.0); // z == y, y ==z
            glScaled(0.75, 0.5, 1.5);
            glutSolidCone(1.0, 2.0, tesallation, tesallation);
            
            glTranslatef(-2.0, 0.0, 1.2);
            glutSolidCone(1.0, 2.0, tesallation, tesallation);

            glTranslatef(-2.0, 0.0, 1.2);
            glutSolidCone(1.0, 2.0, tesallation, tesallation);
         glPopMatrix();

         // Right Antenna
         glPushMatrix();
            glRotatef(-55, 0.0, 0.0, 1.0);
            glTranslatef(5.5, 3.5, 1.0);
            // Wing joint rotation about Z axis
            glRotatef(14, 0.0, 0.0, 1.0);
            // Wing joint rotation about Y axis
            glRotatef(10, 0.0, 1.0, 0.0);
            for (int i = 0; i < 26; i++) {
               glRotatef(1.7, 0.0, 0.0, 1.0);
               glTranslatef(-1.0, 0.0, 0.0);
               glScaled(1.0, 0.90, 0.90);
               glutSolidCube(1.0);
            }
         glPopMatrix();

         // Left Antenna
         glPushMatrix();
            glRotatef(-55, 0.0, 0.0, 1.0);
            glTranslatef(5.5, 3.5, -1.0);
            // Wing joint rotation about Z axis
            glRotatef(14, 0.0, 0.0, 1.0);
            // Wing joint rotation about Y axis
            glRotatef(-10, 0.0, 1.0, 0.0);
            for (int i = 0; i < 26; i++) {
               glRotatef(1.7, 0.0, 0.0, 1.0);
               glTranslatef(-1.0, 0.0, 0.0);
               glScaled(1.0, 0.90, 0.90);
               glutSolidCube(1.0);
            }
         glPopMatrix();
         
         glScaled(1.5, 0.95, 1.5);
         glTranslatef(0.8, -1.0, 0.0);
         glutSolidSphere(2.0, tesallation, tesallation);

         // Eyes 
         setMaterial(PureRed);

         glPushMatrix();
            glTranslatef(1.2, 0.0, 1.5);
            glRotatef(45, 1.0, 0.0, 0.0);
            glRotatef(45.0, 0.0, 0.0, 1.0);
            glScaled(0.7, 1.5, 0.7);
            glutSolidSphere(0.5, tesallation, tesallation);
         glPopMatrix();

         glPushMatrix();
            glTranslatef(1.2, 0.0, -1.5);
            glRotatef(-45, 1.0, 0.0, 0.0);
            glRotatef(45.0, 0.0, 0.0, 1.0);
            glScaled(0.7, 1.5, 0.7);
            glutSolidSphere(0.5, tesallation, tesallation);
         glPopMatrix();
         
         setMaterial(Grey);
         
         glTranslatef(1.0, -1.0, 0.0);
         glRotatef(180, 1.0, 0.0, 0.0);
         glRotatef(40, 0.0, 0.0, 1.0);

         // Top mouth ??
         glPushMatrix();
            glScaled(1.0, 0.95, 2.0);
            for (int i = 0; i < 4; i++) {
               glRotatef(-2, 0.0, 0.0, 1.0);
               glTranslatef(0.7, -0.0, 0.0);
               glScaled(0.99, 0.98, 0.94);
               glutSolidCube(1.0);
            }
            
            for (int i = 0; i < 3; i++) {
               glRotatef(-2, 0.0, 0.0, 1.0);
               glTranslatef(0.7, -0.0, 0.0);
               glScaled(1.01, 1.01, 1.03);
               glutSolidCube(1.0);
            }
         glPopMatrix();

         glTranslatef(-0.3, 0.5, 0.0);
         glRotatef(-180, 1.0, 0.0, 0.0);
         glRotatef(10, 0.0, 0.0, 1.0);
   
         // Bottom Mouth ??
         glPushMatrix();
            glScaled(1.0, 0.95, 2.0);
            for (int i = 0; i < 4; i++) {
               glRotatef(-2, 0.0, 0.0, 1.0);
               glTranslatef(0.7, -0.0, 0.0);
               glScaled(0.99, 0.98, 0.94);
               glutSolidCube(1.0);
            }
            
            for (int i = 0; i < 3; i++) {
               glRotatef(-2, 0.0, 0.0, 1.0);
               glTranslatef(0.7, -0.0, 0.0);
               glScaled(1.01, 1.01, 1.03);
               glutSolidCube(1.0);
            }
         glPopMatrix();
      glPopMatrix();

      // Body
      glPushMatrix();
         glRotatef(-1, 0.0, 0.0, 1.0);
         glScaled(0.95, 0.95, 0.95);
         for (int i = 0; i < 17; i++) {
            glRotatef(0.8, 0.0, 0.0, 1.0);
            glTranslatef(-0.7, 0.1, 0.0);
            glScaled(1.01, 1.01, 1.01);
            glutSolidSphere(1.0, tesallation, tesallation);
         }

         for (int i = 0; i < 17; i++) {
            glRotatef(5.0, 0.0, 0.0, 1.0);
            glTranslatef(-0.7, 0.1 + (i * 1.0 / 50), 0.0);
            glScaled(1.03, 1.03, 1.03);
            glutSolidSphere(1.0, tesallation, tesallation);
         }

         for (int i = 17; i > -2; i--) {
            glRotatef(5.0, 0.0, 0.0, 1.0);
            glTranslatef(-0.9, + (0.1 + (i * 1.0 / 50)), 0.0);
            glScaled(0.99, 0.99, 0.99);
            glutSolidSphere(1.0, tesallation, tesallation);
         }

         for (int i = 0; i < 5; i++) {
            glTranslatef(-0.8, 0.05, 0.0);
            glScaled(0.999, 0.999, 0.999);
            glutSolidSphere(1.0, tesallation, tesallation);
         }

         for (int i = 0; i < 5; i++) {
            glTranslatef(-0.8, 0.05, 0.0);
            glScaled(1.03, 1.03, 1.03);
            glutSolidSphere(1.0, tesallation, tesallation);
         }

         // Left Tail Fork
         glPushMatrix();
            for (int i = 0; i < 30; i++) {
               glRotatef(-5.0, 0.0, 0.0, 1.0);
               glTranslatef(-0.85, -0.1 * (i * 0.5), -0.2);
               glScaled(1.0, 0.925, 0.90);
               glutSolidSphere(1.0, tesallation, tesallation);
            }
         glPopMatrix();
         // Right Tail Fork
         glPushMatrix();
            for (int i = 0; i < 30; i++) {
               glRotatef(-5.0, 0.0, 0.0, 1.0);
               glTranslatef(-0.85, -0.1 * (i * 0.5), 0.2);
               glScaled(1.0, 0.925, 0.90);
               glutSolidSphere(1.0, tesallation, tesallation);
            }
         glPopMatrix();
      glPopMatrix();
      
   glPopMatrix();

   return;
}

void drawTeslaCoil() {
   int tesallation = 8;
   // save the transformation state
   glPushMatrix();

   // locate it in the scene
   glMatrixMode(GL_MODELVIEW);
   
   // orient entire hierarchy
   glTranslatef(0.0, 5.0, 0.0);
   glRotatef(90, 1.0, 0.0, 0.0);
   
   setMaterial(ShinyMetal);
   
   // Coil Head
   glPushMatrix();
      glutSolidSphere(2, tesallation, tesallation);
      glTranslatef(0.0, 0.0, 2.0);
      gluCylinder(gluNewQuadric(), 0.4, 0.4, 10, tesallation, tesallation);
      glTranslatef(0.0, 0.0, 1.5);
      glutSolidTorus(0.4, 2.1, tesallation, tesallation); // inner radius really means thinness
      glTranslatef(0.0, 0.0, 2.0);
      glutSolidTorus(0.4, 3.1, tesallation, tesallation);
      glTranslatef(0.0, 0.0, 2.0);
      glutSolidTorus(0.4, 4.1, tesallation, tesallation);
   glPopMatrix();

   // relative to outward transform. Position Coild sides
   glTranslatef(0.0, 0.0, 13.0); 
   glRotatef(-90, 1.0, 0.0, 0.0);
   glScaled(0.5, 0.5, 0.5); 

   // Three Coil Heads on Sides
   // Grey
   setMaterial(ShinyMetal);
   glPushMatrix();
      glTranslatef(-5.0, 0.0, 0.0);
      glRotatef(45, 0.0, 0.0, 1.0);
      glTranslatef(0.0, 11.5, 0.0); // move outward, relative to xform after coil head
      glPushMatrix();
         glTranslatef(0.0, 5.0, 0.0);
         glRotatef(90, 1.0, 0.0, 0.0);
         glutSolidSphere(2, tesallation, tesallation);
         glTranslatef(0.0, 0.0, 2.0);
         gluCylinder(gluNewQuadric(), 0.4, 0.4, 10, tesallation, tesallation);
         glTranslatef(0.0, 0.0, 1.0);
         glutSolidTorus(0.4, 2.1, tesallation, tesallation); // inner radius really means thinness
         glTranslatef(0.0, 0.0, 2.0);
         glutSolidTorus(0.4, 3.1, tesallation, tesallation);
         glTranslatef(0.0, 0.0, 2.0);
         glutSolidTorus(0.4, 4.1, tesallation, tesallation);
      glPopMatrix();
   glPopMatrix();
   
   glRotatef(60, 0.0, 1.0, 0.0);

   // Red
   setMaterial(PureRed);
   
   glPushMatrix(); // side block
      glTranslatef(-2.0, -3.0, 0.0); // outwardness
      glRotatef(45, 0.0, 0.0, 1.0); // tilt
      glTranslatef(0.0, 11.0, 0.0); // up down along tilt
      glScaled(1.5, 1.0, 3.0);
      glutSolidCube(3);
   glPopMatrix();

   glRotatef(60, 0.0, 1.0, 0.0);

   // Grey
   setMaterial(ShinyMetal);
      
   glPushMatrix();
      glTranslatef(-5.0, 0.0, 0.0);
      glRotatef(45, 0.0, 0.0, 1.0);
      glTranslatef(0.0, 11.5, 0.0); // move outward, relative to xform after coil head
      glPushMatrix();
         glTranslatef(0.0, 5.0, 0.0);
         glRotatef(90, 1.0, 0.0, 0.0);
         glutSolidSphere(2, tesallation, tesallation);
         glTranslatef(0.0, 0.0, 2.0);
         gluCylinder(gluNewQuadric(), 0.4, 0.4, 10, tesallation, tesallation);
         glTranslatef(0.0, 0.0, 1.0);
         glutSolidTorus(0.4, 2.1, tesallation, tesallation); // inner radius really means thinness
         glTranslatef(0.0, 0.0, 2.0);
         glutSolidTorus(0.4, 3.1, tesallation, tesallation);
         glTranslatef(0.0, 0.0, 2.0);
         glutSolidTorus(0.4, 4.1, tesallation, tesallation);
      glPopMatrix();
   glPopMatrix();
   
   glRotatef(60, 0.0, 1.0, 0.0);
   
   // Red
   setMaterial(PureRed);
   
   glPushMatrix(); // side block
      glTranslatef(-2.0, -3.0, 0.0); // outwardness
      glRotatef(45, 0.0, 0.0, 1.0); // tilt
      glTranslatef(0.0, 11.0, 0.0); // up down along tilt
      glScaled(1.5, 1.0, 3.0);
      glutSolidCube(3);
   glPopMatrix();

   glRotatef(60, 0.0, 1.0, 0.0);
   
   // Grey
   setMaterial(ShinyMetal);
   
   glPushMatrix();
      glTranslatef(-5.0, 0.0, 0.0);
      glRotatef(45, 0.0, 0.0, 1.0);
      glTranslatef(0.0, 11.5, 0.0); // move outward, relative to xform after coil head
      glPushMatrix();
         glTranslatef(0.0, 5.0, 0.0);
         glRotatef(90, 1.0, 0.0, 0.0);
         glutSolidSphere(2, tesallation, tesallation);
         glTranslatef(0.0, 0.0, 2.0);
         gluCylinder(gluNewQuadric(), 0.4, 0.4, 10, tesallation, tesallation);
         glTranslatef(0.0, 0.0, 1.0);
         glutSolidTorus(0.4, 2.1, tesallation, tesallation); // inner radius really means thinness
         glTranslatef(0.0, 0.0, 2.0);
         glutSolidTorus(0.4, 3.1, tesallation, tesallation);
         glTranslatef(0.0, 0.0, 2.0);
         glutSolidTorus(0.4, 4.1, tesallation, tesallation);
      glPopMatrix();
   glPopMatrix();

   glRotatef(60, 0.0, 1.0, 0.0);

   setMaterial(PureRed);

   glPushMatrix(); // side block
      glTranslatef(-2.0, -3.0, 0.0); // outwardness
      glRotatef(45, 0.0, 0.0, 1.0); // tilt
      glTranslatef(0.0, 11.0, 0.0); // up down along tilt
      glScaled(1.5, 1.0, 3.0);
      glutSolidCube(3);
   glPopMatrix();

   // Center Base fork
   glPushMatrix();
      glRotatef(60, 0.0, 1.0, 0.0);
      glPushMatrix();
         glTranslatef(5.0, 5.1, 0.0); // x is outwardness in this case
         glScaled(3.0, 1.0, 2.0);
         glutSolidCube(3);
      glPopMatrix();

      glRotatef(120, 0.0, 1.0, 0.0);
      glPushMatrix();
         glTranslatef(5.0, 5.1, 0.0); // x is outwardness in this case
         glScaled(3.0, 1.0, 2.0);
         glutSolidCube(3);
      glPopMatrix();

      glRotatef(120, 0.0, 1.0, 0.0);
      glPushMatrix();
         glTranslatef(5.0, 5.1, 0.0); // x is outwardness in this case
         glScaled(3.0, 1.0, 2.0);
         glutSolidCube(3);
      glPopMatrix();
   glPopMatrix();
   
   // Dark Grey
   setMaterial(DarkGrey);
   
   // Orient base
   glRotatef(270, 1.0, 0.0, 0.0);
   glTranslatef(0.0, 0.0, 5.5);
   // Tower Base
   glPushMatrix();
      // Brown
      setMaterial(Brown);
      
      glPushMatrix(); // don't let scale trickle down
         glScaled(0.9, 0.9, 1.0); // at this point up/down == z, left/right == y
         gluDisk(gluNewQuadric(), 0.0, 10, tesallation, tesallation);
         glTranslatef(0.0, 0.0, -3.5);
         gluCylinder(gluNewQuadric(), 13.0, 10.0, 3.5, tesallation, tesallation);
      glPopMatrix();
      
      glTranslatef(0.0, 0.0, -3.5);

      // Grey
      setMaterial(Grey);
     
       glPushMatrix(); // again, don't let scale tirckle down
         glScaled(0.97, 0.97, 1.0);
         gluDisk(gluNewQuadric(), 0.0, 13, tesallation, tesallation);
         glTranslatef(0.0, 0.0, -1.0);
         gluCylinder(gluNewQuadric(), 13.0, 13.0, 1.0, tesallation, tesallation);
      glPopMatrix();
      
      glTranslatef(0.0, 0.0, -1.0);

      // Dark Grey
      setMaterial(DarkGrey);
   
      gluDisk(gluNewQuadric(), 0.0, 13, tesallation, tesallation);
      glTranslatef(0.0, 0.0, -15.0);
      gluCylinder(gluNewQuadric(), 13.0, 13.0, 15.0, tesallation, tesallation);
   glPopMatrix();
   
   // Orient for base bottom/sides
   glRotatef(22.5, 0.0, 0.0, 1.0);
   // Tower Base Sides
   glPushMatrix();
      glTranslatef(0.0, 12.0, -14.5);
      // Dark Dark Grey
      setMaterial(DarkDarkGrey);

      glPushMatrix();
         glScaled(2.0, 0.25, 2.0);
         glutSolidCube(5);
      glPopMatrix();

      setMaterial(PureRed);

      glTranslatef(0.0, 3.0, -4.0);
      glRotatef(45, 1.0, 0.0, 0.0);
      glScaled(1.0, 0.7, 2.0);
      glutSolidCube(5);
   glPopMatrix();
   
   glRotatef(90, 0.0, 0.0, 1.0);
   glPushMatrix();
      glTranslatef(0.0, 12.0, -14.5);
      // Dark Dark Grey
      setMaterial(DarkDarkGrey);

      glPushMatrix();
         glScaled(2.0, 0.25, 2.0);
         glutSolidCube(5);
      glPopMatrix();

      // Red
      setMaterial(PureRed);

      glTranslatef(0.0, 3.0, -4.0);
      glRotatef(45, 1.0, 0.0, 0.0);
      glScaled(1.0, 0.7, 2.0);
      glutSolidCube(5);
   glPopMatrix();
   
   glRotatef(90, 0.0, 0.0, 1.0);
   glPushMatrix();
      glTranslatef(0.0, 12.0, -14.5);
      // Dark Dark Grey
      setMaterial(DarkDarkGrey);

      glPushMatrix();
         glScaled(2.0, 0.25, 2.0);
         glutSolidCube(5);
      glPopMatrix();

      setMaterial(PureRed);

      glTranslatef(0.0, 3.0, -4.0);
      glRotatef(45, 1.0, 0.0, 0.0);
      glScaled(1.0, 0.7, 2.0);
      glutSolidCube(5);
   glPopMatrix();

   glRotatef(90, 0.0, 0.0, 1.0);
   glPushMatrix();
      glTranslatef(0.0, 12.0, -14.5);
      // Dark Dark Grey
      setMaterial(DarkDarkGrey);
   
      glPushMatrix();
         glScaled(2.0, 0.25, 2.0);
         glutSolidCube(5);
      glPopMatrix();
      
      setMaterial(PureRed);
   
      glTranslatef(0.0, 3.0, -4.0);
      glRotatef(45, 1.0, 0.0, 0.0);
      glScaled(1.0, 0.7, 2.0);
      glutSolidCube(5);
   glPopMatrix();
   
   // Grey
   setMaterial(Grey);
   
   glTranslatef(0.0, 0.0, -21.5);
   // dont alter the 4, it is the ground base
   gluCylinder(gluNewQuadric(), 23.5, 16.5, 2.0, 4, tesallation);
   
   glPopMatrix();
   return;
}

void drawFanDLAnimated(int speed) {
   glPushMatrix();
   glCallList(vtd_dl::fanDL);
   glTranslatef(0.0, 0.0, -7.0);
   animateCPUFan(4, speed);
   glTranslatef(0.0, 0.0, 12.0);
   animateCPUFan(4, speed);
   glPopMatrix();
}

void drawCPUFan() {
   int tesallation = 6;

   glPushMatrix();
      glTranslatef(0.0, 0.0, -6.0);
      // Fan 1
      glPushMatrix();
         // Heatsink
         glPushMatrix();
            setMaterial(FieryOrange);
            glRotatef(210, 0.0, 0.0, 1.0);
            for (int i = 0; i < 100; i++) {
               glRotatef(3.0, 0.0, 0.0, 1.0);
               
               glPushMatrix();
                  // blade height
                  glTranslatef(0.0, 13.0, 0.0);
                  glScaled(0.05, 1.0, 5.0);
                  glutSolidCube(2.0);
               glPopMatrix();
            }
         glPopMatrix();
         
         // Heatsink Rim
         glPushMatrix();
            glTranslatef(0.0, 0.0, -1.0);
            glutSolidTorus(0.30, 13, tesallation, tesallation);
            glTranslatef(0.0, 0.0, 2.0);
            glutSolidTorus(0.25, 13, tesallation, tesallation);
         glPopMatrix();

         glTranslatef(0.0, 0.0, -1.0);

         // Center Core
         glPushMatrix();
            setMaterial(Grey);
            gluCylinder(gluNewQuadric(), 4.0, 4.0, 5.0, tesallation, tesallation);
            
            // Draw faces for cover core
            glPushMatrix();
               // Flip disk to face outward (for lighting)
               glRotatef(180, 1.0, 0.0, 0.0);
               gluDisk(gluNewQuadric(), 0.0, 4.0, tesallation, 1);
               glTranslatef(0.0, 0.0, -5.0);
               glRotatef(180, 1.0, 0.0, 0.0);
               gluDisk(gluNewQuadric(), 0.0, 4.0, tesallation, 1);
            glPopMatrix();
         glPopMatrix();

    //     animateCPUFan(tesallation);
        
         // Base
         glPushMatrix();
            glTranslatef(0.0, -12.0, 1.0);
            glScaled(3.0, 0.65, 2.0);
            glutSolidCube(3.0);
         glPopMatrix();
         
         // Back
         glPushMatrix();
            setMaterial(Grey);
            glRotatef(90, 1.0, 0.0, 0.0);
            glTranslatef(-1.0, 0.0, 0.0);
            gluCylinder(gluNewQuadric(), 0.5, 0.5, 13, tesallation, tesallation);
            glTranslatef(2.0, 0.0, 0.0);
            gluCylinder(gluNewQuadric(), 0.5, 0.5, 13, tesallation, tesallation);
         glPopMatrix();
      glPopMatrix();
   glPopMatrix();   

   return;
}

void drawCPUFanBase() {
   // Circuit
   glPushMatrix();
      setMaterial(Black);
      glTranslatef(0.0, -13.0, -6.0);
      glScaled(27.0, 0.5, 27.0);
      glutSolidCube(1.0);
   glPopMatrix();
}

void animateCPUFan(int tesallation, int speed) {
   // Fan Blades
   glPushMatrix();
      /* animation */
      glRotatef(speed, 0.0, 0.0, 1.0);

      setMaterial(ShinyMetal);
      glTranslatef(0.0, 0.0, 1.0);

      for (int i = 0; i < 7; i++) {
         glRotatef(51.4, 0.0, 0.0, 1.0);
         glPushMatrix();
         glRotatef(-40, 0.0, 1.0, 0.0);
         gluPartialDisk(gluNewQuadric(), 0.0, 11.0, tesallation, 1, 0, 51.4);
         
         glRotatef(180, 0.0, 1.0, 0.0);
         glTranslatef(0.0, 0.0, 0.5);
         gluPartialDisk(gluNewQuadric(), 0.0, 11.0, tesallation, 1, -51.4, 51.4);
         glPopMatrix();
      }
   glPopMatrix();
}

void drawShield() {
   glPushMatrix();
   glTranslatef(-10.0, 0.0, 0.0);
   glRotatef(90, 1.0, 0.0, 0.0);
   glRotatef(180, 0.0, 0.0, 1.0);

   for (int i = 0; i < 25; i++) {
      glTranslatef(0.0, 0.2, 0.2); // y = up, z = forward
      glScaled(0.95, 0.95, 0.95);
      
      glPushMatrix();
         glTranslatef(-8.0, 0.0, 0.0);
         drawShieldBase(i);
      glPopMatrix();
   }

   // Center crest
   glScaled(3.5, 3.5, 3.5);
   setMaterial(Purple);
   glTranslatef(0.0, 0.0, 2.0);
   glutSolidDodecahedron();
   glPopMatrix();
}

/* Used by drawShield */
void drawShieldBase(int set) {
   int tesallation = 3;
   glPushMatrix();
      setMaterial(Grey);
      
      // Half 1
      glPushMatrix();
         // Top
         glPushMatrix();
            if(set > 0) {  
               setMaterial(RedFlat);
            } 

            glRotatef(90, 0.0, 1.0, 0.0);
        
            for (int i = 0; i < 9; i++) {
               if (i > 0) {
                  glTranslatef(0.0, 0.0, 1.0);
               }

               glRotatef(5.0, 0.0, 1.0, 0.0);
               gluCylinder(gluNewQuadric(), 0.25, 0.25, 1.1, tesallation, tesallation);
            }
         glPopMatrix();
      
         // Bottom
         if(set > 0) {  
            setMaterial(GreenShiny);
         } 
         
         for (int i = 0; i < 20; i++) {
            if (i > 0) {
               glTranslatef(0.0, 0.0, 1.0);
            }

            glRotatef(2.25, 0.0, 1.0, 0.0);
            gluCylinder(gluNewQuadric(), 0.25, 0.25, 1.0, tesallation, tesallation);
         }
      glPopMatrix();
      
      
      // Half 2
      glPushMatrix();
         glTranslatef(16.0, 0.0, 0.0);
         glRotatef(180, 0.0, 0.0, 1.0);
         
         // Top
         glPushMatrix();
            if(set > 0) {  
               setMaterial(Yellow);
            } 

            glRotatef(90, 0.0, 1.0, 0.0);
        
            for (int i = 0; i < 9; i++) {
               if (i > 0) {
                  glTranslatef(0.0, 0.0, 1.0);
               }

               glRotatef(5.0, 0.0, 1.0, 0.0);
               gluCylinder(gluNewQuadric(), 0.25, 0.25, 1.0, tesallation, tesallation);
            }
         glPopMatrix();

         // Bottom
         if(set > 0) {  
            setMaterial(Exp);
         } 
         
         for (int i = 0; i < 20; i++) {
            if (i > 0) {
               glTranslatef(0.0, 0.0, 1.0);
            }
        
            glRotatef(2.25, 0.0, 1.0, 0.0);
            gluCylinder(gluNewQuadric(), 0.25, 0.25, 1.0, tesallation, tesallation);
         }
      glPopMatrix();
   glPopMatrix();

   return;
}

void drawTurretDLAnimated(int speed) {
   glPushMatrix();
      glCallList(vtd_dl::turretDL);
      
      glRotatef(speed, 0.0, 1.0, 0.0);
      glCallList(vtd_dl::turretBaseDL);
   glPopMatrix();
}

/* Used by drawMemBase */
void drawMemStick() {
   glPushMatrix();
      glPushMatrix();
         setMaterial(GreenShiny);
         glScaled(1.20, 0.075, 5.0);
         glutSolidCube(1.0);
      
         setMaterial(Yellow);
         glTranslatef(0.58, 0.0, 0.0);
         glScaled(0.15, 0.80, 0.98);
         glutSolidCube(1.0);
      glPopMatrix();
      
      glPushMatrix();
         setMaterial(Black);
         glTranslatef(-0.075, 0.0, -2.15);
         glScaled(1.0, 0.15, 0.55);
         glutSolidCube(1.0);
         glTranslatef(0.0, 0.0, 1.1);
         glutSolidCube(1.0);
         glTranslatef(0.0, 0.0, 1.1);
         glutSolidCube(1.0);
         glTranslatef(0.0, 0.0, 1.1);
         glutSolidCube(1.0);
         glTranslatef(0.0, 0.0, 1.1);
         glutSolidCube(1.0);
         glTranslatef(0.0, 0.0, 1.1);
         glutSolidCube(1.0);
         glTranslatef(0.0, 0.0, 1.1);
         glutSolidCube(1.0);
         glTranslatef(0.0, 0.0, 1.1);
         glutSolidCube(1.0);

      glPopMatrix();
   glPopMatrix();
   return;
}

/* Used by drawTurret */
void drawMemBase() {
   glPushMatrix();
      glPushMatrix();
      glRotatef(0, 0.0, 1.0, 0.0);
      glTranslatef(0.0, 0.0, 1.5);      
      glRotatef(35, 1.0, 0.0, 0.0);
      glRotatef(30, 0.0, 1.0, 0.0);
      drawMemStick();
      glPopMatrix();
      
      glPushMatrix();
      glRotatef(90, 0.0, 1.0, 0.0);
      glTranslatef(0.0, 0.0, 1.5);
      glRotatef(35, 1.0, 0.0, 0.0);
      glRotatef(30, 0.0, 1.0, 0.0);
      drawMemStick();
      glPopMatrix();
      
      glPushMatrix();
      glRotatef(180, 0.0, 1.0, 0.0);
      glTranslatef(0.0, 0.0, 1.5);
      glRotatef(35, 1.0, 0.0, 0.0);
      glRotatef(30, 0.0, 1.0, 0.0);
      drawMemStick();
      glPopMatrix();
      
      glPushMatrix();
      glRotatef(270, 0.0, 1.0, 0.0);
      glTranslatef(0.0, 0.0, 1.5);
      glRotatef(35, 1.0, 0.0, 0.0);
      glRotatef(30, 0.0, 1.0, 0.0);
      drawMemStick();
      glPopMatrix();
   glPopMatrix();
}

void drawTurret() {
   glPushMatrix();
      setMaterial(Black);
      glTranslatef(0.0, 1.7, -0.8);
      glScaled(1.1, 0.4, 4.0);
      glutSolidCube(1.0);
      setMaterial(Grey);
      glTranslatef(0.0, 0.0, -0.57);
      glScaled(0.8, 0.5, 0.15);
      glutSolidCube(1.0);
   glPopMatrix();
   
   //drawMemBase();
}

/* Used by drawTrojan */
void drawLeg(int tes) {
   int tesallation = tes;

   glPushMatrix();
      glTranslatef(0.0, -4.0, 0.0);
      glPushMatrix();
         glRotatef(90, 1.0, 0.0, 0.0);
         glScaled(0.5, 0.65, 1.7);
         glPushMatrix();
            glRotatef(10, 1.0, 0.0, 0.0);
            // thigh
            glutSolidCone(1.0, 2.75, tesallation, tesallation);
         glPopMatrix();
         glTranslatef(0.0, -0.2, 1.9);
         // shin
         gluCylinder(gluNewQuadric(), 0.55, 0.35, 1.7, tesallation, tesallation);
      glPopMatrix();
      
      // knee
      glPushMatrix();
         glScaled(0.6, 1.0, 1.0);
         glTranslatef(0.0, -2.9, -0.2);
         glutSolidSphere(0.6, tesallation, tesallation);
      glPopMatrix();
      
      // foot
      glTranslatef(0.0, -5.7, 0.0);
      glRotatef(45, 1.0, 0.0, 0.0);
      glScaled(0.75, 1.0, 1.25);
      glutSolidCube(1.0);
   glPopMatrix();
   return;
}

/* Used by drawTrojan */
void drawWheelBase(int tes ) {
   int tesallation = tes;

   glPushMatrix();
      glPushMatrix();
         glScaled(2.25, 0.55, 3.75);
         glutSolidCube(2.0);
      glPopMatrix();
      
      glTranslatef(2.8, 0.0, -3.0);
      glRotatef(-90, 0.0, 1.0, 0.0);
      gluCylinder(gluNewQuadric(), 1.5, 1.5, 0.5, tesallation, tesallation);
      gluDisk(gluNewQuadric(), 0.0, 1.5, tesallation, tesallation);

      glTranslatef(5.8, 0.0, 0.0);
      gluCylinder(gluNewQuadric(), 1.5, 1.5, 0.5, tesallation, tesallation);
      gluDisk(gluNewQuadric(), 0.0, 1.5, tesallation, tesallation);
      
      glPushMatrix();
         glTranslatef(0.0, 0.0, 5.1);
         gluCylinder(gluNewQuadric(), 1.5, 1.5, 0.5, tesallation, tesallation);
         glTranslatef(0.0, 0.0, 0.5);
         gluDisk(gluNewQuadric(), 0.0, 1.5, tesallation, tesallation);
      glPopMatrix();
      
      glPushMatrix();
         glTranslatef(-5.8, 0.0, 5.1);
         gluCylinder(gluNewQuadric(), 1.5, 1.5, 0.5, tesallation, tesallation);
         glTranslatef(0.0, 0.0, 0.5);
         gluDisk(gluNewQuadric(), 0.0, 1.5, tesallation, tesallation);
      glPopMatrix();
   glPopMatrix();
}

/* This model has a dynamic tail. Tesallations at or below
   4 will render a different tail vs tesallations greater
   than 4 */
void drawTrojan() {
   int tesallation = 8;
   
   glPushMatrix();
      // Body
      glPushMatrix();
         setMaterial(FieryOrange);
         gluCylinder(gluNewQuadric(), 2.0, 2.0, 3.5, tesallation, tesallation);
         glutSolidSphere(2.0, tesallation, tesallation);
         glTranslatef(0.0, 0.0, 3.5);
         glutSolidSphere(2.0, tesallation, tesallation);
      glPopMatrix();
      
      // Head
      glPushMatrix();
         glTranslatef(0.0, 1.30, 4.5);
         // neck
         glPushMatrix();
            glRotatef(-55, 1.0, 0.0, 0.0);
            glScaled(1.0, 1.4, 1.35);
            glutSolidCone(1.0, 3.0, tesallation, tesallation);
         glPopMatrix();
         
         glPushMatrix();
            glTranslatef(0.0, 2.25, 0.5);
            glRotatef(-35, 1.0, 0.0, 0.0);
            glScaled(0.3, 0.75, 5.5);
            glutSolidCube(1.0);
         glPopMatrix();
         
         glTranslatef(0.0, 2.3, 3.0);
         
         // neck disc right
         glPushMatrix();
            glTranslatef(0.6, 0.0, -0.5);
            glRotatef(90, 0.0, 1.0, 0.0);
            gluCylinder(gluNewQuadric(), 0.75, 0.75, 0.4, tesallation, tesallation);
            glTranslatef(0.0, 0.0, 0.4);
            gluDisk(gluNewQuadric(), 0.0, 0.75, tesallation, tesallation);
         glPopMatrix();
         
         // neck disc left
         glPushMatrix();
            glTranslatef(-1.0, 0.0, -0.5);
            glRotatef(90, 0.0, 1.0, 0.0);
            gluCylinder(gluNewQuadric(), 0.75, 0.75, 0.4, tesallation, tesallation);
            gluDisk(gluNewQuadric(), 0.0, 0.75, tesallation, tesallation);
         glPopMatrix();

         // skull
         glPushMatrix();
            glRotatef(55, 1.0, 0.0, 0.0);
            glScaled(0.60, 0.45, 1.5);
            glutSolidCube(2.0);
         glPopMatrix();
         
         // ears
         glPushMatrix();
            glTranslatef(0.6, 1.25, -0.5);
            glRotatef(-100, 1.0, 0.0, 0.0);
            glScaled(0.5, 0.75, 0.75);
            glutSolidCone(0.4, 1.0, tesallation, tesallation);
            glTranslatef(-2.4, 0.0, 0.0);
            glutSolidCone(0.4, 1.0, tesallation, tesallation);
         glPopMatrix();
      glPopMatrix();
   
      glPushMatrix();
         // back legs
         glTranslatef(1.4, 3.5, -0.75);
         drawLeg(tesallation);
         glTranslatef(-2.8, 0.0, 0.0);
         drawLeg(tesallation);
         // front legs
         glTranslatef(0.40, 0.0, 4.5);
         drawLeg(tesallation);
         glTranslatef(2.00, 0.0, 0.0);
         drawLeg(tesallation);
      glPopMatrix();
      
      // dynamic tail
      if (tesallation <= 4) {
         glPushMatrix();
            glTranslatef(0.0, 1.25, -1.0);
            glScaled(0.6, 1.3, 1.3);
            glutSolidSphere(1.0, tesallation, tesallation);
         glPopMatrix();
      } else {
         glPushMatrix();
            glScaled(0.8, 0.8, 0.8);
            glTranslatef(0.0, 1.0, -3.5);
            glRotatef(25, 1.0, 0.0, 0.0);
            glPushMatrix();
               glScaled(0.9, 0.9, 5.0);
               glutSolidCone(1.0, 1.0, tesallation, tesallation);
            glPopMatrix();
            
            glutSolidSphere(1.0, tesallation, tesallation);
            
            glTranslatef(0.0, 0.0, 0.0);
            glRotatef(80, 1.0, 0.0, 0.0);
            glPushMatrix();
               glScaled(0.25, 0.25, 2.0);
               gluCylinder(gluNewQuadric(), 3.0, 2.0, 2.25, tesallation, tesallation);
            glPopMatrix();
             
            glTranslatef(0.0, 0.0, 5.15);
            glutSolidSphere(0.8, tesallation, tesallation);
         glPopMatrix();
      }

      // base
      glTranslatef(0.0, -6.8, 1.5);
      drawWheelBase(tesallation);
   glPopMatrix();
   return;
}

void drawBearLeftArm() {
   glPushMatrix();
      // left arm
      glTranslatef(-2.5, -3.0, 0.0);
      glRotatef(-45, 0.0, 0.0, 1.0);
      glPushMatrix();
         glScaled(0.65, 1.8, 0.65);
         glutSolidSphere(1.0, 10, 10);
      glPopMatrix();

      glTranslatef(0.5, -1.0, 1.0);
      glRotatef(-55, 0.0, 1.0, 0.0);
      glRotatef(-70, 0.0, 0.0, 1.0);
      glPushMatrix();
         glScaled(0.65, 1.5, 0.65);
         glutSolidSphere(1.0, 10, 10);
      glPopMatrix();
   glPopMatrix();
}

void drawBearRightArm() {
   glPushMatrix();
      // right arm
      glTranslatef(2.5, -3.0, 0.0);
      glRotatef(45, 0.0, 0.0, 1.0);
      glPushMatrix();
         glScaled(0.65, 1.8, 0.65);
         glutSolidSphere(1.0, 10, 10);
      glPopMatrix();
               
      glTranslatef(-0.5, -1.0, 1.0);
      glRotatef(55, 0.0, 1.0, 0.0);
      glRotatef(70, 0.0, 0.0, 1.0);
      glPushMatrix();
         glScaled(0.65, 1.5, 0.65);
         glutSolidSphere(1.0, 10, 10);
      glPopMatrix();
   glPopMatrix();
}

void drawBearLeftLeg() {
   glPushMatrix();
      // left leg
      glTranslatef(-0.95, -6.0, 1.0);
      glRotatef(75, 0.0, 1.0, 0.0);
      glRotatef(-35, 0.0, 0.0, 1.0);
      glPushMatrix();
         glScaled(1.75, 4.0, 1.75);
         glutSolidSphere(0.5, 20, 20);
      glPopMatrix();

      glTranslatef(1.25, -2.00, 0.0);
      glRotatef(70, 0.0, 0.0, 1.0);
      glPushMatrix();
         glScaled(1.20, 3.0, 1.20);      
         glutSolidSphere(0.5, 20, 20);
      glPopMatrix();

      glTranslatef(0.90, -1.70, 0.0);
      glRotatef(-120, 0.0, 0.0, 1.0);
      glTranslatef(0.0, -2.5, 0.0);
      glPushMatrix();
         glScaled(1.0, 6.5, 2.0);
         glutSolidCube(0.5);
      glPopMatrix();
   glPopMatrix();
}

void drawBearRightLeg() {
   glPushMatrix();
      // right leg
      glTranslatef(0.95, -6.0, 1.0);
      glRotatef(105, 0.0, 1.0, 0.0);
      glRotatef(-35, 0.0, 0.0, 1.0);
      glPushMatrix();
         glScaled(1.75, 4.0, 1.75);
         glutSolidSphere(0.5, 20, 20);
      glPopMatrix();
      
      glTranslatef(1.25, -2.00, 0.0);
      glRotatef(70, 0.0, 0.0, 1.0);
      glPushMatrix();
         glScaled(1.20, 3.0, 1.20);      
         glutSolidSphere(0.5, 20, 20);
      glPopMatrix();

      glTranslatef(0.90, -1.70, 0.0);
      glRotatef(-120, 0.0, 0.0, 1.0);
      glTranslatef(0.0, -2.5, 0.0);
      glPushMatrix();
         glScaled(1.0, 6.5, 2.0);
         glutSolidCube(0.5);
      glPopMatrix();
   glPopMatrix();
}


void drawEar() {
	glPushMatrix();
      setMaterial(Brown);
      glutSolidTorus(0.45, 2.0, 10, 20);
      setMaterial(RedFlat);
      gluDisk(gluNewQuadric(), 0.0, 2.0, 20, 1);
      glRotatef(180.0, 1.0, 0.0, 0.0);
      glTranslatef(0.0, 0.0, 0.01);
      gluDisk(gluNewQuadric(), 0.0, 2.0, 20, 1);
   glPopMatrix();
   return;
}

void drawBearCore() {
   glPushMatrix();
      glPushMatrix();
         // head
         setMaterial(Brown);
         glScaled(1.725, 1.45, 1.20);
         glutSolidSphere(2, 20, 20);
      glPopMatrix();
      
      glPushMatrix();
         // eyes
         setMaterial(Black);
         glTranslatef(1.4, 0.0, 2.25);
         glutSolidSphere(0.5, 10, 10);
         glTranslatef(-2.8, 0.0, 0.0);
         glutSolidSphere(0.5, 10, 10);
      glPopMatrix();
      
      glPushMatrix();
         // mouth
         glTranslatef(0.0, -1.0, 2.5);
         glPushMatrix();
            glTranslatef(0.0, -0.15, 0.7);
            glutSolidSphere(0.5, 10, 10);
         glPopMatrix();
         
         glPushMatrix();
            setMaterial(LightBrown);
            glTranslatef(0.75, -0.25, 0.0);
            glutSolidSphere(0.6, 10, 10);
            glTranslatef(-1.5, 0.0, 0.0);
            glutSolidSphere(0.6, 10, 10);
         glPopMatrix();
         
         glPushMatrix();
            glTranslatef(0.0, -1.0, -0.3);
            glRotatef(-10, 1.0, 0.0, 0.0);
            glScaled(0.35, 0.425, 0.35);
            drawEar();
         glPopMatrix();
      glPopMatrix();
      
      glPushMatrix();
         // Ears
         glTranslatef(2.5, 2.0, 0.0);
         glPushMatrix();
            glScaled(0.45, 0.45, 0.45);
            drawEar();
         glPopMatrix();
         glTranslatef(-5.0, 0.0, 0.0);
         glPushMatrix();
            glScaled(0.45, 0.45, 0.45);
            drawEar();
         glPopMatrix();
      glPopMatrix();
      
      glPushMatrix();
         // head hair
         setMaterial(Brown);
         glPushMatrix();
            // right side
            glRotatef(40, 0.0, 0.0, 1.0);
            glRotatef(70, 1.0, 0.0, 0.0);
            glTranslatef(0.0, 0.0, 2.25);
            glutSolidCone(0.45, 1.3, 10, 10);
            glRotatef(10, 1.0, 1.0, 0.0);
            glTranslatef(0.5, -0.25, 0.5);
            glutSolidCone(0.45, 1.3, 10, 10);
            glRotatef(10, 1.0, 1.0, 0.0);
            glTranslatef(0.5, -0.25, 0.3);
            glutSolidCone(0.45, 1.3, 10, 10);
            glRotatef(10, 1.0, 1.0, 0.0);
            glTranslatef(0.5, -0.25, 0.0);
            glutSolidCone(0.45, 1.3, 10, 10);
            glRotatef(10, 1.0, 1.0, 0.0);
            glTranslatef(0.5, -0.25, 0.0);
            glutSolidCone(0.45, 1.3, 10, 10);
         glPopMatrix();
         
         glPushMatrix();
            // left side
            glRotatef(-40, 0.0, 0.0, 1.0);
            glRotatef(70, 1.0, 0.0, 0.0);
            glTranslatef(0.0, 0.0, 2.25);
            glutSolidCone(0.45, 1.3, 10, 10);
            glRotatef(-10, 0.0, 1.0, 0.0);
            glRotatef(10, 1.0, 0.0, 0.0);
            glTranslatef(-0.5, -0.25, 0.5);
            glutSolidCone(0.45, 1.3, 10, 10);
            glRotatef(-10, 0.0, 1.0, 0.0);
            glRotatef(10, 1.0, 0.0, 0.0);
            glTranslatef(-0.5, -0.25, 0.5);
            glutSolidCone(0.45, 1.3, 10, 10);
            glRotatef(-10, 0.0, 1.0, 0.0);
            glRotatef(10, 1.0, 0.0, 0.0);
            glTranslatef(-0.5, -0.25, 0.0);
            glutSolidCone(0.45, 1.3, 10, 10);
            glRotatef(-10, 0.0, 1.0, 0.0);
            glRotatef(10, 1.0, 0.0, 0.0);
            glTranslatef(-0.5, -0.25, 0.0);
            glutSolidCone(0.45, 1.3, 10, 10);
         glPopMatrix();
      glPopMatrix();
      
      glPushMatrix();
         // body
         glTranslatef(0.0, -3.6, -0.2);
         glScaled(0.95, 1.2, 0.95);
         glutSolidSphere(2.5, 30, 30);
      glPopMatrix();
   glPopMatrix();
}

void drawBearDLAnimated(int rotation) {
   glCallList(vtd_dl::bearDL);

   // +
   glPushMatrix();
      glRotatef(rotation, 1.0, 0.0, 0.0);
      drawBearLeftArm();
   glPopMatrix();
   // - 
   glPushMatrix(); 
      glRotatef(-rotation, 1.0, 0.0, 0.0);
      drawBearRightArm();
   glPopMatrix();
   // - 
   glPushMatrix();
      glRotatef(-rotation, 1.0, 0.0, 0.0);
      drawBearLeftLeg();
   glPopMatrix();
   // +
   glPushMatrix();
      glRotatef(rotation, 1.0, 0.0, 0.0);
      drawBearRightLeg();
   glPopMatrix();
}

using namespace vtd_dl;
void composeDisplayLists(){
  lockDL = glGenLists(1);
  blkhatDL = glGenLists(1);
  forkbDL = glGenLists(1);
  virusDL = glGenLists(1);
  wormDL = glGenLists(1);
  backtrackDL = glGenLists(1);
  teslaDL = glGenLists(1);
  fanDL = glGenLists(1);
  shieldDL = glGenLists(1);
  turretDL = glGenLists(1);
  turretBaseDL = glGenLists(1);
  trojanDL  = glGenLists(1);
  bearDL = glGenLists(1);

  glNewList(lockDL, GL_COMPILE);
    drawLock();
  glEndList();

  glNewList(blkhatDL, GL_COMPILE);
    drawBlackHat();
  glEndList();

  glNewList(forkbDL, GL_COMPILE);
    drawForkBomb();
  glEndList();

  glNewList(virusDL, GL_COMPILE);
    drawVirus();
  glEndList();

  glNewList(wormDL, GL_COMPILE);
    drawWorm();
  glEndList();

  glNewList(backtrackDL, GL_COMPILE);
    drawBackTrack();
  glEndList();

  glNewList(teslaDL, GL_COMPILE);
    drawTeslaCoil();
  glEndList();

  glNewList(fanDL, GL_COMPILE);
    glPushMatrix();
       drawCPUFan();
       glTranslatef(0.0, 0.0, 12.0);
       drawCPUFan();
       glTranslatef(0.0, 0.0, -7.0);
       drawCPUFanBase();
    glPopMatrix();
  glEndList();

  glNewList(shieldDL, GL_COMPILE);
    drawShield();
  glEndList();

  glNewList(turretDL, GL_COMPILE);
    drawTurret();
  glEndList();
  
  glNewList(turretBaseDL, GL_COMPILE);
    drawMemBase();
  glEndList();
  
  glNewList(trojanDL, GL_COMPILE);
    drawTrojan();
  glEndList();
  
  glNewList(bearDL, GL_COMPILE);
    drawBearCore();
  glEndList();
}