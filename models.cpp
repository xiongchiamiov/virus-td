#include "models.h"

void drawWorm() {
   // save the transformation state
   glPushMatrix();

   // set the material
   GLfloat diffuseColor[] = {1.0, 1.0, 0.0, 1.0};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);

   // locate it in the scene
   glMatrixMode(GL_MODELVIEW);
   
   // Eyes
   glPushMatrix();
   diffuseColor[0] = 1.0;
   diffuseColor[1] = 1.0;
   diffuseColor[2] = 1.0;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);
   glScaled(0.5, 2.0, 0.5);
   glTranslatef(3.5, 1.4, 2.0);
   glutSolidSphere(0.4, 10, 10);
   glTranslatef(0.0, 0.0, -4.0);
   glutSolidSphere(0.4, 10, 10);
   glPopMatrix();
   
   diffuseColor[0] = 1.0;
   diffuseColor[1] = 1.0;
   diffuseColor[2] = 0.0;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);

   // Hierarchical transforms
   glScaled(2.0, 2.0, 2.0);
   glTranslatef(0.0, 1.0, 0.0);
   glutSolidSphere(1.0, 20, 20);
   
   // Head
   for (int i = 0; i < 10; i++) {
      glScaled(0.95, 0.95, 0.95);
      glRotatef(15.0, 0.0, 0.0, 1.0);
      glTranslatef(-0.5, 0.4, 0.0);
      glutSolidSphere(1.0, 20, 20);
   }

   // Mid Section
   glTranslatef(-0.6, 0.2, 0.0);
   glutSolidSphere(1.0, 20, 20);

   glTranslatef(-0.6, 0.12, 0.0);
   glutSolidSphere(1.0, 20, 20);

   glTranslatef(-0.6, 0.17, 0.0);
   glutSolidSphere(1.0, 20, 20);

   glTranslatef(-0.6, 0.2, 0.0);
   glutSolidSphere(1.0, 20, 20);

   glTranslatef(-0.6, 0.22, 0.0);
   glutSolidSphere(1.0, 20, 20);
   
   glTranslatef(-0.7, 0.27, 0.0);
   glutSolidSphere(1.0, 20, 20);
   
   glTranslatef(-0.7, 0.3, 0.0);
   glutSolidSphere(1.0, 20, 20);
   
   glTranslatef(-0.9, 0.42, 0.0);
   glutSolidSphere(1.0, 20, 20);
   
   glTranslatef(-0.9, 0.62, 0.0);
   glutSolidSphere(1.0, 20, 20);
   
   glRotatef(180, 0.0, 1.0, 0.0);
   glRotatef(-180, 0.0, 0.0, 1.0);
   
   // Lower Front Body   
   for (int i = 0; i < 6; i++) {
      glScaled(0.95, 0.95, 0.95);
      glRotatef(15.0, 0.0, 0.0, 1.0);
      glTranslatef(-0.6, -0.4, 0.0);
      glutSolidSphere(1.0, 20, 20);
   }
   
   // Lower Mid Body
   for (int i = 0; i < 2; i++) {
      glTranslatef(-0.5, -0.6, 0.0);
      glutSolidSphere(1.0, 20, 20);
   }

   // Tail
   for (int i = 0; i < 10; i++) {
      glScaled(0.95, 0.95, 0.95);
      glRotatef(15.0, 0.0, 0.0, 1.0);
      glTranslatef(-0.6, -0.4, 0.0);
      glutSolidSphere(1.0, 20, 20);
   }

   glPopMatrix();

   return;
}
