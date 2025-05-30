#pragma once
#include "Punto.h"

class Rectangulo {
private:
    Punto verticeIzqInf;
    float ancho;
    float largo;
public:
    Rectangulo(float x, float y, float anc, float lar);
    void setAncho(float anc);
    void setLargo(float lar);
    float getAncho() const;
    float getLargo() const;
    Punto getVerticeIzqInf() const;
    void setVerticeIzqInf(float x, float y);
    float getX() const;
    float getY() const;
};