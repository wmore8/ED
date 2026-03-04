 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Partición de una lista doblemente enlazada

#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
#include "list_linked_double.h"
/*
El coste de la funcion particion es lineal en el orden de O(N) debido a que necestamos recorrer todos los elementos de la lista para poder reordenar los elementos en
posiciones impares de manera constante O(1). N es el tamaño de la lista.
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int valor = 0;
    int pivote = 0;
    ListLinkedDouble<int> lista;

    // leer los datos de la entrada

    cin >> valor;
    while (valor != 0) {
        lista.push_back(valor);
        cin >> valor;
    }

    cin >> pivote;

    lista.partition(pivote);
    // escribir solución

    cout << lista << "\n";
    lista.display_reverse();
    cout << "\n";
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("3_3.in");
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