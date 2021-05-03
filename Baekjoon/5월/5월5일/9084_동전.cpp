#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T,N,M;
    int coin[20];
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> N;
        for(int j=0;j<N;j++) cin >> coin[j];
        
        cin >> M;
        vector <long long unsigned> dp(M+1,0);
        for(int j=0;j<N;j++){
            if(j==0){
                for(int k=1;k<=M;k++) if(k%coin[j]==0) dp[k]=1;
            }
            else{
                    for(int k=0;k<=M;k++){
                        if(k+coin[j]<=M) dp[k+coin[j]]+=dp[k];
                        if(k!=0 && k%coin[j]==0) dp[k]++;
                    } 
            }
        }

        cout << dp[M] << "\n";

    }
    return 0;
}