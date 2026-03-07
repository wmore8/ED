 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: El alumno afortunado

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
// Introduce más librerías si son necesarias
//#include "queue_linkedlist.h";
/*
Para resolver este ejercicio necesitamos utilizar una cola doble que simulara nuestra linea de escritura, y una cola que simulara nuestra pila de errores de escritura.
Vamos añadiendo palabras al final de la cola hasta que aparezca uno de los siguientes comandos. Si aparece la opcion de deshacer (<), añadimos la palabra del final a la 
pila y luego la borramos de la cola. Si la opercion es rehacer (>) añadimso al final de la cola el elemento top de la pila, y luego hacemos pop(). Ninguna de estas acciones
se llevan a cabo si alguna de las estructuras a consultar estan vacias. Si no hay ningun comando, añadimos la palabra al final de cola y borramos la pila de errores

Coste total: Sin contar la lectura de la entrada ni salida, el coste es de O(N) siendo N el numero de palabras a escribir. 
Costes de push_back, front, pop_back,front -> O(1)
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {    
    // leer los datos de la entrada
    vector<string> linea;
    string palabra = " ";

    cin >> palabra;

    while (palabra != ".") {
        linea.push_back(palabra);
        cin >> palabra;
    }
 
    // escribir solución
    deque<string> escribir;
    stack<string> deshacer;  

    for (string p : linea) {
        if (p == "<") { // ctrl +  z, asi que "borramos"
            if (!escribir.empty()) {
                deshacer.push(escribir.back());
                escribir.pop_back(); //quitamos el ultimo elemento escrito
            }
        }
        else if (p == ">") { // ctrl +  y, asi que "recuperamos"
            if (!deshacer.empty()) {
                escribir.push_back(deshacer.top());
                deshacer.pop();
            }
        }
        else {
            escribir.push_back(p);
            //al añadir una palabra ya no se puede deshacer
            while (!deshacer.empty()) {
                deshacer.pop();
            }
        }
    }
    //escribimos la solucion
    while (!escribir.empty()) {
        cout << escribir.front() << " ";
        escribir.pop_front();
    }

    cout << "\n";

    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("4_4.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("4_1.out");
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