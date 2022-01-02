#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,T,ans=0;
    vector<int> DP(1001,-1);    
    DP[0] = 0;
    DP[1] = 0;
    for(int i=2;i<=1000;i++){
        if(DP[i]!=-1) continue;
        DP[i]=1;
        for(int j=i+1;j<=1000;j++){
            if(DP[j]!=-1) continue;
            if(j%i==0) DP[j] = 0;
        }
    }
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> T;
        if(DP[T]==1) ans++;
    }
    cout << ans << "\n";
    return 0;
}