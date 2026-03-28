 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Teclado estropeado

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <stack>
// Introduce más librerías si son necesarias
//#include "queue_linkedlist.h";
/*
Para resolver este problema necesitamos utilizar una list y un iterador. Tras leer la linea, creamos una lista vacia y un iterador que apunte al principio de esta. Vamos
leyendo caracter a caracter realizando los comandos del enunciado segun el tipo ('-' = list.begin(); '+' = list.end(); '*' = it++; '3' = list.erase(it); en cualquier 
otro caso list.insert(char, it)). 

Coste total: Sin contar la lectura de la entrada ni salida, el coste es de O(N) siendo N el numero de caracteres en la linea. 
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {    
    // leer los datos de la entrada
    string linea; cin >> linea;

    if (!std::cin) return false;

    list<char> palabra;

    auto it = palabra.begin();

    for (char c : linea) {

        switch (c)
        {
        case '-': { 
            it = palabra.begin(); 
        } break;
        case '+': { 
            it = palabra.end(); 
        } break;
        case '*': { 
            if (it != palabra.end()) 
                it++; 
        } break;
        case '3': { 
            if (it != palabra.end()) 
                it = palabra.erase(it); 
        } break;

        default: {
            palabra.insert(it, c);
        }break;
        }
    }


    // escribir solución
    for (auto c : palabra) {
        cout << c;
    }

    cout << "\n";

    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("5_1.in");
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