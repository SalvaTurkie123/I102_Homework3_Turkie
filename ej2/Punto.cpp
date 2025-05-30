#include "Punto.h"

Punto::Punto(float x, float y) : posicionX(x), posicionY(y) {}
void Punto::setX(float x) { posicionX = x; }
void Punto::setY(float y) { posicionY = y; }
float Punto::getX() const { return posicionX; }
float Punto::getY() const { return posicionY; }