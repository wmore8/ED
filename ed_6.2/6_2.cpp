 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Árboles zurdos

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
    int num_nodos;
    bool esZurdo;
};

tSol es_zurdo(const BinTree<char>& arb) {
    if (arb.empty()) { // Caso base: el arbol es vacio (por lo tanto es zurdo)
        return { 0,true };
    }
    else  if (arb.left().empty() && arb.right().empty()) { // Caso base: el arbol es una hoja (no tiene hijos y por lo tanto es zurdo)
        return { 1,true };
    }
    else {// caso recursivo: es un nodo con 1 o 2 hijos
        tSol iz = es_zurdo(arb.left());
        tSol dr = es_zurdo(arb.right());

        bool esZurdo = iz.esZurdo && dr.esZurdo && iz.num_nodos > dr.num_nodos;

        return { 1+ iz.num_nodos + dr.num_nodos, esZurdo };
    }
}

void resuelveCaso() {
    int valor = 0;
    BinTree<char> arbol;

    // leer los datos de la entrada
    arbol = read_tree<char>(cin);

    tSol sol = es_zurdo(arbol);

    // escribir solución
    if (sol.esZurdo) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("6_2.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("6_2.out");
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