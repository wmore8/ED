
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Venta de libros por internet

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <fstream>

#include "VentaDeLibros.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N = 0; cin >> N;

    if (!cin) return false;

    Libros L;
    string op, nombreLibro;
    int cantidad;

    for (int i = 0; i < N; i++) {
        cin >> op;
        try {
            if (op == "nuevoLibro") {
                cin >> cantidad;
                cin.ignore();
                getline(cin, nombreLibro);

                L.nuevoLibro(cantidad, nombreLibro);
            }
            else if (op == "comprar") {
                cin.ignore();
                getline(cin, nombreLibro);
                
                L.comprar(nombreLibro);
            }
            else if (op == "estaLibro") {
                cin.ignore();
                getline(cin, nombreLibro);

                if (L.estaLibro(nombreLibro)) {
                    cout << "El libro " << nombreLibro <<" esta en el sistema\n";
                }
                else {
                    cout << "No existe el libro " << nombreLibro << " en el sistema\n";
                }
            }
            else if (op == "elimLibro") {
                cin.ignore();
                getline(cin, nombreLibro);

                L.elimLibro(nombreLibro);
            }
            else if (op == "numEjemplares") {
                cin.ignore();
                getline(cin, nombreLibro);

                if (L.estaLibro(nombreLibro)) {
                    int num = L.numEjemplares(nombreLibro);
                    cout << "Existen " << num << " ejemplares del libro " << nombreLibro << "\n";
                }
                else {
                    cout << "No existe el libro " << nombreLibro << " en el sistema\n";
                }
            }
            else if (op == "top10") {
                vector<string> topLibros = L.top10();

                cout << "TOP10\n";

                for (const string& nombre : topLibros) {
                    cout << "    " << nombre << "\n";
                }
            }
        }
        catch (std::exception const& e) {
            std::cout << e.what() << '\n';
        }
    }

    cout << "---\n";
    return true;

}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("9_6.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("datos.out");
    //auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    while (resuelveCaso());//Resolvemos todos los casos

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //std::cout.rdbuf(coutbuf);
#endif
    return 0;
}