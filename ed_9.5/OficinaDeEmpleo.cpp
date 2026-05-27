
// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Oficinas de empleo

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "OficinaDeEmpleo.h"


bool resuelveCaso() {
	std::string op, persona, empleo;
	std::cin >> op;
	if (!std::cin)
		return false;

	OficinaEmpleo OE;

	while (op != "FIN") {
		try {
			if (op == "altaOficina") {
				cin >> persona >> empleo;

				OE.altaOficina(persona, empleo);
			}
			else if (op == "ofertaEmpleo") {
				cin >> empleo;
				string candidato = OE.ofertaEmpleo(empleo);

				cout << empleo << ": " << candidato << "\n";
			}
			else if (op == "listadoEmpleos") {
				cin >> persona;
				vector<string> lista = OE.listadoEmpleos(persona);

				cout << persona << ": ";

				for (string empleo : lista) {
					cout << empleo << " ";
				}

				cout << "\n";
			}
			
			
		}
		catch (std::domain_error e) {
			std::cout << "ERROR: " << e.what() << "\n";
		}
		std::cin >> op;
	}
	std::cout << "---\n";
	return true;
}

	
int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("9_5.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	/*std::ofstream out("datos.out");
	auto coutbuf = std::cout.rdbuf(out.rdbuf());*/
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	//std::cout.rdbuf(coutbuf);
#endif
	return 0;
}