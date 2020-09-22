#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int elem;
	int weight;
	struct node *next;
}node;
typedef struct graph {
	node *arr;//인접 리스트 
	int elem;//vertic
}graph;
node *getnode() {
	node *new_node = NULL;
	new_node = (node *)malloc(sizeof(node));
	new_node->next = NULL;
	new_node->elem = 0;
	new_node->weight = 0;
	return new_node;
}
void make_graph(graph *g, graph *dest,int w) {
	node *tmp = g->arr->next, *tmp_prev = g->arr;
	node *new_node = getnode();
	new_node->elem = dest->elem;
	new_node->weight = w;
	while (tmp != NULL && tmp->elem < dest->elem) {
		tmp = tmp->next;
		tmp_prev = tmp_prev->next;
	}
	tmp_prev->next = new_node;
	new_node->next = tmp;
}
void print_graph(graph *g) {
	node *tmp;
	tmp = g->arr->next;
	while (tmp != NULL) {
		printf(" %d %d", tmp->elem,tmp->weight);
		tmp = tmp->next;
	}
	printf("\n");
}
void remove_edge(graph *a, graph *b, int *n) {
	node *tmp = a->arr->next, *tmp_prev = a->arr;
	int cnt=0;
	if ((*n) == 2) {
		return;
	}
	else {
		while (tmp->elem != b->elem) {
			tmp = tmp->next;
			cnt++;
		}
		while (cnt > 0) {
			tmp_prev = tmp_prev->next;
			cnt--;
		}
		tmp_prev->next = tmp->next;
		free(tmp);
		(*n)++;
		if (a != b) {
			remove_edge(b, a, n);
		}
		else {
			return;
		}
	}
}
int check_num(graph *a, graph *b) {
	node *tmp;
	int flag = 0;
	tmp = a->arr;
	while(tmp != NULL) {
		if (tmp->elem == b->elem) {
			flag = 1;
			break;
		}
		tmp = tmp->next;
	}
	return flag;
}
void change_weight(graph *a, graph *b, int w) {
	node *tmp = a->arr;
	while (tmp->elem != b->elem) {
		tmp = tmp->next;
	}
	tmp->weight = w;
	tmp = b->arr;
	while (tmp->elem != a->elem) {
		tmp = tmp->next;
	}
	tmp->weight = w;
}
int main() {
	graph *g = NULL;
	char ch;
	int n, a, b, w, k;
	g = (graph *)malloc(sizeof(graph) * 6);
	for (int i = 0; i < 6; i++) {
		g[i].elem = i + 1;
		g[i].arr = getnode();
	}
	make_graph(g, g + 1, 1);
	make_graph(g, g + 2, 1);
	make_graph(g, g + 3, 1);
	make_graph(g, g + 5, 2);
	make_graph(g + 1, g, 1);//5
	make_graph(g + 1, g + 2, 1);
	make_graph(g + 2, g, 1);
	make_graph(g + 2, g + 1, 1);
	make_graph(g + 2, g + 4, 4);
	make_graph(g + 3, g, 1);//10
	make_graph(g + 4, g + 2, 4);
	make_graph(g + 4, g + 4, 4);
	make_graph(g + 4, g + 5, 3);
	make_graph(g + 5, g, 2);
	make_graph(g + 5, g + 4, 3);//15*/
	while (1) {
		scanf("%c", &ch);
		if (ch == 'q') {
			break;
		}
		if (ch == 'a') {
			scanf("%d", &n);
			if (n > 6 || n < 0 ) {
				printf("-1\n");
			}
			else {
				print_graph(g + (n - 1));
			}
		}
		if (ch == 'm') {
			scanf("%d %d %d", &a, &b, &w);
			if (a > 6 || b > 6 || a < 1 || b < 1 ) {
				printf("-1\n");
			}
			else {
				if (w == 0) {
					remove_edge(&g[a - 1], &g[b - 1], &w);
				}
				else {
					k = check_num(&g[a - 1], &g[b - 1]);
					if (k == 1) {// 있으면 가중치 바꾸기
						change_weight(&g[a - 1], &g[b - 1], w);
					}
					else {//없으면 가중치 간선 만들기
						if (a != b) {
							make_graph(&g[a - 1], &g[b - 1], w);
							make_graph(&g[b - 1], &g[a - 1], w);
						}
						else {
							make_graph(&g[a - 1], &g[b - 1], w);
						}
					}
				}
			}
		}
		getchar();
	}
}
