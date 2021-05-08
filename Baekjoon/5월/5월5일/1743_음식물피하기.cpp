#include<iostream>
#include<vector>
using namespace std;

int ans;
int current;
int N,M;
void findFood(vector<vector<int>> &map, int x, int y){
    int dir[4][2]= {{0,1},{0,-1},{1,0},{-1,0}};
    int tmpx,tmpy;
    for(int i=0;i<4;i++){
        tmpx = x+dir[i][0];
        tmpy = y+dir[i][1];
        if(tmpx>=0 && tmpx<N && tmpy>=0 && tmpy<M && map[tmpx][tmpy]==1){
            map[tmpx][tmpy]=0;
            current++;
            findFood(map,tmpx,tmpy);
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int K;
    int r,c;
    ans =0;
    cin >> N >> M >> K;
    vector<vector<int>> map(N,vector<int> (M,0));
    for(int i=0;i<K;i++){
        cin >> r >> c;
        r--;
        c--;
        map[r][c] = 1;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) if(map[i][j]==1) {
            map[i][j]=0;
            current = 1;
            findFood(map,i,j);
            if(current>ans) ans = current;
        }
    }
    cout << ans << "\n";
    return 0;
}