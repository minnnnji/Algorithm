#define _CRT_SECURE_NO_WARNINGS
#define MAX 30000
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	struct node *next;
	int u, v;
	int weight;
}node;
node *getnode() {
	node *p = NULL;
	p = (node*)malloc(sizeof(node));
	p->next = NULL;
	return p;
}
void makegraph(int u, int v, int w, node *p) {
	node *newnode = getnode();
	node *tmp = p;
	newnode->u = u;
	newnode->v = v;
	newnode->weight = w;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = newnode;
}
void print_edge(node *p) {
	node *tmp = p->next;
	while (tmp != NULL) {
		printf(" %d %d %d\n", tmp->u, tmp->v, tmp->weight);
		tmp = tmp->next;
	}
	printf("\n");
}
void bellmanFord(node *p, int n, int m,int s) {
	int *dest = NULL;
	node *tmp = p->next;
	dest = (int *)malloc(sizeof(int)*(n + 1));
	for (int i = 0; i <= n; i++) {
		dest[i] = MAX;
	}
	dest[s] = 0;
	for (int i = 0; i < n; i++) {
		tmp = p->next;
		for (int j = 0; j < m; j++) {
			if (dest[tmp->u] == MAX) {
				tmp = tmp->next;
			}
			else {
				if (dest[(tmp->v)] > (dest[(tmp->u)] + (tmp->weight))) {
					dest[(tmp->v)] = dest[(tmp->u)] + (tmp->weight);
				}
				tmp = tmp->next;
			}
		}
	}
	tmp = p->next;
	for (int i = 1; i <= n; i++) {
		if (i != s&&dest[i]!=MAX) {
			printf("%d %d\n", i, dest[i]);
		}
	}
}
int main() {
	int n, m, s, u, v, weight;
	node *p = getnode();
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &weight);
		makegraph(u, v, weight, p);
	}
	bellmanFord(p, n, m, s);
}
/*
4 5 1
1 2 1
2 3 -2
3 1 2
3 4 1
1 4 5

5 7 1
1 2 1
1 4 5
5 1 -2
3 5 3
3 4 1
1 3 2
3 2 -3

5 7 1 
2 4 -3 
5 4 8 
3 4 4 
3 2 12 
2 3 -3 
3 1 7 
1 4 3
*/
