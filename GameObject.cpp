#include "GameObject.h"

GameObject::GameObject():
x(0.0), y(0.0), z(0.0)
{
}
GameObject::GameObject(float inx, float iny, float inz):
x(inx), y(iny), z(inz)
{
}

GameObject::~GameObject(void) {
}