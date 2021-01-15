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

 -2, insert_node O(log n)
 새로운 노드 p를 만들고 최상위 레이어 부터 시작해서 tmp에 최상위 레이어 head를 넣고 tmp의 값이 추가할 값보다 크면 그 밑 레이어로 내려가고
 tmp - e - tmp->next값이 되는 위치가 되면 새로운 노드와 연결시켜주고 아니면 그 값을 찾을 때까지 넘겨준다 그렇게
 제일 밑 레이어까지 돌아서 추가하면 끝내기

 -3, delete_node O(log n)
  insert와 비슷한 방법으로 tmp->next 값이 e보다 크면 밑으로 내리고 아니면 내가 없앨 값이랑 같으면 erase에 tmp를 넣고
  tmp->next를 tmp->next->next랑 연결한 후 tmp는 그 밑으로 내리고 erase는 메모리 해제를 해준다 그게 아니라면
  다음으로 넘겨서 그 값을 찾아준다 만약 tmp가 NULL이라는 소리는 이제 최하위 층까지 이미 다 끝났다는 소리임으로 종료

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
	int i = l - 1 ,k = 1;
	tmp_prev = (*head)[l - 1];
	tmp = (*head)[l - 1];
	while (1) {
		if (tmp->elem > e) {
			tmp = (*head)[l - 1 - k]->next;
			k++;
		}
		else {
			if (tmp->next->elem > e && tmp->elem < e) {
				p[i]->next = tmp->next;
				tmp->next = p[i];
				i--;
				tmp = tmp->down;
			}
			else {
				tmp = tmp->next;
			}
		}
		if (i < 0) {
			break;
		}
	}
}
void delete_node(node ***head, node ***tail, int e, int l) {
	node *tmp = (*head)[l - 1], *erase = NULL;
	int i = 1;
	while (1) {
		if (tmp->next->elem > e) {
			tmp = (*head)[l - 1 - i];
			i++;
		}
		else {
			if (tmp->next->elem == e) {
				erase = tmp->next;
				tmp->next = (tmp->next)->next;
				tmp = tmp->down;
				free(erase);
			}
			else {
				tmp = tmp->next;
			}
		}
		if (tmp == NULL) {
			break;
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
