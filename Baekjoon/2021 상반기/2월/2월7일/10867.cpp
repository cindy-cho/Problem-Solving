#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main(void){
    int N,i,value;
    int M=-1000;
    int num[2001]={0,};
    
    scanf("%d",&N);
    
    for(i=0;i<N;i++){
        scanf("%d",&value);
        num[value+1000]=1;
        M = max(M,value);
    }
    M = max(M,2001);
    for(i=0;i<M;i++){
        if(num[i]==1) printf("%d ",i-1000);
    }
    return 0;
}