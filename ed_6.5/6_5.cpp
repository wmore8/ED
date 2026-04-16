 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Perfil izquierdo de un árbol binario

#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
#include "bintree_V6.h"
/*
Para resolver el ejercicio necesitamos realizar un recorrido en profundidad (DFS) sobre el arbol, priorizando el lado izquierdo para encontrar que nodos conformaran
el perfil. Usamos una funcion recursiva no final, en la que usamos parametros con y sin referencia a memoria para ir descendiendo en altura y alamcenar el nodo que 
este mas a la izquierda en el vector solucion.

El coste es lineal en funcion del numero de nodos del arbol (debido a que solo se recorre una unica vez) : O(N) siendo N el numero de nodos
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void rec_perfil(const BinTree<int>& arb, int profundidad, vector<int>& sol) {
    if (!arb.empty()) {
        if (profundidad == sol.size()) { //si es el primer nodo que encontramos (empezamos por la raiz y luego damos prioridad al lado izquierdo)
            sol.push_back(arb.root());
        }

        rec_perfil(arb.left(), profundidad + 1, sol); // damos prioridad al lado izquierdo primero

        rec_perfil(arb.right(), profundidad + 1, sol); // continuamos con el lado derecho
    }
}

vector<int> perfil(BinTree<int> arbol) {
    vector<int> sol;

    rec_perfil(arbol, 0, sol);

    return sol;
}

void resuelveCaso() {
    BinTree<int> arbol;

    // leer los datos de la entrada
    arbol = read_tree<int>(cin);

    vector<int> sol = perfil(arbol);

    // escribir solución
    for (int valor : sol) {
        cout << valor << " ";
    }

    cout << "\n";
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("6_5.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("6_5.out");
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