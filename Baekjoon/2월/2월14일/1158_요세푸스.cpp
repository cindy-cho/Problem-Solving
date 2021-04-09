#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int main(void){
    int N,K;

    scanf("%d %d",&N,&K);

    vector <int> candidates;

    int i,pos=K-1;
             
    for(i=1;i<=N;i++) candidates.push_back(i);
    printf("<");
    for(i=1;i<N;i++){
        printf("%d, ",candidates[pos]);
        candidates.erase(candidates.begin()+pos);
        pos = (pos + K - 1) % candidates.size();
    }
    printf("%d>\n",candidates[0]);

    return 0;
}
