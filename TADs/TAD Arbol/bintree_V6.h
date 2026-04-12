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
  * Se sustituye el recorrido en inorden recursivo por una
  * versión iterativa.
  */

#ifndef __BINTREE_H
#define __BINTREE_H

#include <cassert>
#include <iostream>
#include <iterator>
#include <memory>
#include <queue>
#include <stack>

template<class T>
class BinTree {

private:
	struct TreeNode;  // Prototipo para la definición de NodePointer.
	using NodePointer = std::shared_ptr<TreeNode>; // Alias del puntero inteligente al nodo.

public:

	// Constructoras

	// La constructora por defecto crea un árbol vacío.
	BinTree() : root_node(nullptr) {}

	// La constructora con un elemento crea un árbol con un único nodo.
	BinTree(const T& elem) : root_node(std::make_shared<TreeNode>(nullptr, elem, nullptr)) {}

	// La constructora con un elemento y dos subárboles crea un árbol con un nodo raíz
	// con el elemento dado y los subárboles dados como hijos.
	BinTree(const BinTree& left, const T& elem, const BinTree& right)
		:root_node(std::make_shared<TreeNode>(left.root_node, elem, right.root_node)) {
	}


	// empty comprueba si el árbol es vacío.
	bool empty() const {
		return root_node == nullptr;
	}

	// root devuelve el elemento del nodo raíz si el árbol es NO vacío.
	const T& root() const {
		assert(root_node != nullptr);
		return root_node->elem;
	}

	// left devuelve el subárbol izquierdo del nodo raíz si el árbol NO es vacío.
	BinTree left() const {
		assert(root_node != nullptr);
		BinTree result;
		result.root_node = root_node->left;
		return result;
	}

	// right devuelve el subárbol derecho del nodo raíz si el árbol NO es vacío.
	BinTree right() const {
		assert(root_node != nullptr);
		BinTree result;
		result.root_node = root_node->right;
		return result;
	}

	void display(std::ostream& out) const {
		display_node(root_node, out);
	}

	// preorder, inorder, postorder y levelorder reciben una función func y aplican func a los elementos del árbol
	// siguiendo el orden de recorrido indicado por el nombre de la función.

	// El recorrido en inorden se ha implementado de forma iterativa, utilizando una pila auxiliar.
	// El recorrido en nivel se ha implementado de forma iterativa, utilizando una cola auxiliar.

	template <typename U>
	void preorder(U func) const {
		preorder(root_node, func);
	}

	template <typename U>
	void inorder(U func) const {  // iterativa
		std::stack<NodePointer> st;  // Pila auxiliar 

		descend_and_push(root_node, st);

		while (!st.empty()) {
			NodePointer current = st.top();
			st.pop();

			func(current->elem);

			descend_and_push(current->right, st);
		}
	}

	template <typename U>
	void postorder(U func) const {
		postorder(root_node, func);
	}

	template <typename U>
	void levelorder(U func) const;

private:
	struct TreeNode {
		// La constructora de TreeNode recibe un elemento y dos punteros a nodos, 
		// y construye un nodo con raiz el elemento dado e hijos los punteros dados.
		TreeNode(const NodePointer& left, const T& elem, const NodePointer& right) 
			: elem(elem), left(left), right(right) {}

		T elem;  // El elemento almacenado en el nodo.
		NodePointer left, right; // Punteros a los hijos izquierdo y derecho del nodo.
	};

	NodePointer root_node;  // Puntero al nodo raíz del árbol.

	// display_node muestra un árbol de la siguiente forma:
	//   - Un árbol vacío se muestra como un punto (.).
	//   - Un árbol no vacío se muestra como una cadena de la forma (L E R), donde
	//  L es la representación del subárbol izquierdo, 
	//  E es el elemento del nodo raíz y 
	//  R es la representación del subárbol derecho.

	static void display_node(const NodePointer& root, std::ostream& out) {
		if (root == nullptr) {
			out << ".";
		}
		else {
			out << "(";
			display_node(root->left, out);
			out << " " << root->elem << " ";
			display_node(root->right, out);
			out << ")";
		}
	}


	static void descend_and_push(const NodePointer& node, std::stack<NodePointer>& st);

	template <typename U>
	static void preorder(const NodePointer& node, U func);

	template <typename U>
	static void postorder(const NodePointer& node, U func);
};


template <typename T>
void BinTree<T>::descend_and_push(const NodePointer& node, std::stack<NodePointer>& st) {
	NodePointer current = node;
	while (current != nullptr) {
		st.push(current);
		current = current->left;
	}
}


template<typename T>
template<typename U>
void BinTree<T>::preorder(const NodePointer& node, U func) {
	if (node != nullptr) {
		func(node->elem);
		preorder(node->left, func);
		preorder(node->right, func);
	}
}

template<typename T>
template<typename U>
void BinTree<T>::postorder(const NodePointer& node, U func) {
	if (node != nullptr) {
		postorder(node->left, func);
		postorder(node->right, func);
		func(node->elem);
	}
}


// La función levelorder se implementa de forma iterativa, 
// utilizando una cola auxiliar. 

template<typename T>
template<typename U>
void BinTree<T>::levelorder(U func) const {
	std::queue<NodePointer> pending;
	if (root_node != nullptr) {
		pending.push(root_node);
	}
	while (!pending.empty()) {
		NodePointer current = pending.front();
		pending.pop();
		func(current->elem);
		if (current->left != nullptr) {
			pending.push(current->left);
		}
		if (current->right != nullptr) {
			pending.push(current->right);
		}
	}
}


template<typename T>
std::ostream& operator<<(std::ostream& out, const BinTree<T>& tree) {
	tree.display(out);
	return out;
}


template<typename T>
BinTree<T> read_tree(std::istream& in) {
	char c;
	in >> c;
	if (c == '.') {
		return BinTree<T>();
	}
	else {
		assert(c == '(');
		BinTree<T> left = read_tree<T>(in);
		T elem;
		in >> elem;
		BinTree<T> right = read_tree<T>(in);
		in >> c;
		assert(c == ')');
		BinTree<T> result(left, elem, right);
		return result;
	}

}

#endif
