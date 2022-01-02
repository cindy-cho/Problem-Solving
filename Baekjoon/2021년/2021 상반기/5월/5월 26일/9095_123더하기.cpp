#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T,n;
    int DP[11];
    cin >> T;
    DP[0]=1;
    DP[1]=2;
    DP[2]=4;
    
    for(int i=3;i<11;i++){
        DP[i] = DP[i-3] + DP[i-2] + DP[i-1];
    }
    for(int i=0;i<T;i++){
        cin >> n;
        cout << DP[n-1] << "\n";
    }
    return 0;
}