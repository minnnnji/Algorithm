#include<stdio.h>
#pragma once
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
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void travel_arr(int *p, int n) {
	for (int i = 1; i <= n; i++) {
		printf(" %d", p[i]);
	}
	printf("\n\n");
}
void travel_node(node *p) {
	node *tmp = p;
	while (tmp != NULL) {
		printf(" %d", tmp->elem);
		tmp = tmp->next;
	}
	printf("\n\n");
}
