#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Clase 1: Generador de datos
class DatosGenerador {
private:
    vector<double> vecDoubles;
    vector<string> vecStrings;
    vector<vector<int>> listas;

public:
    template<typename T>
    void agregarDato(const T &valor) {
        if constexpr(is_same_v<T, double>) {
            vecDoubles.push_back(valor);
        } else if constexpr(is_same_v<T, string>) {
            vecStrings.push_back(valor);
        } else if constexpr(is_same_v<T, vector<int>>) {
            listas.push_back(valor);
        } else {
            cout << "Tipo no soportado\n";
        }
    }

    const vector<double>& getDoubles() const { return vecDoubles; }
    const vector<string>& getStrings() const { return vecStrings; }
    const vector<vector<int>>& getListas() const { return listas; }
};

// Clase 2: Constructor de JSON
class ConstructorJson {
private:
    map<string, vector<double>> infoDouble;
    map<string, vector<string>> infoString;
    map<string, vector<vector<int>>> infoListas;

public:
    void setVec(const string& etiqueta, const vector<double>& valor) { infoDouble[etiqueta] = valor; }
    void setVec(const string& etiqueta, const vector<string>& valor) { infoString[etiqueta] = valor; }
    void setVec(const string& etiqueta, const vector<vector<int>>& valor) { infoListas[etiqueta] = valor; }

    void imprimirJson() {
        cout << "{\n";
        // Doubles
        for (auto it = infoDouble.begin(); it != infoDouble.end(); ++it) {
            cout << " \"" << it->first << "\": [";
            const vector<double>& vec = it->second;
            for (size_t i = 0; i < vec.size(); ++i) {
                cout << vec[i];
                if (i < vec.size() - 1) cout << ", ";
            }
            cout << "]";
            if (!infoString.empty() || !infoListas.empty()) cout << ",";
            cout << "\n";
        }
        // Strings
        for (auto it = infoString.begin(); it != infoString.end(); ++it) {
            cout << " \"" << it->first << "\": [";
            const vector<string>& vec = it->second;
            for (size_t i = 0; i < vec.size(); ++i) {
                cout << "\"" << vec[i] << "\"";
                if (i < vec.size() - 1) cout << ", ";
            }
            cout << "]";
            if (!infoListas.empty()) cout << ",";
            cout << "\n";
        }
        // Listas
        for (auto it = infoListas.begin(); it != infoListas.end(); ++it) {
            cout << " \"" << it->first << "\": [\n";
            const vector<vector<int>>& matriz = it->second;
            for (size_t i = 0; i < matriz.size(); ++i) {
                cout << "  [";
                for (size_t j = 0; j < matriz[i].size(); ++j) {
                    cout << matriz[i][j];
                    if (j < matriz[i].size() - 1) cout << ", ";
                }
                cout << "]";
                if (i < matriz.size() - 1) cout << ",\n";
            }
            cout << "\n ]\n";
        }
        cout << "}\n";
    }
};

int main() {
    // Usar DatosGenerador para agregar los datos
    DatosGenerador generador;
    generador.agregarDato(1.3);
    generador.agregarDato(2.1);
    generador.agregarDato(3.2);
    generador.agregarDato(string("Hola"));
    generador.agregarDato(string("Mundo"));
    generador.agregarDato(vector<int>{1,2});
    generador.agregarDato(vector<int>{3,4});

    // Pasar los datos a ConstructorJson
    ConstructorJson json;
    json.setVec("vec_doubles", generador.getDoubles());
    json.setVec("palabras", generador.getStrings());
    json.setVec("listas", generador.getListas());

    // Imprimir el JSON generado
    json.imprimirJson();

    return 0;
}