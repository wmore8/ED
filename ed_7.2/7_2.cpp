 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Los k elementos mayores

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
// Introduce más librerías si son necesarias
/*
Para resolver el ejercicio necesitamos utilizar una lista ordenada para quedarnos con los K mayores elementos. Para ello aprovecharemos la iteración de la entrada para
ir filtrando los valores en funcion del tamaño de la lista. Si tenemos mas de k elementos, borramos el primero de la lista, quedandonos con siempre con los k mayores

El coste de la funcion en el caso promedio es de O(n log (k)), siendo n el numero de elementos y k el numero de elementos mayores a consultar. El coste de recorrer todos
los elementos es lineal O(N), y el coste de insertar de manera ordenada un elemento en la lista es de O(log K). Como las inserciones e hacen durante el recorrido de todos 
los elementos, el coste total asciende a  : O(n log (k))
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

template <typename T>
void procesarEntrada(int k, T final) {
    set<T> lista;
    T valor;

    cin >> valor;
    while (valor != final) {
        lista.insert(valor);

        //Nos quedamos siempre con los k elementos mayores
        if (lista.size() > k) {
            lista.erase(lista.begin());
        }

        std::cin >> valor;
    }

    for (T valor : lista) {
        cout << valor << " ";
    }

    cout << "\n";
}

bool resuelveCaso() {
    char tipo = ' '; cin >> tipo;

    if (!cin) return false;
    // leer los datos de la entrada
    int k = 0; cin >> k;
    if (tipo == 'N') {
        procesarEntrada<int>(k, -1);
    }
    else {
        procesarEntrada<string>(k, "FIN");
    }

    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("7_2.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("7_2.out");
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