#include <iostream>
#include <fstream>
#include "SaveFlightData.h"

int main() {

    // Creo un objeto SaveFlightData con datos de ejemplo
    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3f);
    Presion presion(101.3f, 5.8f, 6.1f);
    SaveFlightData vuelo(posicion, presion);

    // Serializo el objeto a un archivo binario
    std::ofstream out("vuelo.dat", std::ios::binary);
    if (out.is_open()) {
        vuelo.serializar(out);
        out.close();
    } else { std::cout << "Error al abrir archivo para escritura. \n";}

    // Deserializo el objeto desde el archivo y lo imprimo
    SaveFlightData datosLeidos(Posicion(0,0,0,0), Presion(0,0,0));
    std::ifstream in("vuelo.dat", std::ios::binary);
    if (in.is_open()) {
        datosLeidos.deserializar(in);
        in.close();
    } else { std::cout << "Error al abrir el archivo para lectura \n"; }

    datosLeidos.imprimir();

    return 0;
}