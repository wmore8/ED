 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Diámetro de un árbol binario

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
    int altura;
    int diametro;
};

tSol rec_diametro(const BinTree<char>& arb) {
    if (arb.empty()) {
        return { 0,0 };
    }
    else if (arb.left().empty() && arb.right().empty()) {
        return { 1,1 };
    }
    else {
        tSol iz = rec_diametro(arb.left()); // la solucion puede estar en el hijo izquierdo
        tSol dr = rec_diametro(arb.right());// la solucion puede estar en el hijo derecho
        //la solucion puede estar en la raiz junto al camino formado por la altura ambos hijos
        int diametro_raiz = iz.altura + dr.altura + 1;
        int diametro_hijos = max(iz.diametro, dr.diametro);

        //Nos quedamos con la altura altura (independientemente de si estamos en el nodo iz o dr), y el maximo entre las 3 opciones
        return { max(dr.altura,iz.altura) + 1, max(diametro_raiz,diametro_hijos) };
    }
}

void resuelveCaso() {
    BinTree<char> arbol;

    // leer los datos de la entrada
    arbol = read_tree<char>(cin);

    tSol sol = rec_diametro(arbol);

    // escribir solución
    cout << sol.diametro << "\n";
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("6_3.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("6_3.out");
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