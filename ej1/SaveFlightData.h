#pragma once
#include "Posicion.h"
#include "Presion.h"
#include <fstream>

class SaveFlightData {
public:
    Posicion posicion;
    Presion presion;
    SaveFlightData(const Posicion& p, const Presion& q);
    void serializar(std::ofstream& out);
    void deserializar(std::ifstream& in);
    void imprimir();
};