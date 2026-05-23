 
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: El juego de la mona

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
// Introduce más librerías si son necesarias
/*
Para resolver el ejercicio necesitamos utilizar un diccionario que alamecen el nombre de los jugadores como clave y los numeros de su carton como un set desordeando.
Tras leer la entrada, vamos leyendo numero a numero los valores que se estan cantando y comprobamos en todos los cartones de los jugadores si ese numero existe. En 
caso de que si, lo eliminamos. En esta iteracion tambien comporbamos que jugador tiene el set vacio (es decir todo tachado), para parar el bucle.

Coste total: El coste en espacio es de O(N + K) siendo N el numero de jugadores y K el numero de valores en el carton.

El coste asindotico necesita recorrer todos los cartones para ver que numero tachar O(N),y para cada carton, nencesitamos saber si existe O(1) y eliminarlo en caso
de que si O(1). Para saber si esta vacio el carton, tambien es constante -> empty O(1). El coste total es de O(N + K) siendo N el numero de cartones y K el numero de
valores dentro de cada carton
*/

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta


bool resuelveCaso() {
    int N; cin >> N;

    if (N == 0) return false;
    // leer los datos de la entrada
    unordered_map<int, unordered_set<string>> numeros_a_jugadores;
    unordered_map<string, int> faltantes;
    set <string> ganadores;

    for (int i = 0; i < N; i++) {
        string nombre; 
        unordered_set<int> carton;
        int valor;
        cin >> nombre >> valor;

        while (valor != 0) {
            numeros_a_jugadores[valor].insert(nombre);
            faltantes[nombre]++;
            cin >> valor;
        }

    }

    //leemos los numeros que van saliendo

    int numero = 0;
    bool hayGanador = false;

    while (!hayGanador) {
        cin >> numero; 
        //si hay algun numero que coincida con los demas cartones
        if (numeros_a_jugadores.count(numero) == 1) {
            for (const string& jugador : numeros_a_jugadores[numero]) {
                faltantes[jugador]--;

                if (faltantes[jugador] == 0) {
                    hayGanador = true;
                    ganadores.insert(jugador);
                }
            }
        }

    }

    // Escribir solución
    for (string ganador : ganadores) {
        cout << ganador << " ";
    }

    cout << "\n";
  
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("8_1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    //std::ofstream out("8_1.out");
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