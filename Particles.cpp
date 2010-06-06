#include "Particles.h"

GLuint particle_texture[4];

Particles::Particles(double partSize) {
   particle_size = partSize;
   
   /* default is fire */
   weapon_type = particle_texture[0];
   
   direction[0] = 0.0;
   direction[1] = 0.0;
   direction[2] = 1.0;
   
   spread = 2.0;
   AoE = false;
   non_random_AoE = true;
   speed = 1.0;
   cutoff[0] = 20;
   cutoff[1] = 7;
   cutoff[2] = 20;
   // initial values for all the particles
   // must be last thing called cuz it needs the initialized
   // variables above.
   reset();
}
Particles::~Particles(){
}

void Particles::drawParticles() {
   sumForces();
   EularIntegrate();

   static int lock = 0;

   // draw all the particles

   for (int i=0; i<NUM_PARTICLES; i++) {
      // for each particle

      // save the transformation state
      glPushMatrix();

      glRotatef(rotate[i], 0, 0, 1);
      // this translation will be used to animate the particle
      glTranslatef(pos[i][0], pos[i][1], pos[i][2]);	 
	glShadeModel(GL_SMOOTH);						           // Enables Smooth Shading
//	glClearColor(0.0f,0.0f,0.0f,0.0f);					     // Black Background
//	glClearDepth(1.0f);							              // Depth Buffer Setup
   glDisable(GL_DEPTH_TEST);						           // Disables Depth Testing
	glEnable(GL_BLEND);							              // Enable Blending
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);					     // Type Of Blending To Perform
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);	  // Really Nice Perspective Calculations
	glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);				  // Really Nice Point Smoothing
	glEnable(GL_TEXTURE_2D);						           // Enable Texture Mapping
      // each particle is just a glPoint
 //     glBegin(GL_POINTS);
   //      glColor3f(color[i][0], color[i][1], color[i][2]);
  //       glVertex3f(0.0, 0.0, 0.0);
 //     glEnd();
 //	glDisable(GL_LIGHTING);
//	glEnable(GL_TEXTURE_2D);
glEnable(GL_LIGHTING);
   // this is just for fun dynamic particles and mixing
   if (lock == 0) {
 //     if(num == 1) {
         glBindTexture(GL_TEXTURE_2D, weapon_type);
  //    } else if (num == 2) {
   //      glBindTexture(GL_TEXTURE_2D, testMap2);
   //   } else if (num == 3) {
   //      glBindTexture(GL_TEXTURE_2D, testMap3);
   //   } else if (num == 4) {
   //      glBindTexture(GL_TEXTURE_2D, testMap4);
   //   }

      lock = 1;
   } else {
   //   if(num == 1) {
         glBindTexture(GL_TEXTURE_2D, weapon_type);
   //   } else if (num == 2) {
   //      glBindTexture(GL_TEXTURE_2D, testMap2);
   //   } else if (num == 3) {
   //      glBindTexture(GL_TEXTURE_2D, testMap3);
   //   } else if (num == 4) {
   //      glBindTexture(GL_TEXTURE_2D, testMap4);
   //   }
      lock = 0;
   }
   
   setMaterial(White);
   billboardSphericalBegin();
	glBegin(GL_QUADS);
    glTexCoord2f(0.0,1.0);
    glVertex2f(0.0, 0.0);
    glTexCoord2f(1.0,1.0);
    glVertex2f(particle_size, 0.0);
    glTexCoord2f(1.0,0.0);
    glVertex2f(particle_size, particle_size);
    glTexCoord2f(0.0,0.0);
    glVertex2f(0.0, particle_size);
   glEnd();
   billboardSphericalEnd();
   

	//glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
   glDisable(GL_BLEND);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(SHADING_MODE);
	//glEnable(GL_LIGHTING); // <-- this makes it look amazing
   
     // recover the transform state
      glPopMatrix();
   }

   return;
}

void Particles::setParticleSize(double partSize) {
   particle_size = partSize;
}

void Particles::sumForces(void) {
   // for this timestep, accumulate all the forces that
   //   act on each particle
   double yDistance, xDistance, zDistance, totalDistance;
   
   for (int i=0; i<NUM_PARTICLES; i++) {
      yDistance = (pos[i][1] - 0);
      xDistance = (pos[i][0] - 0);
      zDistance = (pos[i][2] - 0);

      totalDistance = (xDistance * xDistance + yDistance * yDistance);
     
   //   if (elapsedTime < 250) {
         // ZERO ALL FORCES

          // GRAVITY (Y forces)
   //   force[i][1] = -GRAVITY*mass[i] + WINDFORCE;
      
      // WINDFORCE (X Forces)
   //   force[i][0] += WINDFORCE;
      if (!AoE) {
         force[i][0] = force[i][1] = force[i][2] = 0.0;
         //x direction force
         force[i][0] -= WINDFORCE * direction[0] * -1;
         // y direction force
         force[i][1] -= WINDFORCE * direction[1] * -1;
         // z direction force
         force[i][2] -= WINDFORCE * direction[2] * -1;
      }

      if (pos[i][1] >= -4 && pos[i][1] <= 4) {
    //     force[i][0] += (WINDFORCE * 0.15);
      }
      if (pos[i][1] >= -2 && pos[i][1] <= 2) {
    //     force[i][0] += (WINDFORCE * 0.15);
      }
      if (pos[i][1] >= -0.5 && pos[i][1] <= 0.5) {
    //     force[i][0] += (WINDFORCE * 0.15);
      }

         // GRAVITY (Y forces)
         //force[i][1] = -GRAVITY*mass[i] + WINDFORCE;
      //   if (pos[i][1] > 0) {
       //     force[i][1] = -PULLSTR / (totalDistance);
      //   } else {
      //      force[i][1] = PULLSTR / (totalDistance);
      //   }
         // WINDFORCE (X Forces)
         //force[i][0] += WINDFORCE;
        // if (pos[i][0] > 0) {
        //    force[i][0] = -PULLSTR / (totalDistance);
        // } else {
         //   force[i][0] = PULLSTR / (totalDistance);
        // }

      //   force[i][2] = -1.0 / pow(E - 1, totalDistance - 13);

         // WINDFORCE
    //     rotate[i]+= SPINSPEED / (totalDistance);
  //    }
      
  //    color[i][0] = sqrt(totalDistance) / 10.0;
  //    color[i][1] = sqrt(totalDistance) / 10.0;
  //    color[i][2] = sqrt(totalDistance) / 10.0;
   }
}

void Particles::EularIntegrate(void) {
   // for each particle, compute the new velocity
   //   and position
 //  elapsedTime++;
//fprintf(stdout, "%d\n", elapsedTime);
   for (int i = 0; i < NUM_PARTICLES; i++) {
      // CALCULATE NEW ACCEL
      acc[i][0] = force[i][0] / mass[i];
      acc[i][1] = force[i][1] / mass[i];
      acc[i][2] = force[i][2] / mass[i];

      // CALCULATE NEW POS
      pos[i][0] += vel[i][0] * TIMESTEP +
                        0.5 * acc[i][0] * TIMESTEP * TIMESTEP;
      pos[i][1] += vel[i][1] * TIMESTEP +
                        0.5 * acc[i][1] * TIMESTEP * TIMESTEP;
      pos[i][2] += vel[i][2] * TIMESTEP +
                        0.5 * acc[i][2] * TIMESTEP * TIMESTEP;
   
      // CALCULATE NEW VEL
      vel[i][0] += acc[i][0] * TIMESTEP;
      vel[i][1] += acc[i][1] * TIMESTEP;
      vel[i][2] += acc[i][2] * TIMESTEP;
      
   //   if (pos[i][2] < -12) {
   
      // x cutoff resets
      if (/*direction[0] <= 0 &&*/ pos[i][0] < -cutoff[0]) {
         resetSingleParticle(i);
      } else if (/*direction[0] >= 0 &&*/ pos[i][0] > cutoff[0]) {
         resetSingleParticle(i);
      } else

      // y cutoff resets
      if (/*direction[1] <= 0 &&*/ pos[i][1] < -cutoff[1]) {
         resetSingleParticle(i);
      } else if (/*direction[1] >= 0 && */pos[i][1] > cutoff[1]) {
         resetSingleParticle(i);
      } else

      // z cutoff resets
      if (/*direction[2] <= 0 &&*/ pos[i][2] < -cutoff[2]) {
         resetSingleParticle(i);
      } else if (/*direction[2] >= 0 &&*/ pos[i][2] > cutoff[2]) {
         resetSingleParticle(i);
      }
   }
}

/* reset particles */
void Particles::reset() {
   for (int i=0; i<NUM_PARTICLES; i++) {
      mass[i] = 5.0;//rand_non_uniform() * 2.0;//1.0;
   
      pos[i][0] = rand_non_uniform() * spread;
      pos[i][1] = rand_non_uniform() * spread;
      pos[i][2] = rand_non_uniform() * spread;
   
      vel[i][0] = rand_non_uniform() * speed; 
      vel[i][1] = rand_non_uniform() * speed; 
      vel[i][2] = rand_non_uniform() * speed; 
      
      acc[i][0] = 0.0;
      acc[i][1] = 0.0;
      acc[i][2] = 0.0;
      
      if (!AoE) {
         force[i][0] = 0.0;
         force[i][1] = 0.0;
         force[i][2] = 0.0;
      } else {
         if (non_random_AoE) {
            pos[i][0] = 0.0;
            pos[i][1] = 0.0;
            pos[i][2] = 0.0;
   
            vel[i][0] = 0.0; 
            vel[i][1] = 0.0; 
            vel[i][2] = 0.0; 

            force[i][0] = speed * rand_non_uniform() * direction[0];
            force[i][1] = speed * rand_non_uniform() * direction[1];
            force[i][2] = speed * rand_non_uniform() * direction[2];
         } else {
            force[i][0] = rand_non_uniform() * speed * direction[0];
            force[i][1] = rand_non_uniform() * speed * direction[1];
            force[i][2] = rand_non_uniform() * speed * direction[2];
         }
      }

      rotate[i] = 0;

    //  color[i][0] = 1.0;
    //  color[i][1] = 1.0;
    //  color[i][2] = 1.0;
   }
}

void Particles::resetSingleParticle(int index) {
      mass[index] = 5.0;//rand_non_uniform() * 2.0;//1.0;
      
      pos[index][0] = rand_non_uniform() * spread;
      pos[index][1] = rand_non_uniform() * spread;
      pos[index][2] = rand_non_uniform() * spread;
   
      vel[index][0] = rand_non_uniform() * speed; 
      vel[index][1] = rand_non_uniform() * speed; 
      vel[index][2] = rand_non_uniform() * speed; 
      
      acc[index][0] = 0.0;
      acc[index][1] = 0.0;
      acc[index][2] = 0.0;
      
      if (!AoE) {
         force[index][0] = 0.0;
         force[index][1] = 0.0;
         force[index][2] = 0.0;
      } else {
         if (non_random_AoE) {
            pos[index][0] = 0.0;
            pos[index][1] = 0.0;
            pos[index][2] = 0.0;
   
            vel[index][0] = 0.0; 
            vel[index][1] = 0.0; 
            vel[index][2] = 0.0; 

            force[index][0] = speed * rand_non_uniform() * direction[0];
            force[index][1] = speed * rand_non_uniform() * direction[1];
            force[index][2] = speed * rand_non_uniform() * direction[2];
         } else {
            force[index][0] = rand_non_uniform() * speed * direction[0];
            force[index][1] = rand_non_uniform() * speed * direction[1];
            force[index][2] = rand_non_uniform() * speed * direction[2];
         }
      }

      rotate[index] = 0;

    //  color[index][0] = 1.0;
    //  color[index][1] = 1.0;
    //  color[index][2] = 1.0;
}
      
/* Sets the weapon type of this particle (Set in sub-tower constructors) */
void Particles::setWeaponType(GLuint wepType) {
   weapon_type = wepType;
}

void Particles::setAoE(bool yes, bool uniform) {
   AoE = yes;
   non_random_AoE = uniform;
}

// makes rand() non-uniform is capable of generating negative 
// values.
double rand_non_uniform() {
   double temp = 0;
   
   for (int i = 0; i < 12 ; i++) {
      temp += (rand() * 1.0 / RAND_MAX);
   }
   
   temp -= 6;
   
   return temp / 6;
}

/* normalizes vectors for you */ 
void Particles::setDirection(float xDir, float yDir, float zDir, bool normalize) {
   if (normalize) {
      int magnitude = sqrt(xDir * xDir + yDir * yDir + zDir * zDir);

      direction[0] = xDir / magnitude;
      direction[1] = yDir / magnitude;
      direction[2] = zDir / magnitude;
   } else {
      direction[0] = xDir;
      direction[1] = yDir;
      direction[2] = zDir;
   }
}

/* Sets how far the particles will spray out */ 
void Particles::setSpread(int sp) {
   spread = sp;      
}

void Particles::setSpeed(double spd) {
   speed = spd;
}

void Particles::setCutOffs(int xCut, int yCut, int zCut) {
   cutoff[0] = xCut;
   cutoff[1] = yCut;
   cutoff[2] = zCut;
}

// use the simpler version so it's not dependent on camera
void billboardSphericalBegin() {
	
	float modelview[16];
	int i,j;

	// save the current modelview matrix
	glPushMatrix();

	// get the current modelview matrix
	glGetFloatv(GL_MODELVIEW_MATRIX , modelview);

	// undo all rotations
	// beware all scaling is lost as well 
	for( i=0; i<3; i++ ) 
	    for( j=0; j<3; j++ ) {
		if ( i==j )
		    modelview[i*4+j] = 1.0;
		else
		    modelview[i*4+j] = 0.0;
	    }

	// set the modelview with no rotations
	glLoadMatrixf(modelview);
}

void billboardSphericalEnd() {
   glPopMatrix();
}

/* Particles will choose which type to use */
void initializeParticleTextures() {
   particle_texture[0] = LoadTexture("fire.bmp");
   particle_texture[1] = LoadTexture("green_fire.bmp");
   particle_texture[2] = LoadTexture("blue_fire.bmp");
   particle_texture[3] = LoadTexture("arcane.bmp");
}

/* Stupid function that randomizes 1 or -1 */
int neg_pos_rand() {
   double temp = rand_non_uniform();

   if (temp <= 0) {
      return -1;
   } else {
      return 1;
   }
}
