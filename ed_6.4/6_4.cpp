 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Excursionistas atrapados

#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
#include "bintree_V6.h"
/*
Para resolver el ejercicio necesitamos utilizar una funcion recursiva (divide y venceras) para saber cuantos nodos el arbol binario y si es zurdo.
Mientras iteramos devolvemos 2 casos bases : es zurdo y tiene 0 nodos si es un arbol vacio, y es zurdo y tiene 1 nodo si es una hoja (es decir un nodo del final). 
En cualquier otro caso comparamos si ambos hijos son zurdos o si el numero de nodos del hio izquierdo es mayor que el del derechp.

El coste es lineal en funcion del numero de nodos del arbol (debido a que solo se recorre una unica vez) : O(N) siendo N el numero de nodos
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

struct tSol {
    int equipos;
    int viajeros;
};

tSol rescate(const BinTree<int>& arb) {
    if (arb.empty()) { // Caso base: arbol vacio
        return { 0,0 };
    }
    else if (arb.left().empty() && arb.right().empty()) { // Caso base: hoja con o sin viajeros
        if (arb.root() == 0) {
            return { 0, arb.root() };
        }
        else {
            return { 1, arb.root() };
        }
    }
    else {
        tSol iz = rescate(arb.left());
        tSol dr = rescate(arb.right());

        int max_viajeros = arb.root() + max(iz.viajeros, dr.viajeros); // nos quedamos con el maximo numero de viajereos entre los hijos y la raiz

        int min_equipos = iz.equipos + dr.equipos;

        if (min_equipos == 0 && arb.root() > 0) { // si no hay ningun equipo de rescate, y hay viajeros, entonces asignamos el primer equipo
            min_equipos = 1;
        }

        return { min_equipos, max_viajeros };
    }
}

void resuelveCaso() {
    BinTree<int> arbol;

    // leer los datos de la entrada
    arbol = read_tree<int>(cin);

    tSol sol = rescate(arbol);

    // escribir solución
    cout << sol.equipos << " " << sol.viajeros <<  "\n";
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("6_4.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("6_4.out");
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