#pragma once
#include <fstream>
#include <memory>

// Interfaz IMediciones
class IMediciones {

public:
    virtual void serializar(std::ofstream&) const = 0;
    virtual void deserializar(std::ifstream&) = 0;
    virtual ~IMediciones() {}
};

// Clase base MedicionBase que implementa IMediciones
class MedicionBase : public IMediciones {

protected:
    std::unique_ptr<float> tiempoMedicion;

public:
    MedicionBase(float t);
    MedicionBase();
    
    float getTiempo() const;
    virtual void imprimir() const = 0;
};