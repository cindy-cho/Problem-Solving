#include<iostream>
#include<vector>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int one=0,zero=0;
    vector<vector<int>> map(N,vector<int> (N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            if(map[i][j]==1) one++;
            else zero++;
        }
    }
    return 0;
}