#pragma once
#include "Punto.h"
#include "Circulo.h"
#include "Elipse.h"
#include "Rectangulo.h"
#include <iostream>

#define PI 3.14

template<typename T>
class ProcesadorFigura {
public:
    float calcularArea(const T &figura) {
        std::cout << "Figura no valida en el sistema.";
        return 0.0f;
    }
};

template<>
class ProcesadorFigura<Punto> {
public:
    float calcularArea(const Punto&) {
        return 0.0f;
    }
};

template<>
class ProcesadorFigura<Circulo> {
public:
    float calcularArea(const Circulo &circulo) {
        return PI * (circulo.getR() * circulo.getR());
    }
};

template<>
class ProcesadorFigura<Elipse> {
public:
    float calcularArea(const Elipse &elipse) {
        return PI * elipse.getSemiejeMayor() * elipse.getSemiejeMenor();
    }
};

template<>
class ProcesadorFigura<Rectangulo> {
public:
    float calcularArea(const Rectangulo &rectangulo) {
        return rectangulo.getAncho() * rectangulo.getLargo();
    }
};