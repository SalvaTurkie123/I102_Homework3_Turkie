#pragma once
#include "MedicionBase.h"
#include <iostream>

class Presion : public MedicionBase {
public:
    float presionEstatica;
    float presionDinamica;
    Presion(float p, float q, float t);
    Presion(const Presion& other);
    void serializar(std::ofstream& out) const override;
    void deserializar(std::ifstream& in) override;
    void imprimir() const override;
};