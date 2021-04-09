#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main(void){
    int N,i,num;
    int small,big;
    scanf("%d",&N);

    if(N==1) {
        scanf("%d",&num);
        cout << num*num << endl;
    }

    else{
        for(i=0;i<N;i++){
            scanf("%d",&num);
            if(i==0){
                small = num;
                big = num;
            }
            else{
                small = min(small, num);
                big = max(big, num);
            }
        }
        cout<< small * big << endl;
    }

    return 0;
}