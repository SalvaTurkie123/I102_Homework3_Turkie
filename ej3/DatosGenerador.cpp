#include "DatosGenerador.h"

template<typename T>
void DatosGenerador<T>::agregarDato(const T& dato) {
    datos.push_back(dato);
}

template<typename T>
std::string DatosGenerador<T>::procesador() const {
    if constexpr(std::is_same_v<T, std::string>) {
        std::string vecEnString = "[";
        for (size_t i = 0; i < datos.size(); i++) {
            vecEnString += "\"" + datos[i] + "\"";
            if (i < datos.size() -1) vecEnString += ",";
        }
        return vecEnString += "]";
    }
    else if constexpr(std::is_same_v<T, double>) {
        return vectorToString(datos);
    }
    else if constexpr(std::is_same_v<T, std::vector<int>>) {
        std::string vecEnString = "[ \n";
        for (size_t i = 0; i < datos.size(); i++) {
            vecEnString += "\t  " + vectorToString(datos[i]);
            if (i < datos.size() - 1) {
                vecEnString += ", \n";
            }
        }
        vecEnString += "\n\t  ]";
        return vecEnString;
    }
    else {
        return "";
    }
}

// Explicit template instantiation
template class DatosGenerador<double>;
template class DatosGenerador<std::string>;
template class DatosGenerador<std::vector<int>>;