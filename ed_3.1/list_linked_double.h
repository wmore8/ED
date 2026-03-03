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

  void zip(ListLinkedDouble& other);


private:
  Node *head;
  int num_elems;

  Node *nth_node(int n) const;
  void delete_nodes();
  void copy_nodes_from(const ListLinkedDouble &other);
};

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

#endif
