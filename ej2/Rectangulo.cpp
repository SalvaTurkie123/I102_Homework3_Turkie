#include "Rectangulo.h"

Rectangulo::Rectangulo(float x, float y, float anc, float lar)
    : verticeIzqInf(x, y), ancho(anc), largo(lar) {}

void Rectangulo::setAncho(float anc) { ancho = anc; }
void Rectangulo::setLargo(float lar) { largo = lar; }
float Rectangulo::getAncho() const { return ancho; }
float Rectangulo::getLargo() const { return largo; }
Punto Rectangulo::getVerticeIzqInf() const { return verticeIzqInf; }
void Rectangulo::setVerticeIzqInf(float x, float y) { verticeIzqInf.setX(x); verticeIzqInf.setY(y); }
float Rectangulo::getX() const { return verticeIzqInf.getX(); }
float Rectangulo::getY() const { return verticeIzqInf.getY(); }