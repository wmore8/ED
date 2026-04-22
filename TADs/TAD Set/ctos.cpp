/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Sonia Estévez martín
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

 /*
  * Uso del TAD Conjunto
  *
  */


#include <iostream>
  // usamos el TAD conjunto de la STL, que es un conjunto ordenado
  // (no permite duplicados)
#include <set>
#include <unordered_set>
using namespace std;


void print_set(const set<int>& s) {
	cout << "{ ";
	// En el for, set<int>::iterator se puede sustituir por auto
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
		cout << *it << " ";
	}
	cout << "}" << endl;
}

void print_set(const unordered_set<int>& s) {
	cout << "{ ";
	// En el for, set<int>::iterator se puede sustituir por auto
	for (unordered_set<int>::iterator it = s.begin(); it != s.end(); ++it) {
		cout << *it << " ";
	}
	cout << "}" << endl;
}


void ejemplo_set() {

	// 1. Crear conjunto
	set<int> Cto_1;

	// 2. Insertar elementos
	Cto_1.insert(5);
	Cto_1.insert(3);
	Cto_1.insert(8);
	Cto_1.insert(1);
	Cto_1.insert(4);

	// Intento de duplicado (no se inserta)
	Cto_1.insert(3);

	// 3. Mostrar conjunto
	cout << "3. Cto_1: ";
	print_set(Cto_1);


	cout << "3. Cto_1: ";
	for (int x : Cto_1) {
		cout << x << " ";
	}
	cout << endl;

	// 4. Tamaño
	cout << "4. Size: " << Cto_1.size() << endl;

	// 5. Comprobar si contiene elementos
	cout << "5. Contiene 4? " << (Cto_1.contains(4) ? "SI" : "NO") << endl;
	cout << "5. Contiene 10? " << (Cto_1.contains(10) ? "SI" : "NO") << endl;

	// 6. Borrar elementos
	Cto_1.erase(3);
	cout << "6. Cto_1 tras borrar el 3: ";
	print_set(Cto_1);

	// 7. Copia (constructor de copia)
	set<int> Cto_2(Cto_1);
	cout << "7. Cto_2: ";
	print_set(Cto_2);

	// 8. Asignación
	set<int> Cto_3;
	Cto_3.insert(100);
	cout << "8. Cto_3: ";
	print_set(Cto_3);
	Cto_3 = Cto_1;
	cout << "8. Cto_3 tras asignacion: ";
	print_set(Cto_3);

	// 9. Borrar todo
	for (auto it = Cto_1.begin(); it != Cto_1.end(); ) {
		it = Cto_1.erase(it); // devuelve el siguiente iterador válido
	}

	cout << "9. Cto_1 ya vacio: ";
	print_set(Cto_1);
	cout << "9. Esta vacio? " << (Cto_1.empty() ? "SI" : "NO") << endl;
}




void ejemplo_unordered_set() {

	// 1. Crear conjunto
	unordered_set<int> Cto_1;

	// 2. Insertar elementos
	Cto_1.insert(5);
	Cto_1.insert(3);
	Cto_1.insert(8);
	Cto_1.insert(1);
	Cto_1.insert(4);

	// Intento de duplicado (no se inserta)
	Cto_1.insert(3);

	// 3. Mostrar conjunto
	cout << "3. Cto_1: ";
	print_set(Cto_1);


	cout << "3. Cto_1: ";
	for (int x : Cto_1) {
		cout << x << " ";
	}
	cout << endl;

	// 4. Tamaño
	cout << "4. Size: " << Cto_1.size() << endl;

	// 5. Comprobar si contiene elementos
	cout << "5. Contiene 4? " << (Cto_1.contains(4) ? "SI" : "NO") << endl;
	cout << "5. Contiene 10? " << (Cto_1.contains(10) ? "SI" : "NO") << endl;

	// 6. Borrar elementos
	Cto_1.erase(3);
	cout << "6. Cto_1 tras borrar el 3: ";
	print_set(Cto_1);

	// 7. Copia (constructor de copia)
	unordered_set<int> Cto_2(Cto_1);
	cout << "7. Cto_2: ";
	print_set(Cto_2);

	// 8. Asignación
	unordered_set<int> Cto_3;
	Cto_3.insert(100);
	cout << "8. Cto_3: ";
	print_set(Cto_3);
	Cto_3 = Cto_1;
	cout << "8. Cto_3 tras asignacion: ";
	print_set(Cto_3);

	// 9. Borrar todo
	for (auto it = Cto_1.begin(); it != Cto_1.end(); ) {
		it = Cto_1.erase(it); // devuelve el siguiente iterador válido
	}

	cout << "9. Cto_1 ya vacio: ";
	print_set(Cto_1);
	cout << "9. Esta vacio? " << (Cto_1.empty() ? "SI" : "NO") << endl;
}


int main() {

	ejemplo_set();
	ejemplo_unordered_set();
	return 0;
}