#pragma once
#include <iostream>

template <class T>
class List
{
public:
	template<class T2>
	class Node
	{
	private:
		T2* data;
	public:
		Node<T2>* next;
		Node<T2>* prev;
		Node() {
			data = NULL;
			next = NULL;
			prev = NULL;
		}
		~Node() {
			data = NULL;
			next = NULL;
			prev = NULL;
		}
		void setData(T2* data) {
			this->data = data;
		}
		void setNext(Node<T2>* n) {
			next = n;
		}
		void setPrev(Node<T2>* p) {
			prev = p;
		}
		T2* getData() {
			return data;
		}
	};
	List() {
		head = NULL;
		tail = NULL;
	}
	~List() {
		Node<T>* a1 = head;
		Node<T>* a2 = a1;

		while (a1 != NULL) {
			a2 = a1->next;
			delete a1;
			a1 = a2;
		}
	}
	void setData(T* data) {
		if (data == NULL) {
			std::cout << "Valor Inválido" << std::endl;
			return;
		}
		Node<T>* aux = new Node<T>;
		aux->setData(data);
		if (head == NULL) {
			head = aux;
			tail = aux;
		}
		else {
			tail->next = aux;
			aux->prev = tail;
			tail = aux;
		}
	}
	T* operator[](int pos) {
		Node<T>* aux = head;
		for (int i = 0; i <= pos; i++) {
			if (aux == NULL) {
				std::cout << "acesso de posição não definida" << std::endl;
				return NULL;
			}
			aux = aux->next;
		}
		return aux->getData();
	}
	int getSize() {
		Node<T>* aux = head;
		int i = 0;
		while (aux != NULL) {
			aux = aux->next;
			i++;
		}
		return i;
	}
protected:
	Node<T>* head;
	Node<T>* tail;
};

