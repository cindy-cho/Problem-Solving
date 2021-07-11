#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> deck;
int N;


int upperBound(int value);
int lowerBound(int value);
int main(void){
    
    int i,value,idx;
    int upper,lower;

    scanf("%d",&N);

    for(i=0;i<N;i++){
        scanf("%d",&value);
        deck.push_back(value);
    }
    sort(deck.begin(),deck.end());
    
    int M;
    scanf("%d",&M);
    for(i=0;i<M;i++){
        scanf("%d",&value);
        upper = upperBound(value);
        lower = lowerBound(value);

        if(deck[lower]==value){
            idx = upper - lower + 1;
        }
        else idx = 0;

        printf("%d ",idx);
    }
    printf("\n");
    return 0;
}
int upperBound(int value){
    int s,e,m;
    s=0;
    e=N-1;

    while(e-s > 0){
        m = (s+e)/2;
        if(deck[m] <=value) s= m+1;
        else e=m;
    }

    if(deck[e] !=value) e --;

    return e;
}
int lowerBound(int value){
    int s,e,m;
    s=0;
    e=N-1;

    while(e-s > 0){
        m = (s+e)/2;
        if(deck[m] <value) s= m+1;
        else e=m;
    }

    return e;
}