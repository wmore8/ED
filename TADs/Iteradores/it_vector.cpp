/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Sonia Estévez Martín
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */


// Iteradores en vector
// Un iterador es un objeto que permite recorrer los elementos 
// de una estructura de datos, como el vector.
// Se pueden usar iteradores constantes (const_iterator) 
// para recorrer un vector sin modificarlo, 
// o iteradores no constantes (iterator) para recorrer un vector y modificarlo.



#include <iostream>
#include <vector>
using namespace std;

int suma(vector<int>& v) {

	vector<int>::iterator it;  // auto it

	int suma = 0;

	for (it = v.begin(); it != v.end(); ++it) {
		suma += *it;
	}
	cout << suma << endl;
	return 0;
}


// En la función suma, el iterador no es constante, por lo tanto, se puede modificar el vector a través del iterador.
// Sin embargo, en este ejemplo no se modifica el vector, solo se recorre para sumar sus elementos.
// Así mejor usar un iterador constante, pues solo se quiere leer sus elementos.

// Importante: Si el parámetro es const, no se puede usar un iterador no constante, da error de compilación. 

int suma_const(const vector<int>& v) {

	int suma = 0;

	for (auto it = v.cbegin(); it != v.cend(); ++it) {
		suma += *it;
	}
	cout << suma << endl;
	return 0;
}


int main() {

	vector<int> v = { 1, 2, 3, 4 };
	suma_const(v);
	suma(v);
	return 0;
}
