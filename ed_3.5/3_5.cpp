 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Intercambiar de dos en dos los elementos de una lista doblemente enlazada

#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
#include "list_linked_double.h"
/*
El coste de la funcion swap2by2 es lineal O(N) respecto al numero de elementos de la lista. Necistamos recorrer todos los elementos para poder cambiar de posicion 
los 2 nodos en los que estemos actualmente. Cada cambio de puntero es constante O(1) y en el caso de que sea impar, el bucle termina cuando uno de los nodos actuales
llega al nodo fantasma (head).
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N = 0; cin >> N;

    if (N == 0) {
        return false;
    }

    ListLinkedDouble<int> lista;
    int valor = 0;
    // leer los datos de la entrada
    for (int i = 0; i < N; i++) {
        cin >> valor;
        lista.push_back(valor);
    }

    lista.swap2by2();
    // escribir solución

    cout << lista << "\n";
    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("3_5.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("3_4.out");
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