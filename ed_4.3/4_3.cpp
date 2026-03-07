 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: El alumno afortunado

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
// Introduce más librerías si son necesarias
//#include "queue_linkedlist.h";
/*
Para resolver el ejercicio necesitamos utilizar un cola doble en la que almacenaremos al principio de la cola el indice del valor mayor durante ese intervalo K.
Iteramos sobre todos los elementos O(N), y comparamos si es el elemento actual es mayor al que ya tenemos, si no lo es lo eliminamos del principio y quitamos 
a los menores sobrantes para quedarnos con el mayor.

Coste total: Sin contar la lectura de la entrada, el coste es de O(N) siendo N el numero de elementos en la lista. Costes de push_back, front, pop_back,front -> O(1)
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N = 0, K = 0; cin >> N >> K;
    
    if (!std::cin) return false;

    // leer los datos de la entrada
    vector<int> lista(N);
    int valor = 0; 

    for (int i = 0; i < N; i++) {
        cin >> lista[i];
    }

    // escribir solución
    deque<int> cola;

    int intervalo = 1;
    for (int i = 0; i < N; i++) {

        if (!cola.empty() && cola.front() <= i - K) {
            cola.pop_front();
        }

        while (!cola.empty() && lista[cola.back()] <= lista[i]) {
            cola.pop_back();
        }

        cola.push_back(i);

        if (i >= K - 1) {
            cout << lista[cola.front()] << " ";
        }

    }

    cout << "\n";

    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("4_3.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("4_1.out");
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