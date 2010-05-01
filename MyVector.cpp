#include <math.h>
#include "MyVector.h"

MyVector::MyVector(void):
i(0), j(0), k(0), x(0), y(0), z(0)
{
}

MyVector::MyVector(float in_i, float in_j, float in_k):
i(in_i), j(in_j), k(in_k)
{
}

MyVector::MyVector(float in_i, float in_j, float in_k, float in_x, float in_y, float in_z):
i(in_i), j(in_j), k(in_k), x(in_x), y(in_y), z(in_z)
{
}

MyVector::~MyVector(void){

}

void MyVector::setVector(float in_i, float in_j, float in_k) {
  i = in_i;
  j = in_j;
  k = in_k;
}

void MyVector::setPosition(float in_x, float in_y, float in_z) {
  x = in_x;
  y = in_y;
  z = in_z;
}


float MyVector::dotProduct(MyVector other){
  return this->i * other.i + this->j * other.j + this->k * other.k;
}

void MyVector::crossProduct(MyVector other, MyVector& newVector){
  newVector.i = this->j * other.k - this->k * other.j;
  newVector.j = this->k * other.i - this->i * other.k;
  newVector.k = this->i * other.j - this->j * other.i;
}

float MyVector::getLength(){
  float square = i * i + j * j + k * k;

  return sqrt(square);
}

//inline
float MyVector::getI(){
  return i;
}

//inline
float MyVector::setI(float newI){
  i = newI;
  return i;
}

//inline
float MyVector::getJ(){
  return j;
}

//inline
float MyVector::setJ(float newJ){
  j = newJ;
  return j;
}

//inline
float MyVector::getK(){
  return k;
}

//inline
float MyVector::setK(float newK){
  k = newK;
  return k;
}

//inline
float MyVector::getX(){
  return x;
}

//inline
float MyVector::setX(float newX){
  x = newX;
  return x;
}

//inline
float MyVector::getY(){
  return y;
}

//inline
float MyVector::setY(float newY){
  y = newY;
  return y;
}

//inline
float MyVector::getZ(){
  return z;
}

//inline
float MyVector::setZ(float newZ){
  z = newZ;
  return z;
}

void MyVector::normalize(){
  float l = getLength();
  if(l != 0) {
    i = i/l;
    j = j/l;
    k = k/l;
  }
}

MyVector& MyVector::operator=(const MyVector& other){
  if(this != &other){
    i = other.i;
    j = other.j;
    k = other.k;
    x = other.x;
    y = other.y;
    z = other.z;
  }
  return *this;
}
  
MyVector& MyVector::operator+=(const MyVector& other){
  MyVector retVal(i + other.i, j + other.j, k + other.k,
                  x + other.x, y + other.y, z + other.z);
  *this = retVal;
  return *this;
}
  
MyVector& MyVector::operator-=(const MyVector& other){
  MyVector retVal(i - other.i, j - other.j, k - other.k,
                  x - other.x, y - other.y, z - other.z);
  *this = retVal;
  return *this;
}
  
MyVector& MyVector::operator+(const MyVector& other){
  MyVector retVal(i + other.i, j + other.j, k + other.k,
                  x + other.x, y + other.y, z + other.z);
  return retVal;
}

MyVector& MyVector::operator-(const MyVector& other){
  MyVector retVal(i - other.i, j - other.j, k - other.k,
                  x - other.x, y - other.y, z - other.z);
  return retVal;
}