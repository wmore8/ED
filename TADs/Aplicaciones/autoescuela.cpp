
// Ejercicio de la autoescuela

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "autoescuela.h"


bool resuelveCaso() {
	std::string op, alum, prof;
	int punt;
	std::cin >> op;
	if (!std::cin)
		return false;

	autoescuela AE;

	while (op != "FIN") {
		try {
			if (op == "alta") {
				cin >> alum >> prof;
				AE.alta(alum, prof);
			}
			else if (op == "es_alumno") {


			}
			else if (op == "puntuacion") {


			}
			else if (op == "actualizar") {


			}
			else if (op == "examen") {


			}
			else if (op == "aprobar") {


			}
		}
		catch (std::domain_error e) {
			std::cout << "ERROR\n";
		}
		std::cin >> op;
	}
	std::cout << "---\n";
	return true;
}

	
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("1.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	std::ofstream out("datos.out");
	auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);
#endif
	return 0;
}