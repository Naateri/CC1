#include <stdio.h>

struct node {
	int val;
	struct node *next;
};

struct node * insertb(int val, struct node *head){
	struct node *prev;
	prev = malloc(sizeof(struct node));
	prev -> val = val;
	prev -> next = head;
	head = prev;
	return head;
}

void insertmiddle(int pos, int val, struct node *head){
	struct node *prev, *cur, *hola;
	int i;
	i = 1;
	cur = malloc(sizeof(struct node));
	cur = head;
	prev = head;
	while ((cur != NULL) && (i < pos)){
		cur = cur -> next;
		prev = prev -> next;
		i++;
	}
	hola = malloc(sizeof(struct node));
	hola -> val = val;
	cur = cur -> next;
	prev -> next = hola;
	hola -> next = cur;
	
}

void imprimirlist(struct node *head){
	struct node *t;
	t = head;
	while (t != NULL){
		printf("%d ", t->val);
		t = t->next;
	}
}

void crearlist(int start, int finish, struct node *head){
	struct node *prev, *cur; 
	int i;
	head -> val = start;
	prev = head;
	for (i=start+1; i<=finish; i++){
		cur = malloc(sizeof(struct node));
		cur -> val = i;
		prev -> next = cur;
		prev = cur;
	}
	prev -> next = NULL;
}

void eliminarlist(struct node *head, int key){
	struct node *prev, *cur, *temp;
	if (head-> val == key){
		temp = head;
		head = head -> next;
		free(temp);
	} else {
		prev = head;
		cur = head -> next;
		while (cur != NULL){
			if (cur -> val == key){
				prev -> next = cur -> next;
				free(cur);
				break;
			}
			prev = cur;
			cur = cur -> next;
		}
		
	}
}

void concatenarlist(struct node *head, struct node *head2){
	struct node *t;
	t = head;
	while (t->next != NULL){
		t = t->next;
	}
	t->next = head2;
	
}

void insertorden(int val, struct node *head){
	struct node *t, *cur, *prev;
	t = malloc(sizeof(struct node));
	t = head;
	prev = head;
	while ((t != NULL) && (val > t->val)){
		t = t-> next;
		prev = prev -> next;
	}
	cur = malloc(sizeof(struct node));
	t = t-> next;
	cur -> val = val;
	prev->next = cur;
	if (t -> next == NULL){
		cur -> next = NULL;
	} else {
	cur -> next = t;
	}
}

main() {
	
	struct node *head, *prev, *cur, *head2;
	int i;
	i = 8;
	head = malloc(sizeof(struct node));
	head2 = malloc(sizeof(struct node));
	crearlist(9,15, head2);
	printf("Lista enlazada de 9 a 15: \n");
	imprimirlist(head2);
	printf("\n");
	printf("Lista enlazada de 1 a 8: \n");
	crearlist(1, 8, head); 
	imprimirlist(head);
	printf("\n");
	printf("Eliminando el 3:\n");
	eliminarlist(head, 3);
	imprimirlist(head);
	printf("\nReinsertando el 3: \n");
	insertmiddle(2, 3, head);
	imprimirlist(head);
	printf("\nInsertando un 1 al comienzo(ARREGLAR): \n");
	head = insertb(1, head);
	imprimirlist(head);
	printf("\nConcatenando la primera lista con la segunda:\n");
	concatenarlist(head, head2);
	imprimirlist(head);
	printf("\nInsertando en orden (un 6): (ERROR SI SE INGRESA AL FINAL)\n");
	insertorden(6, head);
	imprimirlist(head);
	
}

