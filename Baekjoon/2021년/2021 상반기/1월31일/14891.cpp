#include<iostream>
#include<stdio.h>

/* 
톱니바퀴 저장 순서
   0
  7  1
6      2
  5  3
    4
맞닿는건
1-2번의 2,6
2-3번의 2,6
3-4번의 2,6

시계방향으로 돌면 : 1
70123456
반시계 : -1
12345670
*/
using namespace std;

int main(void){
    int gear[4][8];
    int move[4] = {0,};
    int i,j,value;
    for(i=0;i<4;i++){
        scanf("%d",&value);
        for(j=7;j>=0;j--){
            gear[i][j] = value%10;
            value = value/10;
        }
    }

    // for(i=0;i<4;i++){
    //     for(j=0;j<8;j++) printf("%d",gear[i][j]);
    //     printf("\n");
    // }

    int k,gearNum, gearDir;
    int m,tmp;
    scanf("%d",&k); //회전 횟수
    for(i=0;i<k;i++){
        for(j=0;j<4;j++) move[j] = 0; //  0으로 초기화

        scanf("%d %d",&gearNum,&gearDir);
        move[gearNum-1] = gearDir;
        // printf("move : %d %d %d %d \n",move[0],move[1],move[2],move[3]);
        //맞닿은 톱니 극이 다르면 : 반대방향 회전
        //같으면 : 안움직임
        for(j=gearNum-1;j>0;j--){ //회전하는 톱니바퀴에서 왼쪽으로 먼저 검색
            if(gear[j][6] != gear[j-1][2]){ // 중심 톱니바퀴와 다른 극이면
                move[j-1] = move[j] * -1; //반대방향으로 돔
            }
        }
        for(j=gearNum-1;j<3;j++){
            if(gear[j][2] != gear[j+1][6]){
                move[j+1] = move[j] * -1; 
            }
        }
        //시계방향으로 돌면
        // 12345670
        // 반시계
        // 70123456
        for(j=0;j<4;j++){
            if(move[j]==1){ //반시계방향
                tmp = gear[j][7];
                for(m=7;m>=1;m--) gear[j][m] = gear[j][m-1];
                gear[j][0] = tmp;

            }
            else if(move[j]==-1){
                tmp = gear[j][0];
                for(m=0;m<=6;m++) gear[j][m]=gear[j][m+1];
                gear[j][7] = tmp;
            }
        }

        

   }

   int score = 0;
        score = gear[0][0]*1 + gear[1][0]*2 + gear[2][0]*4 + gear[3][0] * 8;
        printf("%d",score);
    return 0;
}