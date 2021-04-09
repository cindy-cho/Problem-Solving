#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int N,M;

    vector <int> list;

    scanf("%d",&N);
    int i,value;

    for(i=0;i<N;i++){
        scanf("%d",&value);
        list.push_back(value);
    }

    scanf("%d",&M);

    for(i=0;i<M;i++){
        scanf("%d",&value);
        if(find(list.begin(),list.end(),value)!=list.end()){
            printf("1 ");
        }
        else printf("0 ");
    }

    return 0;
}