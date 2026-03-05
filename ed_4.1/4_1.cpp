 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Paréntesis equilibrados

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
// Introduce más librerías si son necesarias
#include "stack_linkedlist.h"
/*
Para resolver el problema necesitamos comprobar si los parentesis cuentan con su apertura y cierre en orden de insercion. Leemos toda la linea en un string, 
y observamos caracter a caracter para ver si hay algun parentesis. Si es de apertura, lo añadimos a la pila con coste O(1), si es de cierre miramos al elemento
en la cima de la pila para ver si concide con el esperado de apertura con top() -> O(1). Si coincide, lo eliminamos de la pila (pop() -> O(1)), si no, lo añadimos
para que la pila no se encuentre vacia. Una vez finalizado el recorrido de la linea si la pila de parentesis esta vacia, entonces esta equilibrado.

Coste total: Recorremos todos los caracteres de la linea, realizando operaciones constantes como push, top, y pop O(1) -> O(N) siendo N el numero de caracteres.
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string linea = "", salto = "";
    getline(cin, linea);
    
    if (!std::cin) return false;

    // escribir solución
    StackLinkedList<char> parentesis;

    for (char c : linea) {
        if (c == '{' || c == '(' || c == '[') {
            parentesis.push(c);
        }
        else if (c == '}' || c == ')' || c == ']') {
            char expected = '?';
            switch (c){
            case '}': { expected = '{'; }break;
            case ']': { expected = '['; }break;
            case ')': { expected = '('; }break;
            }
            
            if (!parentesis.empty() && expected == parentesis.top()) {
                parentesis.pop();
            }
            else {
                parentesis.push(c);
            }
        }
    }
    // si la pila de parentesis esta vacia, entonces esta equilibrado
    bool equilibrado = parentesis.empty();

    if (equilibrado) {
        cout << "SI\n";
    }else{
        cout << "NO\n";
    }

    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("4_1.in");
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