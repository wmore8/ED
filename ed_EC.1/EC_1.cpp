
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Desparizar una lista doblemente enlazada

#include <iostream>
#include <fstream>
#include "list_linked_double.h"
// Introduce más librerías si son necesarias
using namespace std;


// resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta
void resuelveCaso() {
   
   // leer los datos de la entrada
    ListLinkedDouble<int> lista, aux;

    int valor = 0;
    cin >> valor;

    while (valor != 0) {
        lista.push_back(valor);
        cin >> valor;
    }

    cin >> valor;
    while (valor != 0) {
        aux.push_back(valor);
        cin >> valor;
    }
   
   // escribir solución
    lista.desparizar(aux);

    lista.display();
    cout << "\n";
    aux.display();
    cout << "\n";
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