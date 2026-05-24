 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Juegos online

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
// Introduce mas librerias si son necesarias
/*
Para resolver el ejerecicio necesitamos utilizar 2 unordered map para almacenar que juegos ha jugado el abuelo, y en que dia lo ha hecho.
Mientras leemos que titulo jugo cada dia, guardamos esa clave si no existe, y añadimos la vez en la que ha jugado junto al dia que es.
Cuando leemos las consultas buscamos en ambos diccionarios para ver si existe algun dato o no.

Coste asintotico: Lineal al añadir cada informacion sobre los juegos cada vez -> O(N),siendo N el numero de dias que ha jugado. Como al hacer las consultas en los
mapas, el metodo count es constante O(1) , el coste sube a O(M). Coste total -> O(N + M)

Coste Espacial: O(N), ya que almacenamos exactamente el registro de los N dias jugados.
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta


bool resuelveCaso() {
    // leer los datos de la entrada
    int N = 0; cin >> N;
    if (!cin) return false;

    unordered_map<string, unordered_map<int, int>> juegos;

    string nombre;

    for (int i = 1; i <= N; i++) {
        cin >> nombre;
        int k_esima = juegos[nombre].size() + 1;
        juegos[nombre][k_esima] = i;
    }

    // Escribir solucion
    int M = 0; cin >> M;
    int dia;
    string clave;
    for (int i = 0; i < M; i++) {
        cin >> dia >> clave;

        if (juegos.count(clave) == 1) {
            if (juegos[clave].count(dia) == 1) {
                cout << juegos[clave][dia];
            }
            else {
                cout << "NO JUEGA";
            }
        }
        else {
            cout << "NO JUEGA";
        }
        cout << "\n";
    }
    cout << "---\n";

    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("8_6.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("8_6.out");
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