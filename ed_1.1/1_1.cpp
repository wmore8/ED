
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Invertir un segmento de una lista implementada con un array dinámico

#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
#include "list_array.h"

/*
El coste de la funcion duplicate es lineal O(N) debido a que necestamos recorrer todos los elementos para poder duplicarlos, siendo N el tamaño de la lista
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N, P, L;
    cin >> N >> P >> L;
    if (!std::cin) return false;

    // leer los datos de la entrada
    ListArray lista;
    string valor = "";

    for (int i = 0; i < N; i++) {
        cin >> valor;
        lista.push_back(valor);
    }
    // escribir solución
    lista.reverse_segment(P, L);

    lista.display();

    cout << "\n";

    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("1_1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("2_1.out");
    //auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    while(resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //std::cout.rdbuf(coutbuf);
#endif
    return 0;
}