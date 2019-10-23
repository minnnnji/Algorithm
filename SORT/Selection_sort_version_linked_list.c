#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
void print_node(node *p) {
	node *tmp = p;
	printf("------------------\n");
	while (tmp != NULL) {
		printf(" %d", tmp->elem);
		tmp = tmp->next;
	}
	printf("\n");
}
void insert_node(node **h, int k) {
	node *p = getnode();
	p->elem = k;
	if (*h == NULL) {
		*h = p;
	}
	else {
		node *tmp = (*h);
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = p;
	}
}
void swap(node *a, node *b) {
	int tmp;
	tmp = a->elem;
	a->elem = b->elem;
	b->elem = tmp;
}
void selection_sort(node *h,int n) {
	node *tmp = h, *tmp_2, *tmp_3;
	for (int i = 0; i < n; i++) {
		tmp = h;
		for (int j = 0; j < i; j++) {
			tmp = tmp->next;
		}
		tmp_3 = tmp;
		tmp_2 = tmp->next;
		for (int j = i + 1; j < n; j++) {
			if (tmp->elem > tmp_2->elem) {
				tmp = tmp_2;
			}
			tmp_2 = tmp_2->next;
		}
		swap(tmp, tmp_3);
		print_node(h);
	}
}
int main() {
	srand(time(NULL));
	int n, key;
	scanf("%d", &n);
	node *p = NULL;
	for (int i = 0; i < n; i++) {
		key = rand() % 50 + 1;
		insert_node(&p, key);
	}
	print_node(p);
	selection_sort(p, n);
	print_node(p);
}
