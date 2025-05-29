#include <iostream>
#include <fstream>
#include <memory>
#include <string>

using namespace std;

// Interfaz IMediciones

class IMediciones {
 
public:

    virtual void serializar(ofstream&) const = 0;
    virtual void deserializar(ifstream&) = 0;
    virtual ~IMediciones() {}

};

class MedicionBase : public IMediciones {

protected:
    
    unique_ptr<float> tiempoMedicion;

public:

    MedicionBase(float t) : tiempoMedicion(make_unique<float>(t)) {}
    MedicionBase() : tiempoMedicion(std::make_unique<float>(0.0f)) {}
    float getTiempo() const { return *tiempoMedicion;}
    virtual void imprimir() const = 0; 

};

class Presion : public MedicionBase {

public:

    float presionEstatica;
    float presionDinamica;
    Presion(float p, float q, float t) 
        : presionEstatica(p), 
        presionDinamica(q), 
        MedicionBase(t) {}
    Presion(const Presion& other) 
        : MedicionBase(*other.tiempoMedicion),  // Copia profunda del tiempo
        presionEstatica(other.presionEstatica),
        presionDinamica(other.presionDinamica) {}

    void serializar(ofstream& out) const override { 
        out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(presionEstatica));
        out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(presionDinamica));
        out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float));
    
    }
    void deserializar(ifstream& in) override {
        in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
        in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));

        // Nuevo espacio para el unique pointer de tiempo
        tiempoMedicion = make_unique<float>();
        in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(float));
    }
    void imprimir() const override {
        cout <<  "=============================================" << endl;
        cout << "Datos sobre la Presion: \n";
        cout << "Presion Estatica: " << presionEstatica << endl;
        cout << "Presion Dinamica: " << presionDinamica << endl;
        cout << "Tiempo de medicion: " << getTiempo() << endl;
    }

};

class Posicion : public MedicionBase {

public:

    float latitud;
    float longitud;
    float altitud;
    Posicion(float lat, float lon, float alt, float t) 
        : latitud(lat), 
        longitud(lon), 
        altitud(alt), 
        MedicionBase(t) {}
    Posicion(const Posicion& other) 
        : latitud(other.latitud),
        longitud(other.longitud), 
        altitud(other.altitud),
        MedicionBase(*other.tiempoMedicion) {}
    void serializar(ofstream& out) const override {
        out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
        out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
        out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
        out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float));
    }
    void deserializar(ifstream& in) override {
        in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
        in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
        in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));

        // Nuevo espacio para el unique pointer de tiempo
        tiempoMedicion = make_unique<float>();
        in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(float));
    }
    void imprimir() const override {
        cout <<  "=============================================" << endl;
        cout << "Datos sobre la Posicion: \n";
        cout << "Latitud: " << latitud << endl;
        cout << "Longitud: " << longitud << endl;
        cout << "Altitud: " << altitud << endl;
        cout << "Tiempo de medicion: " << getTiempo() << endl;
    }

};

class SaveFlightData {

public:

    Posicion posicion;
    Presion presion;
    SaveFlightData(const Posicion& p, const Presion& q) 
        : posicion(p), 
        presion(q) {}
    void serializar(ofstream& out) {
        posicion.serializar(out);
        presion.serializar(out);
    }
    void deserializar(ifstream& in) {
        posicion.deserializar(in);
        presion.deserializar(in);
    }

    void imprimir() {
        cout << "================ FLIGHT DATA ================\n";
        posicion.imprimir();
        presion.imprimir();
        cout << "=============================================\n";
    }
};

int main(){
    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3f);
    Presion presion(101.3f, 5.8f, 6.1f);
    SaveFlightData vuelo(posicion, presion);
    
    ofstream out("vuelo.dat", ios::binary);
    if (out.is_open()) {
        vuelo.serializar(out);
        out.close();
    } else { cout << "Error al abrir archivo para escritura. \n"; }

    SaveFlightData datosLeidos(Posicion(0,0,0,0), Presion(0,0,0));
    ifstream in("vuelo.dat", ios::binary);
    if (in.is_open()) {
        datosLeidos.deserializar(in);
        in.close();
    } else { cout << "Error al abrir el archivo para lectura \n"; }

    datosLeidos.imprimir();

    return 0;

}
