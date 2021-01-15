#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int find_num(char *str,int a,int b,int i,int n){
	int k = -99, mid = (a + b) / 2;

	if (i == n|| a >= b ) {
		return mid;
	}
	else {
		if (str[i] == 'N') {
			k = find_num(str, a, mid, ++i, n);
			if (k != -99) {
				return k;
			}
		}
		if (str[i] == 'Y') {
			k = find_num(str, mid + 1, b, ++i, n);
			if (k != -99) {
				return k;
			}
		}
	}
	return k;
}
int main() {
	int a, b, k, n;
	char *str = NULL;
	scanf("%d %d %d", &a, &b, &n);
	getchar();
	str = (char *)malloc(sizeof(char)*n);
	scanf("%s", str);
	printf("%d",find_num(str, a, b, 0, n));
}

// N이면 k < mid  Y이면 k > mid  
