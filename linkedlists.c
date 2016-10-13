#include <stdio.h>

struct node {
	int val;
	struct node *next;
};

struct node insertb(int val, struct node *head){
	struct node *prev;
	prev = malloc(sizeof(struct node));
	prev -> val = val;
	prev -> next = head;
	head = prev;
	return *head;
}

void insertmiddle(int n, int val, struct node *head){
	struct node *prev, *cur, *hola;
	int i;
	while ((cur != NULL) && (i < n)){
		cur = malloc(sizeof(struct node));
		prev = malloc(sizeof(struct node));
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

void crearlist(int n){
	struct node *head, *prev, *cur;
	int i;
	head = malloc(sizeof(struct node));
	head -> val = 1;
	prev = head;
	for (i=2; i<=n; i++){
		cur = malloc(sizeof(struct node));
		prev = malloc(sizeof(struct node));
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
main() {
	
	struct node *head, *prev, *cur, *head2;
	int i;
	head = crearlist(8);
	/*head = malloc(sizeof(struct node));
	head -> val = 1;
	prev = head;
	for (i=2; i<=6; i++){
		cur = malloc(sizeof(struct node));
		cur -> val = i;
		prev -> next = cur;
		prev = cur;
	}
	prev -> next = NULL;*/
	/*/////////////////////////////////////NUEVA LISTA///////////////////////////////////////////
	head2 = malloc(sizeof(struct node));
	head2 -> val = 7;
	prev = head2;
	for (i=8; i<=10; i++){
		cur = malloc(sizeof(struct node));
		cur -> val = i;
		prev -> next = cur;
		prev = cur;
	}
	prev -> next = NULL;
	
	insertb(8, head); */
	imprimirlist(head);
	printf("\n");
	eliminarlist(head, 3);
	imprimirlist(head);
	
	/*insertmiddle(2, 69, head);
	imprimirlist(head2);
	printf("\n");*/

	
	
