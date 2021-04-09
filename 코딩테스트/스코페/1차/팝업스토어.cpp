#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int M,N,i,j;
    cin >> N >> M;
    int map[10000][100] = {0,};
    int dp[10000][100] = {0,};
    
    for(i=0;i<M;i++) {
        for(j=0;j<N;j++) {
            cin >> map[i][j];
            if(i==0 && j==0) dp[0][0] = map[0][0];
            else if(i==0) dp[i][j] = dp[i][j-1] + map[i][j];
            else if(j==0) dp[i][j] = dp[i-1][j] + map[i][j];
        }
    }
    for(i=1;i<M;i++){
        for(j=1;j<N;j++){
            dp[i][j] = map[i][j] + max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[M-1][N-1] << '\n';
    return 0;
}