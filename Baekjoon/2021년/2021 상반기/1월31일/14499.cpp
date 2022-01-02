#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
// N * M 인 지도
//지도 좌표(r, c) r: 북쪽으로부터, c : 서쪽으로부터
/*r
  r
  r
  r
  rccccc

*/
//1 동쪽 2 서쪽 3 북쪽 4 남쪽
//  0,1  0,-1  -1,0  1,0
//  ->    <-     ^    V
/* 배열에 저장하는 순서, 2가 윗면, 3이 오른쪽
    0
  1 2 3
    4
    5
동쪽으로 이동시    서쪽으로 이동시    북쪽으로 이동시    남쪽으로 이동시
    0              0               2             5
  5 1 2          2 3 5           1 4 3         1 0 3
    4              4               5             2
    3              1               0             4
 
  051243         023541          214350        510324
*/
int main(void){
    int N, M, x, y, stage;
    /*
    x
    x
    x
    xyyyyyy
    */
    scanf("%d %d %d %d %d",&N, &M, &x, &y, &stage);
    int i, j, value;
    int dice[6]={0,}, new_dice[6]={0,};
    int dice_arrangement[4][6]={{0,5,1,2,4,3},{0,2,3,5,4,1},{2,1,4,3,5,0},{5,1,0,3,2,4}};
    int movement[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
    vector<vector< int > > dice_map(N);
    
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            scanf("%d",&value);
            dice_map[i].push_back(value);
        }        
    }

    for(i=0;i<stage;i++){
        scanf("%d",&value);
        value = value -1;
        if(x+movement[value][0]>=0 && x+movement[value][0]<N && y+movement[value][1] >=0 && y+movement[value][1] < M){ // 지도 밖을 안 벗어나는 경우에만
            x = x+movement[value][0];
            y = y+movement[value][1];
            
            // cout << "moved stage : " << i+1 << "(x,y)" << "(" << x << "," << y << ")" << endl; 
            for(j=0;j<6;j++){ //주사위 업데이트
                new_dice[j] = dice[dice_arrangement[value][j]];
            }

            for(j=0;j<6;j++) { //업데이트 된 값 적용
                dice[j] = new_dice[j];
            }
            


            
            if(dice_map[x][y] == 0){ //이동한 칸에 쓰여 있는 수가 0이면
                dice_map[x][y] = dice[5]; //주사위의 바닥면에 쓰여있는 수가 칸에 복사
            }
            else{ //이동한 칸에 쓰여 있는 수가 0이 아니면
                dice[5] = dice_map[x][y]; //칸에 쓰여 있는 수가 주사위의 바닥면으로 복사
                dice_map[x][y] = 0; //칸에 있는 수는 0 이 된다.
            }

            cout << dice[2] << endl;
        }
        else continue;
    }
    
    return 0;
}
