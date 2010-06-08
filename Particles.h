#pragma once
#include "lighting.h"
#include "textures.h"
#include <math.h>

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

extern GLuint particle_texture[5];

class Particles {
   public:
      Particles(double partSize);
      ~Particles(void);
      void drawParticles();
      void setParticleSize(double partSize);
      void sumForces(void);
      void EularIntegrate(void);
      void reset(void);   /* should call this to update particle system with latest values */
      void resetSingleParticle(int index); /* only used in EularIntegrate to update one single particle */
      void setWeaponType(GLuint wepType);
      void setDirection(float xDir, float yDir, float zDir, bool normalize); /* normalizes vector for you */
      void setSpread(int sp);
      void setAoE(bool yes, bool uniform);
      void setSpeed(double spd);
      void setCutOffs(int xCut, int yCut, int zCut);
      inline GLuint getWeaponType(){ return weapon_type;}
   private:
      float mass[NUM_PARTICLES];
      float pos[NUM_PARTICLES][3];
      float vel[NUM_PARTICLES][3];
      float acc[NUM_PARTICLES][3];
      float force[NUM_PARTICLES][3];
      float rotate[NUM_PARTICLES];
      float color[NUM_PARTICLES][3];
      double particle_size; /* bigger particle == bigger texture mapping */
      GLuint weapon_type; /* texture type */
      double speed; /* alters velocity for non AoE, force for AoE */
      int cutoff[3]; /* cutoff distances for x, y, and z */
      float direction[3]; /* <x, y, z> */
      int spread; /* how far apart particles get */
      bool AoE; /* aoe ?*/
      bool non_random_AoE; /* unform blast or random spread blast */
};

/* Wrapper function around rand() to generate non-uniform values */
double rand_non_uniform();
/* Billboarding setup function */
void billboardSphericalBegin();
/* Billboarding cleanup function */
void billboardSphericalEnd();

void initializeParticleTextures();

int neg_pos_rand();
