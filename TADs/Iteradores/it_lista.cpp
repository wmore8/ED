/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Sonia Estévez Martín
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */


#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>
using namespace std;

int suma_todos(const list<int>& lista) {
	int suma = 0;
	for (auto it = lista.cbegin(); it != lista.cend(); ++it) {
		suma += *it;
	}
	return suma;
}

void display(const list<int>& lista) {

	std::cout << "{ ";
	auto it = lista.cbegin();  //iterador apunta al primer elemento
	std::cout << *it;  // se muestra el primer elemento
	++it;              // avanza el iterador al siguiente elemento
	while (it != lista.cend()) {
		std::cout << ", " << *it;
		++it;
	}
	std::cout << "} ";
}


int main() {

	list<int> l = { 1, 2, 3, 4 };

	cout << "La suma de los elementos de l = ";
	display(l);
	cout << "es " << suma_todos(l) << endl; ;

	l.push_front(6);
	l.push_back(7);

	cout << "l = ";
	display(l);


	auto it = l.begin();
	it++;
	it = l.erase(it);
	it++;
	l.insert(it, 777);
	display(l);



	// find - Busca un elemento.
	it = find(l.begin(), l.end(), 30);

	if (it != l.end())
		cout << "Encontrado \n";
	else
		cout << "No encontrado \n";

	// count - Cuenta cuántas veces aparece un valor.

	cout << count(l.begin(), l.end(), 5) << endl;
	l.push_back(4);
	cout << count(l.begin(), l.end(), 4) << endl;

	// accumulate - Suma todos los elementos.
	// #include <numeric>

	cout << accumulate(l.begin(), l.end(), 0) << endl;


	// reverse
	reverse(l.begin(), l.end());

	display(l);



	cout << "Funciones típicas con iteradores que tienen en la condición es una func lambda que devuelve true o false";


	list<int> l1 = { 1, 2, 3, 4 };
	list<int> l2 = { 1, -2, 3, -4 };
	list<int> l3 = { -1, -2, -3, -4 };


	// for_each
	cout << "\nfor_each: ";
	for_each(l1.begin(), l1.end(), [](int x) {
		cout << x << " "; }
	); // for_each
	cout << endl;


	// any_of
	// ¿Existe al menos un elemento que cumpla la condición?

	bool hay_positivos1 = any_of(l1.begin(), l1.end(), [](int x) {
		return x > 0; }
	); // any_of
	bool hay_positivos2 = any_of(l2.begin(), l2.end(), [](int x) {
		return x > 0; }
	); // any_of
	bool hay_positivos3 = any_of(l3.begin(), l3.end(), [](int x) {
		return x > 0; }
	); // any_of

	cout << "any_of: " << boolalpha << hay_positivos1 << " - " << hay_positivos2 << " - " << hay_positivos3 << endl;



	// all_of  ¿Todos cumplen la condición?
	bool todosPositivos1 = all_of(l1.begin(), l1.end(), [](int x) {
		return x > 0; }
	);

	bool todosPositivos2 = all_of(l2.begin(), l2.end(), [](int x) {
		return x > 0; }
	);

	bool todosPositivos3 = all_of(l3.begin(), l3.end(), [](int x) {
		return x > 0; }
	);

	cout << "all_of: " << boolalpha << todosPositivos1 << " - " << todosPositivos2 << " - " << todosPositivos3 << endl;




	// none_of   ¿Ninguno cumple la condición?
	bool ningunoPositivo1 = none_of(l1.begin(), l1.end(), [](int x) {
		return x > 0; }
	);

	bool ningunoPositivo2 = none_of(l2.begin(), l2.end(), [](int x) {
		return x > 0; }
	);

	bool ningunoPositivo3 = none_of(l3.begin(), l3.end(), [](int x) {
		return x > 0; }
	);

	cout << "none_of: " << boolalpha << ningunoPositivo1 << " - " << ningunoPositivo2 << " - " << ningunoPositivo3 << endl;

}


