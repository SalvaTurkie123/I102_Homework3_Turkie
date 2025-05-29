#include <iostream>
#include <string>
#define PI 3.14

using namespace std;

class Punto {

private:
    float posicionX;
    float posicionY;

public:    
    Punto(float x, float y) 
        : posicionX(x),
        posicionY(y) {}
    
    // Setters
    void setX(float x) { posicionX = x; }
    void setY(float y) { posicionY = y; }

    // Getters
    float getX() const { return posicionX; }
    float getY() const { return posicionY; } 
};

class Circulo {

private: 
    float radio;
    Punto centro;

public: 
    Circulo(float x, float y, float r) 
        : centro(x,y), 
        radio(r) {}

    void setR(float r) { radio = r; }
    float getR() const { return radio;}

    Punto getCentro() const { return centro; }
    void setCentro(float x, float y) { centro.setX(x); centro.setY(y); }

    float getX() const { return centro.getX(); }
    float getY() const { return centro.getY(); }

};

class Elipse {

private:
    Punto centro;
    float semiejeMayor;
    float semiejeMenor;

public:
    Elipse(float x, float y, float a, float b) 
        : centro(x,y),
        semiejeMayor(a),
        semiejeMenor(b) {}
    
    void setSemiejeMayor(float a) { semiejeMayor = a; }
    float getSemiejeMayor() const { return semiejeMayor;}
    void setSemiejeMenor(float a) { semiejeMenor = a; }
    float getSemiejeMenor() const { return semiejeMenor;}

    Punto getCentro() const { return centro; }
    void setCentro(float x, float y) { centro.setX(x); centro.setY(y); }

    float getX() const { return centro.getX(); }
    float getY() const { return centro.getY(); }
};

class Rectangulo {

private:
    Punto verticeIzqInf;
    float ancho;
    float largo;

public:
    Rectangulo(float x, float y, float anc, float lar) 
        : verticeIzqInf(x,y),
        ancho(anc),
        largo(lar) {}

    void setAncho(float anc) { ancho = anc;}
    void setLargo(float lar) { largo = lar;}
    float getAncho() const {return ancho;}
    float getLargo() const {return largo;}


    Punto getVerticeIzqInf() const { return verticeIzqInf; }
    void setVerticeIzqInf(float x, float y) { verticeIzqInf.setX(x); verticeIzqInf.setY(y); }

    float getX() const { return verticeIzqInf.getX(); }
    float getY() const { return verticeIzqInf.getY(); }

}; 

template<typename T>
class ProcesadorFigura {

public:
    float calcularArea(const T &figura) {
        cout << "Figura no valida en el sistema.";
        return 0.0f;
    }
};

template <>
class ProcesadorFigura<Punto> {
public:
    float calcularArea(const Punto&) {
        return 0.0f;
    }
};

template<>
class ProcesadorFigura<Circulo> {

public:
    float calcularArea(const Circulo &circulo) { return PI * (circulo.getR()*circulo.getR()); }
};

template<>
class ProcesadorFigura<Elipse> {

public:
    float calcularArea(const Elipse &elipse) { return PI * elipse.getSemiejeMayor() * elipse.getSemiejeMenor() ; }
};

template<>
class ProcesadorFigura<Rectangulo> {

public:
    float calcularArea(const Rectangulo &rectangulo) { return rectangulo.getAncho() * rectangulo.getLargo() ; }
};

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