//#과제제출 18011809 엄민지
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INT_MIN -2147483647 // 최소값
#define INT_MAX 2147483647 // 최댓값
/*skip_list 
 노드를 만들때 노드배열을 만들어서 제일 위에 레이어부터 시작해서 다음 값으로 넘어가면서 다음 값이 찾는 값보다 크면 그 밑에 레이어에 내려갈 수 있도록 down 포인터를
 통해 내려갈 수 있고 내려간 노드의 또 다음값을 찾아 출력하면서 값을 찾는다
 밑에 설명이 없는 것은 함수 각각에 설명하도록 하겠습니다 ex) getnode, error

 -1, init O(n)
 head와 tail를 각각 레이어의 개수대로 연결하고 head의 값은 int의 최솟값으로 tail의 값은 int형의 최댓값으로 설정했다.

 -2, insert_node O(n^2)
 새로운 노드 p를 만들어서 tmp에는 head의 다음 값에 연결해주고 tmp_prev에는 head를 넣어줬다.
 그리고 tmp가 tail이 아니면서 tmp의 값이 입력한 값보다 커질 때까지 while문을 돈다 O(n);
 찾으면 tmp_prev - p - tmp 순으로 연결시켜줍니다. 이 과정을 레이어 개수 대로 해야하기 때문에
 결국 insert_node의 시간 복잡도는 O(n^2)

 -3, delete_node O(n^2)
 insert할때 와 동일하게 tmp와 tmp의 전노드를 설정해두고 삭제해야하는 값이 있으면 tmp_prev와 tmp->next값을 연결해줍니다. O(n)
 이 방법을 레이어 개수대로 하니까 결국 시간 복잡도는 O(n^2)

 -4, check_node O(n)
 내가 찾는 노드가 최하위레이어에 없다면 결국 위 레이어에는 없는거니까 error처리를 하기위해서 check_node를 만들었고
 check_node는 최하위 레이어만 하기때문에 O(n) 찾는 값이 있으면 flag를 1로 바꿔주고 
 flag가 0이면 없는거니까 error처리
 
 -5, search_node O(log n)
 최상위층 레이어 값을 tmp에 넣고 tmp의 값이 내가 찾는 값보다 크면 밑으로 내려가서 레이어를 다시 찾아주고 아니면
 tmp의 다음값이 내가 찾는 값보다 크고 찾는 값도 아니고 down값이 NULL도 아니면 밑에 레이어로 내려가고 아니면
 tmp의 값이 찾는 값이면 출력하고 끝내기 다음값이 찾는 값이거나 작으면 출력하고 다음값으로 넘기기

 -6, print_node  O(n^2)
 모든 레이어를 다 돌아가면서 출력해야하기 때문에 O(n^2)

	main문 설명은 main에서 하겠습니다.
*/
void error() {
	printf("Error\n");
}//오류메세지 출력
typedef struct node {
	struct node *next, *down;
	int elem;
}node;// node 하나 만들때의 구성 아래 레이어로 내려갈 수 있는 down과 다음 노드로 넘어갈 수 있는 next
node **getnode(int k,int e) {
	node **p = NULL; // 노드 배열을 위한 선언
	p = (node **)malloc(sizeof(node *)* k);// k는 내가 입력한 레이어의 갯수인데 그 만큼 노드 배열 동적할당 받기
	for (int i = 0; i < k; i++) {
		p[i] = (node *)malloc(sizeof(node));// 노드 하나하나 동적할당해주고
		p[i]->next = NULL;
		p[i]->down = NULL;//next와 down은 널로 초기화해준다.
		p[i]->elem = e;//입력한 값대로 값도 초기화
	}
	for (int i = k - 1; i > 0; i--) {
		p[i]->down = p[i - 1];
	}//3->2 2->1 1->0 이런식으로 최상위층부터 최하위레이어까지 연결하기 위해
	return p;
}
void init(node ***h, node ***t,int k) {
	(*h) = getnode(k,INT_MIN);
	(*t) = getnode(k,INT_MAX);
	for (int i = 0; i < k; i++) {
		(*h)[i]->next = (*t)[i];
	}
}
void insert_node(node ***head, node ***tail, int e, int l) {
	node *tmp_prev = NULL, *tmp = NULL;
	node **p = getnode(l, e);
	for (int i = 0; i < l; i++) {
		tmp_prev = (*head)[i];
		tmp = (*head)[i]->next;
		while (tmp!=(*tail)[i]&&tmp->elem < e) {
			tmp = tmp->next;
			tmp_prev = tmp_prev->next;
		}
		tmp_prev->next = p[i];
		p[i]->next = tmp;
	}
}
void delete_node(node ***head, node ***tail, int e, int l) {
	node *tmp_prev = NULL, *tmp = NULL;
	for (int i = 0; i < l; i++) {
		tmp_prev = (*head)[i];
		tmp = (*head)[i]->next;
		while (tmp != (*tail)[i]) {
			if (tmp->elem == e) {
				tmp_prev->next = tmp->next;
				free(tmp);
				break;
			}
			tmp = tmp->next;
			tmp_prev = tmp_prev->next;
		}	
	}
}
int check_node(node **head, node **tail, int e) {
	node *tmp = NULL;
	int flag = 0;
	tmp = head[0]->next;
	while (tmp != tail[0]) {
		if (tmp->elem == e) {
			flag = 1;
		}
		tmp = tmp->next;
	}
	return flag;
}
void search_node(node **head, node **tail, int e, int l_cnt) {
	int i = 1;
	node *tmp = head[l_cnt - 1]->next;
	while (1) {
		if (tmp->elem > e) {
			tmp = head[l_cnt - 1 - i]->next;
			i++;
		}
		else {
			if (tmp->next->elem > e && tmp->elem != e &&tmp->down != NULL) {
				tmp = tmp->down;
			}
			else {
				if (tmp->elem == e) {
					printf(" %d\n",tmp->elem);
					break;
				}
				else {
					if (tmp->next->elem <= e) {
						printf(" %d", tmp->elem);	
						tmp = tmp->next;
					}
					else if (tmp->next->elem == e) {
						printf(" %d\n", tmp->next->elem);
						return;
					}
				}
			}
		}
	}
}
void print_node(node **p,int l_cnt) {
	node *tmp;
	for (int i = 0; i < l_cnt; i++) {
		tmp = p[l_cnt - 1 - i]->next;
		while (tmp->next != NULL) {
			printf(" %d", tmp->elem);
			tmp = tmp->next;
		}
		printf("\n");
	}
}
int main() {
	int l_cnt, n, e, l, check = 0, cnt=0;
	// l_cnt = 최대 레이어개수, n = 명령문 개수 e = key값 , l = key가 들어가는 레이어의 층수, check는 유효하는 key인지 flag역활
	char str; 
	node **head = NULL , **tail = NULL;
	scanf("%d", &l_cnt);//최대 레이어 개수 받기
	scanf("%d\n", &n);// 명령 개수
	init(&head, &tail, l_cnt);//초기화
	for (int i = 0; i < n; i++) {
		scanf("%c", &str);// 무슨 명령할지 str
		if (str == 'I') {
			scanf("%d %d", &e, &l);
			check = check_node(head, tail, e);
			if(check ==1){
				error();
			}
			else {
				if (l <= l_cnt&&l > 0) { // 입력한 레이어가 1이상 최대 이하일때
					insert_node(&head, &tail, e, l); //insert_node호출
					cnt++;
				}
				else {
					error();//아니면 에러
				}
			}
		}
		if (str == 'S') {
			scanf("%d", &e); //찾고 싶은 key값
			check = check_node(head, tail, e); //유효한 값인지 확인
			if (check == 1) {//유효하면 함수 호출
				search_node(head, tail, e, l_cnt);
			}
			else {
				error();
			}
		}
		if (str == 'D') {
			scanf("%d", &e);//삭제하고 싶은 key값
			check = check_node(head, tail, e);// 유효한 값인지 확인
			if (check == 1) {// 유효하면 함수 호출
				delete_node(&head, &tail, e, l_cnt);
				cnt--;
			}
			else {
				error();
			}
		}
		if (str == 'P') {
			if (cnt == 0) {
				printf("Empty\n"); 
			}
			else{
			print_node(head, l_cnt); //모든 레이어 출력
			}
		}
		getchar();
	}
}
