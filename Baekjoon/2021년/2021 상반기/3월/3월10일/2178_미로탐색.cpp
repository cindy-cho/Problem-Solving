#include<iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef struct{
    int r;
    int c;
    int stage;
}qset;

int main(void){
    int i,j, N,M;
    int dir[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
    queue <qset> q;
    qset crnt,tmp;

    string input;
    scanf("%d %d\n",&N,&M);
    vector< vector < int > > map(N, vector<int> (M,0));
    
    for(i=0;i<N;i++){
        getline(cin,input);
        for(j=0;j<input.length();j++){
            if(input[j]=='1') map[i][j]=1;
        }
    }

    tmp.r=0;
    tmp.c=0;
    tmp.stage=1;

    //cout << N << "," << M << endl;
    q.push(tmp);

    while(!q.empty()){
        crnt.r= q.front().r;
        crnt.c= q.front().c;
        crnt.stage= q.front().stage;
        //printf("r,c : %d,%d : stage : %d\n",crnt.r,crnt.c,crnt.stage);
        if(crnt.r==N-1 && crnt.c==M-1) break;
        q.pop();
        for(i=0;i<4;i++){
            if(crnt.r+dir[i][0]>=0 && crnt.r+dir[i][0] <N && crnt.c+dir[i][1]>=0 && crnt.c+dir[i][1]<M && map[crnt.r+dir[i][0]][crnt.c+dir[i][1]]==1){
                tmp.r=crnt.r+dir[i][0];
                tmp.c=crnt.c+dir[i][1];
                tmp.stage = crnt.stage + 1;
                map[crnt.r+dir[i][0]][crnt.c+dir[i][1]]=0;
                q.push(tmp);
            }
        }
    }
    cout << crnt.stage << endl;

    return 0;
}