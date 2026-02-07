
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Duplicar una lista

#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
#include "list_linked_single_v4.h"

/*
El coste de la funcion duplicate es lineal O(N) debido a que necestamos recorrer todos los elementos para poder duplicarlos, siendo N el tamaño de la lista
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    string valor = "0";
    ListLinkedSingle lista;

    cin >> valor;

    while (valor != "0") {
        lista.push_back(valor);
        cin >> valor;
    }
    // leer los datos de la entrada

    lista.duplicate();
    // escribir solución

    cout << lista << "\n";

}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("2_1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("2_1.out");
    //auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //std::cout.rdbuf(coutbuf);
#endif
    return 0;
}