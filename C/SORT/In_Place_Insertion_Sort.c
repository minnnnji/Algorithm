#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void print_arr(int *p, int n,int cnt) {
	printf("-------------------------\n");
	for (int i = 0; i < n; i++) {
		printf(" %d", p[i]);
	}
	printf(" cnt = %d\n",cnt);
}
void insertion_sort(int *p, int n) {
	int j, tmp, cnt ;
	for (int i = 1; i < n; i++) {
		j = i - 1;
		tmp = p[i];
		cnt = 0;
		while (j >= 0 && tmp < p[j]) {
			p[j + 1] = p[j];
			j--;
			cnt++;
		}
		p[j + 1] = tmp;
		print_arr(p, n, cnt);
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
	print_arr(p, n, 0);
	insertion_sort(p, n);
	printf("-----------final----------\n");
	print_arr(p, n, 0);
}
