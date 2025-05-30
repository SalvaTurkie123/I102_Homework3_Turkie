#include "Elipse.h"

Elipse::Elipse(float x, float y, float a, float b)
    : centro(x, y), semiejeMayor(a), semiejeMenor(b) {}

void Elipse::setSemiejeMayor(float a) { semiejeMayor = a; }
float Elipse::getSemiejeMayor() const { return semiejeMayor; }
void Elipse::setSemiejeMenor(float a) { semiejeMenor = a; }
float Elipse::getSemiejeMenor() const { return semiejeMenor; }
Punto Elipse::getCentro() const { return centro; }
void Elipse::setCentro(float x, float y) { centro.setX(x); centro.setY(y); }
float Elipse::getX() const { return centro.getX(); }
float Elipse::getY() const { return centro.getY(); }