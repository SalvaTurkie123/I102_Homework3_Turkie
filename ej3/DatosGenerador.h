#pragma once
#include <vector>
#include <string>
#include <type_traits>
#include "vectorToString.h"


// Clase DatosGenerador que almacena datos de tipo T y los procesa
template<typename T>
class DatosGenerador {

private:
    std::vector<T> datos;
    
public:
    void agregarDato(const T& dato);    // Agrega un dato al vector de datos
    std::string procesador() const;     // Procesa los datos y devuelve una representación en string (Luego se  usa para generar un JSON)
};