#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

vector<int> basket;

void push();
void pop();
void size();
void empty();
void top();

int main(void){
    int N;
    int i;
    char line[100]={0,};
    
    scanf("%d",&N);

    for(i=0;i<N;i++){
        scanf("%s",line);
        
        if(strcmp(line,"push")==0) push();
        else if(strcmp(line,"pop")==0) pop();
        else if(strcmp(line,"size")==0) size();
        else if(strcmp(line,"empty")==0) empty();
        else if(strcmp(line,"top")==0) top();
    }

    return 0;
}

void push(){
    int i;
    scanf("%d",&i);
    basket.push_back(i);
    return ;
}

void pop(){
    top();
    if(basket.size()>0) basket.pop_back();
    return ;
}

void size(){
    printf("%d\n",basket.size());
    return ;

}

void empty(){
    basket.size()==0 ? printf("1\n") : printf("0\n") ;
    return ;
}

void top(){
    if(basket.size()!=0) printf("%d\n",basket.back());
    else printf("-1\n");
    return ;
}