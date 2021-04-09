#include<iostream>

using namespace std;


int board[101];
int dp[101];

void dfs(int start, int dice){
    int newStart,i;
    if(start+dice <=100 && board[start+dice]==0){
        newStart = start+dice;
        if(dp[newStart]==0) dp[newStart] = dp[start]+1;
        else if(dp[newStart] > dp[start]+1) dp[newStart] = dp[start]+1;
        else return;
    }

    else if(start+dice<=100 && board[start+dice]!=0){
        newStart = board[start+dice];
        if(dp[newStart]==0) dp[newStart] = dp[start]+1;
        else if(dp[newStart] > dp[start] + 1) dp[newStart] = dp[start] + 1;
        else return;
    }

    if(newStart == 100) return;
    
    for(i=1;i<=6;i++){
        if(newStart+i>100) continue;
        dfs(newStart,i);
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M,i,j,x,y,u,v;
    int start=0;
    
    cin >> N >> M;

    for(i=0;i<N;i++){
        cin >> x >> y;
        board[x]=y;
    }

    for(i=0;i<M;i++){
        cin >> u >> v;
        board[u]=v;
    }

    // for(i=1;i<=100;i++){
    //     cout << board[i] << ",";
    // }
    // cout << "dp\n";
    dp[1]=1;
    // for(i=1;i<=100;i++){
    //     cout << dp[i] << ",";
    // }

    for(i=1;i<=6;i++){
        dfs(1,i);
    }
    
    cout << dp[100]-1 << "\n";

    return 0;
}