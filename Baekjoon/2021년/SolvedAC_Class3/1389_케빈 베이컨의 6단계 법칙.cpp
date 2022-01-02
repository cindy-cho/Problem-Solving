#include<iostream>
#include<algorithm>
#include<vector>
#define endl '\n'
#define INF 21000000
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M,a,b;
    int minIdx, minAns=1000000, curAns;
    cin >> N >> M;
    vector< vector<int>> Friends(N+1, vector<int> (N+1, INF));
    for(int i=0;i<M;i++){
        cin >> a >> b;
        Friends[a][b] = 1;
        Friends[b][a] = 1;
    }
    for(int i=1;i<=N;i++) Friends[i][i] = 0;
    
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(Friends[i][k] + Friends[k][j] < Friends[i][j]){
                    Friends[i][j] = Friends[i][k] + Friends[k][j];
                }
            }
        }
    }

    for(int i=1;i<=N;i++){
        curAns = 0;
        for(int j=1;j<=N;j++){
            curAns += Friends[i][j];
        }
        if(curAns < minAns){
            minAns = curAns;
            minIdx = i;
        }
    }

    cout << minIdx << endl;
    return 0;
}