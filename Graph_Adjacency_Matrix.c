#define _CRT_SECURE_NO_WARNINGS
#define INT_MIN -2147483648
#include<stdio.h>
#include<stdlib.h>
void make_graph(int **p, int w, int a, int b) {
	p[a][b] = w;
	if (a != b) {
		p[b][a] = w;
	}
	else {
		return;
	}
}
void print_graph(int **p, int a) {
	for (int i = 0; i < 6; i++) {
		if (p[a][i] != INT_MIN) {
			printf(" %d %d", i + 1, p[a][i]);
		}
	}
	printf("\n");
}
void remove_graph(int **p,int a,int b) {
	p[a][b] = INT_MIN;
	if (a != b) {
		p[b][a] = INT_MIN;
	}
	else {
		return;
	}
}
int main() {
	int **p = NULL;
	char ch;
	int a, b, w, n;
	p = (int **)malloc(sizeof(int *) * 6);
	for (int i = 0; i < 6; i++) {
		p[i] = (int *)malloc(sizeof(int) * 6);
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			p[i][j] = INT_MIN;
		}
	}
	make_graph(p, 1, 0, 1);
	make_graph(p, 1, 0, 2);
	make_graph(p, 1, 0, 3);
	make_graph(p, 2, 0, 5);
	make_graph(p, 1, 1, 2);
	make_graph(p, 4, 2, 4);
	make_graph(p, 4, 4, 4);
	make_graph(p, 3, 4, 5);
	while (1) {
		scanf("%c", &ch);
		if (ch == 'q') {
			break;
		}
		if (ch == 'a') {
			scanf("%d", &n);
			if (n > 6 || n < 0) {
				printf("-1\n");
			}
			else {
				print_graph(p, n - 1);
			}
		}
		if (ch == 'm') {
			scanf("%d %d %d", &a, &b, &w);
			if (a > 6 || b > 6 || a < 1 || b < 1) {
				printf("-1\n");
			}
			else {
				if (w == 0) {
					remove_graph(p, a - 1, b - 1);
				}
				else {
					make_graph(p, w, a - 1, b - 1);
				}
			}
		}
		getchar();
	}
}
