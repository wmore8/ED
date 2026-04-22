 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: ¿Es un árbol binario de búsqueda?

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

template <typename T>
struct tSol {
    T min;
    T max;
    bool esBinario;
};

template <typename T>
tSol<T> esABB(const BinTree<T>& arb) {
    if (arb.empty()) {
        return { T(), T(), true}; //caso base vacio
    }
    else {
        T min_absoluto = arb.root();
        T max_absoluto = arb.root();
        bool esBinario = true;

        if (!arb.left().empty()) {
            tSol<T> iz = esABB(arb.left());
            esBinario = esBinario && iz.esBinario && (iz.max < arb.root());
            min_absoluto = iz.min; // Actualizamos el minimo
        }

        if (!arb.right().empty()) {
            tSol<T> dr = esABB(arb.right());
            esBinario = esBinario && dr.esBinario && (arb.root() < dr.min);
            max_absoluto = dr.max; // Actualizamos el maximo
        }

        return { min_absoluto,max_absoluto,esBinario };
    }
}

bool resuelveCaso() {
    char Tipo = ' '; cin >> Tipo;
    if (!cin) return false;
    
    // leer los datos de la entrada
    if (Tipo == 'N') {
        BinTree<int> intArb = read_tree<int>(cin);
        tSol<int> intSol = esABB(intArb);

        if (intSol.esBinario) {
            cout << "SI";
        }
        else {
            cout << "NO";
        }
    }else{
        BinTree<string> stringArb = read_tree<string>(cin);
        tSol<string> stringSol = esABB(stringArb);

        if (stringSol.esBinario) {
            cout << "SI";
        }
        else {
            cout << "NO";
        }
    }
    
    // escribir solución
    
    cout << "\n";

    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("6_9.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("6_9.out");
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