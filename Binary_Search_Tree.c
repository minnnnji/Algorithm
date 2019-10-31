#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	struct node *left, *right, *parent;
	int key;
}node;
node *getnode() {
	node *p = NULL;
	p = (node *)malloc(sizeof(node));
	p->left = NULL;
	p->parent = NULL;
	p->right = NULL;
	return p;
}
int isExternal(node *p) {
	if (p->left == NULL && p->right == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
int isInternal(node *p) {
	if (p->left != NULL || p->right != NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
int isroot(node *p) {
	if (p->parent == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
node *sibling(node *p) {
	if (isroot(p)) {
		return;
	}
	else if (p == p->parent->left) {
		return p->parent->right;
	}
	else {
		return p->parent->left;
	}
}
node *treeSearch(node *p, int k) {
	if (isExternal(p) == 1) {
		return p;
	}
	if (k == p->key) {
		return p;
	}
	else if (k < p->key) {
		return treeSearch(p->left, k);
	}
	else {
		return treeSearch(p->right, k);
	}
}
int find_element(node *p, int k) {
	node *tmp = treeSearch(p, k);
	if (isExternal(tmp) == 1) {
		return -9999;
	}
	else {
		return tmp->key;
	}

}
void print_find_elem(node *p, int k) {
	int tmp;
	tmp = find_element(p, k);
	if (tmp == k) {
		printf("%d\n", tmp);
	}
	else {
		printf("X\n");
	}
}
void expandExternal(node *p) {
	node *L, *R;
	L = getnode();
	R = getnode();
	p->left = L;
	p->right = R;
	L->parent = p;
	R->parent = p;
}
void insertItem(node **h, int k) {
	node *tmp = NULL;
	node *new_node = getnode();
	new_node->key = k;
	if (*h == NULL) {
		*h = new_node;
		expandExternal(*h);
		return;
	}
	tmp = treeSearch(*h, k);
	if (isInternal(tmp) == 1) {
		return;
	}
	else {
		tmp->key = k;
		expandExternal(tmp);
		return;
	}
}
node *inOrderSucc(node *p) {
	p = p->right;
	if (isExternal(p) == 1) {
		return p;
	}
	while (isInternal(p->left) == 1) {
		p = p->left;
	}
	return p;
}
node *reduce_External(node *z, node **h) {
	node *w = NULL, *zs = NULL, *g = NULL;
	w = (z)->parent;
	zs = sibling(z);
	if (isroot(w) == 1) {
		zs->parent = NULL;
		(*h) = zs;
		return;
	}
	else {
		g = w->parent;
		zs->parent = g;
		if (w == g->left) {
			g->left = zs;
		}
		else {
			g->right = zs;
		}
	}
	free(z);
	free(w);
	return zs;
}
void removeElement(node **h, int k) {
	node *w = NULL, *z = NULL, *y = NULL;
	int elem;
	w = treeSearch(*h, k);
	if (isExternal(w) == 1) {
		printf("X\n");
		return;
	}
	elem = w->key;
	z = w->left;
	if (isExternal(z) != 1) {
		z = w->right;
	}
	if (isExternal(z) == 1) {
		reduce_External(z, h);
	}
	else {
		y = inOrderSucc(w);
		z = y->left;
		w->key = y->key;
		reduce_External(z,h);
	}
	printf("%d\n", elem);
}
void preorder(node *p) {
	if (isExternal(p) == 1) {
		return;
	}
	else {
		printf(" %d", p->key);
		preorder(p->left);
		preorder(p->right);
	}
}
int main() {
	char ch;
	int key;
	node *root = NULL;
	while (1) {
		scanf("%c", &ch);
		if (ch == 'q') {
			break;
		}
		if (ch == 'i') {
			scanf("%d", &key);
			insertItem(&root, key);
		}
		if (ch == 'd') {
			scanf("%d", &key);
			removeElement(&root, key);
		}
		if (ch == 's') {
			scanf("%d", &key);
			print_find_elem(root, key);
		}
		if (ch == 'p') {
			preorder(root);
			printf("\n");
		}
		getchar();
	}
}
