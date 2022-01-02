#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int main(void){

    int N,target,i,j,r=0,c=0,turn=0,value,nr,nc,tr,tc;
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}}; //하, 우, 상, 좌
    scanf("%d",&N);
    scanf("%d",&target);

    vector <vector <int> > map(N, vector<int> (N,0));
    value = N*N;
    for(i=0;i<N*N;i++){
        map[r][c] = value;
        if(value==target){
            tr = r;
            tc = c;
        }
        value --;
        nr = r + dir[turn][0];
        nc = c + dir[turn][1];
        if( nr<0 || nr>=N || nc <0 || nc >= N || map[nr][nc] !=0) turn = (turn+1)%4;
        r = r + dir[turn][0];
        c = c + dir[turn][1];
    }

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("%d %d\n",tr+1,tc+1);
    return 0;
}