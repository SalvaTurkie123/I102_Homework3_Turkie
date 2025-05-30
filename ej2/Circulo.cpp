#include "Circulo.h"

Circulo::Circulo(float x, float y, float r) : centro(x, y), radio(r) {}
void Circulo::setR(float r) { radio = r; }
float Circulo::getR() const { return radio; }
Punto Circulo::getCentro() const { return centro; }
void Circulo::setCentro(float x, float y) { centro.setX(x); centro.setY(y); }
float Circulo::getX() const { return centro.getX(); }
float Circulo::getY() const { return centro.getY(); }