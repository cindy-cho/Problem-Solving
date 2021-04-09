#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef struct{
    int i;
    int j;   
    int mov;
}Cursor;

int main(void){
    int M, N,i,j;
    int minMov=0;
    int dir[3][2] = {{1,0},{0,1},{0,-1}};
    int vst[1000][20];
    queue <Cursor> q;
    Cursor tmp, current;
    cin >> N >> M;
    cin.ignore();
    vector <string> data(M);
    for(i=0;i<M;i++) getline(cin,data[i]);
    for(i=0;i<M;i++) for(j=0;j<N;j++) vst[i][j]=-1;
    for(i=0;i<N;i++){
        if(data[0][i]=='c'){
            tmp.i=0;
            tmp.j=i;
            tmp.mov=0;
            q.push(tmp);
            vst[tmp.i][tmp.j] = tmp.mov;
        }
    }
    minMov = M*N;
     
    while(!q.empty()){
        current.i=q.front().i;
        current.j=q.front().j;
        current.mov = q.front().mov;
        
        q.pop();
        if(current.i==M-1 && current.mov<minMov) minMov = current.mov;
        
        else{
            for(i=0;i<3;i++){
                tmp.i=current.i+dir[i][0];
                tmp.j=current.j+dir[i][1];
                tmp.mov= current.mov;
                if( tmp.i< M &&  tmp.j< N && data[tmp.i][tmp.j]=='.'){
                    if(i>0) tmp.mov=tmp.mov+1;
                    if(vst[tmp.i][tmp.j]==-1 || vst[tmp.i][tmp.j]>tmp.mov) {
                        q.push(tmp);
                        if(vst[tmp.i][tmp.j]==-1 || tmp.mov < vst[tmp.i][tmp.j]){
                              vst[tmp.i][tmp.j] = tmp.mov;
         
                          }
                    }
                }
            }
        }
    }
    if(minMov== M*N) cout << "-1" << "\n";
    else cout << minMov << endl;
    return 0;
}