#include <iostream>
#include "DatosGenerador.h"
#include "ConstructorJson.h"

int main() {
    // Crear instancias de DatosGenerador para los diferentes tipos de datos

    // Primero los Doubles
    DatosGenerador<double> doubles;
    doubles.agregarDato(1.3);
    doubles.agregarDato(2.1);
    doubles.agregarDato(3.2);

    // Luego las Palabras
    DatosGenerador<std::string> palabras;
    palabras.agregarDato("Hola");
    palabras.agregarDato("Mundo");

    // Y por ultimo, las Listas de enteros
    DatosGenerador<std::vector<int>> listas;
    listas.agregarDato({1, 2});
    listas.agregarDato({3, 4});

    // Crear el generador de JSON y agregar los datos
    ConstructorJson generador;
    generador.agregar("vec_doubles", doubles);
    generador.agregar("palabras", palabras);
    generador.agregar("listas", listas);

    // Lo imprimo
    generador.imprimirInfo();
    return 0;
}