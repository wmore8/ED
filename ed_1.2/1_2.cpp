
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Perfil de una curva concava

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
// Introduce más librerías si son necesarias

/*
El coste de la funcion duplicate es lineal O(N) debido a que necestamos recorrer todos los elementos para poder duplicarlos, siendo N el tamaño de la lista
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta
/*

Ecuacion de recurrencia:
    - Caso base:        T(n) = C1  si n < 1
    - Caso recrusivo:   T(n) = T(n/2) +  C2  si n > 1
 
Coste: O(log N) por el teorema de la division con a =  1, b = 2 y k = 0.
*/

int concavo(const vector<int>& v, int ini, int fin) {
    if (ini == fin) {
        return v[ini];
    }
    else{
        int m = (ini + fin) / 2;
        if (v[m] < v[m + 1]) {
            return concavo(v, ini, m);
        }
        else {
            return concavo(v, m + 1, fin);
        }
    }
}

bool resuelveCaso() {
    int N = 0; cin >> N; 
    if (!std::cin) return false;
   
    // leer los datos de la entrada
    vector<int> lista(N);

    for (int i = 0; i < N; i++) {
        cin >> lista[i];
    }
    // escribir solución
    int min = concavo(lista, 0, N - 1);

    cout << min << "\n";

    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("1_2.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("2_1.out");
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