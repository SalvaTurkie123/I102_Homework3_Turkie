#include <iostream>
#include "DatosGenerador.h"
#include "ConstructorJson.h"

int main() {
    DatosGenerador<double> doubles;
    doubles.agregarDato(1.3);
    doubles.agregarDato(2.1);
    doubles.agregarDato(3.2);

    DatosGenerador<std::string> palabras;
    palabras.agregarDato("H͟o͟l͟a͟"); // SUbrayado!!!
    palabras.agregarDato("Mundo");

    DatosGenerador<std::vector<int>> listas;
    listas.agregarDato({1, 2});
    listas.agregarDato({3, 4});

    ConstructorJson generador;
    generador.agregar("vec_doubles", doubles);
    generador.agregar("palabras", palabras);
    generador.agregar("listas", listas);

    generador.imprimirInfo();
    return 0;
}