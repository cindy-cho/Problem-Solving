#include<iostream>
#include<stdio.h>

using namespace std;

int main(void){

    int N,M;
    int i,value;
    int Nset1[10000000]={0,};
    int Zero=0;
    int Nset2[10000000]={0,};

    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&value);
        if(value<0) Nset1[value+10000000]=1;
        else if(value==0) Zero=1;
        else Nset2[value-1]=1;
    }

    scanf("%d",&M);
    for(i=0;i<M;i++){
        scanf("%d",&value);
        if(value<0 && Nset1[value+10000000]==1) printf("1 ");
        else if(value==0 && Zero==1) printf("1 ");
        else if(value>0 && Nset2[value-1]==1) printf("1 ");
        else printf("0 ");
    }

    return 0;
}