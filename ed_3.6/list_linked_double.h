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
 * Implementación del TAD Lista mediante listas doblemente enlazadas circulares.
 *
 * Esta versión introduce genericidad mediante plantillas.
 */

#ifndef __LIST_LINKED_DOUBLE_H
#define __LIST_LINKED_DOUBLE_H

#include <cassert>
#include <iostream>

template <typename Elem> class ListLinkedDouble {
private:
  struct Node {
    Elem value;
    Node *next;
    Node *prev;
  };

public:
  ListLinkedDouble() : num_elems(0) {
    head = new Node;
    head->next = head;
    head->prev = head;
  }

  ListLinkedDouble(const ListLinkedDouble &other) : ListLinkedDouble() {
    copy_nodes_from(other);
    num_elems = other.num_elems;
  }

  ~ListLinkedDouble() { delete_nodes(); }

  void push_front(const Elem &elem) {
    Node *new_node = new Node{elem, head->next, head};
    head->next->prev = new_node;
    head->next = new_node;
    num_elems++;
  }

  void push_back(const Elem &elem) {
    Node *new_node = new Node{elem, head, head->prev};
    head->prev->next = new_node;
    head->prev = new_node;
    num_elems++;
  }

  void pop_front() {
    assert(num_elems > 0);
    Node *target = head->next;
    head->next = target->next;
    target->next->prev = head;
    delete target;
    num_elems--;
  }

  void pop_back() {
    assert(num_elems > 0);
    Node *target = head->prev;
    target->prev->next = head;
    head->prev = target->prev;
    delete target;
    num_elems--;
  }

  int size() const { return num_elems; }

  bool empty() const { return num_elems == 0; };

  const Elem &front() const {
    assert(num_elems > 0);
    return head->next->value;
  }

  Elem &front() {
    assert(num_elems > 0);
    return head->next->value;
  }

  const Elem &back() const {
    assert(num_elems > 0);
    return head->prev->value;
  }

  Elem &back() {
    assert(num_elems > 0);
    return head->prev->value;
  }

  const Elem &operator[](int index) const {
    assert(0 <= index && index < num_elems);
    Node *result_node = nth_node(index);
    return result_node->value;
  }

  Elem &operator[](int index) {
    assert(0 <= index && index < num_elems);
    Node *result_node = nth_node(index);
    return result_node->value;
  }

  ListLinkedDouble &operator=(const ListLinkedDouble &other) {
    if (this != &other) {
      delete_nodes();
      head = new Node;
      head->next = head->prev = head;
      copy_nodes_from(other);
      num_elems = other.num_elems;
    }
    return *this;
  }

  void display(std::ostream &out) const;

  void display() const { display(std::cout); }

  void display_reverse(std::ostream& out) const;

  void display_reverse() const { display_reverse(std::cout); }

  void zip(ListLinkedDouble& other);

  void unzip(ListLinkedDouble& other);

  void partition(int pivot);
  
  void sort_and_dedup();

  void swap2by2();

  void add_to(int index, int m);

private:
  Node *head;
  int num_elems;

  Node *nth_node(int n) const;
  void delete_nodes();
  void copy_nodes_from(const ListLinkedDouble &other);
  static void detach(Node* node);
  static void attach(Node* node, Node* before);
  //void attach(Node* node, Node* position); //position es after
  Node* minimum(Node* start, Node* end) const;
};

template <typename Elem>
void ListLinkedDouble<Elem>::swap2by2() {
    Node* first = head->next;
    Node* second = first->next;

    while (first != head && second != head) {//mientras ninguno de los 2 lleguen al nodo fantasma
        
        Node* next_first = second->next;//guardamos los siguientes nodos antes de cmambiar los actuales
        Node* next_second = next_first->next;

        first->next = second->next; //El siguiente del primero sera el siguiente del segundo
        second->prev = first->prev; //El anterior del segundo sera el anterior del primero

        first->prev->next = second; //El siguiente del anterior del primero, es el segundo
        first->prev = second;       //El anterior del primero sera el segundo
        
        second->next->prev = first; //El anterior del siguiente del segundo, es el primero
        second->next = first;       //El siguiente del segundo sera el primero

        //avanzamos
        first = next_first;
        second = next_second;
    }

}

/*
template <typename Elem>
void ListLinkedDouble<Elem>::detach(Node* node) { //Coste O(1): solo modificamos 2 punteros de los nodos adyacentes
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

template <typename Elem>
void ListLinkedDouble<Elem>::attach(Node* node, Node* position) {//Coste O(1): solo modificamos 4 punteros de los nodos adyacentes
    // Insertamos 'node' ANTES de 'position'
    node->prev = position->prev;
    node->next = position;

    position->prev->next = node;
    position->prev = node;
}
*/

// Coste: O(1) -> Desenganchamos el nodo actual cambiando los punteros de los nodos vecinos.
template <typename Elem>
void ListLinkedDouble<Elem>::detach(Node* node) { 
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

// Coste: O(1) -> Enganchamos el nodo actual cambiando los punteros de los nodos vecinos a before.
template <typename Elem>
void ListLinkedDouble<Elem>::attach(Node* node, Node* before) {
    node->prev = before->prev;
    node->next = before;

    before->prev->next = node;
    before->prev = node;
}

template <typename Elem>
void ListLinkedDouble<Elem>:: add_to(int index, int m) {
    Node* sumar = nth_node(index);
    sumar->value += m;
    detach(sumar); //desenganchamos el nodo sumado
    bool encontrado = false;
    Node* current = head->next; //empezamos a iterar desde el primero

    //buscamos el primer nodo mayor al nodo sumado (para colocarlo antes)
    while (current != head && !encontrado) {
        if (current->value > sumar->value) {
            encontrado = true;
            attach(sumar, current);
        }
        
        current = current->next;
    }

    if (!encontrado) {
        attach(sumar, head);
        encontrado = true;
    }

}

//Coste O(K): siendo K el tamaño del intervalo entre stard y end. En el caso peor K es igual a N -> N es el numero de elementos
template <typename Elem>
typename ListLinkedDouble<Elem>::Node* ListLinkedDouble<Elem>::minimum(Node* start, Node* end) const {
    Node* current = start;
    Node* min_node = start;

    while (current != end) {
        if (current->value < min_node->value) {
            min_node = current;
        }

        current = current->next;
    }
    return min_node;
}

/*
Coste O(N ^ 2) : Necesitamos recorrer todos los elementos de la lista para evitar duplicados O(N), y a su vez usamos la funcion minimum para encontrar 
al menor elemento en cada iteracion, lo cual ya supone un coste lineal O(N) -> O(N*N) = O(N^2).
*/
template <typename Elem>
void ListLinkedDouble<Elem>::sort_and_dedup() {
    Node* current = head->next;

    while (current != head) {
        //buscamos el minimo
        Node* min = minimum(current, head);

        //si el elemento ya ha sido ordenado entonces esta duplicado
        if (current->prev != head && current->prev->value == min->value) {
            if (min == current) {
                current = current->next;
            }
            detach(min);
            delete min;
            num_elems--;
        }
        else {
            if (min != current) {// si el nodo actual no es igual al minimo, entonces lo colocamos antes del actual
                detach(min);
                attach(min, current);
            }
            else { //el nodo actual es el minimo y por lo tanto ya esta ordenado, asi que avanzamos
                current = current->next;
            }
        }
    }    
}

template <typename Elem> 
void ListLinkedDouble<Elem>::zip(ListLinkedDouble& other) {
    Node* current_this = head->next;
    Node* current_other = other.head->next;
    Node* next_this = head;
    Node* next_other = other.head;

    while (current_this != head && current_other != other.head) {
        //guardamos los siguientes de cada lista para no perderlos
        next_this = current_this->next; 
        next_other = current_other->next;
        // conexion entre el actual y el siguiente de la lista 1 : {current_this} -> [current_other] <- {next_this}
        current_this->next = current_other;
        next_this->prev = current_other;
        // conexion entre el anterior y el siguiente del actual de la lista 2 : [current_this] <- {current_other} -> [next_this]
        current_other->next = next_this;
        current_other->prev = current_this;
        //avanzamos en ambas listas con sus respectivos siguientes nodos
        current_this = next_this;
        current_other = next_other;
    }

    //Terminamos de entramar la lista 1 añadiendo los elementos faltantes en la lista 2
    if (current_other != other.head) {
        Node* ultimo_this = head->prev;
        Node* ultimo_other = other.head->prev;

        //entramamos el ultimo de la lista 1 con el primero de la lista 2
        ultimo_this->next = current_other;
        current_other->prev = ultimo_this;
        //entramamos el ultimo de la lista 1 con el primero de la lista 2
        head->prev = ultimo_other;
        ultimo_other->next = head;
    }

    //actualizamos el numero de elementos
    num_elems += other.num_elems;

    //Dejamos la lista 2 vacia
    other.head->next = other.head;
    other.head->prev = other.head;
    other.num_elems = 0;
}

template <typename Elem>
void ListLinkedDouble<Elem>::unzip(ListLinkedDouble& other) {
    Node* current_this = head->next;
    Node* next_this = head;
    int posicion = 0;

    while (current_this != head) {
        next_this = current_this->next;
        //si la posicion es impar
        if (posicion % 2 == 1) { 
            //nos saltamos el siguiente del actual por ser impar
            current_this->next->prev = current_this->prev;
            current_this->prev->next = current_this->next;

            Node* ultimo_other = other.head->prev;

            other.head->prev = current_this; //el anterior del head es el actual
            ultimo_other->next = current_this;

            //el nodo de la posicion impar tiene como siguiente al head y como anterior al contenido actual
            current_this->next = other.head; //lo mismo que apuntar al head de other
            current_this->prev = ultimo_other;

            this->num_elems--; //quitamos elementos de la lista 1
            other.num_elems++; //añadimos elementos de la lista 2
        }
        //seguimos avanzando;
        posicion++;
        current_this = next_this; 
    }
}

template <typename Elem>
void ListLinkedDouble<Elem>::partition(int pivot) {
    Node* current = head->next;
    Node* next = head;

    for (int i = 0; i < num_elems; i++) {
        next = current->next;

        if (current->value > pivot) {
            detach(current);
            attach(current, head);
        }

        current = next;
    }
}


template <typename Elem>
typename ListLinkedDouble<Elem>::Node *
ListLinkedDouble<Elem>::nth_node(int n) const {
  int current_index = 0;
  Node *current = head->next;

  while (current_index < n && current != head) {
    current_index++;
    current = current->next;
  }

  return current;
}

template <typename Elem> void ListLinkedDouble<Elem>::delete_nodes() {
  Node *current = head->next;
  while (current != head) {
    Node *target = current;
    current = current->next;
    delete target;
  }

  delete head;
}

template <typename Elem>
void ListLinkedDouble<Elem>::copy_nodes_from(const ListLinkedDouble &other) {
  Node *current_other = other.head->next;
  Node *last = head;

  while (current_other != other.head) {
    Node *new_node = new Node{current_other->value, head, last};
    last->next = new_node;
    last = new_node;
    current_other = current_other->next;
  }
  head->prev = last;
}

template <typename Elem>
void ListLinkedDouble<Elem>::display(std::ostream &out) const {
  out << "[";
  if (head->next != head) {
    out << head->next->value;
    Node *current = head->next->next;
    while (current != head) {
      out << ", " << current->value;
      current = current->next;
    }
  }
  out << "]";
}

template <typename Elem>
std::ostream &operator<<(std::ostream &out, const ListLinkedDouble<Elem> &l) {
  l.display(out);
  return out;
}

template <typename Elem>
void ListLinkedDouble<Elem>::display_reverse(std::ostream& out) const {
    out << "[";

    // Si la lista no esta vacia (el anterior al fantasma no es el propio fantasma)
    if (head->prev != head) {
        // Imprimimos el ultimo elemento (que es el primero en nuestro recorrido inverso)
        out << head->prev->value;

        // Nos situamos en el penultimo
        Node* current = head->prev->prev;

        // Mientras no lleguemos al nodo fantasma, seguimos retrocediendo
        while (current != head) {
            out << ", " << current->value;
            current = current->prev; // Damos un paso hacia atras
        }
    }

    out << "]";
}

#endif
