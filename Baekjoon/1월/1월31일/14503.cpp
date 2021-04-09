#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;

// d가 0 1  2 3  북동남서
//      북
//   서    동
//      남
//현재방향 기준 왼쪽방향
/* 현재위치가 (r,c)
 0(북) : 서쪽방향 (r,c-1) 3 후진 : r+1,c : 3
 1(동) : 북쪽방향 (r-1,c) 0 후진 : r, c-1 : 0 
 2(남) : 동쪽방향 (r,c+1) 1 후진 : r-1,c : 1
 3(서) : 남쪽방향 (r+1,c) 2 후친 : r, c+1 : 2
*/
int N,M;
int totalClean=0;
int movement[4][3]={{0,-1,3},{-1,0,0},{0,1,1},{1,0,2}};
void step2(vector < vector < int > > location, int r, int c, int d);
int main(void){
    int r,c,d;

    scanf("%d %d",&N,&M);
    scanf("%d %d %d",&r,&c,&d);

    vector < vector < int > > location(N);

    int i,j,value;

    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            scanf("%d",&value);
            location[i].push_back(value);
        }
    }

    step2(location,r,c,d);

    cout << totalClean ;

    return 0;
}

void step2(vector < vector < int > > location, int r, int c, int d){
    if(location[r][c] == 0){ //현재위치 청소
        totalClean ++;
        location[r][c] = -1; //청소하면 -1로 업데이트
    }

    int i;
    int tr,tc,td=d;
    for(i=0;i<4;i++){
        tr = r+movement[td][0];
        tc = c+movement[td][1]; //왼쪽방향

        if(tr>=0 && tr<N && tc>=0 && tc<M && location[tr][tc]==0){ //청소가능한 구역이면
            step2(location,tr,tc,movement[td][2]); //위치 업데이트 하고 넘겨주기
            return;
        }

        td = movement[td][2];
    }
    td = movement[d][2];

    tr = r+movement[td][0];
    tc = c+movement[td][1];

    if(location[tr][tc]==1) return; //후진 안될때
    else step2(location,tr,tc,d); //후친하긔
}