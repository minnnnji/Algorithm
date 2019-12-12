#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct edge {
	struct edge *next;
	char elem;
}node;
typedef struct vertex {
	node *inedge, *outedge;
	int indegree;
	char elem;
}vertex;
node *getnode() {
	node *p = NULL;
	p = (node *)malloc(sizeof(node));
	p->next = NULL;
	return p;
}
vertex *getvertex(char ch) {
	vertex *p = NULL;
	p = (vertex *)malloc(sizeof(vertex));
	p->inedge = getnode();
	p->outedge = getnode();
	p->indegree = 0;
	p->elem = ch;
	return p;
}
int find_index(char ch, vertex **p,int n) {
	for (int i = 0; i < n; i++) {
		if (p[i]->elem == ch) {
			return i;
		}
	}
}
void make_graph(vertex *from, vertex *to) {
	node *tmp = from->outedge->next;
	node *a = getnode();
	a->elem = to->elem;
	a->next = tmp;
	from->outedge->next = a;
	// from out 처리
	tmp = to->inedge->next;
	node *b = getnode();
	b->elem = from->elem;
	b->next = tmp;
	to->inedge->next = b;
	to->indegree++;
}
void print_graph(vertex *p) {
	node *tmp = p->inedge->next;
	node *out = p->outedge->next;
	printf("%c\n in", p->elem);
	while (tmp != NULL) {
		printf(" %c", tmp->elem);
		tmp = tmp->next;
	}
	printf("\nout");
	while (out != NULL) {
		printf(" %c", out->elem);
		out = out->next;
	}
	printf("\n");
}
int topological_sort(vertex **p, int n) {
	int *in = NULL;
	int *index = NULL;// indegree가 0인 index 저장
	int cnt = 0, front = 0;
	int flag = 0;// 사이클 존재여부
	in = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		in[i] = p[i]->indegree;
	}
	int u;
	index = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		if (in[i] == 0) {
			index[cnt++] = i;
		}
	}
	int k;
	while (front < cnt) {
		u = index[front++];//첫번째꺼 빼기
		for (node *e = p[u]->outedge->next; e != NULL; e = e->next) {
			k = find_index(e->elem, p, n);
			p[k]->indegree--;
			if (p[k]->indegree == 0) {
				index[cnt++] = k;
			}
		}
	}
	if (front < n) {
		printf("0\n");
	}
	else {
		for (int i = 0; i < cnt; i++) {
			printf("%c ", p[index[i]]->elem);
		}
		printf("\n");
	}

}
int main() {
	int n, m, from_index, to_index;
	char ch, from, to;
	vertex **p = NULL;
	scanf("%d\n",&n);
	p = (vertex **)malloc(sizeof(vertex *)*n);
	for (int i = 0; i < n; i++) {
		scanf("%c", &ch);
		p[i] = getvertex(ch);
		getchar();
	}
	scanf("%d\n", &m);
	for (int i = 0; i < m; i++) {
		scanf("%c %c", &from, &to);
		from_index = find_index(from, p, n);
		to_index = find_index(to, p, n);
		make_graph(p[from_index], p[to_index]);
		getchar();
	}
	topological_sort(p, n);
}
