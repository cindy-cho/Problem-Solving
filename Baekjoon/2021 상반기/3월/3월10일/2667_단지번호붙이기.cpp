#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int connected,N;
int dir[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
void dfs(int i, int j, vector < vector <int > > &map){
    map[i][j] = 0; 
    connected++;

    for(int a=0;a<4;a++){
        if(i+dir[a][0]>=0 && i+dir[a][0]<N && j+dir[a][1]>=0 && j+dir[a][1]<N && map[i+dir[a][0]][j+dir[a][1]]==1){
            dfs(i+dir[a][0],j+dir[a][1],map);
        }
    }
    
    return ;
}

int main(void){
    int i,j;
    string input;
    scanf("%d\n",&N);
    vector < vector <int > > map(N, vector<int> (N, 0));
    vector <int> ans;
    for(i=0;i<N;i++){
        getline(cin, input);
        for(j=0;j<N;j++){
            if(input[j]=='1') map[i][j]=1;
        }
    }

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){ 
            if(map[i][j]==1) {
                connected=0;
                dfs(i,j,map);
                ans.push_back(connected);
            }
        }
    }

    cout << ans.size() << endl;
    sort(ans.begin(),ans.end());
    for(i=0;i<ans.size();i++) cout << ans[i] << endl;

    return 0;
}