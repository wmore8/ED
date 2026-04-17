 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Área más grande de un árbol binario

#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
#include "bintree_V6.h"
/*
Para resolver el ejercicio necesitamos realizar un recorrido en profundidad (DFS) sobre el arbol, priorizando el lado izquierdo para encontrar que nodos conformaran
el perfil. Usamos una funcion recursiva no final, en la que usamos parametros con y sin referencia a memoria para ir descendiendo en altura y alamcenar el nodo que 
este mas a la izquierda en el vector solucion.

El coste de la funcion es lineal O(N) en funcion del numero de nodos. Como necesitamos recorrer todos los nodos el coste es lineal
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

struct tSol {
    int actual;
    int max_area;
};

tSol max_area(const BinTree<char>& arb) {
    if (arb.empty()) {
        return { 0,0 };
    }
    else {
        tSol iz = max_area(arb.left());
        tSol dr = max_area(arb.right());

        int area_actual = 1 + iz.actual + dr.actual;
        int area_hijos = max(iz.max_area, dr.max_area);

        if (arb.root() == 'B') { //si es un nodo bloqueante, reiniciamos el area actual y nos quedamos con el mayor area de los hijos
            return { 0,area_hijos };
        }
        else { //si es un nodo valido, aumentamos el area y nos quedamos con el mayor area
            return{ area_actual, max(area_actual,area_hijos) };
        }
    }

}

void resuelveCaso() {
    BinTree<char> arbol;

    // leer los datos de la entrada
    arbol = read_tree<char>(cin);

    tSol sol = max_area(arbol);

    // escribir solución

    cout << sol.max_area << "\n";
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("6_7.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("6_7.out");
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