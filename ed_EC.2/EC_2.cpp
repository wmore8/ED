
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Factor de equilibrio en un árbol binario (hojas)

#include <iostream>
#include <fstream>
#include "bintree_V6.h"
// Introduce más librerías si son necesarias
using namespace std;

/*
Para resolver el ejercicio hemos realizado una funcion recursiva del tipo divide y venceras,en el que recurivamente miramos el lado izquierdo y derecho del arbol.
Si el arbol es vacio o es una hoja, entonces cumple la funcion de equilibrio. en cualquier otro caso revisaremos que el valor de la raiz sea igual al numero de 
hojas del hijo izquierdo menos las del hijo derecho (ademas de que ambos hijos sean equilibrados tambien).

Ecuacion de recurrencia:
    - Caso base:        t(n) = C1  si               n <= 1
    - Caso recursivo    t(n) = 2*(t/2) + C2 si      n > 1

Coste asintotico: 
En el caso peor recorremos el arbol entero para verificar que cumpla la funcion de equilibrio.  Por el teorema de la division, con a = 2, b = 2 y k = 0; 
como a > b^k, el coste seria del orden O(n^{log_b(a)}). Como a y b son iguales -> a = b, el coste quedaria en O(n^{1}) = O(n) lineal
*/

struct tSol {
    int num_hojas;
    bool esEquilibrado;
};

tSol arbol_de_equilibrio_rec(BinTree<int> const& arb) {
    
    if (arb.empty()) { //Caso base: el arbol es vacio, por lo tanto cumple la funcion de equilibrio
        return { 0,true };
    }
    else if (arb.left().empty() && arb.right().empty()) { //Caso base: Estamos en una hoja, por lo tanto cumple la funcion de equilibrio
        return { 1,true };
    }
    else {
        tSol iz = arbol_de_equilibrio_rec(arb.left());
        tSol dr = arbol_de_equilibrio_rec(arb.right());

        bool esEquilibrado = arb.root() == iz.num_hojas - dr.num_hojas;

        return { iz.num_hojas + dr.num_hojas, esEquilibrado && iz.esEquilibrado && dr.esEquilibrado };
    }
}

bool arbol_de_equilibrio(BinTree<int> const& tree) {
    tSol sol = arbol_de_equilibrio_rec(tree);
    return sol.esEquilibrado;
}

// resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta
void resuelveCaso() {
   
   // leer los datos de la entrada
    BinTree<int> arbol = read_tree<int>(cin);
   
   // escribir solución
    if (arbol_de_equilibrio(arbol)) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }   
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("1.out");
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