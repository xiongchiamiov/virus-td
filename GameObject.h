#pragma once
#include "lighting.h"

class GameObject
{
public:
  GameObject();
  GameObject(float x, float y, float z);
  virtual ~GameObject(void);
  inline float getX(void){return x;}
  inline float getY(void){return y;}
  inline float getZ(void){return z;}
  //Virtual functions to implement
  virtual void draw() = 0;
  virtual void step(int dt) = 0;
protected:
  float x;
  float y; 
  float z;
};
