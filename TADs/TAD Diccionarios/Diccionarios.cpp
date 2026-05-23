/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */


/*

Ejercicio: frecuencia de palabras en un texto


Si las palabras con tilde no se muestran correctamente con Microsoft Visual Studio, hacer:
	Archivo -> Guardar como…
	Flechita en Guardar
	Guardar con codificación…
	Selecciona: UTF-8 sin firma (Codepage 65001)
*/

#include <iostream>
#include <unordered_map>
#include <sstream>
#include <map>
#include <cctype>  // tolower - convierte un carácter a minúscula
#include <locale>  // Mostrar bien caracteres acentuados
#include <windows.h>

using namespace std;



// Limpia la palabra de signos de puntuación y la pasa a minúsculas
string limpiar(string palabra) {
	string res;
	for (string::iterator it = palabra.begin(); it != palabra.end(); ++it) {
		if (*it != ',' && *it != '.' && *it != ';') {
			res += tolower(*it);  // convierte a minúscula.
		}
	}
	return res;
}

int main() {

	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "");  // Para mostrar bien en consola las tildes

	string texto = "En un lugar de la Mancha, de cuyo nombre no quiero acordarme, "
		"no ha mucho tiempo que vivía un hidalgo de los de lanza en astillero, "
		"adarga antigua, rocín flaco y galgo corredor. Una olla de algo más "
		"vaca que carnero, salpicón las más noches, duelos y quebrantos los sábados, "
		"lantejas los viernes, algún palomino de añadidura los domingos, "
		"consumían las tres partes de su hacienda.";

	string palabra;
	stringstream ss(texto);  // flujo de entrada a partir de un string

	unordered_map<string, int> dic_no_ord;

	while (ss >> palabra) {  // O(n) siendo n el número de palabras del texto
		palabra = limpiar(palabra);  
		if (!palabra.empty()) 
			dic_no_ord[palabra]++;  // insercción en un unordered_map es O(1) en promedio
	}

	cout << "Número de palabras distintas: " << dic_no_ord.size() << endl;  // O(1) 

	// Vamos a pasar unordered_map a map usando iteradores para ordenar las entradas por claves.
	
	map<string, int> dic_ord;

	// la construcción de un map a partir de un unordered_map es O(u log u), 
	// siendo u el número de palabras contenidas en el unordered_map (todas distintas), 
	// pues cada inserción en map es O(log u)
	// Se puede cambiar auto por unordered_map<string, int>::iterator
	for (auto it = dic_no_ord.begin(); it != dic_no_ord.end(); ++it) {
		dic_ord.insert(*it);
	}


	// Mostrar el diccionario dic_ord O(u) siendo u el número de palabras distintas
	// Se puede cambiar auto por map<string, int>::iterator 
	for (auto it = dic_ord.begin(); it != dic_ord.end(); ++it) {
		cout << it->first << " -> " << it->second << endl;
	}

	return 0;
}
