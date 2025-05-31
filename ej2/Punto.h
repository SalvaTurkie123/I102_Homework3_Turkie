#pragma once

// Clase punto
class Punto {

private:
    float posicionX;
    float posicionY;

public:
    Punto(float x, float y);

    void setX(float x);
    void setY(float y);
    
    float getX() const;
    float getY() const;
};