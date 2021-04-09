#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

int main(void){
    int N,i,j,x,y,M=-100000;
    vector < vector <int> > coordinate (200001);

    scanf("%d",&N);

    for(i=0;i<N;i++){
        scanf("%d %d",&x,&y);
        coordinate[x+100000].push_back(y);
        M = max(M,x+100000);
    }

    for(i=0;i<M+1;i++){
        if(coordinate[i].size()!=0){
            sort(coordinate[i].begin(),coordinate[i].end());
            for(j=0;j<coordinate[i].size();j++){
                printf("%d %d\n",i-100000,coordinate[i][j]);
            }

        }
        
    }


    return 0;
}