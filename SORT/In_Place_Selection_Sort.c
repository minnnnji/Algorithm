#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void print_arr(int *p, int n) {
	printf("-------------------------\n");
	for (int i = 0; i < n; i++) {
		printf(" %d", p[i]);
	}
	printf("\n");
}
void selection_sort(int *p, int n) {
	int min;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (p[min] > p[j]) {
				min = j;
			}
		}
		swap(p + min, p + i);
		print_arr(p, n);
	}
}
int main() {
	srand(time(NULL));
	int n, *p = NULL;
	scanf("%d", &n);
	p = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		p[i] = rand() % 50 + 1;
	}
	print_arr(p, n);
	selection_sort(p, n);
	printf("-----------final----------\n");
	print_arr(p, n);
}
