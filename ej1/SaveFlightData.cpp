#include "SaveFlightData.h"
#include <iostream>

SaveFlightData::SaveFlightData(const Posicion& p, const Presion& q)
    : posicion(p), presion(q) {}

void SaveFlightData::serializar(std::ofstream& out) {
    posicion.serializar(out);
    presion.serializar(out);
}

void SaveFlightData::deserializar(std::ifstream& in) {
    posicion.deserializar(in);
    presion.deserializar(in);
}

void SaveFlightData::imprimir() {
    std::cout << "================ FLIGHT DATA ================\n";
    posicion.imprimir();
    presion.imprimir();
    std::cout << "=============================================\n";
}