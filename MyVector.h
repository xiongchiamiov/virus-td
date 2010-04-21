#pragma once

class MyVector
{
public:
  MyVector(void);
  MyVector(float in_i, float in_j, float in_k, float in_x, float in_y, float in_z);
  MyVector(float in_i, float in_j, float in_k);
  ~MyVector(void);
  void setVector(float in_i, float in_j, float in_k);
  void setPosition(float in_x, float in_y, float in_z);
  float dotProduct(MyVector other);
  void crossProduct(MyVector other, MyVector& newVector);
  float getLength();
  float getI();
  float setI(float newI);
  float getJ();
  float setJ(float newJ);
  float getK();
  float setK(float newK);
  float getX();
  float setX(float newX);
  float getY();
  float setY(float newY);
  float getZ();
  float setZ(float newZ);
  void normalize();
  MyVector& operator=(const MyVector& other);
  MyVector& operator+=(const MyVector& other);
  MyVector& operator-=(const MyVector& other);
  MyVector& operator+(const MyVector& other);
  MyVector& operator-(const MyVector& other);

private:
  float i;
  float j;
  float k;
  float x;
  float y;
  float z;
};
