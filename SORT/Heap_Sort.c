#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void upheap(int *p, int n) {
	int i = n / 2;
	if (i < 1) {
		return;
	}
	else {
		if (p[n] > p[i]) {
			swap(p + n, p + i);
			upheap(p, i);
		}
	}
}
void insert_heap(int *p, int k, int *cnt) {
	(*cnt)++;
	p[(*cnt)] = k;
	upheap(p,*cnt);
	printf("0\n");
}
void downheap(int *p, int cnt,int index) {
	int l = 2 * index, r = (2 * index) + 1, max = index;
	if (r <= cnt) {
		if (p[l] > p[r]) {
			if (p[l] > p[index]) {
				max = l;
			}
			else {
				max = index;
			}
		}
		else {
			if (p[r] > p[index]) {
				max = r;
			}
			else {
				max = index;
			}
		}
	}
	else if (l <= cnt) {
		if (p[l] > p[index]) {
			max = l;
		}
		else {
			max = index;
		}
	}
	else {
		return;
	}
	if (max != index) {
		swap(p + max, p + index);
		downheap(p, cnt, max);
	}
}
void delete_heap(int *p,int *cnt) {
	int erase = p[1];
	swap(p + 1, p + (*cnt));
	(*cnt)--;
	downheap(p, *cnt, 1);
	printf("%d\n", erase);
}
void print_heap(int *p, int n) {
	for (int i = 1; i <= n; i++) {
		printf(" %d", p[i]);
	}
	printf("\n");
}
int main() {
	int *p = NULL, cnt = 0, key;
	char ch;
	p = (int *)malloc(sizeof(int) * 100);
	while (1) {
		scanf("%c", &ch);
		if (ch == 'q') {
			break;
		}
		if (ch == 'i') {
			scanf("%d", &key);
			insert_heap(p, key, &cnt);
		}
		if (ch == 'd') {
			delete_heap(p, &cnt);
		}
		if (ch == 'p') {
			print_heap(p, cnt);
		}
		getchar();
	}
}
