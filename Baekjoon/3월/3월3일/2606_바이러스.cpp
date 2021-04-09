#include<iostream>
#include<vector>

using namespace std;

int total=0;
void dfs(int t, vector <vector <int > > &map, vector <bool> &visited){
    visited[t] = true;
    int i;
    for(i=0;i<map[0].size();i++){
        if( map[t][i]==1 && visited[i]==false){
            total++;
            dfs(i,map,visited);
        }
    }

    return ; 
}

int main(void){
    int N,C,i,j,r,c;
    scanf("%d",&N);
    scanf("%d",&C);

    vector <bool> visited (N, false);
    vector <vector <int > > map(N, vector <int> (N, 0));

    for(i=0;i<C;i++){
        scanf("%d %d",&r,&c);
        r--;
        c--;
        map[r][c]=1;
        map[c][r]=1;
    }

    
    dfs(0,map,visited);

    cout << total << endl;
    return 0;
}