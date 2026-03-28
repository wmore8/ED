 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Eliminar los elementos decrecientes de una lista enlazada doble

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <stack>
// Introduce más librerías si son necesarias
#include "list_linked_double.h"

/*
Coste total: Sin contar la lectura de la entrada ni salida, el coste es de O(N) siendo N el numero de elementos en la lista. 
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {    
    // leer los datos de la entrada

    int N = 0; cin >> N;

    if (N == 0) return false;

    ListLinkedDouble<int> lista;
    int valor = 0;

    for (int i = 0; i < N; i++) {
        cin >> valor;
        lista.push_back(valor);
    }

    // escribir solución
    lista.eliminarDecrecientes();

    lista.mostrarJuez();

    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("5_2.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("4_1.out");
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