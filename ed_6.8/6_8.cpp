 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Reconstrucción de un árbol binario

#include <iostream>
#include <fstream>
#include <vector>
// Introduce más librerías si son necesarias
#include "bintree_V6.h"
/*
Para resolver el ejercicio necesitamos reconstruir el arbol recursivamente mediante una funcion recuriva no final auxiliar. Comparamos las listas en preorden e inorden
para ver de que manera colocamos los nodos, mirando primero el lado izquierdo para luego mirar el lado derecho y reconstruir uniendo la raiz con ambos hijos.

El coste en el caso peor es cuadratico O(N^2) debido a que si el arbol esata muy desordenado, en cada iteracion necesitamos recorrer todos los elementos hasta encontrar
la raiz. El caso promedio es de O(N log N), si el arbol esta mas o menos equlibrado, y no hace falta recorrer todos los nodos para buscar la raiz actual (divide y venceras)
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta


BinTree<int> reconstruir_rec(const vector<int>& preorden, const vector<int>& inorden, int pre_ini, int pre_fin, int in_ini, int in_fin) {

    // Caso base: Si el inicio supera al fin, el subarbol esta vacio
    if (pre_ini > pre_fin) {
        return BinTree<int>();
    }

    // La raiz es siempre el primer elemento del segmento de preorden
    int raiz = preorden[pre_ini];

    // Buscamos donde esta esa raiz en el segmento de inorden
    int pos_raiz_in = in_ini;
    while (inorden[pos_raiz_in] != raiz) {
        pos_raiz_in++;
    }

    // Calculamos el tamaño del subarbol izquierdo
    int tam_izq = pos_raiz_in - in_ini;

    /*Construimos el subarbol izquierdo recursivamente:
        - El preorden izquierdo empieza justo despues de la raiz y ocupa tam_izq elementos
        - El inorden izquierdo va desde el principio hasta justo antes de la raiz
    */
    BinTree<int> izq = reconstruir_rec(preorden, inorden, pre_ini + 1, pre_ini + tam_izq, in_ini, pos_raiz_in - 1);

    /*
    Construimos el subarbol derecho recursivamente:
        - El preorden derecho empieza despues de saltar la raiz y todo el subarbol izquierdo
        - El inorden derecho empieza justo despues de la raiz
    */
    BinTree<int> der = reconstruir_rec(preorden, inorden, pre_ini + tam_izq + 1, pre_fin, pos_raiz_in + 1, in_fin);

    // Unimos los trozos con la constructora de BinTree y lo devolvemos
    return BinTree<int>(izq, raiz, der);
}

BinTree<int> reconstruir(const vector<int>& preorden, const vector<int>& inorden) {
    return reconstruir_rec(preorden, inorden, 0, preorden.size() - 1, 0, inorden.size() - 1);
}

bool resuelveCaso() {

    int N = 0; cin >> N;
    if (!cin) return false;

    // leer los datos de la entrada
    vector<int> preorden(N), inorden(N);

    for (int i = 0; i < N; i++){
        cin >> preorden[i];
    }

    for (int i = 0; i < N; i++){
        cin >> inorden[i];
    }

    // escribir solución
    BinTree<int> sol = reconstruir(preorden, inorden);

    sol.display(cout);

    cout << "\n";
    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("6_8.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("6_8.out");
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