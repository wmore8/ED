 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Método count_interval

#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
#include "set_tree_v1.h"
/*
Para resolver el ejercicio necesitamos realizar un recorrido recursivo sobre el arbol, aprovechando que esta ordenado (ABB) para podar las ramas que quedan fuera del 
intervalo. Usamos una funcion recursiva que evalua el nodo actual: si es menor que el limite inferior, solo explora el hijo derecho; si es mayor que el superior, solo 
el izquierdo; y si esta dentro, lo cuenta y explora ambos hijos.

El coste de la funcion en el caso promedio es de O(h + k), siendo h la altura del arbol y k el numero de elementos dentro del intervalo. En el peor de los casos 
(si el intervalo abarca todo el arbol o este esta degenerado), necesitamos recorrer todos los nodos y el coste sera lineal O(N).
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta



bool resuelveCaso() {
    int N = 0, M = 0; cin >> N >> M;

    if (!cin) return false;
    // leer los datos de la entrada
    SetTree<int> lista; 
    int valor = 0;

    for (int i = 0; i < N; i++) {
        cin >> valor;
        lista.insert(valor);
    }

    // escribir solución
    int lower = 0, upper = 0;
    for (int i = 0; i < M; i++) {
        cin >> lower >> upper;
        int sol = lista.count_interval(lower, upper);
        cout << sol << "\n";
    }
    
    cout << "---\n";

    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("7_1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("7_1.out");
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