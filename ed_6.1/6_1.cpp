 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Número de nodos, hojas y altura de un árbol binario

#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
#include "bintree_V6.h"
/*
Para resolver el ejercicio necesitamos utilizar una funcion recursiva (divide y venceras) para saber cuantos nodos, hojas y altura contiene el arbol binario.
Mientras iteramos devolvemos 2 casos bases : todo 0 si es un arbol vacio, y todo 1 si es una hoja (es decir un nodo del final). En cualquier otro caso nos quedamos
con la altura maximo de los 2 hijos + 1, la suma de las hojas de ambos hijos y la suma de los nodos de ambos hijos + el actual.

El coste es lineal en funcion del numero de nodos del arbol (debido a que solo se recorre una unica vez) : O(N) siendo N el numero de nodos
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

struct tSol {
    int num_nodos;
    int num_hojas;
    int altura;
};

tSol rec_arbol(const BinTree<char>& arb) {
    if (arb.empty()) { // Caso base: el arbol es vacio
        return { 0,0,0 };
    }
    else  if (arb.left().empty() && arb.right().empty()) { // Caso base: el arbol es una hoja (no tiene hijos)
        return { 1,1,1 };
    }
    else {// caso recursivo: es un nodo con 1 o 2 hijos
        tSol iz = rec_arbol(arb.left());
        tSol dr = rec_arbol(arb.right());

        return { 1+ iz.num_nodos + dr.num_nodos, iz.num_hojas + dr.num_hojas,1 + max(iz.altura,dr.altura) };
    }
}

void resuelveCaso() {
    int valor = 0;
    BinTree<char> arbol;

    // leer los datos de la entrada
    arbol = read_tree<char>(cin);

    tSol sol = rec_arbol(arbol);

    // escribir solución
    cout << sol.num_nodos << " " << sol.num_hojas << " " << sol.altura << "\n";
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("6_1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("6_1.out");
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