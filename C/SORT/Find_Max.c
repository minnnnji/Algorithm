#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int MAX(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int rArrayMax(int *p, int l,int r) {
	int maxL,maxR,mid;
	if (r == l) {
		return p[l];
	}
	mid = (r + l) / 2;
	maxL = rArrayMax(p, 0, mid);
	maxR = rArrayMax(p, mid + 1, r);
	return MAX(maxL, maxR);
}
int arrayMax(int *p, int n) {
	return rArrayMax(p, 0, n - 1);
}
void print_arr(int *p, int n) {
	printf("--------------------\n");
	for (int i = 0; i < n; i++) {
		printf(" %d", p[i]);
	}
	printf("\n");
}
int main() {
	srand(time(NULL));
	int n;
	scanf("%d", &n);
	int *p = NULL;
	p = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		p[i] = rand() % 100 + 80;
	}
	print_arr(p, n);
	printf("%d", arrayMax(p, n));
}
