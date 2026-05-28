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

  void desparizar(ListLinkedDouble& aux);

private:
  Node *head;
  int num_elems;

  Node *nth_node(int n) const;
  void delete_nodes();
  void copy_nodes_from(const ListLinkedDouble &other);
};

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

//Coste O(N) lineal en funcion del numero de elementos de las lista principal
template <typename Elem>
void ListLinkedDouble<Elem>::desparizar(ListLinkedDouble& aux) {
    Node* current_this = head->next;
    Node* current_other = aux.head->prev;

    while (current_this != head) {
        Node* next_this = current_this->next;
        Node* next_other = current_other->next;
        // si el elemento es par
        if (current_this->value % 2 == 0) { 

            //separamos el nodo par actual de la primera lista
            current_this->prev->next = next_this;
            next_this->prev = current_this->prev;
            this->num_elems--;

            //unimos el nodo al final de la lista auxiliar
            current_this->next = next_other;
            current_this->prev = current_other;
            //actualizamos referencias de la lista auxiliar al nuevo nodo
            current_other->next = current_this;
            next_other->prev = current_this;
            aux.num_elems++;
            //seguimos avanzando en la lista
            current_other = current_this;
        }

        current_this = next_this;
    }
}

#endif
