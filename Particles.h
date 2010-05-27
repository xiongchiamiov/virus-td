#pragma once
#include "lighting.h"
#include "textures.h"

/* How it works: each tower has a particle instance variable/attribute
   in which it initializes the weapon type in it's constructor. The main
   application will initialize the textures for the weapon types. 
   Wepaon types can be changes with the setWeaponType function, but only
   among the weapon types available. Particles are drawn and updated
   in each tower's draw function. 
   
   Particle updating functions are very touchy, aka they use alot of 
   magic numbers to tweak speed and look. */

/* Particel System Variables. */
const int NUM_PARTICLES = 20;
const int NUM_SUBPARTICLES = 10;
const float GRAVITY = 16;
const float HEAT = 10;
const float DRAG = 0.05;
const float TIMESTEP = 0.1; 
const float PULLSTR = 10;
const float WINDFORCE = 10;

extern GLuint particle_texture[4];

class Particles {
   public:
      Particles(double partSize);
      ~Particles(void);
      void drawParticles();
      void setParticleSize(double partSize);
      void sumForces(void);
      void EularIntegrate(void);
      void reset(void);
      void setWeaponType(GLuint wepType);
   private:
      float mass[NUM_PARTICLES];
      float pos[NUM_PARTICLES][3];
      float vel[NUM_PARTICLES][3];
      float acc[NUM_PARTICLES][3];
      float force[NUM_PARTICLES][3];
      float rotate[NUM_PARTICLES];
      float color[NUM_PARTICLES][3];
      double particle_size;
      GLuint weapon_type;
    // float speed;
    //  int x_cutoff;
    //  int y_cutoff;
    //  int z_cutoff;  
};

/* Wrapper function around rand() to generate non-uniform values */
double rand_non_uniform();
/* Billboarding setup function */
void billboardSphericalBegin();
/* Billboarding cleanup function */
void billboardSphericalEnd();

void initializeParticleTextures();
