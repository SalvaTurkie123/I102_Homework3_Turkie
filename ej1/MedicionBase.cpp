#include "MedicionBase.h"

MedicionBase::MedicionBase(float t) : tiempoMedicion(std::make_unique<float>(t)) {}
MedicionBase::MedicionBase() : tiempoMedicion(std::make_unique<float>(0.0f)) {}
float MedicionBase::getTiempo() const { return *tiempoMedicion; }