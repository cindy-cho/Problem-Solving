#include<iostream>
#include<vector>
#include<stdio.h>
#include<string.h>

using namespace std;
vector <int> deck;

void push_front();
void push_back();
void pop_front();
void pop_back();
void size();
void empty();
void front();
void back();

int main(void){
    int N,i;
    char line[20]={0,};

    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%s",line);
        if(strcmp(line,"push_front")==0) push_front();
        else if(strcmp(line,"push_back")==0) push_back();
        else if(strcmp(line,"pop_front")==0) pop_front();
        else if(strcmp(line,"pop_back")==0) pop_back();
        else if(strcmp(line,"size")==0) size();
        else if(strcmp(line,"empty")==0) empty();
        else if(strcmp(line,"front")==0) front();
        else if(strcmp(line,"back")==0) back();
    }

    return 0;
}

void push_front(){
    int i;
    scanf("%d",&i);
    deck.insert(deck.begin(), i);
    return;
}
void push_back(){
    int i;
    scanf("%d",&i);
    deck.push_back(i);
    return;
}
void pop_front(){
    if(deck.size()!=0) {
        front();
        deck.erase(deck.begin());
    }
    else printf("-1\n");
    return;
}
void pop_back(){
    if(deck.size()!=0) {
        back();
        deck.pop_back();
    }
    else printf("-1\n");
    return;
}
void size(){
    printf("%d\n",deck.size());
    return;
}
void empty(){
    deck.size()!=0 ? printf("0\n") : printf("1\n");
    return;
}
void front(){
    if(deck.size()!=0) printf("%d\n",deck.front());
    else printf("-1\n");
    return;
}
void back(){
    if(deck.size()!=0) printf("%d\n",deck.back());
    else printf("-1\n");
    return ;
}