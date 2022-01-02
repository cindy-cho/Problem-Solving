#include<iostream>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T,k,n,sum;
    int DP[15][14];
    cin >> T;
    for(int i=0;i<14;i++) DP[0][i] = i+1;
    for(int i=1;i<15;i++){
        sum =0;
        for(int j=0;j<14;j++){
            DP[i][j] = sum + DP[i-1][j];
            sum = DP[i][j];
        }
    }
    
    for(int i=0;i<T;i++){
        cin >> k >> n;
        cout << DP[k][n-1] << endl;
    }

    return 0;
}