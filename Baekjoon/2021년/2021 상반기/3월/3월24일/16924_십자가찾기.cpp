#include<iostream>
#include<queue>
using namespace std;

int main(void){
    int N, M, i,j;
    cin >> N >> M;
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    int x,y,size,flag;
    int tmp[4][2];
    int answer[10000][3];
    int ansIdx=0;
    char map[100][100];
    queue <pair <int , int  > > q;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            cin >> map[i][j];
            if(map[i][j]=='*'){
                q.push(make_pair(i,j));
            }
        }
    }

    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        
        size=0;
        for(i=0;i<4;i++) {
            tmp[i][0]=x;
            tmp[i][1]=y;
        }
        while(1){
            flag=0;
            for(i=0;i<4;i++){
                tmp[i][0] += dir[i][0];
                tmp[i][1] +=  dir[i][1];
                
                if(tmp[i][0]>=0 && tmp[i][0]<N && tmp[i][1]>=0 && tmp[i][1]<M){
                    if(map[tmp[i][0]][tmp[i][1]]=='*' || map[tmp[i][0]][tmp[i][1]]=='@') flag++;
                    else break;
                }
                else break;
                
            }
            if(flag!=4) break;
            size++;
        }
       
        if(size>0){
            for(i=x-size;i<=x+size;i++) map[i][y]='@';
            for(i=y-size;i<=y+size;i++) map[x][i]='@';
            answer[ansIdx][0]=x+1;
            answer[ansIdx][1]=y+1;
            answer[ansIdx][2]=size;
            ansIdx++;
        }
    }

    
    
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                if(map[i][j]=='*'){
                    cout << "-1\n";
                    return 0;
                }
            }
        }
        
        cout << ansIdx << "\n";
        for(i=0;i<ansIdx;i++){
            cout << answer[i][0] << " " << answer[i][1] << " " << answer[i][2] << "\n";
        }
    
    return 0;
}