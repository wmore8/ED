// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Carnet por puntos 2


#ifndef CARNET
#define CARNET

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <vector>
#include <list>


using namespace std;

const int PUNTOS_INICIALES = 15;

struct InfoConductor {
	int puntos;
	list<string>::iterator posicion;
};

class CarnetPuntos {
private:
	// ATRIBUTOS
	unordered_map<string, InfoConductor> conductores;
	vector<list<string>> listaPuntos;



public:

	// MÉTODOS
	//CONSTRUCTORA PARA INICIALIZAR EL ARRAY (16 porque contamos el 0 tambien)
	CarnetPuntos() : listaPuntos(16) {};

	//Coste: O(1) o O(N) en funcion del contenido de la tabla hash. El promedio suele ser constante por el insert
	void nuevo(const string& dni) {
		if (conductores.count(dni) == 1) {
			throw std::domain_error("Conductor duplicado");
		}

		//añadimos el conductor en la primera posicion para tenerlo ordenado (LIFO)
		listaPuntos[PUNTOS_INICIALES].push_front(dni);

		InfoConductor datos = { PUNTOS_INICIALES, listaPuntos[PUNTOS_INICIALES].begin() };

		conductores.insert({ dni,datos });
	}

	//Coste: O(1) La operacion erase es constante en list (siempre y cuando tengamos el iterador), push_front tambien es constante
	void quitar(const string& dni, int puntos) {
		if (conductores.count(dni) == 0) {
			throw std::domain_error("Conductor inexistente");
		}

		InfoConductor datosConductor = conductores[dni];
		//solo eliminamos puntos si son mayores que 0

		if (datosConductor.puntos > 0 && puntos > 0) {
			//eliminamos el dni de la lista de los puntos antiguos
			listaPuntos[datosConductor.puntos].erase(datosConductor.posicion);

			//actualizamos los puntos
			datosConductor.puntos -= puntos;

			if (datosConductor.puntos < 0) {
				datosConductor.puntos = 0;
			}
			//actualizamos la posicion
			listaPuntos[datosConductor.puntos].push_front(dni);
			datosConductor.posicion = listaPuntos[datosConductor.puntos].begin();

			conductores[dni] = datosConductor;
		}
	}
	
	void recuperar(const string& dni, int puntos) {
		if (conductores.count(dni) == 0) {
			throw std::domain_error("Conductor inexistente");
		}

		//eliminamos el dni de la lista de los puntos antiguos
		InfoConductor datosConductor = conductores[dni];
		if (datosConductor.puntos < 15 && puntos > 0) {
			listaPuntos[datosConductor.puntos].erase(datosConductor.posicion);

			//actualizamos los puntos
			datosConductor.puntos += puntos;

			if (datosConductor.puntos > 15) {
				datosConductor.puntos = 15;
			}
			//actualizamos la posicion
			listaPuntos[datosConductor.puntos].push_front(dni);
			datosConductor.posicion = listaPuntos[datosConductor.puntos].begin();

			conductores[dni] = datosConductor;

		}
	}


	//Coste: O(1) consultar con count en un unordered_map es constante 
	int consultar(const string& dni) const{
		if (conductores.count(dni) == 0) {
			throw std::domain_error("Conductor inexistente");
		}
		return conductores.at(dni).puntos;
	}

	//Coste: O(1) consultar el tamaño de una lista es constante, y acceder al valor del vector tambien lo es

	int cuantos_con_puntos(int puntos) const {
		if (puntos < 0 || puntos > 15) {
			throw std::domain_error("Puntos no validos");
		}

		return listaPuntos[puntos].size();
	}

	//Coste: O(1) porque acceder a un valor de un vector a traves de [] es constante
	const list<string>& lista_por_puntos(int puntos) const {
		if (puntos < 0 || puntos > 15) {
			throw std::domain_error("Puntos no validos");
		}

		return listaPuntos[puntos];
	}

};
#endif
