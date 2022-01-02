#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>

using namespace std;

queue <int> q;

void push();
void pop();
void size();
void empty();
void front();
void back();

int main(void){
    int N,i;
    char order[10]={0,};
    scanf("%d",&N);

    for(i=0;i<N;i++){
        scanf("%s",order);
        if(strcmp(order,"push")==0) push();
        else if(strcmp(order,"pop")==0) pop();
        else if(strcmp(order,"size")==0) size();
        else if(strcmp(order,"empty")==0) empty();
        else if(strcmp(order,"front")==0) front();
        else if(strcmp(order,"back")==0) back();
    }

    return 0;
}

void push(){
    int i;
    scanf("%d",&i);
    q.push(i);
    return;
}
void pop(){
    
    if(q.size()!=0){
        front();
        q.pop();
    }

    else printf("-1\n");
    return;
}
void size(){
    cout << q.size() <<endl;
    return;
}
void empty(){
    q.size()==0 ? printf("1\n") : printf("0\n");
    return;
}
void front(){
    if(q.size()!=0)    printf("%d\n",q.front());
    else printf("-1\n");
    return;
}
void back(){
    if(q.size()!=0) printf("%d\n",q.back());
    else printf("-1\n");
    return;
}