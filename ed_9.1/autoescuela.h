

// Autor/a: Washington Morocho Lema
// email: wmorocho@ucm.es
// Nombre del problema: Autoescuela


#ifndef AUTOESCUELA
#define AUTOESCUELA

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>


using namespace std;


class autoescuela {
	// ATRIBUTOS

	struct DatosAlumno {
		int puntuacion;
		string profesor;
	};

	unordered_map<string, unordered_set<string>> profesores; //diccionario de profesores con una lista ordenada de alumnos
	unordered_map<string, DatosAlumno> alumnos; // diccionario de las puntuaciones de los alumnos y el profesor asignado a un alumno

public:

	// MÉTODOS

	//Coste: O(1) al usar unordered map con unordered_set, los costes de insercion son constantes en la tabla hash
	void alta(const string& alumno, const string& profesor) {
		//si el alumno ya esta matriculado
		if (alumnos.count(alumno) == 1) {
			//le cambiamos el profesor
			string antiguo_profesor = alumnos[alumno].profesor;
			profesores[antiguo_profesor].erase(alumno);
			alumnos[alumno].profesor = profesor; //cambiamos el profesor asignado al alumno
			profesores[profesor].insert(alumno); //añadimos el alumno a la lista del nuevo profesor
			//no tocamos la puntuacion puesto que ya esta dado de alta
		}
		else {
			DatosAlumno datos{ 0, profesor };
			alumnos.insert({ alumno, datos });
			profesores[profesor].insert(alumno);
		}

	}

	// Coste: O(1) constante gracias a la consulta del unordered_map. Con ese acceso podemos saber si el alumno tiene asignado profesor y viceversa.
	bool es_alumno(const string& alumno, const string& profesor) {
		return alumnos.count(alumno) && alumnos[alumno].profesor == profesor;
	}
	// Coste: O(1) constante gracias a la consulta del unordered_map. Con ese acceso podemos saber si el alumno existe y en caso de que si, obtener su puntuacion.
	int puntuacion(const string& alumno) {
		if (alumnos.count(alumno) == 0) {			
			throw std::domain_error("El alumno " + alumno + " no está matriculado.");
		}

		return alumnos[alumno].puntuacion;
	}

	// Coste: O(1) constante gracias a la consulta del unordered_map. Con ese acceso podemos saber si el alumno existe y en caso de que si, actualizar su puntuacion.
	void actualizar(const string& alumno, const int& N) {
		if (alumnos.count(alumno) == 0) {
			throw std::domain_error("El alumno " + alumno + " no está matriculado.");
		}
		alumnos[alumno].puntuacion += N;
	}

	// Coste: O(N + A log A) lineal en funcion del numero de alumnos asignados al profesor, pero logaritmico al hacer los inserts de la lista desordenada a la ordenada
	set<string> examen(const string& profesor, const int& N) {
		set<string> aptos;

		if (profesores.count(profesor) == 1) { // si existe el profesor
			for (auto alumno : profesores[profesor]) {
				if (alumnos[alumno].puntuacion >= N) {
					aptos.insert(alumno);
				}
			}
		}

		return aptos;
	}

	// Coste: O(1) constante gracias a la consulta del unordered_map. Con ese acceso podemos saber si el alumno existe y en caso de que si, lo eliminamos de ambas estructuras
	void aprobar(const string& alumno) {
		if (alumnos.count(alumno) == 0) {
			throw std::domain_error("El alumno " + alumno + " no está matriculado.");
		}

		string profesor = alumnos[alumno].profesor;
		profesores[profesor].erase(alumno);
		alumnos.erase(alumno);
	}

};
#endif
