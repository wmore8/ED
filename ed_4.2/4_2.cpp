 
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
Para resolver el ejercicion necesitamos utilizar un cola para mantener a los alumnos ordenados y saber a cual eliminar en cada iteracion. saltamos a tantos
alumnos como saltos tengamos y los añadimso al final de cola, y eliminamos al que corresponda, quedandonos con un alumno menos en la cola tras cada iteracion.
Finalmente cuando queda 1 finalizamos el bucle y lo mostramos

Coste total: Sin contar la lectura de la entrada, el coste es de O(N * S) siendo N el numero de alumnos y S el valor del salto 
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N = 0, salto = 0; cin >> N >> salto;
    
    if (N == 0 && salto == 0) return false;

    // escribir solución
    queue<int> alumnos;

    for (int i = 0; i < N; i++) {
        alumnos.push(i + 1);
    }

    //iteramos hasta que solo quede 1
    while (alumnos.size() > 1) {
        //salvamos a los que no les corresponde el salto
        for (int i = 0; i < salto; i++) {
            int salvado = alumnos.front();
            alumnos.pop();
            alumnos.push(salvado);
        }
        //eliminamos al alumno al que le corresponde el salto
        alumnos.pop();
    }

    cout << alumnos.front() << "\n";

    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("4_2.in");
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