#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int find_non_key(int *p, int k, int n) {
	int i = 0;
	while (p[i] < k&& n > i) {
		i++;
	}
	return i - 1;
}
int find_dic(int *p, int k, int l,int r) {
	if (l > r) {
		return -99;
	}
	int mid = (l + r) / 2;
	if (k == p[mid]) {
		return mid;
	}
	else if (k < p[mid]) {
		return find_dic(p, k, l, mid - 1);
	}
	else {
		return find_dic(p, k, mid + 1, r);
	}
}
int main() {
	int n, k, *p = NULL;
	scanf("%d %d", &n, &k);
	p = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", p + i);
	}
	int m = find_dic(p, k, 0, n - 1);
	if (m != -99) {
		printf("%d", m);
	}
	else if (m == -99 && p[n - 1] < k) {
		printf("%d", n - 1);
	}
	else if (m == -99 && p[0] > k) {
		printf("-1");
	}
	else {
		printf("%d",find_non_key(p, k, n));
	}
}
