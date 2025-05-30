#pragma once
#include <vector>
#include <string>
#include <type_traits>
#include "vectorToString.h"

template<typename T>
class DatosGenerador {
private:
    std::vector<T> datos;
public:
    void agregarDato(const T& dato);
    std::string procesador() const;
};