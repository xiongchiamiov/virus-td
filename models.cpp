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
   glutSolidSphere(0.45, 10, 10);
   glTranslatef(0.0, 0.0, -4.0);
   glutSolidSphere(0.45, 10, 10);
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

void drawBackTrack() {
   // save the transformation state
   glPushMatrix();
      // set the material
      GLfloat diffuseColor[] = {1.0, 1.0, 1.0, 1.0};
      glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);

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
                  glutSolidCone(1.0, 1.5, 10, 10);
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
                  glutSolidCone(1.0, 1.5, 10, 10);
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
            glutSolidSphere(1.0, 12, 12);
         }
         
         // Neck Horns
         glPushMatrix();

            glTranslatef(-1.5, 1.0, 0.0);
            glRotatef(-90, 1.0, 0.0, 0.0);
            glRotatef(-40, 0.0, 1.0, 0.0); // z == y, y ==z
            glScaled(0.75, 0.5, 1.5);
            glutSolidCone(1.0, 2.0, 10, 10);
            
            glTranslatef(-2.0, 0.0, 1.2);
            glutSolidCone(1.0, 2.0, 10, 10);

            glTranslatef(-2.0, 0.0, 1.2);
            glutSolidCone(1.0, 2.0, 10, 10);
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
         glutSolidSphere(2.0, 10, 10);

         // Eyes 
         diffuseColor[0] = 1.0;
         diffuseColor[1] = 0.0;
         diffuseColor[2] = 0.0;
         glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);

         glPushMatrix();
            glTranslatef(1.2, 0.0, 1.5);
            glRotatef(45, 1.0, 0.0, 0.0);
            glRotatef(45.0, 0.0, 0.0, 1.0);
            glScaled(0.7, 1.5, 0.7);
            glutSolidSphere(0.5, 10, 10);
         glPopMatrix();

         glPushMatrix();
            glTranslatef(1.2, 0.0, -1.5);
            glRotatef(-45, 1.0, 0.0, 0.0);
            glRotatef(45.0, 0.0, 0.0, 1.0);
            glScaled(0.7, 1.5, 0.7);
            glutSolidSphere(0.5, 10, 10);
         glPopMatrix();
         
         diffuseColor[0] = 1.0;
         diffuseColor[1] = 1.0;
         diffuseColor[2] = 1.0;
         glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);
         
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
            glutSolidSphere(1.0, 10, 10);
         }

         for (int i = 0; i < 17; i++) {
            glRotatef(5.0, 0.0, 0.0, 1.0);
            glTranslatef(-0.7, 0.1 + (i * 1.0 / 50), 0.0);
            glScaled(1.03, 1.03, 1.03);
            glutSolidSphere(1.0, 10, 10);
         }

         for (int i = 17; i > -2; i--) {
            glRotatef(5.0, 0.0, 0.0, 1.0);
            glTranslatef(-0.9, + (0.1 + (i * 1.0 / 50)), 0.0);
            glScaled(0.99, 0.99, 0.99);
            glutSolidSphere(1.0, 10, 10);
         }

         for (int i = 0; i < 5; i++) {
            glTranslatef(-0.8, 0.05, 0.0);
            glScaled(0.999, 0.999, 0.999);
            glutSolidSphere(1.0, 10, 10);
         }

         for (int i = 0; i < 5; i++) {
            glTranslatef(-0.8, 0.05, 0.0);
            glScaled(1.03, 1.03, 1.03);
            glutSolidSphere(1.0, 10, 10);
         }

         // Left Tail Fork
         glPushMatrix();
            for (int i = 0; i < 30; i++) {
               glRotatef(-5.0, 0.0, 0.0, 1.0);
               glTranslatef(-0.85, -0.1 * (i * 0.5), -0.2);
               glScaled(1.0, 0.925, 0.90);
               glutSolidSphere(1.0, 10, 10);
            }
         glPopMatrix();
         // Right Tail Fork
         glPushMatrix();
            for (int i = 0; i < 30; i++) {
               glRotatef(-5.0, 0.0, 0.0, 1.0);
               glTranslatef(-0.85, -0.1 * (i * 0.5), 0.2);
               glScaled(1.0, 0.925, 0.90);
               glutSolidSphere(1.0, 10, 10);
            }
         glPopMatrix();
      glPopMatrix();
      
   glPopMatrix();

   return;
}
