#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int N,value,i;
    vector<int> list;

    scanf("%d",&N);

    for(i=0;i<N;i++){

        scanf("%d",&value);
        list.push_back(value);

    }

    sort(list.begin(),list.end());

    for(i=0;i<N;i++) printf("%d\n",list[i]);

    return 0;
}