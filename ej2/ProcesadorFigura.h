#pragma once
#include "Punto.h"
#include "Circulo.h"
#include "Elipse.h"
#include "Rectangulo.h"
#include <iostream>

#define PI 3.14


//Template class ProcesadorFigura, para usar template specialization
// Figuras que no son Punto, Circulo, Elipse o Rectangulo
template<typename T>
class ProcesadorFigura {
public:
    float calcularArea(const T &figura) {
        std::cout << "Figura no valida en el sistema.";
        return 0.0f;
    }
};

// Para puntos, el área es 0
template<>
class ProcesadorFigura<Punto> {
public:
    float calcularArea(const Punto&) {
        return 0.0f;
    }
};

// Para el circulo, el área se calcula como π * r²
template<>
class ProcesadorFigura<Circulo> {
public:
    float calcularArea(const Circulo &circulo) {
        return PI * (circulo.getR() * circulo.getR());
    }
};

// Para la elipse, el área se calcula como π * a * b
template<>
class ProcesadorFigura<Elipse> {
public:
    float calcularArea(const Elipse &elipse) {
        return PI * elipse.getSemiejeMayor() * elipse.getSemiejeMenor();
    }
};

// Para el rectángulo, el área se calcula como ancho * largo
template<>
class ProcesadorFigura<Rectangulo> {
public:
    float calcularArea(const Rectangulo &rectangulo) {
        return rectangulo.getAncho() * rectangulo.getLargo();
    }
};