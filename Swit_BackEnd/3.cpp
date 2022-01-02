#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int **board_DP;
int **board_copy;
#define MAXVALUE 10000000

void moveToTarget(size_t rows,size_t cols,int c,int x,int y,int tX,int tY){
    if(x==tX && y==tY) return;
    int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
    int tmpX,tmpY,updatedValue;
    for(int i=0;i<4;i++){
        tmpX = x + dir[i][0];
        tmpY = y + dir[i][1];
        
        if(tmpX>=0 && tmpX<rows && tmpY>=0 && tmpY<cols){
    
            updatedValue = board_DP[x][y];
            if(board_copy[tmpX][tmpY]==0) updatedValue+=1;
            else updatedValue +=(c+1);
    
            if(updatedValue < board_DP[tmpX][tmpY]){
                board_DP[tmpX][tmpY] = updatedValue;
                moveToTarget(rows,cols,c,tmpX,tmpY,tX,tY);
            }
        }
    }
}
// board_rows는 2차원 배열 board의 행 길이, board_cols는 2차원 배열 board의 열 길이입니다.
int solution(int** board, size_t board_rows, size_t board_cols, int c) {
    board_DP = (int**) malloc(board_rows*sizeof(int *));
    board_copy = (int**) malloc(board_rows*sizeof(int*));
    for(int i=0;i<board_rows;i++) {
        board_DP[i] = (int*) malloc(board_cols*sizeof(int));
        board_copy[i] = (int*) malloc(board_cols*sizeof(int));
    }

    int answer = 0;
    int rX,rY,tX,tY; //robot X,Y, target X,Y
    for(int i=0;i<board_rows;i++){
        for(int j=0;j<board_cols;j++){
            board_DP[i][j] = MAXVALUE;
            if(board[i][j]==2){
                rX = i;
                rY = j;
                board[i][j] = 0; //이동 cost 1 이기위해 0으로 업데이트
                board_DP[i][j] = 0; //출발점만 DP값 0
            }
            else if(board[i][j]==3){
                tX = i;
                tY = j;
                board[i][j] = 0; //이동 cost 1 이기위해 0으로 업데이트
            }
            board_copy[i][j] = board[i][j];
        }
    }

    moveToTarget(board_rows,board_cols,c,rX,rY,tX,tY);

    return board_DP[tX][tY];
}