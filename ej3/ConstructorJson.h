#pragma once
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include "DatosGenerador.h"

// Crea una clase ConstructorJson que almacene pares clave-valor
// donde la clave es un string y el valor es un objeto de DatosGenerador<T>.
class ConstructorJson {

private:
    std::vector<std::pair<std::string, std::string>> info; // clave-valor

public:
    template<typename T>
    void agregar(const std::string& key, const DatosGenerador<T>& value) {
        info.push_back(std::make_pair(key, value.procesador()));
    }
    void imprimirInfo() const;
};