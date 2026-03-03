 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Desentramar una lista doblemente enlazada

#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
#include "list_linked_double.h"
/*
El coste de la funcion unzip es lineal en el orden de O(N + M) debido a que necestamos recorrer todos los elementos de ambas listas para poder desentramarlas,
siendo N el tamaño de la lista1 y M el tamaño de la lista2
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int N = 0, M = 0;
    int valor = 0;
    ListLinkedDouble<int> lista1, lista2;

    // leer los datos de la entrada

    cin >> valor;
    while (valor != 0) {
        lista1.push_back(valor);
        cin >> valor;
    }

    cin >> valor;
    while (valor != 0) {
        lista2.push_back(valor);
        cin >> valor;
    }

    lista1.unzip(lista2);
    // escribir solución

    cout << lista1 << "\n";
    cout << lista2 << "\n";
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("3_2.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("2_2.out");
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