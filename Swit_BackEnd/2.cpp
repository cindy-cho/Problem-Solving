#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

// numbers_len은 배열 numbers의 길이입니다.
int minAnswer;

void swap(int *a, int *b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

int canFindAnswer(int numbers[],size_t numbers_len,int K){
    int *newNumbers;

    newNumbers = malloc(sizeof(int)*numbers_len);
    for(int i=0;i<numbers_len;i++) newNumbers[i] = numbers[i];
    
    for(int i=0;i<numbers_len-1;i++){
        for(int j=1;j<numbers_len-i;j++){
            if(newNumbers[j]<newNumbers[j-1]) swap(&newNumbers[j],&newNumbers[j-1]);
        }
    }

    for(int i=1;i<numbers_len;i++){
        if(newNumbers[i]-newNumbers[i-1]>K){ //방법이 없는 경우
            return -1;
        }
    }
    return 1;
}

void findSolution(int numbers[], size_t numbers_len, int K,int crntIdx, int swapCount){

    bool isAnswer = true;
    for(int i=1;i<numbers_len;i++){
        if(abs(numbers[i]-numbers[i-1]) > K){
            isAnswer = false;
            break;
        }
    }

    if(isAnswer == true && swapCount < minAnswer){ //가장 최솟값으로 갱신
        minAnswer = swapCount;
        return;
    }

    if(crntIdx == numbers_len) return;

    for(int i=crntIdx+1;i<numbers_len;i++){
        //swap안하는 경우
        findSolution(numbers, numbers_len, K, crntIdx+1, swapCount);
        //swap하는 경우
        swap(&numbers[crntIdx],&numbers[i]);
        findSolution(numbers, numbers_len, K, crntIdx+1, swapCount+1);
        swap(&numbers[crntIdx],&numbers[i]);
    }
}

int solution(int numbers[], size_t numbers_len, int K) {
    
    if(canFindAnswer(numbers, numbers_len, K)==-1){
        return -1;
    }
    
    minAnswer = 100;

    findSolution(numbers,numbers_len,K,0,0);
    return minAnswer;
}