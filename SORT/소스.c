#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"heap.h"
#include"basic.h"//swap, print, node의 정보 저장 헤더
void build_heap(int *p, int n) {
	for (int i = n / 2; i >= 1; i--) {
		down_heap(p, n, i);
	}
}
void heap_sort(int *p, int n) {
	int tmp = p[1];
	p[1] = p[n];
	p[n] = tmp;
	down_heap(p, n - 1, 1);
}
int main() {
	srand(time(NULL));
	int n, *p = NULL;
	scanf("%d", &n);
	p = (int *)malloc(sizeof(int)*(n + 1));
	for (int i = 1; i <= n; i++) {
		p[i] = rand() % 100;
	}
	printf("--------정렬전--------\n\n");
	travel_arr(p, n);
	build_heap(p, n);
	printf("--------max heap 만들기--------\n\n");
	travel_arr(p, n);

	printf("--------정렬후--------\n\n");
	for (int i = 0; i < n; i++) {
		heap_sort(p, n - i);
	}

	travel_arr(p, n);
}