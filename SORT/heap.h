#pragma once
#include<stdio.h>
#include"basic.h"
void up_heap(int *p, int n) {
	int k = n / 2;
	if (n > 1) {
		if (p[n] > p[k]) {
			swap(p + n, p + k);
			up_heap(p, k);
		}
	}
}
void insert_heap(int *p, int key, int *cnt) {
	p[++(*cnt)] = key;
	up_heap(p, *cnt);
}
void down_heap(int *p, int n, int index) {
	int l = 2 * index, r = (2 * index) + 1, max = index;
	if (r <= n) {
		if (p[l] > p[r]) {
			if (p[l] > p[max]) {
				max = l;
			}
			else {
				max = index;
			}
		}
		else {
			if (p[r] > p[max]) {
				max = r;
			}
			else {
				max = index;
			}
		}
	}
	else if (l <= n) {
		if (p[l] > p[max]) {
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
		down_heap(p, n, max);
	}
}
void delete_heap(int *p, int cnt) {
	int erase = p[1];
	swap(p + 1, p + (cnt));
	down_heap(p, cnt, 1);
	printf("%d\n", erase);
}