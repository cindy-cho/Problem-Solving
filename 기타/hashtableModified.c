#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
	구조체, 포인터, 이중Array 등 자유롭게 사용
	index[100]
	Key,value -> key 0 ~ 1000, value -> 알아서
	hashFunction -> 알아서
	Hash값 충돌 시 LinkedList 처리, 나중에 들어온 값이 head에 위치

	<필수함수>
   int insert(int key, char* value) -> 성공 1, 실패 -1
   int remove(int key) -> 성공 1, 실패 -1
   char* get(int key) -> 값이 없으면 NULL POINTER 반환
   void print(int index) -> 해당 index의 LinkedList 출력, 표현형식은 자유
   const 키워드 공부하고 함수 Parameter, 함수 내부, return 타입에 const 지정
*/

/*
key 중복은 허용하지 않음
*/

typedef struct node{
    int key;
    char *value;
    struct node *next;
}node;

typedef struct bucket {
	struct node* headNode; // 제일 처음 노드 
	int count; // 테이블에 있는 요소 갯수
} bucket;

int size = 100; //bucket size

bucket hashTable[100];

int hashFunction(int key) {
    return key%size;
}

int isKeyExist(const int key, const node* head){
    while(head != NULL){
        if(head->key==key) return -1;
        head = head -> next;
    }
    return 1;
}

int insert(int key, char* value){ // success -> 1 , fail -> -1
    const int index = hashFunction(key);
    node* newNode = (node*)malloc(sizeof(node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if(hashTable[index].count==0){
        hashTable[index].headNode = newNode;
        hashTable[index].count = 1;
    }else{
        //해당 키 존재함으로 생성 불가
        if(isKeyExist(key, hashTable[index].headNode) == -1) {
            printf("[Insert][Fail]    Bucket[%d] : (key: %d, value: %s)\n",index,key,value);
            return -1;
        }

        newNode->next = hashTable[index].headNode;
        hashTable[index].headNode = newNode;
        hashTable[index].count++;
    }
    
    printf("[Insert][Success] Bucket[%d] : (key: %d, value: %s)\n",index,key,value);
    return 1;
}

int remover(int key){
    const int index = hashFunction(key);

    // 해당 key가 들어있는 bucket count 값이 0이면 존재하지 않는다는 거니까 바로 -1 리턴
    if(hashTable[index].count==0) {
        printf("[Remove][Fail]    key:%d not exist\n",key);
        return -1;
    }

    node* prev = hashTable[index].headNode;

    //찾는 값이 바로 head에 있을 경우
    if(prev->key==key){
        hashTable[index].headNode = prev->next;
        hashTable[index].count--;
        free(prev);
        printf("[Remove][Success] key:%d removed\n",key);
        return 1;
    }

    node* deleteNode;
    while(prev->next!=NULL){
        if(prev->next->key==key){
            deleteNode = prev->next;
            prev->next = prev->next->next;
            hashTable[index].count--;

            free(deleteNode);
            printf("[Remove][Success] key:%d removed\n",key);
            return 1;
        }   
        prev = prev->next;
    }
    printf("[Remove][Fail]    key:%d not exist\n",key);
    return -1;
}

char* get(const int key){
    const int index = hashFunction(key);
    node* tmp = hashTable[index].headNode;
    while(tmp!=NULL){
        if(tmp->key== key) return tmp->value;
    }
    return NULL;
}

void print(int index){
    if(hashTable[index].count==0){
        printf("Bucket[%d] is empty\n",index);
        return;
    }

    printf("Bucket[%d] : ",index);
    node *tmp =  hashTable[index].headNode;
    
    for(int i=0;i<hashTable[index].count-1;i++){
        printf("(key : %d, value : %s) -> ", tmp->key, tmp->value);
        tmp=tmp->next;
    }
    printf("(key : %d, value : %s)", tmp->key, tmp->value);
    
    printf("\n");
    return;
}

void printResultofGet(char* target,int key){
    if(target==NULL) printf("(key : %-4d, value : )\n",key);
    else printf("(key : %-4d, value : %s)\n",key,target);
}
int main(void) {
	
    for(int i=0;i<size;i++){
        hashTable[i].headNode= NULL;
        hashTable[i].count=0;
    }

    char* target;

    insert(0,"123");
    insert(0,"123");

	print(0);
    print(0);
    print(1);
    print(0);
    print(6);
    print(7);

	remover(31);
    remover(0);
	// remover(11);
    print(0);
    print(6);

    insert(0,"가나다라마바사");
    insert(1000,"가바사");
    printResultofGet(get(1000),1000);
    printResultofGet(get(50),50);

    print(0);
    remover(0);
    print(0);
    remover(0);
    print(0);


	// print(0);
    // print(1);
    // print(6);
    // print(7);

    return 0; //int main -> always return 0;
}