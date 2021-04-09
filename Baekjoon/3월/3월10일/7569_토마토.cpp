#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct{
    int i;
    int j;
    int k;
}loc;

int main(void){
    int M,N,H,i,j,k,val=0,notRiped=0;
    int dir[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
    scanf("%d %d %d",&M,&N,&H);
    vector < vector < vector < int > > > tomato(H, vector<vector< int > > (N, vector <int > ( M )));
    queue <pair <loc, int > > q;
    loc tmp;
    loc current;
    int tmpDays;
    int days=0;

    for(i=0;i<H;i++){
        for(j=0;j<N;j++){
            for(k=0;k<M;k++){
                scanf("%d",&val);
                tomato[i][j][k] = val;
                if(val==0) notRiped--;
                if(val==1){
                    tmp.i=i;
                    tmp.j=j;
                    tmp.k=k;
                    q.push(make_pair(tmp,0));
                }
            }
        }
    }

    if(notRiped==0) cout << "0" << endl;
    else{
        while(!q.empty()){
            current.i=q.front().first.i;
            current.j=q.front().first.j;
            current.k=q.front().first.k;
            tmpDays=q.front().second;
            days = max(tmpDays,days);
            q.pop();
            for(i=0;i<6;i++){
                tmp.i=current.i+dir[i][0];
                tmp.j=current.j+dir[i][1];
                tmp.k=current.k+dir[i][2];
                if(tmp.i>=0 && tmp.i<H && tmp.j>=0 && tmp.j<N && tmp.k>=0 && tmp.k<M && tomato[tmp.i][tmp.j][tmp.k]==0){
                    notRiped++;
                    tomato[tmp.i][tmp.j][tmp.k]=1;
                    q.push(make_pair(tmp,tmpDays+1));
                }
            }
        }

        if(days==0 || notRiped!=0) cout << "-1" << endl;
        else cout << days << endl;
    }


    return 0;
}