#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int safety=0;
int current=0;
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};


void dfs(int y, int x, int N, vector < vector <int > > &rainy){
    int i,xx,yy;
    for(i=0;i<4;i++){
        yy = y + dir[i][0];
        xx = x + dir[i][1];
        if(xx>=0 && xx<rainy[0].size() && yy>=0 && yy < rainy[0].size() && rainy[yy][xx] > N){
            rainy[yy][xx] = N;
            dfs(yy,xx,N,rainy);
        }
    }
}

int main(void){
    int N,i,j,k,now;
    cin >> N ;
    vector < vector <int > > rainy(N, vector <int> (N));
    vector < vector <bool > > visited (N, vector <bool> (N,false));
    vector <bool> map (100,false);
    int max=0;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cin >> rainy[i][j];
            if(map[rainy[i][j]]==false){
                map[rainy[i][j]]=true;
                if(max<rainy[i][j]) max = rainy[i][j];

            }
        }
    }

    for(k=max;k>=0;k--){
        current=0;
                
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                if(rainy[i][j]>k) {
               //     cout << "(" << i << " , " << j << ")" << endl;
                    dfs(i,j,k, rainy);
                    current ++;
                }
                
            }
        }
        
        if(current>safety) safety = current;
    }

    cout << safety << endl;
    return 0;
}