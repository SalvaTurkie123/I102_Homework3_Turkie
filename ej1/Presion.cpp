#include "Presion.h"

Presion::Presion(float p, float q, float t)
    : presionEstatica(p), presionDinamica(q), MedicionBase(t) {}

Presion::Presion(const Presion& other)
    : MedicionBase(*other.tiempoMedicion),
      presionEstatica(other.presionEstatica),
      presionDinamica(other.presionDinamica) {}

void Presion::serializar(std::ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(presionDinamica));
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float));
}

void Presion::deserializar(std::ifstream& in) {
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
    tiempoMedicion = std::make_unique<float>();
    in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(float));
}

void Presion::imprimir() const {
    std::cout <<  "=============================================" << std::endl;
    std::cout << "Datos sobre la Presion: \n";
    std::cout << "Presion Estatica: " << presionEstatica << std::endl;
    std::cout << "Presion Dinamica: " << presionDinamica << std::endl;
    std::cout << "Tiempo de medicion: " << getTiempo() << std::endl;
}