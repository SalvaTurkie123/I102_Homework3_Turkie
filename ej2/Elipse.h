#pragma once
#include "Punto.h"

// Clase Elipse
class Elipse {

private:
    Punto centro;
    float semiejeMayor;
    float semiejeMenor;

public:
    Elipse(float x, float y, float a, float b);

    void setSemiejeMayor(float a);
    float getSemiejeMayor() const;
    void setSemiejeMenor(float a);
    float getSemiejeMenor() const;

    Punto getCentro() const;
    void setCentro(float x, float y);
    
    float getX() const;
    float getY() const;
};