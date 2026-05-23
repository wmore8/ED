 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Referencias cruzadas

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <sstream>
#include <cctype>
// Introduce más librerias si son necesarias
/*
Para resolver este problema, utilizamos un diccionario ordenado (map) donde la clave es la palabra valida (string) y el valor es un conjunto ordenado (set<int>) 
con los numeros de linea. El set garantiza automaticamente que los numeros de linea esten ordenados de menor a mayor y que no haya  duplicados, cumpliendo los 
requisitos del problema. Usamos stringstream para separar facilmente las lineas en palabras.

Coste asintotico: Procesar cada palabra de una linea cuesta O(log P + log L), donde P es el numero de palabras distintas del mapa y L el numero de lineas en las que 
aparece (por la insercion en el set). El recorrido final cuesta O(P * L). Coste espacial: O(P * L) para almacenar el diccionario completo.
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta


bool resuelveCaso() {
    int N; cin >> N;

    if (N == 0) return false;
    cin.ignore();
    // leer los datos de la entrada
    map<string, set<int>> referencias;

    for (int i = 1; i <= N; i++) {
        string linea;
        getline(cin, linea);

        // Usamos stringstream para extraer las palabras de la linea facilmente
        stringstream ss(linea);
        string palabra;

        while (ss >> palabra) {
            // Solo procesamos si la palabra tiene mas de 2 letras
            if (palabra.length() > 2) {

                // Convertimos la palabra a minusculas modificandola directamente
                for (char& c : palabra) {
                    c = tolower(c);
                }

                // Insertamos la linea en el conjunto.
                // Si la linea ya estaba, el set la ignora automaticamente.
                referencias[palabra].insert(i);
            }
        }
    }

    // Escribir solucion
    for (const auto& par : referencias) {
        cout << par.first;

        // Recorremos el set asociado a cada palabra
        for (int linea : par.second) {
            cout << " " << linea;
        }
        cout << "\n";
    }

    cout << "---\n";
  
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("8_3.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("8_3.out");
    //auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //std::cout.rdbuf(coutbuf);
#endif
    return 0;
}