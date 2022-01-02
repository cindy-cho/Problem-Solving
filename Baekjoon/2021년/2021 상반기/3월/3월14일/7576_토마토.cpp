#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct{
    int i;
    int j;
    int day;
}toma;

int main(void){
    int M,N,i,j,ans=0,ripe=0;
    int x,y,nx,ny,stage=0;
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    toma tmp,current;
    queue <toma> q;
    cin >> M >> N;
    vector < vector <int > > tomato (N, vector<int> (M, 0));
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            cin >> tomato[i][j];
            if(tomato[i][j]==0) {
                ans=-1;
                ripe++;
            }
            else if(tomato[i][j]==1){
                tmp.i=i;
                tmp.j=j;
                tmp.day=stage;
                q.push(tmp);
            }
        }
    }
    if(ans==0) cout << 0 << endl;
    else{
        while(!q.empty()){
            x=q.front().i;
            y=q.front().j;
            stage = q.front().day;
            q.pop();
            for(i=0;i<4;i++){
                nx = x + dir[i][0];
                ny = y + dir[i][1];
                if(nx>=0 && nx<N && ny>=0 && ny<M && tomato[nx][ny]==0){
                    current.i=nx;
                    current.j=ny;
                    current.day=stage +1;
                    q.push(current);
                    tomato[nx][ny]=1;
                    ripe--;
                }
            }
        }
        if(ripe==0) cout << stage << endl;
        else cout << "-1" << endl;
    }
    return 0;
}