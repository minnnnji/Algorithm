//swap 함수랑 node의 기본 정보와 getnode, print node , print배열이 있는 헤더
// 사용방법은 #include"basic.h" <- 이렇게 불러오면 됨
#include<stdio.h>
#pragma once
typedef struct node {
	struct node *next;
	int elem;
}node;
node *getnode() {
	node *p = NULL;
	p = (node *)malloc(sizeof(node));
	p->next = NULL;
	return p;
}
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void travel_arr(int *p, int n) {
	for (int i = 1; i <= n; i++) {
		printf(" %d", p[i]);
	}
	printf("\n\n");
}
void travel_node(node *p) {
	node *tmp = p;
	while (tmp != NULL) {
		printf(" %d", tmp->elem);
		tmp = tmp->next;
	}
	printf("\n\n");
}
