// linkedList 를 이용한 hashTable 구현 (chaining) 
#include <stdio.h>
#include <stdlib.h>

// 노드에 들어갈 것은 키와 밸류, next linked 

struct bucket* hashTable = NULL; // 버켓 포인터로 이루어진 테이블
int size = 10; // 몇개를 갖고 시작할 것인지? ex) 10 -> 0 ~ 9

struct node {
	int key;
	int value;
	struct node* next;
};

struct bucket { // 각각 인덱스를 담을 버켓
	struct node* head; // 제일 처음 노드
	int count; // 버켓 안에 몇개의 노드가 들어있는 지 
};

///////////////// 필요함수

struct node* createNode(int key, int value) { // 새로운 노드의 메모리를 할당받고 기본값(key, value)를 셋팅해주는 함수(노드생성)

	struct node* newNode; // 새로운 노드 포인터 생성

	newNode = (struct node*)malloc(sizeof(struct node)); // 구조체 node 사이즈 만큼의 메모리 할당

	newNode->key = key;
	newNode->value = value;	// 넘겨받은 초기 key, value 로 새로 만들어질 노드 값 초기화

	newNode->next = NULL; // next 포인터는 NULL로 설정 
	return newNode;		// 새롭게 만들어진 노드의 포인터를 호출자에게 리턴해줌
}

// hashFunction() : 노드가 왔을 때 키를 갖고있는 노드가 어느 버켓으로 들어가야하는 지 정의해주는 기능
int hashFunction(int key) {
						// 해시 함수의 한 간단한 해싱 방법으로서 integer 타입으로 된 key 값이 오면 
	return key % size;  // 해시맵의 전체 크기(size)로 Modulo(나누고 나머지) 연산을 하여 나온 숫자의 
						// bucket에 맵핑 하라고 알려주는 간단한 해시함수
}

// insert() : 호출될 때 전달 된 key, value를 가진 노드를 해시맵 안에 넣는 함수
void insert(int key, int value) {		// 유저로부터 key, value 를 전달 받는다

	int hashIndex = hashFunction(key);	// 유저로부터 전달 된 key값의 인덱스를 알기 위해서 해시 함수를 호출한다.
										// 그러면 해시함수에 의해 정의된 매핑 방법에 따른 index를 리턴 받아서 hashIndex에 변수에 저장한다
	struct node* newNode = createNode(key, value); // 전달된 key, value 값을 가진 노드를 생성한다
	
	// 넣고자 하는 인덱스(버켓)에 값이 없는 경우 (노드가 없음)
	if (hashTable[hashIndex].count == 0) {	 // 즉, hashTable의 해시함수에 의해 전달받은 index의 bucket 에 접근할 때 비어있다면 
		hashTable[hashIndex].head = newNode; // 새로운 head 노드를 새로운 노드로 지정하고 
		hashTable[hashIndex].count = 1;		 // 해당 bucket의 노드 카운트를 1로 설정한다.
	}
	else { // 넣고자 하는 인덱스에 값이 있는 경우 (head를 옮겨줌)
		newNode->next = hashTable[hashIndex].head;	// bucket 이 비어있지 않다면 새로운 노드의 next 포인터를 예전 head로 바꾼 다음 
		hashTable[hashIndex].head = newNode;		// bucket의 head를 새로운 노드로 바꾼다
		hashTable[hashIndex].count++;				// 그 다음 해당 bucket의 노드 카운트를 증가시킨다.
	}
	return;
}

// delete() : 호출될 때 전달 된 key 를 가진 노드를 해시맵에서 지우는 함수 
void delete(int key) {
	
	int hashIndex = hashFunction(key);		// 해시값 받아오기 
	struct node* node;	// bucket 안에 chaining된 노드들을 하나 하나 비교하며 찾아야 하기 때문에 임시 노드 포인터인 node 생성 
	struct node* trace; // node가 head가 아닐 때 필요, 중간에 있는 노드를 없애는 경우 이전 노드를 추적하여 next 포인터를 연결해줘야 함
	
	trace = (struct node*)calloc(10, sizeof(struct node));

	node = hashTable[hashIndex].head;	// 임시 노드는 해당 버켓의 head 노드를 가리키게 된다

	if (node == NULL) {			// bucket 안에 아무런 노드가 없을 시 그냥 리턴 
		printf("\nNo key found\n");
		return;
	}
	
	while (node != NULL) {	// head노드 부터 Null 이 아닐 경우 계속 루프를 돈다 
		if (node->key == key) { // key 를 찾을 경우 = 만약 key 값이 동일한 노드를 찾았을 경우 
			// next 포인터를 바꾸어 줌 
			if (node == hashTable[hashIndex].head) { // 찾은 노드가 bucket 의 head 일 경우 
				hashTable[hashIndex].head = node->next; // 노드의 head 포인터를 다음 칸으로 이동 
			}
			else { // head가 아니면 
				trace->next = node->next; // 이전 노드의 포인터를 현재 노드의 next 가 가리키고 있는 노드로 바꾼다 
			}

			hashTable[hashIndex].count--; // 해당 bucket의 정보 업데이트 후 노드 삭제  (카운트 감소 , free() 로 메모리 반환)
			free(node);
			return;
		}
		trace = node; // 현재 노드가 찾고있는 노드가 아니라면 다음 노드로 가기 전에 이전 노드를 현재 노드로 바꾸고 다음 노드로 이동
		node = node->next;
	}
	printf("\nNot key found\n"); // 노드를 못 찾은 경우 
	return;
}

// 유저가 해당 키를 넘겨줄 때 있는지 없는지 확인하는 것 , 있을 경우 값을 출력
// search() : 호출될 때 전달 된 key를 가진 노드를 해시맵에서 찾는 함수 
void search(int key) {

	int hashIndex = hashFunction(key); // 해시값 받아오기
	struct node* node = hashTable[hashIndex].head; // bucket 안에 chaining된 노드들을 하나 하나 비교하며 찾아야 하기 때문에 임시 노드 포인터인 node 생성 후 
												   // 그 bucket 의 head 노드를 point 한다 
	// head 에서 계속 추적
	if (node == NULL) {	// bucket 의 head가 NULL, 해당 bucket 이 비어있다면 
		printf("\nno search, no key found\n");
		return; // search() 함수에서 빠져 나간다 
	}
	while (node != NULL) { // chaining 된 bucket 안의 노드들을 보며 만약 key 값이 동일한 노드를 찾았을 경우 
		// key를 찾았을 때 (곧 head)
		if (node->key == key) { // 해당 노드의 key와 value 를 화면에 출력하고 
			printf("ket found,  key = [%d] , value = [%d]\n", node->key, node->value);
			return;	// search() 함수에서 빠져 나간다 
		}
		node = node->next; // 현재 노드가 찾고있는 노드가 아니라면 다음 노드로 이동하게 된다 
	}
	printf("\n no key found\n");
	return; // chaining 된 노드를 다 찾아봤는데도 해당 key 를 가진 node를 못찾았다면 함수를 빠져나간다 
}

// 해시의 현재상태, 어떻게 노드가 되어있나, 순서는 어떻게, head는 누구 등 현재 상황을 출력
// display() : 유저의 편의를 위한 해시맵의 현재 존재하는 노드를 화면에 출력하는 함수
void display() {

	struct node* horse;	// 모든 노드의 iteration 을 위한 임시 노드 포인터 생성 
	int i = 0;
	
	for (i = 0; i < size; i++) { // bucket[0] 부터 [9] 까지 반복 
		horse = hashTable[i].head; // 임시 노드는 bucket 의 head 부터 시작
		printf("Bucket[%d] : ", i);	// 몇번 bucket 인지 bucket index 출력

		while (horse != NULL) { // bucket의 head 노드 부터 NULL 이 아닐 시 
			printf("(key : %d, value : %d) -> ", horse->key, horse->value); // 노드의 key, value 화면에 출력 
			horse = horse->next; // 해당 bucket 의 다음 노드로 이동 
		}
		printf("\n");	// 하나의 bucket 을 다 돌 고 다음 라인으로 가려는 개행 표시
	}
	printf("\n -------end of display-------\n");
	return;
}


int main() {
	// 초기화 작업 
	hashTable = (struct bucket*)malloc(size * sizeof(struct bucket));
	for (int i = 0; i < 10; i++) {
		hashTable[i].count = 0;
		hashTable[i].head = NULL;
	}
	
	insert(0, 1);
	insert(1, 10);
	insert(11, 90);
	insert(21, 64);
	insert(31, 23);
	insert(6, 25);
	insert(97, 4);

	display();

	delete(31);
	delete(11);

	display();
}

/*
Bucket[0] : (key : 0, value : 1) ->
Bucket[1] : (key : 31, value : 23) -> (key : 21, value : 64) -> (key : 11, value : 90) -> (key : 1, value : 10) ->
Bucket[2] :
Bucket[3] :
Bucket[4] :
Bucket[5] :
Bucket[6] : (key : 6, value : 25) ->
Bucket[7] : (key : 97, value : 4) ->
Bucket[8] :
Bucket[9] :

 -------end of display-------
Bucket[0] : (key : 0, value : 1) ->
Bucket[1] : (key : 21, value : 64) -> (key : 1, value : 10) ->
Bucket[2] :
Bucket[3] :
Bucket[4] :
Bucket[5] :
Bucket[6] : (key : 6, value : 25) ->
Bucket[7] : (key : 97, value : 4) ->
Bucket[8] :
Bucket[9] :

 -------end of display-------
*/