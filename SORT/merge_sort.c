#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	struct node *next;
	double elem;
}node;
typedef struct TMP {
	node *L1, *L2;
}TMP;
node *getnode() {
	node *p = NULL;
	p = (node *)malloc(sizeof(node));
	p->next = NULL;
	return p;
}
void insert_node(node **h, double e) {
	node *tmp = *h;
	node *new_nd = getnode();
	new_nd->elem = e;
	if (*h == NULL) {
		(*h) = new_nd;
	}
	else {
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = new_nd;
	}
}
TMP mg_partition(node *h, int k) {
	TMP result;
	node *tmp = h, *L1, *L2;

	L1 = tmp;
	for (int i = 0; i < k - 1; i++) {
		tmp = tmp->next;
	}
	L2 = tmp->next;
	tmp->next = NULL;

	result.L1 = L1;
	result.L2 = L2;

	return result;
}
node *merge(node *L1, node *L2) {
	node *result = NULL;
	if (L1 == NULL) {
		return L2;
	}
	else if (L2 == NULL) {
		return L1;
	}
	int a = L1->elem, b = L2->elem;
	if (a <= b) {
		result = L1;
		L1->next = merge(L1->next, L2);
	}
	else if(a > b) {
		result = L2;
		L2->next = merge(L1, L2->next);
	}
	return result;
}
void mergeSort(node **h, int n) {
	node *L1, *L2;
	TMP tmp;
	if (n > 1 && (*h) != NULL) {
		tmp = mg_partition(*h, n / 2);
		L1 = tmp.L1;
		L2 = tmp.L2;
		mergeSort(&L1, n / 2);
		mergeSort(&L2, n - n / 2);

		*h = merge(L1, L2);
	}
}
void print_node(node *h) {
	node *tmp = h;
	while (tmp->next != NULL) {
		printf(" %.1lf", tmp->elem);
		tmp = tmp->next;
	}
	printf(" %.1lf\n", tmp->elem);
}
int main() {
	int n;
	double key;
	node *h = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &key);
		insert_node(&h, key);
	}
	mergeSort(&h, n);
	print_node(h);
}
