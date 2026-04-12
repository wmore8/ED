
// Construye un árbol binario a partir de la entrada y después
// recorre el árbol en preorden, inorden, postorden y nivel.


#include <iostream>
#include <algorithm>
#include "bintree_V6.h"
using namespace std;




int main() {

    /*
         A
        / \
       B   C
      / \   \
     D   E   F

    */


    BinTree<char> arbol_char = {
    { { {}, 'D', {} }, 'B', { {}, 'E', {} } },
    'A',
    { {}, 'C', { {}, 'F', {} } }
    };

	// Recorridos del árbol.
	// En cada recorrido se muestra el orden de los elementos del árbol 
    // aplicando una función lambda que recibe un carácter c 
    // e imprime el elemento seguido de un espacio.
	// ([](char c) { std::cout << c << ' '; }) 

	std::cout << "Preorden:  ";
    arbol_char.preorder([](char c) { std::cout << c << ' '; });
	std::cout << "\nInorden:   ";
    arbol_char.inorder([](char c) { std::cout << c << ' '; });
	std::cout << "\nPostorden: ";
    arbol_char.postorder([](char c) { std::cout << c << ' '; });
	std::cout << "\nNivel:     ";
    arbol_char.levelorder([](char c) { std::cout << c << ' '; });
    std::cout << '\n';



    /*
         1
        / \
       2   3
      / \   \
     4   5   6

    */


    BinTree<int> arbol_int = {
    { { {}, 4, {} }, 2, { {}, 5, {} } },
    1,
    { {}, 3, { {}, 5, {} } }
    };

    // Recorridos del árbol.
    // En cada recorrido se muestra el orden de los elementos del árbol 
    // aplicando una función lambda que recibe un carácter c 
    // e imprime el elemento seguido de un espacio.
    // ([](char c) { std::cout << c << ' '; }) 

    std::cout << "\nPreorden:  ";
    arbol_int.preorder([](int x) { std::cout << x << ' '; });

    std::cout << "\nPreorden de los elementos pares:  ";
    arbol_int.preorder([](int x) { 
		if (x % 2 == 0) std::cout << x << ' '; }
    );

	// Pasar los elementos del árbol a un vector, 
    // ordenados en preorden, y mostrar el vector.
	// v se pasa por referencia a la función lambda, 
    // para que la función lambda pueda modificar el vector v.

	vector<int> v;
	arbol_int.preorder([&v](int x) { v.push_back(x); });
	std::cout << "\nDatos del vector:  ";
	for (int x : v) {
		std::cout << x << ' ';
	}
	std::cout << '\n';

    return 0;
}
