#pragma once
#include "Punto.h"

// Clase Circulo
class Circulo {

private:
    float radio;
    Punto centro;

public:
    Circulo(float x, float y, float r);

    void setR(float r);
    float getR() const;

    Punto getCentro() const;
    void setCentro(float x, float y);
    
    float getX() const;
    float getY() const;
};