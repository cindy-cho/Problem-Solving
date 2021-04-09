#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

void determinePerfect(int n);

int main(void){
    int n;

    scanf("%d",&n);

    while(n!=-1){
        determinePerfect(n);
        scanf("%d",&n);
    }

    return 0;
}

void determinePerfect(int n){
    vector <int> small;
    small.push_back(1);

    int flag1=1;

    int i=2,k=n,sum=1;
    for(i=2;i<=k/i;i++){
        if(n%i==0){
            small.push_back(i);
            small.push_back(k/i);
            sum = sum + i + k/i;
            if(sum > n) {
                printf("%d is NOT perfect.\n",n);
                return;
            }
        }
    }

    if(sum==n){
        sort(small.begin(),small.end());
        printf("%d = 1",n);
        for(i=1;i<small.size();i++){
            printf(" + %d",small[i]);
        }
        printf("\n");
    }
    else printf("%d is NOT perfect.\n",n);
}