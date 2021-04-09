#include<iostream>
#include <vector>

using namespace std;

void checkCharacter(vector <vector <int > > &map, int x, int y,int M, int N){
    int dir[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
    int i,tmpx,tmpy;
    map[x][y] = 0;
    for(i=0;i<8;i++){
        tmpx = x+dir[i][0];
        tmpy = y+dir[i][1];
        if(tmpx>=0 && tmpx<M && tmpy>=0 && tmpy<N && map[tmpx][tmpy]==1){
            checkCharacter(map,tmpx,tmpy,M,N);
        }
    }
}
int main(void){
    int M,N,i,j,ans=0;
    
    cin >> M >> N;

    vector <vector < int > > map (M, vector<int> (N));

    for(i=0;i<M;i++){
        for(j=0;j<N;j++) cin >> map[i][j];
    }
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            if(map[i][j]==1){
                checkCharacter(map,i,j,M,N);
                ans ++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}