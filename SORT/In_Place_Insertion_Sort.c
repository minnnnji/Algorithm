#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*void swap(int *a,int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}*/
void InPlaceInsertionSort(int *p, int n) {
	int tmp,i,j;
	for (i = 1; i < n; i++) {
		tmp = p[i];
		j = i - 1;
		while (j >= 0&&tmp<p[j]) {
			p[j + 1] = p[j];
			j--;
		}
		p[j + 1] = tmp;
	}
}
void travel(int *p, int n) {
	for (int i = 0; i < n; i++) {
		printf(" %d", p[i]);
	}
	printf("\n\n");
}
int main() {
	srand(time(NULL));
	int n, *p = NULL;
	scanf("%d", &n);
	p = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		p[i] = rand() % 10; //0 ~ 10까지의 수

	}
	printf("----------정렬전----------\n\n");
	travel(p, n);
	InPlaceInsertionSort(p, n);
	printf("----------정렬후----------\n\n");
	travel(p, n);
}
