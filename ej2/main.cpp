#include <iostream>
#include <iomanip>
#include "Punto.h"
#include "Circulo.h"
#include "Elipse.h"
#include "Rectangulo.h"
#include "ProcesadorFigura.h"

using namespace std;

int main() {
    // Crear figuras con valores de ejemplo
    Circulo circulo(0.0f, 0.0f, 5.0f);           // centro en (0,0), radio = 5
    Elipse elipse(2.0f, 3.0f, 4.0f, 2.0f);       // centro en (2,3), a = 4, b = 2
    Rectangulo rect(0.0f, 0.0f, 10.0f, 5.0f);    // vértice en (0,0), ancho = 10, largo = 5
    Punto punto(1.0f, 1.0f);                     // punto en (1,1)

    ProcesadorFigura<Circulo> procCirculo;
    ProcesadorFigura<Elipse> procElipse;
    ProcesadorFigura<Rectangulo> procRect;
    ProcesadorFigura<Punto> procPunto;

    // Calcular e imprimir áreas
    cout << fixed;
    cout.precision(2);

    cout << "Área del círculo: " << procCirculo.calcularArea(circulo) << " unidades²" << endl;
    cout << "Área de la elipse: " << procElipse.calcularArea(elipse) << " unidades²" << endl;
    cout << "Área del rectángulo: " << procRect.calcularArea(rect) << " unidades²" << endl;
    cout << "Área del punto: " << procPunto.calcularArea(punto) << " unidades²" << endl;

    return 0;
}