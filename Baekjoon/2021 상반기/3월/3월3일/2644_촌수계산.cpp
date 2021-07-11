#include<iostream>
#include<vector>

using namespace std;
int flag=1;

void dfs(int r,int target,vector <vector <bool> > &family, vector <bool> &visited,int stage){
    if(r==target) {
        cout << stage << endl;
        flag =-1;
        return;
    }
    if(flag==-1) return;
    visited[r]= true;

    int i;
    for(i=0;i<visited.size();i++){
        if(family[r][i]==true && visited[i]==false){
            dfs(i,target,family,visited,stage+1);
        }
    }
}

int main(void){
    int n,r,c,m,i,x,y;
    scanf("%d",&n);
    scanf("%d %d",&r, &c);
    r--;
    c--;
    scanf("%d",&m);

    vector <vector <bool> > family ( n, vector <bool> (n,false));
    vector <bool> visited (n, false);
    for(i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        x--;
        y--;
        family[x][y] = true;
        family[y][x] = true;
    }

    dfs(r,c,family,visited,0);

    if(flag==1) cout << "-1" <<endl;
    return 0;

}