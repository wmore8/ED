 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Ordenación por selección

#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
#include "list_linked_double.h"
/*
El coste de la funcion sort_and_dedup es cuadratrica en el orden de O(N^2) debido a que necestamos recorrer todos los elementos de la lista para
 evitar elmentos duplicados, ademas de que necesitamos usar la funcion minimum O(N) para encontrar el menor elemento en cada iteracion. 
 N es el tamaño de la lista.
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int valor = 0;
    ListLinkedDouble<int> lista;

    // leer los datos de la entrada

    cin >> valor;
    while (valor != -1) {
        lista.push_back(valor);
        cin >> valor;
    }

    lista.sort_and_dedup();
    // escribir solución

    cout << lista << "\n";
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("3_4.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("3_4.out");
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