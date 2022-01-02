#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    long long int K;
    long long int ans=0;
    cin >> N >> K;

    vector <long long int> coin(N);
    for(int i=0;i<N;i++){
        cin >> coin[i];
    }
    for(int i = N-1;i>=0;i--){
        ans += K/coin[i];
        K %=coin[i];
        if(K==0)break;
    }
    cout << ans << "\n";
    return 0;
}