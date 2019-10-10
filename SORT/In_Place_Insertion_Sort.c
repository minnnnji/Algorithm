#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>;
void swap(int *a, int*b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}// 자리 바꾸기 함수
void inPlaceInsertionSort(int *p, int n) {
	int tmp, j;
	for (int i = 1; i < n; i++) {
		tmp = p[i];
		j = i - 1;
		while (j >= 0 && p[j] > tmp) {
			p[j + 1] = p[j];
			j--;
		}
		p[j + 1] = tmp;
	}
}
void print_Array(int *p, int n) {
	for (int i = 0; i < n; i++) {
		printf(" %d", p[i]);
	}
	printf("\n");
}// 배열 프린트하기
int main() {
	int n, *p = NULL;
	scanf("%d", &n);
	srand(time(NULL));
	p = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		p[i] = rand() % 100 + 1;
	}
	print_Array(p, n);
	inPlaceInsertionSort(p, n);
	print_Array(p, n);
	free(p);
}
