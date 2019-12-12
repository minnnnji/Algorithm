#define _CRT_SECURE_NO_WARNINGS
#define INF 1000
#include<stdio.h>
#include<stdlib.h>
typedef struct vertic {
	int elem;
	int set_num;
}vertic;
typedef struct node {
	struct node *next;
	vertic *from, *to;
	int weight;
}node;
node *getnode() {
	node *p = NULL;
	p = (node *)malloc(sizeof(node));
	p->from = NULL;
	p->to = NULL;
	p->next = NULL;
	return p;
}
void change_setnum(vertic **v, int k, int ori,int n) {
	for (int i = 0; i < n; i++) {
		if (v[i]->set_num == ori) {
			v[i]->set_num = k;
		}
	}
}
void Kruckal(node *p,int n,vertic **v) {
	node *tmp = p->next;
	node **rmp = NULL;
	int i = 0;
	rmp = (node **)malloc(sizeof(node)*n);
	while (tmp != NULL) {
		if (tmp->from->set_num != tmp->to->set_num) {
			if (tmp->from->set_num < tmp->to->set_num) {
				change_setnum(v, tmp->from->set_num, tmp->to->set_num, n + 1);
				rmp[i] = tmp;
				i++;
			}
			else {
				change_setnum(v, tmp->to->set_num, tmp->from->set_num, n + 1);
				rmp[i] = tmp;
				i++;
			}
		}
		tmp = tmp->next;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		printf(" %d", rmp[i]->weight);
		sum += rmp[i]->weight;
	}
	printf("\n%d", sum);
}
void make_graph(node *p, vertic *from, vertic *to, int w, int *cnt) {
	node *new_E = getnode();
	new_E->from = from;
	new_E->to = to;
	new_E->weight = w;
	node *tmp = p->next, *tmp_prev = p;
	while (tmp != NULL&&tmp->weight < w) {
		tmp_prev = tmp_prev->next;
		tmp = tmp->next;
	}
	tmp_prev->next = new_E;
	new_E->next = tmp;
}
void print_node(node *p) {
	node *tmp = p->next;
	while (tmp != NULL) {
		printf("from %d to %d w %d \nset_n_f %d set_n_t %d \n\n", tmp->from->elem, tmp->to->elem, tmp->weight,tmp->from->set_num,tmp->to->set_num);
		tmp = tmp->next;
	}
}
int main() {
	int n, m, from, to, weight, cnt = 1;
	vertic **num = NULL;
	node *Tree = getnode();//tree header
	scanf("%d %d", &n, &m);//n - vertics m - edges
	num = (vertic **)malloc(sizeof(vertic *)*n);
	for (int i = 0; i < n; i++) {
		num[i] = (vertic *)malloc(sizeof(vertic));
		num[i]->set_num = 0;
		num[i]->elem = i + 1;//vertic 함수
		num[i]->set_num = i + 1;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &weight);
		make_graph(Tree, num[from-1], num[to-1], weight, &cnt);
	}
	Kruckal(Tree, n - 1, num);
}
