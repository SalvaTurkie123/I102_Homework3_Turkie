#pragma once
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include "DatosGenerador.h"

class ConstructorJson {
private:
    std::vector<std::pair<std::string, std::string>> info;
public:
    template<typename T>
    void agregar(const std::string& key, const DatosGenerador<T>& value) {
        info.push_back(std::make_pair(key, value.procesador()));
    }
    void imprimirInfo() const;
};