#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

int findLength(int num){
    int len = 0;
    while(num>0){
        num/=10;
        len++;
    }
    return len;
}

int solution(int num) {
    int answer = 0;
    int len = findLength(num);
    if(len==1){
        return 11;
    }
    if(len%2==1){ //자릿수가 홀수인 경우에는 그 다음 1000..이 정답이다. (n>=3)
        answer = pow(10,len);
        return answer;
    }
    int maxAnswer = pow(10,len); //22면 99까지만 검사
    bool isAnswerFind = false;
    int current;
    int front, rear;
    for(answer = num; answer<maxAnswer; answer++){
        current = answer;
        front = 1; rear = 1;
        for(int i=0;i<len/2;i++){
            rear *= current % 10;
            current/=10;
        }
        for(int i=0;i<len/2;i++){
            front *= current % 10;
            current /= 10;
        }
        if(rear == front){
            isAnswerFind = true;
            break;
        }
    }
    if(isAnswerFind == true) return answer;
    return maxAnswer * 10;
}