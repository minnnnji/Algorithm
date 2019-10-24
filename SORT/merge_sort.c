#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	struct node *next;
	int elem;
}node;
node *getnode() {
	node *p = NULL;
	p = (node *)malloc(sizeof(node));
	p->next = NULL;
	return p;
}
void insert_node(node **h, int key) {
	node *p = getnode();
	p->elem = key;
	if (*h == NULL) {
		*h = p;
	}
	else {
		node *tmp = *h;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = p;
	}
}
void travel_node(node *h) {
	node *tmp = h;
	while (tmp != NULL) {
		printf(" %d", tmp->elem);
		tmp = tmp->next;
	}
	printf("\n");
}
void partition(node *L,node **L1, node **L2, int n) {
	*L1 = L;
	node *tmp = L;
	for (int i = 0; i < n - 1; i++) {
		tmp = tmp->next;
	}
	*L2 = tmp->next;
	tmp->next = NULL;
}
node *merge(node *L1, node *L2) {
	node *tmp;
	if (L1 == NULL) {
		return L2;
	}
	else if (L2 == NULL) {
		return L1;
	}
	if (L1->elem < L2->elem) {
		tmp = L1;
		tmp->next = merge(L1->next, L2);
	}
	else {
		tmp = L2;
		tmp->next = merge(L1, L2->next);
	}
	return tmp;
}
void mergeSort(node **L,int n) {
	node *L1, *L2;
	if (n > 1 && *L != NULL) {
		partition(*L, &L1, &L2, n / 2);
		mergeSort(&L1, n / 2);
		mergeSort(&L2, n - n / 2);

		*L = merge(L1, L2);
	}
}
int main() {
	int n, key;
	node *h = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &key);
		insert_node(&h, key);
	}
	mergeSort(&h, n);
	travel_node(h);
}
