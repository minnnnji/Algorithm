#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void print_arr(int *p, int n,int pivot) {
	printf("------------------------\n");
	for (int i = 0; i < n; i++) {
		printf(" %d", p[i]);
	}
	printf(" pivot : %d\n", pivot);
}
void partition(int *p, int l, int r, int k, int *a, int *b) {
	int pivot = p[k];
	int i, j;
	swap(p + k, p + r);
	i = l;
	j = r - 1;
	while (i <= j) {
		while (i <= j&&p[i] < pivot) {
			i++;
		}
		while (j >= i&&p[j] >= pivot) {
			j--;
		}
		if (i < j) {
			swap(p + i, p + j);
		}
	}
	*a = i;
	*a++;
	j = r - 1;
	while (i <= j) {
		while (i <= j&&p[i] == pivot) {
			i++;
		}
		while (j >= i&&p[j] > pivot) {
			j--;
		}
		if (i < j) {
			swap(p + i, p + j);
		}
	}
	swap(p + k, p + i);
	*b = i;
	*b--;
}
void quick_sort(int *p, int l, int r,int n) {
	int pivot = r,
		a = 0, b = 0;
	if (l >= r) {
		return;
	}
	partition(p, l, r, pivot, &a, &b);
	print_arr(p, n, p[r]);
	quick_sort(p, l, a - 1,n);
	quick_sort(p, b + 1, r,n);
}
int main() {
	int n, *p = NULL;
	scanf("%d", &n);
	p = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", p + i);
	}
	quick_sort(p, 0, n - 1, n);
	print_arr(p, n, 0);
}
