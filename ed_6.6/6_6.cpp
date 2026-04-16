 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: La barrera de los primos

#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
#include "bintree_V6.h"
/*
Para resolver el ejercicio necesitamos realizar un recorrido en profundidad (DFS) sobre el arbol, priorizando el lado izquierdo para encontrar que nodos conformaran
el perfil. Usamos una funcion recursiva no final, en la que usamos parametros con y sin referencia a memoria para ir descendiendo en altura y alamcenar el nodo que 
este mas a la izquierda en el vector solucion.

El coste de la funcion es O(log N) debido a que no recorremos todos los nodos, y el calculo para saber si un numero es primo es constante O(1) porque solo calculamos
si es divisible hasta la mitad del valor Coste total -> O(log N) sin contar la entrada y salida.
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

const int INF = 1000000000;

struct tSol {
    int valor;
    int profundidad;
};

bool esPrimo(int n) {
    
    if (n <= 1) { // El 0 y el 1 no se consideran primos matematicamente
        return false;
    }

    // Comprobamos divisores desde el 2 hasta la raiz cuadrada de n
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; // Si es divisible por otro numero que no sea 1 o el mismo ,entonces no es primo
        }
    }

    return true; // Si ha sobrevivido al bucle, es primo
}

tSol accesible(const BinTree<int>& arb, int profundidad) {
    if (arb.empty() || esPrimo(arb.root())) { // Caso base: si es vacio o primo, entonces no hay solucion
        return { -1, INF};
    }
    else {
        if (arb.root() % 7 == 0) { // si el nodo es multiplo de 7 lo devolvemos
            return { arb.root() , profundidad};
        }

        tSol iz = accesible(arb.left(), profundidad + 1);
        tSol dr = accesible(arb.right(), profundidad + 1);

        if (iz.profundidad <= dr.profundidad) {
            return iz;
        }
        else {
            return dr;
        }
    }
}

void resuelveCaso() {
    BinTree<int> arbol;

    // leer los datos de la entrada
    arbol = read_tree<int>(cin);

    tSol sol = accesible(arbol, 1);

    // escribir solución

    if (sol.profundidad != INF) {
        cout << sol.valor << " " << sol.profundidad;
    }
    else {
        cout << "NO HAY";
    }

    cout << "\n";
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("6_6.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("6_6.out");
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