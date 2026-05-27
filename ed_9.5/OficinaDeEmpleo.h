// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Oficinas de empleo


#ifndef OFICINA
#define OFICINA

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>


using namespace std;



class OficinaEmpleo {
	unordered_map<string,list<string>> empleosDisponibles;
	unordered_map<string, map<string,list<string>::iterator>> personasApuntadas;

public:

	// MÉTODOS

	//Coste : O(log E) siendo E el numero de empleos en los que ya este apuntados la persona. Las operaciones de unordered_map son constantes y las de la cola tambien.
	// El unico coste que marca la funcion es insertar el empleo en el set, ya que se ordena al insertarlo
	void altaOficina(const string& nombre, const string& empleo) {

		//si la persona no esta apuntada 
		//if (personasApuntadas.count(nombre) == 0 && empleosDisponibles.count(empleo) == 0) {
		//	personasApuntadas[nombre].insert(empleo);
		//	empleosDisponibles[empleo].push(nombre);
		//}

		if (personasApuntadas[nombre].count(empleo) == 0) {
			//creamos o añadimos al empleo, una persona mas a la cola
			empleosDisponibles[empleo].push_back(nombre); 
			auto it = empleosDisponibles[empleo].end(); it--; //guardamos la posicion donde se ha insertado
			//damos de alta a la persona con el empleo para el que esta cualificada
			personasApuntadas[nombre][empleo] = it;
		}

	}

	//Coste: O(E) Siendo E el numero de empleos asociados a la persona. Necesitamos recorrer esos empleos para eliminar a la persona.
	// las operaciones at y erase de map son O(log E). Las funciones erase y accesos a la list son constantes, al igual que las de unordered_map
	string ofertaEmpleo(const string& empleo) {
		if (empleosDisponibles.count(empleo) == 0 || empleosDisponibles[empleo].empty()) {
			throw std::domain_error("No existen personas apuntadas a este empleo");
		}
		
		//nos quedamos con la persona que mas tiempo lleva esperando
		string persona = empleosDisponibles[empleo].front();

		for (auto per : personasApuntadas[persona]) {
			string empleoApuntado = per.first; // nos quedamos con la clave de ada empleo apuntado
			auto posicion = per.second; // nos quedamos con la posicion

			empleosDisponibles[empleoApuntado].erase(posicion);

			// si no hay mas personas apuntadas en ese empleo lo eliminamos
			if (empleosDisponibles[empleoApuntado].empty()) {
				empleosDisponibles.erase(empleoApuntado);
			}
		}
		personasApuntadas.erase(persona); //desapuntamos a la persona de la oficina de empleo

		return persona;
	}
	
	//Coste: O(E) siendo E el numero de empleos a los que esta apuntado la persona. Necesitamos recorrer todos esos empleos para añadirlos a la lista. Las demas operaciones
	// son constantes
	const vector<string> listadoEmpleos (const string& persona) const{
		if (personasApuntadas.count(persona) == 0) {
			throw std::domain_error("Persona inexistente");
		}

		vector<string> lista;

		for (auto empleo : personasApuntadas.at(persona)) {
			lista.push_back(empleo.first);
		}

		return lista;
	}

};
#endif
