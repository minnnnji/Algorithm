#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>;
void swap(int *a, int*b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}// 자리 바꾸기 함수
void inPlaceSelectSort(int *p, int n) {
	int max;
	for (int i = n - 1; i >= 0; i--) {
		max = i;// 뒤에서 부터 max
		for (int j = i - 1; j >= 0; j--) {
			if (p[j] > p[max]) {
				max = j;
			}// 더 큰 값의 max 정해주기
		}
		swap(p + max, p + i);//swap 하기
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
	}// 난수로 확인해보기 위해
  
	print_Array(p, n);// 정렬 전
  
	inPlaceSelectSort(p, n);// 정렬중 
  
	print_Array(p, n);// 정렬 후
	free(p);// 메모리 해제
}
