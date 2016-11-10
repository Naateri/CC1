#include <iostream>
using namespace std;

struct nodoN{ //linked list, circular linked list
	int n;
	struct nodoN *next;
};

struct nodoIV{ //double linked list, double circular linked list
	int n;
	struct nodoIV *prev;
	struct nodoIV *next;
};

class LinkedList{
private:
	struct nodoN *head;
	int size;
public:
	LinkedList(){
		struct nodoN *node;
		node = new nodoN;
		node = NULL;
		head = node;
		size = 0;
	};
	LinkedList(int a){
		struct nodoN *node;
		node = new nodoN;
		node->n = a;
		node->next = NULL;
		size = 1;
	};
	void insertar(int a){
		struct nodoN *prev, *cur, *node;
		int i;
		i = 1;
		node = new nodoN;
		node->n = a;
		if (head == NULL){
			head = node;
			head->next = NULL;
		} else {
		cur = head;
		prev = head;
		if (size == 1){
			cur->next = node;
			node->next = NULL;
		} else {
		while ((cur != NULL) && (cur->n < a)){
			cur = cur->next;
			prev = prev->next;
		}
		cur = cur->next;
		prev -> next = node;
		node -> next = cur;
		size++;
		}
		}
	};
};

class CircularLinkedList{
private:
	struct nodoN *head;
	int size;
public:
	CircularLinkedList(){
		struct nodoN *node;
		node = new nodoN;
		node = NULL;
		head = node;
		size = 0;
	};
	CircularLinkedList(int a){
		struct nodoN *node;
		node = new nodoN;
		node->n = a;
		node->next = head;
		size = 1;
	};
	void insertar(int a){
		struct nodoN *prev, *cur, *node;
		int i;
		i = 1;
		node = new nodoN;
		node->n = a;
		if (head == NULL){
			head = node;
			head->next = head;
		} else {
			cur = head;
			prev = head;
			while ((i<size) && (cur->n < a)){
				cur = cur->next;
				prev = prev->next;
				i++;
			}
			cur = cur->next;
			prev -> next = node;
			node -> next = cur;
			size++;
		}
	};
};

class DLinkedList{
private:
	struct nodoIV *head;
	int size;
public:
	DLinkedList(){
		head = NULL;
		size = 0;
	};
	DLinkedList(int a){
		struct nodoIV *nodo1;//, *nodo2;
		nodo1 = new nodoIV;
		nodo1->n = a;
		nodo1->next = NULL;
		nodo1->prev = NULL;
		head = nodo1;
		
	};
	void insertar(int a){
		struct nodoIV *nodo1, *prev, *cur;
		nodo1 = new nodoIV;
		nodo1->n = a;
		if (head == NULL){
			head = nodo1;
			head->next = NULL;
			head->prev = NULL;
			size++;
		} else {
			cur = head;
			prev = head;
			if (size == 1){
				cur->next = nodo1;
				nodo1->next = NULL;
				nodo1->prev = cur;
			} else {
			while ((cur != NULL) && (cur->n < a)){
				cur = cur->next;
				prev = prev->next;
			}
			cur = cur->next;
			prev -> next = nodo1;
			nodo1 -> next = cur;
			nodo1 -> prev = prev;
			size++;
			}
		}
	};
};
class CircularDLinkedList{
private:
	struct nodoIV *head;
	int size;
public:
	CircularDLinkedList(){
		head = NULL;
		size = 0;
	};
	CircularDLinkedList(int a){
		struct nodoIV *nodo1;//, *nodo2;
		nodo1 = new nodoIV;
		//nodo2 = new nodoIV;
		nodo1->n = a;
		nodo1->next = nodo1;
		nodo1->prev = nodo1;
		head = nodo1;
		
	};
	void insertar(int a){
		struct nodoIV *nodo1, *prevv, *cur;
		int i;
		i = 1;
		nodo1 = new nodoIV;
		nodo1->n = a;
		if (head == NULL){
			head = nodo1;
			head->next = head;
			head->prev = head;
		} else {
			cur = head;
			prevv = head;
			while ((i<size) && (cur->n < a)){
				cur = cur->next;
				prevv = prevv->next;
				i++;
			}
			cur = cur->next;
			prevv -> next = nodo1;
			nodo1 -> next = cur;
			nodo1 -> prev = prevv;
			size++;
	}
	}
};
int main(){
	
	LinkedList Hola(6);
	Hola.insertar(3);
	Hola.insertar(2);
	Hola.insertar(1);
	return 0;
}
