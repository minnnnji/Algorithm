#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int find_index(int *p, int r, int l) {
	srand(time(NULL));
	int a, b, c;
	a = rand() % (r - l + 1) + l;
	b = rand() % (r - l + 1) + l;
	c = rand() % (r - l + 1) + l;

	if ((p[a] >= p[b] && p[a] <= p[c]) || (p[a] >= p[c] && p[a] <= p[b])){
		return a;
	}
	else if ((p[b] >= p[a] && p[b] <= p[c]) || (p[b] >= p[c] && p[b] <= p[a])) {
		return b;
	}
	else {
		return c;
	}
}
void partition(int *p, int r, int l, int k, int *a, int *b) {
	int i, j, pivot = p[k];
	i = l;
	j = r - 1;
	swap(p + r, p + k);
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
	swap(p + i, p + r);
	*b = i;
	*b--;
}
void quick_sort(int *p, int l, int r) {
	int a , b , pivot;
	if (l >= r) {
		return;
	}
	pivot = find_index(p, r, l);
	partition(p, r, l, pivot, &a, &b);
	quick_sort(p, l, a - 1);
	quick_sort(p, b + 1, r);
}
int main() {
	int n, *p = NULL;
	scanf("%d",&n);
	p = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", p + i);
	}
	quick_sort(p, 0, n-1);
	for (int i = 0; i < n; i++) {
		printf(" %d", p[i]);
	}
	printf("\n");
}
