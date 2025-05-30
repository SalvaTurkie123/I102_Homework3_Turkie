#include "Posicion.h"

Posicion::Posicion(float lat, float lon, float alt, float t)
    : latitud(lat), longitud(lon), altitud(alt), MedicionBase(t) {}

Posicion::Posicion(const Posicion& other)
    : latitud(other.latitud), longitud(other.longitud), altitud(other.altitud),
      MedicionBase(*other.tiempoMedicion) {}

void Posicion::serializar(std::ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float));
}

void Posicion::deserializar(std::ifstream& in) {
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
    tiempoMedicion = std::make_unique<float>();
    in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(float));
}

void Posicion::imprimir() const {
    std::cout <<  "=============================================" << std::endl;
    std::cout << "Datos sobre la Posicion: \n";
    std::cout << "Latitud: " << latitud << std::endl;
    std::cout << "Longitud: " << longitud << std::endl;
    std::cout << "Altitud: " << altitud << std::endl;
    std::cout << "Tiempo de medicion: " << getTiempo() << std::endl;
}