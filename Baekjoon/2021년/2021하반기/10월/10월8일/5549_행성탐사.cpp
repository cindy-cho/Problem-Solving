#include<iostream>
#include<string>
#include<vector>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M,N,K;
    int a,b,c,d;
    int jungle, ocean, ice;
    char type[3] = {'J', 'O', 'I'} ;
    cin >> M >> N;
    cin >> K;
    vector<string> map(M);
    vector<vector<vector<int>>> saved(M+1, vector<vector<int>> (N+1, vector<int> (3,0)));
    
    for(int x=0;x<M;x++) cin >> map[x];

    //0,0 초기화
    for(int x=0;x<3;x++){
        if(map[0][0]==type[x]){
            saved[1][1][x]=1;
        }
    }
    //Map 누적합
    for(int x=0;x<M;x++){
        for(int y=0;y<N;y++){
            if(x==0 && y==0) continue;
            for(int z=0;z<3;z++){
                if(map[x][y]==type[z]) saved[x+1][y+1][z]=1;
            }
            if(y==0) for(int z=0;z<3;z++) saved[x+1][y+1][z] += saved[x][y+1][z];
            else if(x==0) for(int z=0;z<3;z++) saved[x+1][y+1][z] += saved[x+1][y][z];
            else for(int z=0;z<3;z++) saved[x+1][y+1][z] += (saved[x+1][y][z] + saved[x][y+1][z] - saved[x][y][z]);
        }
    }

    // for(int i=0;i<M;i++){
    //     for(int j=0;j<N;j++){
    //         cout << "(" << saved[i+1][j+1][0] << "," << saved[i+1][j+1][1] << "," << saved[i+1][j+1][2] << ")" << " " ;
    //     }
    //     cout << endl;
    // }
    while(K--){
        cin>> a >> b >> c >> d;
        
        jungle = saved[c][d][0] - saved[c][b-1][0] - saved[a-1][d][0] + saved[a-1][b-1][0];        
        ocean = saved[c][d][1] - saved[c][b-1][1] - saved[a-1][d][1] + saved[a-1][b-1][1];
        ice = saved[c][d][2] - saved[c][b-1][2] - saved[a-1][d][2] + saved[a-1][b-1][2];
        cout << jungle << " " << ocean << " " << ice << endl;
    }
    return 0;
}