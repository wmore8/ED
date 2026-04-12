
// Construye un árbol binario a partir de la entrada y después
// calcula de forma recursiva su altura, nodos y hojas con una función externa a la clase

// Implementación que lee/escribe los datos de ficheros disponibles en 
// el juez de la asignatura de Estructuras de Datos.





#include <iostream>
#include <algorithm>
#include "bintree_V6.h"
using namespace std;


template <typename T>
int numero_nodos(const BinTree<T> &tree) {
    if (tree.empty()) {
        // El árbol vacío no tiene nodos.
        return 0;
    } else {
        // Devolvemos la suma de:
        //   - el número de nodos del hijo izquierdo
        //   - el número de nodos del hijo derecho
        //   - 1, por el nodo raííz.
        return 1 + numero_nodos(tree.left()) + numero_nodos(tree.right());
    }
}

template <typename T>
int numero_hojas(const BinTree<T> &tree) {
    if (tree.empty()) {
        // El árbol vacío no tiene hojas.
        return 0;
    } else if (tree.left().empty() && tree.right().empty()) {
       return 1;
    } else {
        return numero_hojas(tree.left()) + numero_hojas(tree.right());
    }
}


template <typename T>
int altura(const BinTree<T> &tree) {
    if (tree.empty()) {
        // La altura del árbol vacío es, por convenio, cero
        return 0;
    } else {
        // Calculamos la altura de ambos hijos. Nos quedamos con
        // la mayor de ellas y le sumamos uno (por el nivel extra que
        // añade la raíz)
        return 1 + std::max(altura(tree.left()), altura(tree.right()));
    }
}


void resuelveCaso() {
   auto arbol = read_tree<char>(cin);

   std::cout << numero_nodos(arbol) << ' '
   << numero_hojas(arbol) << ' ' << altura(arbol) << "\n";
   
}

int main() {
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   return 0;
}
