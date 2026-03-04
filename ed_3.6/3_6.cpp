 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Intercambiar de dos en dos los elementos de una lista doblemente enlazada

#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
#include "list_linked_double.h"
/*
El coste de la funcion add_to es lineal O(N) respecto al numero de elementos de la lista. Necesitamos recorrer los nodos para encontrar el nodo con posicion i, que
en el caso peor puede ser O(N). Despues desenganchamos ese nodo con detach de forma constante O(1), y recorremos de nuevo la lista para encontrar el primer nodo que
sea mayor que el desenganchado sumado con m -> O(N-1). Una vez encontrado lo enganchamos en la posicion anterior al actual con coste constante O(1).

Coste total: O(N) lineal porque podemos recorrer la lista por completo 2 veces en el caso peor. Siendo N el numero de elementos de la lista.
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N = 0, i = 0, m = 0; cin >> N >> i >> m;

    if (N == 0 && i == 0 && m == 0) {
        return false;
    }

    ListLinkedDouble<int> lista;
    int valor = 0;
    // leer los datos de la entrada
    for (int i = 0; i < N; i++) {
        cin >> valor;
        lista.push_back(valor);
    }

    lista.add_to(i,m);
    // escribir solución

    cout << lista << "\n";
    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("3_6.in");
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