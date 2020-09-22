#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void downHeap(int *p, int n, int i) {
	int r = (2 * i) + 1, l = 2 * i;
	if (r > n && l > n) {
		return;
	}
	int max = i;
	if (r <= n) {
		if (p[r] > p[max]) {
			max = r;
		}
	}
	if (p[l] > p[max]) {
		max = l;
	}
	if (max != i) {
		swap(p + max, p + i);
		downHeap(p, n, max);
	}
}
void buildHeap(int *p, int n) {
	for (int i = n / 2; i > 0; i--) {
		downHeap(p, n, i);
	}
}
void deleteHeap(int *p, int n) {
	int tmp;
	for (int i = 0; i < n; i++) {
		tmp = p[1];
		p[1] = p[n - i];
		p[n - i] = tmp;
		downHeap(p, n - i - 1, 1);
	}
}
void print_arr(int *p, int n) {
	for (int i = 1; i <= n; i++) {
		printf(" %d", p[i]);
	}
	printf("\n");
}
int main() {
	srand(time(NULL));
	int n, *p = NULL;
	scanf("%d", &n);
	p = (int *)malloc(sizeof(int)*(n + 1));
	for (int i = 1; i <= n; i++) {
		p[i] = rand() % 200 + 1;
	}
	print_arr(p, n);
	buildHeap(p, n);
	print_arr(p, n);
	deleteHeap(p, n);
	print_arr(p, n);
}
