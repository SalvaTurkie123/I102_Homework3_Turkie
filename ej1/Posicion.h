#pragma once
#include "MedicionBase.h"
#include <iostream>

class Posicion : public MedicionBase {
public:
    float latitud;
    float longitud;
    float altitud;
    Posicion(float lat, float lon, float alt, float t);
    Posicion(const Posicion& other);
    void serializar(std::ofstream& out) const override;
    void deserializar(std::ifstream& in) override;
    void imprimir() const override;
};