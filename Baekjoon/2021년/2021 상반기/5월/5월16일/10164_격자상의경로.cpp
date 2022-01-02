#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M,K;
    int x=-1,y=-1;
    int i,j;
    cin >> N >> M >> K;
    vector<vector<int>> DP (N,vector<int> (M,0));
    if(K!=0){
        x = (K-1)/M;
        y = (K-1)%M;
        for(i=0;i<=x;i++){
            for(j=0;j<=y;j++){
                if(i==0 && j==0) DP[i][j] = 1;
                else if(i==0) DP[i][j] = DP[i][j-1];
                else if(j==0) DP[i][j] = DP[i-1][j];
                else DP[i][j] = DP[i][j-1] + DP[i-1][j];
            }
        }
        for(i=x;i<N;i++){
            for(j=y;j<M;j++){
                if(i==0 && j==0) DP[i][j] = 1;
                else if(i==0) DP[i][j] = DP[i][j-1];
                else if(j==0) DP[i][j] = DP[i-1][j];
                else DP[i][j] = DP[i][j-1] + DP[i-1][j];
            }
        }
    }
    else{
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                if(i==0 && j==0) DP[i][j] = 1;
                else if(i==0) DP[i][j] = DP[i][j-1];
                else if(j==0) DP[i][j] = DP[i-1][j];
                else DP[i][j] = DP[i][j-1] + DP[i-1][j];
            }
        }
    }
    

    cout << DP[N-1][M-1] << "\n";
    
    return 0;
}