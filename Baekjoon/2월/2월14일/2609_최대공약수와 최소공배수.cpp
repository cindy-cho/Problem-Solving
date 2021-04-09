#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main(void){

    int N, M;
    int res,big,small;
    scanf("%d %d",&N,&M);
    if(N > M){
        big=N;
        small=M;
    }
    else{
        big=M;
        small=N;
    }
    while(1){
        if(big%small == 0) break;
        res = big % small;
        big = small;
        small = res;
    }

    cout << small << endl;
    cout << N*M/small ;
    return 0;
}